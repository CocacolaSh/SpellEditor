#ifndef __LOGIC_SKILL_EOTDEF_H__
#define __LOGIC_SKILL_EOTDEF_H__
#include "basedef.h"
#include "PeriodEffect_def.h"
namespace SKILLEDITOR
{
	class EotEntry : public CPeriodEffectEntry
	{
	public:
		EotEntry();
		virtual ~EotEntry();

		virtual BSLib::s32 getID();
		virtual BSLib::s32 getLevel();
		virtual bool isGood();
		virtual bool isUndispeled();

		void reset();
	public:
		BSLib::s32	m_id;
		BSLib::s32	m_level;
		BSLib::s32	m_isHot;
		BSLib::s32	m_jumpTime;
		BSLib::s32	m_jumpNumber;
		BSLib::s32	m_jumpMaxTime;
		BSLib::s32	m_jumpPower;
		BSLib::s32	m_targetAttrID;
	};

#define EOT_NAME_LEN 32
#define EOT_DESC_LEN 128
#define EOT_FXNAME_LEN 128
	struct EotEntryEx
	{

		char m_name[EOT_NAME_LEN];
		char m_desc[EOT_DESC_LEN];
		char m_fxName[EOT_FXNAME_LEN];

		BSLib::s32 m_id;
		BSLib::s32 m_level;
		BSLib::s32 m_isHot;
	};
}
#endif