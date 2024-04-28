#include "EventAPI.h"
#include "../../log/Log.h"

void KongEvents::EventAPI::dispatchEvent(IEvent& event) {
	dispatcher->dispatchEvent(event);
};

void KongEvents::EventAPI::unsubscribeListener(IEvent& event,IListener& listener) {
	dispatcher->unsubscribeListener(event,listener);
};

void KongEvents::EventAPI::subscribeListener(IEvent& event, IListener& listener) {
	dispatcher->subscribeListener(event, listener);
}