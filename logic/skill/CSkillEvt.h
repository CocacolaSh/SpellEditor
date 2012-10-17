#ifndef __LOGIC_SKILL_SKILLEVT_H__
#define __LOGIC_SKILL_SKILLEVT_H__
#include "basedef.h"
#include <list>
namespace SKILLEDITOR
{
	class CCharacterEntity;
	class CSkillEvt
	{
	public:
		CSkillEvt();
		~CSkillEvt();

		inline void regEvt(BSLib::u32 seqID);

		void unRegEvt(BSLib::u32 seqID);

		bool fireEvt(CCharacterEntity *src, BSLib::s32 type, void *dst);
	private:
		typedef std::list<BSLib::u32> TEvtFuncList;
		TEvtFuncList m_funcList;
	};

	inline void CSkillEvt::regEvt(BSLib::u32 seqID)
	{
		m_funcList.push_back(seqID);
	}
}

#endif