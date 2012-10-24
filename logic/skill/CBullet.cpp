#include "CBullet.h"
#include "Process_error.h"
#include "../attr/CCharacterEntity.h"
#include "../attr/attrFunc.h"
#include "evtDef.h"

namespace SKILLEDITOR
{
	CBullet::CBullet()
	{
		m_isCritical = m_isInvalid = false;
		m_pSource = m_pTarget = NULL;
		m_pSkillTemplate = NULL;
		m_srcObjID = m_hitPart = m_hitPeriodIndex = m_attackPower = m_brokerValue = m_damageValue = 0;

		memset(m_tempValue, 0, sizeof(m_tempValue));
	}
	CBullet::~CBullet()
	{
		//
	}
	bool CBullet::onInit(CCharacterEntity * srcEntity, CSkillTemplate *pSkillTemplate,
		::GSLib::SSkillEntryParameter* skillEntryParameter, BSLib::s32 hitIndex)
	{
		LOG_PROCESS_ERROR(srcEntity && pSkillTemplate && skillEntryParameter);

		setHitIndex(hitIndex);
		setSkillTemplate(pSkillTemplate);
		setSrcObjID(srcEntity->getEntityID());
		setSrcEntity(srcEntity);
		//setSrcAttrList(srcEntity->getFighterImp()->getAttrList());
		m_attackPower = 0;
		memset(m_tempValue, 0, sizeof(m_tempValue));
		m_isInvalid = m_isCritical = false;
		return true;
Exit0:
		return false;
	}
	bool CBullet::onHit(CCharacterEntity* dstEntity)
	{
		LOG_PROCESS_ERROR(m_isInvalid == false);
		LOG_PROCESS_ERROR(dstEntity);
		setTargetEntity(dstEntity);
		//setTargetAttrList(dstEntity->getFighterImp()->getAttrList());

		//dstEntity->getFighterImp()->fireEvt(dstEntity, seBeHit, EAttrModifyType_Bullet, this);
		return explode();
Exit0:
		return false;
	}
	bool CBullet::explode()
	{
		LOG_PROCESS_ERROR(!m_isInvalid);
		LOG_PROCESS_ERROR(m_pSkillTemplate);

		/*BSLib::s32 iSeq = m_pSkillTemplate->getApplySeq(mos_onHit + getHitIndex(), m_oSpellEntryParam);
		if (iSeq > 0)
		{
			sModifierMgr.applySeq(iSeq, getSrcEntity(), EAttrModifyType_Bullet, this);
		}

		if (getSrcEntity())
		{
			LOG_PROCESS_ERROR(!m_isInvalid);
			getSrcEntity()->getFighterImp()->fireEvt(dstEntity, seAfterExploded, EAttrModifyType_Bullet, this);
		}*/
		return true;
Exit0:
		return false;
	}

	bool CBullet::regTempValue(BSLib::s32 index, BSLib::s32 seq, BSLib::s32 arg)
	{
		LOG_PROCESS_ERROR(index >= 0 && index < MAX_BULLET_TEMP_VALUE);
		LOG_PROCESS_ERROR(m_pTarget);

		BSLib::s32 type = 0, id = 0;
		SplitFunctionKey(seq, type, id);

		TGetAttr getFunc = GetAttrFunc(type, id);
		LOG_PROCESS_ERROR(getFunc);

		switch (type)
		{
		case EAttrModifyType_Char:
			m_tempValue[index] = getFunc( m_pTarget->getFighterImp(), arg);
			break;
		case  EAttrModifyType_Bullet:
			m_tempValue[index] = getFunc(this, arg);
			break;
		default:
			LOG_PROCESS_ERROR(false);
		}
		return true;
Exit0:
		return false;
	}
	bool CBullet::unRegTempValue(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index >= 0 && index < MAX_BULLET_TEMP_VALUE);
		m_tempValue[index] = 0;
		return true;
Exit0:
		return false;
	}
	bool CBullet::setTempValue(BSLib::s32	index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index >= 0 && index < MAX_BULLET_TEMP_VALUE);
		m_tempValue[index] = value;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CBullet::getTempValue(BSLib::s32	index)
	{
		LOG_PROCESS_ERROR(index >= 0 && index < MAX_BULLET_TEMP_VALUE);

		return m_tempValue[index];
Exit0:
		return 0;
	}
}