#include "Input.h"


bool KongInput::Input::isKeyPressed(int keyCode) {
	auto window = static_cast<GLFWwindow*> (SmartKong::Engine::getWindow()->getNativeWindow());

	auto state = glfwGetKey(window, keyCode);

	return state == GLFW_PRESS || state == GLFW_REPEAT;
};

bool KongInput::Input::isButtonPressed(int buttonCode) {
	auto window = static_cast<GLFWwindow*> (SmartKong::Engine::getWindow()->getNativeWindow());

	auto state = glfwGetMouseButton(window, buttonCode);

	return state == GLFW_PRESS || state == GLFW_REPEAT;
};

std::tuple<float, float> KongInput::Input::mouseCoordinate() {
	auto window = static_cast<GLFWwindow*> (SmartKong::Engine::getWindow()->getNativeWindow());

	double x, y;
	glfwGetCursorPos(window, &x, &y);

	return { static_cast<float>(x),static_cast<float>(y) };
};