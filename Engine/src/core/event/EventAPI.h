#pragma once
#include "Event.h"
#include "IListener.h"
#include "EventDispatcher.h"
#include <string>

namespace KongEvents {
	class EventAPI {
	private:
		static EventDispatcher* dispatcher;
	public:
		static void dispatchEvent(IEvent& event);
		static void subscribeListener(IEvent& event, IListener& listener);
		static void unsubscribeListener(IEvent& event,IListener& listener);
	};
};