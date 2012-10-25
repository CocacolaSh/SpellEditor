#ifndef __SPELL_EDITOR_ILOGGER_H__
#define __SPELL_EDITOR_ILOGGER_H__

#include "RefrenceCount.h"
namespace BSLib
{
	enum ELogLevel
	{
		ELOG_LEVEL_INFORMATION = 0,
		ELOG_LEVEL_WARNING,
		ELOG_LEVEL_ERROR,
		ELOG_LEVEL_NONE
	};

	void g_printLog(ELogLevel logLevel, c8 *format, c8* condition, c8* func, c8* file, BSLib::u32 line);
	class ILogger : public IReferenceCounted
	{
	public:
		virtual ~ILogger(){;}
		virtual ELogLevel getLogLevel() = 0;
		virtual void setLogLevel(ELogLevel ) = 0;

		virtual void log(const c8* text, ELogLevel) = 0;
		virtual void log(const c8* text, const c8* hits, ELogLevel) = 0;
		virtual void log(const c8* text, const wchar_t* hint, ELogLevel logLevel=ELOG_LEVEL_INFORMATION) = 0;
		virtual void log(const wchar_t* text, const wchar_t* hint, ELogLevel logLevel=ELOG_LEVEL_INFORMATION) = 0;

		virtual void log(const wchar_t* text, ELogLevel logLevel=ELOG_LEVEL_INFORMATION) = 0;
	};

	
}
#endif