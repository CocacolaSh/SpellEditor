#ifndef __BSLIB_CLOGGER_H__
#define __BSLIB_CLOGGER_H__
#include "ILogger.h"
#include "IEventReceiver.h"

namespace BSLib
{
	class CLogger : public ILogger
	{
	public:
		CLogger(IEventReceiver *receiver);
		virtual ~CLogger();

		virtual ELogLevel getLogLevel() const
		{
			return m_logLevel;
		}

		virtual void setLogLevel(ELogLevel logLevel)
		{
			m_logLevel = logLevel;
		}

		virtual void log(const c8* text, ELogLevel logLevel);
		virtual void log(const c8* text, const c8* hits, ELogLevel logLevel) = 0;
		virtual void log(const c8* text, const wchar_t* hint, ELogLevel logLevel=ELOG_LEVEL_INFORMATION) = 0;
		virtual void log(const wchar_t* text, const wchar_t* hint, ELogLevel logLevel=ELOG_LEVEL_INFORMATION) = 0;

		virtual void log(const wchar_t* text, ELogLevel logLevel=ELOG_LEVEL_INFORMATION) = 0;

		void setReceiver(IEventReceiver *receiver);
	private:
		ELogLevel			m_logLevel;
		IEventReceiver*		m_receiver;
	};
}
#endif