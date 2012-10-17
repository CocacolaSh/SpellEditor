#ifndef __LOGIC_ATTR_ATTRFUNC_H__
#define __LOGIC_ATTR_ATTRFUNC_H__
#include "basedef.h"
namespace SKILLEDITOR
{
	class IFighter;
	typedef BSLib::s32 (* TGetAttr)(void* ,BSLib::s32);
	TGetAttr GetAttrFunc(BSLib::s32 funcType, BSLib::s32 key);

	bool GetEumAttrTypeAndIndex(BSLib::s32 inIndex, BSLib::s32 &type, BSLib::s32 &index);
}

#endif