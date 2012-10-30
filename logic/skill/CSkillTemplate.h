#ifndef __LOGIC_SKILL_CSKILLTEMPLATE_H__
#define __LOGIC_SKILL_CSKILLTEMPLATE_H__
#include "basedef.h"
#include "evtDef.h"
#include "ConditionMgr.h"
#include <vector>
#include <string>
#include "colaString.h"
#include <map>

namespace GSLib
{
	struct SSkillEntryParameter
	{
		BSLib::s16	m_chargeLevel;
		BSLib::s16	m_scenarioType;
	};
}
namespace SKILLEDITOR
{
	
	enum ESkillType
	{
		ESkillType_Invalid = -1,
		ESkillType_Physic,
		ESkillType_Magic,
		ESkillType_End,
	};

	enum ESkillIntVar
	{
		ESkillIntVar_Invalid,
		ESkillIntVar_ID,
		ESkillIntVar_Level,

		ESkillIntVar_IsElite,
		ESkillIntVar_IsEmblem,
		ESkillIntVar_Pattern,
		ESkillIntVar_CategoryType,
		ESkillIntVar_CategoryVar,
		ESkillIntVar_CoolDownTime,
		ESkillIntVar_CoolDownType,
		ESkillIntVar_GlobalCDType,

		ESkillIntVar_TargetType,
		ESkillIntVar_TargetRank,
		ESkillIntVar_IsAutoFaceTarget,

		ESkillIntVar_AtLearnSeqs,
		ESkillIntVar_AtEquipSeqs,

		ESkillIntVar_BaseType,
		ESkillIntVar_IsIgnoreHard,
		ESkillIntVar_OmitInputTime,

		ESkillIntVar_ScenarioType,
		ESkillIntVar_ChargeLevel,
		ESkillIntVar_CatingTime,
		ESkillIntVar_AttackingTime,
		ESkillIntVar_CloseAttackTime,

		ESkillIntVar_SpurtTimeSpan,
		ESkillIntVar_SpurtDistance,

		ESkillIntVar_CastArmor,
		ESkillIntVar_FloatTimeStart,
		ESkillIntVar_FloadTimeSpan,

		ESkillIntVar_BreakArmor1,
		ESkillIntVar_BreakArmor2,
		ESkillIntVar_BreakArmor3,
		ESkillIntVar_Count,
	};

	enum ESkillStrVar
	{
		ESkillStrVar_Invalid = -1,
		ESkillStrVar_LoopFX,
		ESkillStrVar_CastingPose,
		ESkillStrVar_AttackingPos,
		ESkillStrVar_CloseAttackPos,
		ESkillStrVar_Count,
	};

	enum ESkillAttackEffect
	{
		ESkillAttackEffect_Invalid = -1,
		ESkillAttackEffect_Begin,
		ESkillAttackEffect_Modifier = ESkillAttackEffect_Begin,
		ESkillAttackEffect_Spurt,
		ESkillAttackEffect_Fire,
		ESkillAttackEffect_Count,
	};

	class CSkillAttackEffect
	{
	public:
		CSkillAttackEffect(){}
		CSkillAttackEffect(BSLib::f32 time, ESkillAttackEffect type)
		{
			m_time = time;
			m_type = type;
		}
		virtual ~CSkillAttackEffect(){}
		
		bool operator < (const CSkillAttackEffect &rhs)const
		{
			return m_time < rhs.m_time;
		}
		ESkillAttackEffect getAttackEffect()const {return m_type;}
		BSLib::f32 getTime(){return m_time;}
	protected:
		BSLib::f32			m_time;
		ESkillAttackEffect m_type;
	};
	class CSkillAttackEffectModifier : public CSkillAttackEffect
	{
	public:
		CSkillAttackEffectModifier()
		{
			m_type = ESkillAttackEffect_Modifier;
		}
		CSkillAttackEffectModifier(BSLib::f32 time, BSLib::u32 modifierSeq)
			:CSkillAttackEffect(time, ESkillAttackEffect_Modifier), m_modifierSeq(modifierSeq)
		{
			//
		}
		
