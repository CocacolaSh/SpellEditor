#ifndef __SPELL_EDITOR_OS_H__
#define __SPELL_EDITOR_OS_H__
#include "ILogger.h"

using namespace BSLib;

namespace OS
{
	class CPrinter
	{
	public:
		static void log(const c8* text, ELogLevel);
		static void log(const c8* text, const c8* hits, ELogLevel);
		static void log(const c8* text, const wchar_t* hint, ELogLevel logLevel=ELOG_LEVEL_INFORMATION);
		static void log(const wchar_t* text, const wchar_t* hint, ELogLevel logLevel=ELOG_LEVEL_INFORMATION);

		static void log(const wchar_t* text, ELogLevel logLevel=ELOG_LEVEL_INFORMATION);

		static ILogger* loger;
	};
}
#endif