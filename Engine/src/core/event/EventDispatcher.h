#pragma once
#include <map>
#include "IEvent.h"
#include "IListener.h"

namespace KongEvents {
	class EventDispatcher {
		private:
		static	std::multimap<IEvent*,IListener*> listeners;
		public:
		 static	void dispatchEvent(IEvent &event);
		 static	void subscribeListener(IEvent &event, IListener &listener);
		 static void unsubscribeListener(IEvent& event, IListener& listner);
	};
}