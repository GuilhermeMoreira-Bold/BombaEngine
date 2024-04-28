#pragma once
#include "..\event\IListener.h"
#include "..\event\IEvent.h"

namespace KongWindow{
	class Window :public KongEvents::IListener {
	protected:
		int width, height;
	private:
		virtual void init() = 0;
		virtual void cleanup() = 0;
	public:
	
		virtual void update() = 0;
		virtual void shutdown() = 0;
		virtual void* getNativeWindow()const = 0;
		virtual void swapBuffers() = 0;
		virtual void onEvent(KongEvents::IEvent &event) = 0;
	};
}