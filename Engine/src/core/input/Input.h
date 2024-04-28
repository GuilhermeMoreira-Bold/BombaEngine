#pragma once
#include<iostream>
#include<tuple>
#include <GLFW/glfw3.h>
#include "..\..\Engine.h"

namespace KongInput {
	class Input {
	public:
		bool isKeyPressed(int keyCode);
		bool isButtonPressed(int buttonCode);
		std::tuple<float, float> mouseCoordinate();
	};
}