#ifndef __LOGIC_ATTR_MODIFIERFUNC_H__
#define __LOGIC_ATTR_MODIFIERFUNC_H__
#include "basedef.h"

namespace SKILLEDITOR
{
	class CCharacterEntity;

	typedef bool (* TAttrModifierFunc)(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3);
	TAttrModifierFunc GetModifierFunc(BSLib::s32 funcType, BSLib::s32 key);
}
#endif