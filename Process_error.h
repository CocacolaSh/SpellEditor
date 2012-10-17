#ifndef _PROCESS_ERROR_H
#define _PROCESS_ERROR_H

#include "ilogger.h"
#ifdef _DEBUG
#include <assert.h>
#endif

#pragma warning(disable:4127)
#define SAFE_FREE(__pointer__)						\
	do												\
	{												\
	if (__pointer)								\
		{											\
		free(__pointer__);						\
		(__pointer__) = NULL;					\
		}											\
	} while (false)

#define SAFE_DELETE(__pointer__)					\
	do												\
	{												\
	if (__pointer__)								\
		{											\
		delete (__pointer__);					\
		(__pointer__) = NULL;					\
		}											\
	} while (false)

#define SAFE_DELETE_ARRAY(__pointer__)				\
	do												\
	{												\
	if (__pointer)								\
		{											\
		delete [](__pointer__);					\
		(__pointer__) = NULL;					\
		}											\
	} while (false)


#ifdef _DEBUG
#define PROCESS_ERROR(__condition__)				\
	do												\
	{												\
	if (!(__condition__))						\
		{											\
		goto Exit0;								\
		}											\
	} while (false)

#define PROCESS_ERROR_RET_CODE(__condition__, __retcode__)				\
	do																		\
	{																		\
	if (!(__condition__))												\
		{																	\
		nReuslt = __retcode__;											\
		goto Exit0;														\
		}																		\
	} while (false)

#define PROCESS_SUCCESS(__condition__)		\
	do											\
	{											\
	if ((__condition__))					\
		{										\
		goto Exit1;							\
		}										\
	} while (false)

#define LOG_PROCESS_ERROR(__condition__)										\
	do																			\
	{																			\
	if (!(__condition__))													\
		{																		\
		g_printLog(BSLib::ELOG_LEVEL_ERROR, "LOG_PROCESS_ERROR(%s) %s %s:%d",				\
#__condition__, __FUNCTION__, __FILE__, __LINE__);				\
	goto Exit0;															\
		}																		\
	} while (false)
#define LOG_CHECK_ERROR(__condition__)											\
	do																			\
	{																			\
	if (!(__condition__))													\
		{																		\
		g_printLog(BSLib::ELOG_LEVEL_ERROR, "LOG_CHECK_ERROR(%s) %s %s:%d",				\
#__condition__, __FUNCTION__, __FILE__, __LINE__);				\
	goto Exit0;															\
		}																		\
	} while (false)

#define LOG_PROCESS_ERROR_RET_CODE(__condition__, __retcode__)					\
	do																			\
	{																			\
	if (!(__condition__))													\
		{																		\
		nResult = __retcode__;												\
		g_printLog(BSLib::ELOG_LEVEL_ERROR, "LOG_PROCESS_ERROR_RET_CODE(%s) %s %s:%d",	\
#__condition__, __FUNCTION__, __FILE__, __LINE__);				\
	goto Exit0;															\
		}																		\
	} while (false)

#else //_debug

#define PROCESS_ERROR(__condition__)

#define PROCESS_ERROR_RET_CODE(__condition__, __retcode__)

#define PROCESS_SUCCESS(__condition__)

#define LOG_PROCESS_ERROR(__condition__)
#define LOG_CHECK_ERROR(__condition__)										

#define LOG_PROCESS_ERROR_RET_CODE(__condition__, __retcode__)	

#endif
#endif