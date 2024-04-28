#include "InputAPI.h"

KongInput::Input* KongInput::InputAPI::input;

bool KongInput::InputAPI::isKeyPressed(int keyCode) {
	 return input->isKeyPressed(keyCode); 
}

bool KongInput::InputAPI::isButtonPressed(int buttonCode) {
	return input->isButtonPressed(buttonCode);
}

std::tuple<float, float> KongInput::InputAPI::getMousePosition() {
	return input->mouseCoordinate();
}