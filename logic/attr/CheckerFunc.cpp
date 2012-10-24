#include "CheckerFunc.h"
#include "attrFunc.h"
#include "Process_error.h"
namespace SKILLEDITOR
{
	inline bool FeatchAttr( void *dst, BSLib::s32 type, BSLib::s32 funcid, BSLib::s32 arg, BSLib::s32 &res)
	{
		if (funcid > 0)
		{
			TGetAttr get_attr = GetAttrFunc(type, funcid);
			LOG_PROCESS_ERROR(get_attr);

			res = get_attr(dst, arg);
			return true;
		}
		else if (funcid == 0)
		{
			res = arg;
			return true;
		}
Exit0:
		return false;
	}

	bool AttrChecker_Equal( void *dst, BSLib::s32 type, BSLib::s32 func1, BSLib::s32 arg1, BSLib::s32 func2, BSLib::s32 arg2)
	{
		BSLib::s32 first, second;
		bool bRet = true;

		bRet = FeatchAttr(dst, type, func1, arg1, first);
		LOG_PROCESS_ERROR(bRet);

		bRet = FeatchAttr(dst, type, func2, arg2, second);
		LOG_PROCESS_ERROR(bRet);

		return first == second;
Exit0:
		return false;
	}
	bool AttrChecker_UnEqual( void *dst, BSLib::s32 type, BSLib::s32 func1, BSLib::s32 arg1, BSLib::s32 func2, BSLib::s32 arg2)
	{
		BSLib::s32 first, second;
		bool bRet = true;

		bRet = FeatchAttr(dst, type, func1, arg1, first);
		LOG_PROCESS_ERROR(bRet);

		bRet = FeatchAttr(dst, type, func2, arg2, second);
		LOG_PROCESS_ERROR(bRet);

		return first != second;
Exit0:
		return false;
	}
	bool AttrChecker_More( void *dst, BSLib::s32 type, BSLib::s32 func1, BSLib::s32 arg1, BSLib::s32 func2, BSLib::s32 arg2)
	{
		BSLib::s32 first, second;
		bool bRet = true;

		bRet = FeatchAttr(dst, type, func1, arg1, first);
		LOG_PROCESS_ERROR(bRet);

		bRet = FeatchAttr(dst, type, func2, arg2, second);
		LOG_PROCESS_ERROR(bRet);

		return first > second;
Exit0:
		return false;
	}
	bool AttrChecker_Less( void *dst, BSLib::s32 type, BSLib::s32 func1, BSLib::s32 arg1, BSLib::s32 func2, BSLib::s32 arg2)
	{
		BSLib::s32 first, second;
		bool bRet = true;

		bRet = FeatchAttr(dst, type, func1, arg1, first);
		LOG_PROCESS_ERROR(bRet);

		bRet = FeatchAttr(dst, type, func2, arg2, second);
		LOG_PROCESS_ERROR(bRet);

		return first < second;
Exit0:
		return false;
	}
	bool AttrChecker_Include( void *dst, BSLib::s32 type, BSLib::s32 func1, BSLib::s32 arg1, BSLib::s32 func2, BSLib::s32 arg2)
	{
		BSLib::s32 first, second;
		bool bRet = true;

		bRet = FeatchAttr(dst, type, func1, arg1, first);
		LOG_PROCESS_ERROR(bRet);

		bRet = FeatchAttr(dst, type, func2, arg2, second);
		LOG_PROCESS_ERROR(bRet);

		return (first & second) != 0;
Exit0:
		return false;
	}
	bool AttrChecker_Exclude( void *dst, BSLib::s32 type, BSLib::s32 func1, BSLib::s32 arg1, BSLib::s32 func2, BSLib::s32 arg2)
	{
		BSLib::s32 first, second;
		bool bRet = true;

		bRet = FeatchAttr(dst, type, func1, arg1, first);
		LOG_PROCESS_ERROR(bRet);

		bRet = FeatchAttr(dst, type, func2, arg2, second);
		LOG_PROCESS_ERROR(bRet);

		return (first & second) == 0;
Exit0:
		return false;
	}
	TAttrCheckerFunc AttrCheckerFuncs[ECheckerType_Count] = 
	{
		//
		AttrChecker_Equal,
		AttrChecker_UnEqual,
		AttrChecker_More,
		AttrChecker_Less,
		AttrChecker_Include,
		AttrChecker_Exclude,
	};

	TAttrCheckerFunc GetCheckerFunc(BSLib::s32 funcType)
	{
		LOG_PROCESS_ERROR(funcType > ECheckerType_Invalid && funcType < ECheckerType_Count);

		return AttrCheckerFuncs[funcType];
Exit0:
		return NULL;
	}
}