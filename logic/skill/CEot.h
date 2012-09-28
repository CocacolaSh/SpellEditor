#ifndef __LOGIC_SKILL_CEOT_H__
#define __LOGIC_SKILL_CEOT_H__
#include "CPeriodEffect.h"
#include "eot_template.h"
namespace SKILLEDITOR
{
	class CEot: public CPeriodEffect
	{
	public:
		CEot();
		virtual ~CEot();

		virtual BSLib::s32	getID();
		virtual BSLib::s32	getLevel();
		virtual EPeriodEffectType	getType();
		virtual EPeriodEffectNature	getNature();
		virtual bool update(CCharacterEntity *owner, float timePass);
		virtual CPeriodEffect *clone();
		virtual bool addToList(CPrdEftList * list, CCharacterEntity *src, CCharacterEntity * dst);
		virtual void onAppend(CCharacterEntity *src, CCharacterEntity *dst);
		virtual void onRemove(CCharacterEntity *dst);

	private:
		EotTemplate *m_eotTemplate;
		float m_curInterval;
	};
}
#endif