#pragma once
#include "Window.h"
#include "WindowContext.h"

namespace KongWindow {
	class WindowAPI {
	private:
		static Window* window;
	public:
		static void create(WindowContext::Context context);
		static void update();
		static void shutdown();
		static void swapBuffers();
		static Window* getWindow();
	};
}