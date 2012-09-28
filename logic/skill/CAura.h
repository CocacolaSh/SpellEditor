#ifndef __LOGIC_SKILL_CAURA_H__
#define __LOGIC_SKILL_CAURA_H__
#include "CPeriodEffect.h"
namespace SKILLEDITOR
{
	class CAura: public CPeriodEffect
	{
	public:
		CAura();
		virtual ~CAura();

		virtual BSLib::s32	getID();
		virtual BSLib::s32	getLevel();
		virtual EPeriodEffectType	getType(){return EPERIOD_EFFECT_TYPE_AURA;}
		virtual EPeriodEffectNature	getNature();
		virtual bool update(CCharacterEntity *owner, float timePass);
		BSLib::s32 getEffectGroup();
		virtual CPeriodEffect *clone();
		virtual bool addToList(CPrdEftList * list, CCharacterEntity *src, CCharacterEntity * dst);
		virtual void onAppend(CCharacterEntity *src, CCharacterEntity *dst);
		virtual void onRemove(CCharacterEntity *dst);

		void setupTemplate(AuraTemplate* t);
		void setupDuration(BSLib::s32 d);
		void modifyMe();
		void copyTemplate(AuraTemplate *t);
		AuraTemplate *getInfo(){return m_auraTemplate;}
	private:
		AuraTemplate *	m_auraTemplate;
		BSLib::s32      m_powerAdded;
	};
	CAura *GCreateAuraInstance(AuraTemplate *t, CCharacterEntity *src);
}
#endif