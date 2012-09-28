#ifndef __LOGIC_SKILL_AURADEF_H__
#define __LOGIC_SKILL_AURADEF_H__
#include "basedef.h"
#include "PeriodEffect_def.h"
namespace SKILLEDITOR
{
	enum EAuraType
	{
		EAURA_TYPE_INVALID = -1,
		EAURA_TYPE_PHYCTL,
		EAURA_TYPE_MAGCTL,
		EAURA_TYPE_NORMALLOSE,
		EAURA_TYPE_BADLYLOSE,
	};
	class AuraEntry : public CPeriodEffectEntry
	{
	public:
		AuraEntry();
		virtual ~AuraEntry();

		virtual BSLib::s32 getID();
		virtual BSLib::s32 getLevel();
		virtual bool isGood();
		virtual bool isUndispeled();

		void reset();
	public:
		BSLib::s32	m_id;
		BSLib::s32	m_level;
		BSLib::s32	m_isGood;
		BSLib::s32	m_isUnDispeled;
		BSLib::s32	m_isDisapearAfterDead;
		BSLib::s32	m_groupID;
		BSLib::s32	m_subGroupID;
		BSLib::s32	m_targetAttrID;
		BSLib::s32	m_targetAttrType;
		BSLib::s32	m_powerOfAura;
		BSLib::s32	m_powerUpperLimit;
		BSLib::s32	m_fixTime;
		BSLib::s32	m_maxTime;
	};

#define AURA_NAME_LEN 32
#define AURA_DESC_LEN 128
#define AURA_FXNAME_LEN 128
	struct AuraEntryEx
	{

		char m_name[AURA_NAME_LEN];
		char m_desc[AURA_DESC_LEN];
		char m_fxName[AURA_FXNAME_LEN];

		BSLib::s32 m_id;
		BSLib::s32 m_level;
		BSLib::s32 m_isHot;
	};
}
#endif