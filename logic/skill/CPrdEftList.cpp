#include "CPrdEftList.h"
#include "CAura.h"
#include "CEot.h"

namespace SKILLEDITOR
{
	CPrdEftList::CPrdEftList(){}
	CPrdEftList::~CPrdEftList(){}

	void CPrdEftList::update(CCharacterEntity *owner, float timePass)
	{
		TEffectList::iterator begIter = m_effectList.begin();
		TEffectList::iterator endIter = m_effectList.end();
		for (; begIter != endIter; ++begIter)
		{
			CPeriodEffect *effect = *begIter;
			if (effect == NULL || effect->update(owner, timePass))
			{
				if (effect != NULL)
				{
					//owner->onDelPeriodEft(effect);
				}
				m_effectList.erase(begIter++);
				continue;
			}
			
		}
	}
	bool CPrdEftList::addAura(CAura *aura, CCharacterEntity *src, CCharacterEntity *dst)
	{
		return _addNewEffect(aura);
	}
	bool CPrdEftList::addEot(CEot* eot, CCharacterEntity *src, CCharacterEntity *dst)
	{
		return _addNewEffect(eot);
	}
	bool CPrdEftList::delAllEffect(CCharacterEntity *owner)
	{
		TEffectList::iterator begIter = m_effectList.begin();
		TEffectList::iterator endIter = m_effectList.end();
		for (; begIter != endIter; ++begIter)
		{
			//owner->onDelPeriodEft(*m_iter);
			_delEffect(begIter);
		}
		return true;
	}

	bool CPrdEftList::resetRemainTime(BSLib::s32 mode, BSLib::s32 id)
	{
		TEffectList::iterator begIter = m_effectList.begin();
		TEffectList::iterator endIter = m_effectList.end();
		for (; begIter != endIter; ++begIter)
		{
			CPeriodEffect *effect = *begIter;
			if (effect)
			{
				if (id == 0 || id == effect->getID())
					effect->setRemainTime(mode);
			}

		}
		return true;
	}
	bool CPrdEftList::addRemainTime(BSLib::s32 miliSecs)
	{
		TEffectList::iterator begIter = m_effectList.begin();
		TEffectList::iterator endIter = m_effectList.end();
		for (; begIter != endIter; ++begIter)
		{
			CPeriodEffect *effect = *begIter;
			if (effect)
			{
				effect->addRemainTime(miliSecs);
			}
			
		}
		return true;
	}

	void CPrdEftList::begin()
	{
		m_iter = m_effectList.begin();
	}
	CPeriodEffect* CPrdEftList::next()
	{
		if (m_iter == m_effectList.end())
		{
			return NULL;
		}
		CPeriodEffect *effect = *m_iter;
		m_iter ++;
		return effect;
	}

	bool CPrdEftList::_delCurrentEffect(CCharacterEntity *owner)
	{
		if (m_iter != m_effectList.begin())
		{
			m_iter--;
		}
		//owner->onDelPeriodEft(*m_iter);
		_delEffect(m_iter);
		return true;
	}
	bool CPrdEftList::_delEffect(TEffectList::iterator &iter)
	{
		(*iter )->release();
		TEffectList::iterator iter2 = iter++;
		m_effectList.erase(iter2);
		return true;
	}
	bool CPrdEftList::_addNewEffect(CPeriodEffect *effect)
	{
		m_effectList.push_back(effect);
		return true;
	}
}