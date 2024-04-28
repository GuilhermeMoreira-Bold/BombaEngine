#pragma once
#include "IEvent.h"
namespace KongEvents {
	class IListener {
	public:
		virtual void onEvent(IEvent &event) = 0;
	};
}