		~CSkillAttackEffectModifier(){}
	protected:
		BSLib::u32 m_modifierSeq;
	};
	class CSkillAttackEffectSpurt : public CSkillAttackEffect
	{
	public:
		CSkillAttackEffectSpurt()
		{
			m_type = (ESkillAttackEffect_Spurt);
		}
		CSkillAttackEffectSpurt(BSLib::f32 time, BSLib::f32 timeSpan, BSLib::f32 distanceX, BSLib::f32 distanceY, BSLib::f32 distanceZ, bool stepDown)
			:CSkillAttackEffect(time, ESkillAttackEffect_Spurt), m_timeSpan(timeSpan), m_distanceX(distanceX), m_distanceY(distanceY), m_distanceZ(distanceZ), m_stepDown(stepDown)
		{
			
		}
	protected:
		BSLib::f32	m_timeSpan;
		BSLib::f32	m_distanceX;
		BSLib::f32	m_distanceY;
		BSLib::f32	m_distanceZ;
		bool		m_stepDown;
	};
	class CSkillAttackEffectFire : public CSkillAttackEffect
	{
	public:
		CSkillAttackEffectFire()
		{
			m_type = (ESkillAttackEffect_Fire);
		}
		CSkillAttackEffectFire(BSLib::f32 time, BSLib::u32 entityType, BSLib::stringc missile, BSLib::u32 skillID, BSLib::u32 skillLevel)
			:CSkillAttackEffect(time, ESkillAttackEffect_Fire), m_entityType(entityType), m_missile(missile), m_skillID(skillID), m_skillLevel(skillLevel)
		{
			m_type = (ESkillAttackEffect_Fire);
		}
	protected:
		BSLib::u32			m_entityType;
		BSLib::stringc 		m_missile;
		BSLib::u32			m_skillID;
		BSLib::u32			m_skillLevel;
	};

	class CSkillAttackPeriodInfo
	{
	public:
		virtual ~CSkillAttackPeriodInfo(){}

		bool init(BSLib::s32 collisionGroupID, BSLib::stringc attackInfoName, BSLib::s32 breakArmorValue)
		{
			m_collisionGroupID = collisionGroupID;
			m_attackInfoName = attackInfoName;
			m_breadArmorValue = breakArmorValue;
			return true;
		}

		void setChargeLevel(BSLib::u8 chargeLevel){m_chargeLevel = chargeLevel;}
		void setPeriodID(BSLib::u8 periodID){m_periodID = periodID;}
	private:
		BSLib::stringc		m_attackInfoName;
		BSLib::u32			m_collisionGroupID;
		BSLib::s32			m_breadArmorValue;
		BSLib::u8			m_chargeLevel;
		BSLib::u8			m_periodID;

		BSLib::f32			m_startTime;
		BSLib::f32			m_endTime;
	};
	class CSkillEntry
	{
	public:
		CSkillEntry();
		~CSkillEntry();

		bool clear();

		BSLib::s32						m_intData[ESkillIntVar_Count];
		std::string						m_strData[ESkillStrVar_Count];
		std::vector<BSLib::u64>			m_castEnhancement;
		std::vector<BSLib::u64>			m_attackEnhancement;

		SCondition						m_conditionChecker[EConditionType_Count];

		
		BSLib::u32						m_seq[EModifySkillTime_Count];
		CSkillAttackEffect *			m_attackEffect[ESkillAttackEffect_Count];
		CSkillAttackPeriodInfo			m_attackPeriods[EModifySkillTime_Count];
	};

	enum ESkillScenarioType
	{
		ESkillScenarioType_Invalid = -1,
		ESkillScenarioType_Ignore,
		ESkillScenarioType_PVE,
		ESkillScenarioType_PVP,
		ESkillScenarioType_Count,
	};

	enum ESkillChargeLevel
	{
		ESkillChargeLevel_Level0 = 0,
		ESkillChargeLevel_Level1,
		ESkillChargeLevel_Count,
	};

	class CSkillTemplate
	{
	public:
		CSkillTemplate();
		virtual ~CSkillTemplate();

		bool addSkillEntry(CSkillEntry *pSkillEntry);
		CSkillEntry* getSkillEntry(const ::GSLib::SSkillEntryParameter& skillParameter)const;
	private:
		CSkillEntry*			m_skillEntrys[ESkillChargeLevel_Count][ESkillScenarioType_Count];
	};
}
#endif