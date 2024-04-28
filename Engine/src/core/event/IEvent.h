#pragma once
#include <string>

namespace KongEvents {
	class IEvent {
	public:
		 virtual void trigger() = 0;
	};
}