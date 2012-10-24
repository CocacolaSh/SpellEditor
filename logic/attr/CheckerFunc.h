#ifndef __LOGIC_ATTR_CHECKERFUNC_H__
#define __LOGIC_ATTR_CHECKERFUNC_H__
#include "basedef.h"

namespace SKILLEDITOR
{
	enum ECheckerType
	{
		ECheckerType_Invalid = -1,
		ECheckerType_Equal,
		ECheckerType_UnEqual,
		ECheckerType_More,
		ECheckerType_Less,
		ECheckerType_Include,
		ECheckerType_Exclude,
		ECheckerType_Count
	};

	typedef bool (* TAttrCheckerFunc)( void *dst, BSLib::s32 type, BSLib::s32 func1, BSLib::s32 arg1, BSLib::s32 func2, BSLib::s32 arg2);
	TAttrCheckerFunc GetCheckerFunc(BSLib::s32 funcType);
}
#endif