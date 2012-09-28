#ifndef __LOGIC_SKILL_CPERIODEFFECT_H__
#define __LOGIC_SKILL_CPERIODEFFECT_H__

#include "basedef.h"

namespace SKILLEDITOR
{
	enum EPeriodEffectType
	{
		EPERIOD_EFFECT_TYPE_INVALID = -1,
		EPERIOD_EFFECT_TYPE_AURA,
		EPERIOD_EFFECT_TYPE_EOT,
		EPERIOD_EFFECT_TYPE_COUNT
	};

	enum EPeriodEffectNature
	{
		EPERIOD_EFFECT_NATURE_INVALID = -1,
		EPERIOD_EFFECT_NATURE_NEGATIVE,
		EPERIOD_EFFECT_NATURE_POSITIVE,
		EPERIOD_EFFECT_NATURE_COUNT
	};

	class CCharacterEntity;
	class CPrdEftList;

	class CPeriodEffect
	{
	public:
		CPeriodEffect(){}
		virtual ~CPeriodEffect(){}

		virtual void release(){delete this;}

		virtual BSLib::s32	getID() = 0;
		virtual BSLib::s32	getLevel() = 0;
		virtual EPeriodEffectType	getType() = 0;
		virtual EPeriodEffectNature	getNature() = 0;
		virtual bool update(CCharacterEntity *owner, float timePass) = 0;
		virtual CPeriodEffect *clone() = 0;
		virtual bool addToList(CPrdEftList * list, CCharacterEntity *src, CCharacterEntity * dst);
		virtual void onAppend(CCharacterEntity *src, CCharacterEntity *dst);
		virtual void onRemove(CCharacterEntity *dst);
		BSLib::u64 getSrcObjID(){return m_srcObjID;}
		void setSrcObjID(BSLib::u64 value) {m_srcObjID = value;}
		BSLib::f32 getRemainTime(){return m_leftTime;}
		void setRemainTime(BSLib::s32 mode){m_leftTime = ((mode == 0 )? 0 : m_timeTemplateSpan);}
		void addRemainTime(BSLib::s32 iMiliSecs){m_leftTime += iMiliSecs / 1000.f;}
	protected:
		BSLib::u64		m_srcObjID;//source fighter id
		BSLib::f32		m_leftTime;//remain time span
		BSLib::f32		m_timeTemplateSpan;//template time span
	};
}
#endif
