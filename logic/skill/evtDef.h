#ifndef __LOGIC_SKILL_EVTDEF_H__
#define __LOGIC_SKILL_EVTDEF_H__
#include "basedef.h"
namespace SKILLEDITOR
{
#define MAX_SEQ 8
	enum EModifierOnAuraApplyTime
	{
		EModifyAuraTime_Invalid = -1,
		EModifyAuraTime_OnAppend,
		EModifyAuraTime_OnTrigger,
		EModifyAuraTime_OnRemove,
		EModifyAuraTime_Count
	};
	enum EModifierOnEotApplyTime
	{
		EModifyEotTime_Invalid = -1,
		EModifyEotTime_OnAppend,
		EModifyEotTime_OnTrigger,
		EModifyEotTime_OnRemove,
		EModifyEotTime_Count,
	};
	enum EAttrModifierType
	{
		EAttrModifyType_Invalid = -1,
		EAttrModifyType_Char,
		EAttrModifyType_Skill,
		EAttrModifyType_Bullet,
		EAttrModifyType_Aura,
		EAttrModifyType_Eot,
		EAttrModifyType_Count
	};

	inline void SplitSeqKey(BSLib::s32 key, BSLib::s32 &type, BSLib::s32 &idx)
	{
		type = (key & 0x0f000000) >> 24;
		idx = key & 0x00ffffff;
	}
	inline void SplitFunctionKey(BSLib::s32 key, BSLib::s32 &type, BSLib::s32 &idx)
	{
		type = (key & 0x00ff0000) >> 16;
		idx = key & 0x0000ffff;
	}
	
}
#endif