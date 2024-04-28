#pragma once
#include "IEvent.h"
#include <string>
#include <functional>

namespace KongEvents{
	template <typename ...Args>
	class Event : public IEvent {
	public:
		using callback = std::function<void(Args...)>;

		explicit Event(const callback& callback) : callbackFunction(callback) {};

		void trigger(Args... args) override { callbackFunction(args...); };

	private:
		const callback  callbackFunction;
	};
}