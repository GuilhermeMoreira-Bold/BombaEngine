#pragma once

#include <iostream>
#include <tuple>
#include <string>
#include <filesystem>

#include "core/window/Window.h"




namespace SmartKong {
	class Engine {
	public:
		static void init();
		static void update();
		static KongWindow::Window* getWindow();
	private:
		 static void initializeWindow();
		 static void initializeGlew();
	};
};