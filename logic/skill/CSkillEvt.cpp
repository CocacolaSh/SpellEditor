#include "CSkillEvt.h"

namespace SKILLEDITOR
{
	CSkillEvt::CSkillEvt()
	{
		//
	}
	CSkillEvt::~CSkillEvt()
	{
		m_funcList.clear();
	}

	void CSkillEvt::unRegEvt(BSLib::u32 seqID)
	{
		TEvtFuncList::iterator begItr = m_funcList.begin();
		TEvtFuncList::iterator endItr = m_funcList.end();
		for (; begItr != endItr; )
		{
			TEvtFuncList::iterator oldItr = begItr++;
			if (*oldItr == seqID)
			{
				m_funcList.erase(oldItr);
			}
		}
	}

	bool CSkillEvt::fireEvt(CCharacterEntity *src, BSLib::s32 type, void *dst)
	{
		//TEvtFuncList::iterator begItr = m_funcList.begin();
		//TEvtFuncList::iterator endItr = m_funcList.end();
		//for (; begItr != endItr; ++begItr)
		//{
		//	CGlobalModifiers::getInstance()->applySeq(*begItr, src, type, dst);
		//}
		return true;
	}
}