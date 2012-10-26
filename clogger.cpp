#include "clogger.h"
#include "colaString.h"
#include <locale>
#include <sstream>

using namespace std;

namespace BSLib
{
	BSLib::stringc ToNarrow( const wchar_t *s, char dfault = '?', 
		const std::locale& loc = std::locale() )
	{
		std::ostringstream stm;

		while( *s != L'\0' ) {
			stm << std::use_facet< std::ctype<wchar_t> >( loc ).narrow( *s++, dfault );
		}
		return BSLib::stringc(stm.str().c_str());
	}

	
	CLogger::CLogger(IEventReceiver* receiver)
		:m_receiver(receiver), m_logLevel(ELOG_LEVEL_INFORMATION)
	{
#ifdef _DEBUG
		setDebugName("CLogger");
#endif
	}

	CLogger::~CLogger()
	{
		//
	}
	void CLogger::log(const c8* text, ELogLevel logLevel)
	{
		if (logLevel < m_logLevel)
		{
			return;
		}

		if (m_receiver)
		{
			SEvent event;
			event.eventType = EEVENT_TYPE_LOG;
			event.logEvent.logText = text;
			event.logEvent.logLevel = logLevel;

			m_receiver->onEvent(event);
		}
	}

	void CLogger::log(const c8* text, const c8* hits, ELogLevel logLevel)
	{
		if (logLevel < m_logLevel)
		{
			return;
		}

		BSLib::stringc logText(text);
		logText += ":";
		logText += hits;

		return log(logText.c_str(), logLevel);
	}
	void CLogger::log(const c8* text, const wchar_t* hint, ELogLevel logLevel)
	{
		if (logLevel < m_logLevel)
		{
			return;
		}

		BSLib::stringc logText(text);
		BSLib::stringc logHint = ToNarrow(hint);
		return log(logText.c_str(), logHint.c_str(), logLevel);
	}
	void CLogger::log(const wchar_t* text, const wchar_t* hint, ELogLevel logLevel)
	{
		if (logLevel < m_logLevel)
		{
			return;
		}

		BSLib::stringc logText = ToNarrow(text);
		BSLib::stringc logHint = ToNarrow(hint);
		return log(logText.c_str(), logHint.c_str(), logLevel);
	}

	void CLogger::log(const wchar_t* text, ELogLevel logLevel)
	{
		if (logLevel < m_logLevel)
		{
			return;
		}

		BSLib::stringc logText = ToNarrow(text);
		return log(logText.c_str(), logLevel);
	}

	void CLogger::setReceiver(IEventReceiver *receiver)
	{
		m_receiver = receiver;
	}
}