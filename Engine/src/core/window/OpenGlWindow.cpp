#include "OpenGlWindow.h"
#include "..\..\log\Log.h"
#include <string>
#include <iostream>

void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);

KongWindow::OpenGlWindow::OpenGlWindow() {
	init();
	getWindowSize();
}

void KongWindow::OpenGlWindow::init(){
	if (!glfwInit()){

	}
	window = glfwCreateWindow(1600,900,"Void Vortex",NULL,NULL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwMakeContextCurrent(window);
	viewPort();
}

void frameBufferSizeCallBack(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void KongWindow::OpenGlWindow::viewPort() {
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
}

void KongWindow::OpenGlWindow::update() {
	cleanup();
}

void KongWindow::OpenGlWindow::cleanup() {
	glClearColor(0.5f, 0.5f, 0.5f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void KongWindow::OpenGlWindow::shutdown() {
	glfwTerminate();
	glfwDestroyWindow(window);
}

void KongWindow::OpenGlWindow::getWindowSize() {
	glfwGetWindowSize(window, &width, &height);
	std::string info = "Window size w:" + std::to_string(width) + "h:" + std::to_string(height);
	Log::print(info, Log::INFO);
}

//generic pointer to get the GLFWwindow
void* KongWindow::OpenGlWindow::getNativeWindow()const {
	return window;
}

void KongWindow::OpenGlWindow::onEvent(KongEvents::IEvent &event) {
	event.trigger();
}

void KongWindow::OpenGlWindow::swapBuffers() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}