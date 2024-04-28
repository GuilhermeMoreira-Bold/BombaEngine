#include "EventDispatcher.h"
#include <map>


std::multimap<KongEvents::IEvent*, KongEvents::IListener*> KongEvents::EventDispatcher::listeners;

void KongEvents::EventDispatcher::dispatchEvent(IEvent &event) {
	for (const auto& eventTwin : listeners) {
		if (eventTwin.first == &event) {
			eventTwin.second->onEvent(event);
		}
	}
}

void KongEvents::EventDispatcher::subscribeListener(IEvent &event,IListener& listener) {
	std::pair<IEvent*, IListener*> eventListenerPair(&event, &listener);
	listeners.insert(eventListenerPair);
}

void KongEvents::EventDispatcher::unsubscribeListener(IEvent& event,IListener& listener) {
	auto range = listeners.equal_range(&event);

	for (auto it = range.first; it != range.second; ++it) {
		if (it->second == &listener) {
			listeners.erase(it);
			return;
		}
	}
}