#ifndef __LOGIC_SKILL_CBULLET_H__
#define __LOGIC_SKILL_CBULLET_H__
#include "basedef.h"
#include "../attr/attrList.h"
namespace GSLib
{
	struct SSkillEntryParameter
	{
		BSLib::s16	m_chargeLevel;
		BSLib::s16	m_mountType;
	};
}
namespace SKILLEDITOR
{
	class CSkillTemplate;
	class CCharacterEntity;
	const BSLib::s32 MAX_BULLET_TEMP_VALUE = 10;

	class CBullet
	{
		struct SBulletTempValue
		{
			BSLib::s32 id;
			BSLib::s32 value;
		};

	public:
		CBullet();
		virtual ~CBullet();

		void release(){delete this;}

		BSLib::s32			getHitIndex(){return m_hitPeriodIndex;}
		void				setHitIndex(BSLib::s32 hitIndex){m_hitPeriodIndex = hitIndex;}
		BSLib::s32			getAttackPower(){return m_attackPower;}
		void				setAttackPower(BSLib::s32 attackPower){m_attackPower = attackPower;}
		BSLib::s32			getDamageValue(){return m_damageValue;}
		void				setDamageValue(BSLib::s32 damageValue){m_damageValue = damageValue;}
		BSLib::s32			getSrcObjID(){return m_srcObjID;}
		void				setSrcObjID(BSLib::s32 srcObjID){m_srcObjID = srcObjID;}
		CCharacterEntity*	getSrcEntity(){return m_pSource;}
		void				setSrcEntity(CCharacterEntity* source){m_pSource = source;}
		CCharacterEntity*	getTargetEntity(){return m_pTarget;}
		void				setTargetEntity(CCharacterEntity* target){m_pTarget = target;}
		BSLib::s32			getHitPart(){return m_hitPart;}
		void				setHitPart(BSLib::s32 hitPart){m_hitPart = hitPart;}

		CSkillTemplate*		getSkillTemplate(){return m_pSkillTemplate;}
		void				setSkillTemplate(CSkillTemplate* skillTemplate){m_pSkillTemplate = skillTemplate;}

		void				setSrcAttrList(CAttrList* pAttrList){ if (pAttrList) pAttrList->clone(m_srcAttrList);}
		CAttrList*			getSrcAttrList(){return &m_srcAttrList;}
		void				setTargetAttrList(CAttrList* pAttrList){ if (pAttrList) pAttrList->clone(m_targetAttrList);}
		CAttrList*			getTargetAttrList(){return &m_targetAttrList;}

		bool				getIsInvalid(){return m_isInvalid;}
		void				setIsInvalid(bool validValue){m_isInvalid = validValue;}
		bool				getIsCritical(){return m_isCritical;}
		void				setIsCritical(bool validValue){m_isCritical = validValue;}

		bool				onInit(CCharacterEntity * srcEntity, CSkillTemplate *pSkillTemplate, ::GSLib::SSkillEntryParameter* skillEntryParameter, BSLib::s32 hitIndex);
		bool				onHit(CCharacterEntity* dstEntity);
		bool				explode();

		bool				regTempValue(BSLib::s32 index, BSLib::s32 seq, BSLib::s32 arg);
		bool				unRegTempValue(BSLib::s32 index);
		bool				setTempValue(BSLib::s32	index, BSLib::s32 value);
		BSLib::s32			getTempValue(BSLib::s32	index);

		
	private:
		bool					m_isInvalid;
		bool					m_isCritical;
		CCharacterEntity*		m_pTarget;
		CCharacterEntity*		m_pSource;
		BSLib::s32				m_srcObjID;
		BSLib::s32				m_hitPart;
		BSLib::s32				m_hitPeriodIndex;

		::GSLib::SSkillEntryParameter	m_oSpellEntryParam;
		BSLib::s32				m_attackPower;
		BSLib::s32				m_damageValue;
		CAttrList				m_srcAttrList;
		CAttrList				m_targetAttrList;
		BSLib::s32				m_brokerValue;
		CSkillTemplate*			m_pSkillTemplate;
		BSLib::s32				m_tempValue[MAX_BULLET_TEMP_VALUE];
		BSLib::s32      m_powerAdded;
	};
}
#endif