#include "os.h"
#include <stdio.h>

namespace BSLib
{
	void g_printLog(ELogLevel logLevel, c8 *format, c8* condition, c8* func, c8* file, BSLib::u32 line)
	{
		char buffer[1024] = {0};
		sprintf_s(buffer, sizeof(buffer) - 1, format, condition, func, file, line);
		OS::CPrinter::log(buffer, logLevel);
	}
}
namespace OS
{
	ILogger* CPrinter::loger = 0;

	void CPrinter::log(const c8* text, ELogLevel logLevel)
	{
		if (loger)
		{
			return loger->log(text, logLevel);
		}
	}
	void CPrinter::log(const c8* text, const c8* hits, ELogLevel logLevel)
	{
		if (loger)
		{
			return loger->log(text, hits, logLevel);
		}
	}
	void CPrinter::log(const c8* text, const wchar_t* hint, ELogLevel logLevel)
	{
		if (loger)
		{
			return loger->log(text, hint, logLevel);
		}
	}
	void CPrinter::log(const wchar_t* text, const wchar_t* hint, ELogLevel logLevel)
	{
		if (loger)
		{
			return loger->log(text, hint, logLevel);
		}
	}

	void CPrinter::log(const wchar_t* text, ELogLevel logLevel)
	{
		if (loger)
		{
			return loger->log(text, logLevel);
		}
	}

	
}