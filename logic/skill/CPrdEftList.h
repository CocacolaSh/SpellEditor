#ifndef __LOGIC_SKILL_CPRDEFTLIST_H__
#define __LOGIC_SKILL_CPRDEFTLIST_H__
#include <list>
#include "basedef.h"
#include "CPeriodEffect.h"

namespace SKILLEDITOR
{
	class CCharacterEntity;
	class CAura;
	class CEot;

	class CPrdEftList
	{
		typedef std::list<CPeriodEffect *> TEffectList;
	public:
		CPrdEftList();
		virtual ~CPrdEftList();

		void update(CCharacterEntity *owner, float timePass);
		bool addAura(CAura *aura, CCharacterEntity *src, CCharacterEntity *dst);
		bool addEot(CEot* eot, CCharacterEntity *src, CCharacterEntity *dst);
		bool delAllEffect(CCharacterEntity *owner);

		BSLib::s32 getEffectCnt(){return m_effectList.size();}

		bool resetRemainTime(BSLib::s32 mode, BSLib::s32 id = 0);
		bool addRemainTime(BSLib::s32 miliSecs);

		void begin();
		CPeriodEffect* next();

	protected:
		bool _delCurrentEffect(CCharacterEntity *owner);
		bool _delEffect(TEffectList::iterator &iter);
		bool _addNewEffect(CPeriodEffect *effect);
	private:
		TEffectList	m_effectList;
		TEffectList::iterator m_iter;
	};
}
#endif