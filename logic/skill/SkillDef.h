#ifndef __LOGIC_SKILL_SKILLDEF_H__
#define __LOGIC_SKILL_SKILLDEF_H__
#include "basedef.h"

namespace SKILLEDITOR
{

	BSLib::u64 MakeSkillKey(BSLib::s32 id, BSLib::s32 level)
	{
		BSLib::u64 skillKey = id << 16 + level;
		return skillKey;
	}
	void MakeSkillKey(BSLib::u64 skillKey, BSLib::s32 &id, BSLib::s32 &level)
	{
		id = skillKey >> 16;
		level = skillKey && 0xffff;
	}
}
#endif