#include "CEot.h"
#include "../attr/EntityFunc.h"
#include "../skill/aura_template.h"
#include "../attr/CCharacterEntity.h"
#include "../attr/ModifierFunc.h"
#include "../attr/ModifierChar.h"
#include "CPrdEftList.h"
#include "CModifyMgr.h"
#include "../attr/attrFunc.h"
#include "Process_error.h"

namespace SKILLEDITOR
{
	CEot::CEot()
	{
		m_leftTime = 0;
		m_curInterval = 0;
		m_template = NULL;
	}
	CEot::~CEot()
	{
		if (m_template)
		{
			SAFE_DELETE(m_template);
		}
	}
	BSLib::s32 CEot::getID()
	{
		return m_template->m_data.m_id;
	}
	BSLib::s32 CEot::getLevel()
	{
		return m_template->m_data.m_level;
	}
	EPeriodEffectType CEot::getType(){return EPERIOD_EFFECT_TYPE_EOT;}
	EPeriodEffectNature CEot::getNature()
	{
		return m_template->m_data.m_isHot ? EPERIOD_EFFECT_NATURE_POSITIVE: EPERIOD_EFFECT_NATURE_NEGATIVE;
	}
	bool CEot::update(CCharacterEntity *owner, float timePass)
	{
		//if (m_leftTime <= 0)
		//{
		//	return true;
		//}

		//m_curInterval += timePass;
		//if (m_curInterval >= getJumpInterval())
		//{
		//	//pass one jump
		//	m_curInterval -= getJumpInterval();

		//	float power = getInfo()->m_data.m_jumpPower;
		//	BSLib::s32 attrID = getInfo()->m_data.m_targetAttrID;
		//	switch(attrID)
		//	{
		//	case 0:
		//		assert(0);
		//		break;
		//	case 1://hp
		//		owner->getFighterImp()->getEntityAttribute()->addHP(power);
		//		break;
		//	case 2://Mp
		//		owner->getFighterImp()->getEntityAttribute()->addMP(power);
		//		break;
		//	case 3://Sp
		//		owner->getFighterImp()->getEntityAttribute()->addSP(power);
		//		break;
		//	default:
		//		assert(0);
		//		break;
		//	}

		//	for(BSLib::u32 i = 0; i < MAX_SEQ; i++)
		//		sModifierMgr->applySeq(m_template->m_dwSeq[EModifyEotTime_OnTrigger][i], owner, amtchar, owner);
		//}

		//m_leftTime -= timePass;
		//if (m_leftTime <= 0)
		//{
		//	return true;
		//}
		return false;
	}
	CPeriodEffect *CEot::clone()
	{
		CEot *pEot = new CEot();
		if (pEot == NULL)
		{
			return NULL;
		}
		pEot->m_srcObjID = m_srcObjID;
		pEot->setupTemplate(m_template);
		return pEot;
	}
	bool CEot::addToList(CPrdEftList * list, CCharacterEntity *src, CCharacterEntity * dst)
	{
		return list->addEot(this, src, dst);
	}
	void CEot::onAppend(CCharacterEntity *src, CCharacterEntity *dst)
	{
		//for(BSLib::u32 i = 0; i < MAX_SEQ; i++)
		//	sModifierMgr->applySeq(m_template->m_dwSeq[EModifyEotTime_OnAppend][i], dst, amtchar, dst);
		//m_leftTime = m_timeTemplateSpan = (m_template->m_data.m_jumpTime * m_template->m_data.m_jumpNumber) / 1000.f;
		//CPeriodEffect::onAppend(src, dst);
	}
	void CEot::onRemove(CCharacterEntity *dst)
	{
		//CPeriodEffect::onRemove(dst);
		//for(BSLib::u32 i = 0; i < MAX_SEQ; i++)
		//{
		//	sModifierMgr->applySeq(m_template->m_dwSeq[EModifyEotTime_OnRemove][i], dst, amtchar, dst);
		//	sModifierMgr->rollbackSeq(m_template->m_dwSeq[EModifyEotTime_OnAppend][i], dst, amtchar, dst);
		//}
	}

	void CEot::setupTemplate(EotTemplate* t)
	{
		if (m_template && m_template->m_iscpy)
		{
			SAFE_DELETE(m_template);
		}
		m_template = t;
	}
	void CEot::modifyMe()
	{
		if (m_template->m_iscpy)
		{
			return;
		}

		EotTemplate* temp = new EotTemplate();
		copyTemplate(temp);
		temp->m_iscpy = true;
		m_template = temp;
	}
	void CEot::copyTemplate(EotTemplate *t)
	{
		t->m_iscpy = m_template->m_iscpy;
		memcpy(&t->m_data, &m_template->m_data, sizeof(EotEntry));
		memcpy(t->m_dwSeq, m_template->m_dwSeq, sizeof(m_template->m_dwSeq));
	}

	CEot *CreateEotInstance(EotTemplate *t, CCharacterEntity * src)
	{
		CEot *pEot = new CEot();
		if (pEot == NULL)
		{
			return NULL;
		}

		pEot->setSrcObjID(src->getEntityID());
		pEot->setupTemplate(t);
		return pEot;
	}
}