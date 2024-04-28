#pragma once
#include "Window.h"
#include "GLFW/glfw3.h"

namespace KongWindow{
	class OpenGlWindow :public Window {
	private:
		GLFWwindow* window;
		void init() override;
		void cleanup() override;
		void viewPort();
	public:
		OpenGlWindow();
		void update() override;
		void shutdown() override;
		void getWindowSize();
		void* getNativeWindow()const override;
		void swapBuffers() override;
		void onEvent(KongEvents::IEvent& event) override;

	};
}