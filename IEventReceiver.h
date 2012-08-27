#ifndef __BSLIB_IEVENTRECEIVER_H__
#define __BSLIB_IEVENTRECEIVER_H__

namespace BSLib
{
	enum EEventType
	{
		EEVENT_TYPE_LOG = 0,
	};
	typedef struct _SEvent
	{

		typedef struct _SLogEvent
		{
			const c8*	logText;
			ELogLevel	logLevel;
		}SLogEvent;

		EEventType	eventType;
		union 
		{
			SLogEvent	logEvent;
		};
	}SEvent;

	class IEventReceiver
	{
	public:
		virtual ~IEventReceiver(){}
		virtual bool onEvent(const SEvent& event) = 0;
	};
}
#endif