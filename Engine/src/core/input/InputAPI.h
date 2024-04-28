#pragma once

#include <tuple>
#include <iostream>
#include "Input.h"
#include "KeyCode.h"



namespace KongInput {
	class InputAPI {
		private:
			 static Input * input;
		public:
			static bool isButtonPressed(int buttonCode);
			static bool isKeyPressed(int keyCode);
			static std::tuple<float, float> getMousePosition();
	};
}