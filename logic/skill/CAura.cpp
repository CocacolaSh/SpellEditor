#include "CAura.h"
#include "../attr/EntityFunc.h"
#include "../skill/aura_template.h"
#include "../attr/CCharacterEntity.h"
#include "../attr/ModifierFunc.h"
#include "../attr/ModifierChar.h"
#include "CPrdEftList.h"
#include "CModifyMgr.h"
#include "../attr/attrFunc.h"
#include <cmath>
#include <algorithm>

namespace SKILLEDITOR
{
	CAura::CAura()
	{
		m_leftTime = 0;
		m_template = NULL;
		m_powerAdded = 0;
	}
	CAura::~CAura(){}

	BSLib::s32	CAura::getID()
	{
		return m_template->m_data.getID();
	}

	BSLib::s32	CAura::getLevel()
	{
		return m_template->m_data.getLevel();
	}

	EPeriodEffectNature	CAura::getNature()
	{
		return (EPeriodEffectNature)(m_template->m_data.m_isGood);
	}

	bool CAura::update(CCharacterEntity *owner, float timePass)
	{
		if (m_leftTime <= 0)
		{
			return true;
		}
		m_leftTime -= timePass;
		if (m_leftTime <= 0)
		{
			return true;
		}
		return false;
	}
	BSLib::s32 CAura::getEffectGroup()
	{
		return m_template->m_data.m_groupID;
	}
	CPeriodEffect *CAura::clone()
	{
		CAura *pAura = new CAura();
		if (pAura == NULL)
		{
			return NULL;
		}
		pAura->m_srcObjID = m_srcObjID;
		pAura->setupTemplate(m_template);
		return pAura;
	}

	bool CAura::addToList(CPrdEftList * list, CCharacterEntity *src, CCharacterEntity * dst)
	{
		BSLib::s32 attrID = m_template->m_data.m_targetAttrID;
		BSLib::s32 attrDelta = m_template->m_data.m_targetAttrType;
		BSLib::s32 powerToAdd = m_template->m_data.m_powerOfAura;
		BSLib::s32 powerUpper = m_template->m_data.m_powerUpperLimit;

		BSLib::s32 keyIndex = EGetCharAttrFunc_GetAttributeA + attrDelta;

		TGetAttr get_attr = GetAttrFunc(EAttrModifyType_Char, keyIndex);
		if (get_attr == NULL)
		{
			return false;
		}

		BSLib::s32 attrValue = get_attr((IFighter*)(dst->getFighterImp()), attrID);
		if (powerToAdd >= 0)
		{
			if(attrValue >= powerUpper)
				return false;

			m_powerAdded = std::min(attrValue + powerToAdd, powerUpper) - attrValue;
		}else
		{
			if (attrValue <= powerUpper)
			{
				return false;
			}
			m_powerAdded = std::max(attrValue + powerToAdd, powerUpper) - attrValue;
		}
		return list->addAura(this, src, dst);
	}

	void CAura::onAppend(CCharacterEntity *src, CCharacterEntity *dst)
	{
		BSLib::s32 attrID = m_template->m_data.m_targetAttrID;

		//A,B,C,D,EÐÞ¸ÄÊôÐÔµÄABCDE
		BSLib::s32 attrDelta = m_template->m_data.m_targetAttrType;

		BSLib::s32 keyIndex = EAMKCHAR_ChangeAttributeA + attrDelta;

		TAttrModifierFunc func = GetModifierFunc(EAttrModifyType_Char, keyIndex);
		if (func)
		{
			if ( !func(src, dst, keyIndex, attrID, m_powerAdded, 0))
			{
				assert(0);
			}
		}
		else
		{
			assert(0);
		}

		for (BSLib::u32 i = 0; i < MAX_SEQ; ++i)
		{
			sModifierMgr.applySeq(m_template->m_dwSeq[EModifyAuraTime_OnAppend][i], NULL, EAttrModifyType_Char, dst);
		}
		m_leftTime = m_timeTemplateSpan = m_template->m_data.m_fixTime / 1000.f;
		CPeriodEffect::onAppend(src, dst);
	}
	void CAura::onRemove(CCharacterEntity *dst)
	{
		CPeriodEffect::onRemove(dst);

		for (BSLib::u32 i = 0; i < MAX_SEQ; ++i)
		{
			sModifierMgr.applySeq(m_template->m_dwSeq[EModifyAuraTime_OnRemove][i], NULL, EAttrModifyType_Char, dst);
			sModifierMgr.rollbackSeq(m_template->m_dwSeq[EModifyAuraTime_OnAppend][i], NULL, EAttrModifyType_Char, dst);
		}
		BSLib::s32 attrID = m_template->m_data.m_targetAttrID;
		BSLib::s32 attrDelta = m_template->m_data.m_targetAttrType;

		BSLib::s32 keyIndex = EAMKCHAR_ChangeAttributeA + attrDelta;

		TAttrModifierFunc func = GetModifierFunc(EAttrModifyType_Char, keyIndex);
		if (func)
		{
			if ( !func(NULL, dst, keyIndex, attrID, m_powerAdded, 0))
			{
				assert(0);
			}
		}
		else
		{
			assert(0);
		}
	}

	void CAura::setupTemplate(AuraTemplate* t)
	{
		m_template = t;
	}
	void CAura::setupDuration(BSLib::s32 d){}
	void CAura::modifyMe()
	{
		if (m_template->m_iscpy)
		{
			return;
		}
		AuraTemplate *tmp = new AuraTemplate();
		copyTemplate(tmp);
		tmp->m_iscpy = true;
		m_template = tmp;
	}
	void CAura::copyTemplate(AuraTemplate *t)
	{
		t->m_iscpy = m_template->m_iscpy;
		memcpy(&t->m_data, &m_template->m_data, sizeof(AuraEntry));
		memcpy(t->m_dwSeq, m_template->m_dwSeq, sizeof(m_template->m_dwSeq));
	}

	CAura *GCreateAuraInstance(AuraTemplate *t, CCharacterEntity *src)
	{
		CAura *pAura = new CAura();
		if (pAura == NULL)
		{
			return NULL;
		}

		pAura->setSrcObjID(src->getEntityID());
		pAura->setupTemplate(t);
		return pAura;
	}
}