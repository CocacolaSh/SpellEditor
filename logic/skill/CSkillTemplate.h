#ifndef __LOGIC_SKILL_CSKILLTEMPLATE_H__
#define __LOGIC_SKILL_CSKILLTEMPLATE_H__
#include "basedef.h"
#include "evtDef.h"
#include <vector>
#include <string>
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

	class CSkillEntry
	{
	public:
		CSkillEntry();
		~CSkillEntry();

		BSLib::s32						m_intData[ESkillIntVar_Count];
		std::string						m_strData[ESkillStrVar_Count];
		std::vector<BSLib::u64>			m_castEnhancement;
		std::vector<BSLib::u64>			m_attackEnhancement;

		
		BSLib::u32						m_seq[EModifySkillTime_Count];
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