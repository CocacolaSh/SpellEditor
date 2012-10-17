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
		virtual float getJumpInterval(){return m_template ? m_template->m_data.m_jumpTime / 1000.f : 0.f;}
		virtual bool update(CCharacterEntity *owner, float timePass);
		virtual CPeriodEffect *clone();
		virtual bool addToList(CPrdEftList * list, CCharacterEntity *src, CCharacterEntity * dst);
		virtual void onAppend(CCharacterEntity *src, CCharacterEntity *dst);
		virtual void onRemove(CCharacterEntity *dst);

		void setupTemplate(EotTemplate* t);
		void modifyMe();
		void copyTemplate(EotTemplate *t);
		EotTemplate * getInfo(){return m_template;}

	private:
		EotTemplate *m_template;
		float m_curInterval;
	};
	CEot *CreateEotInstance(EotTemplate *t, CCharacterEntity * src);
}
#endif