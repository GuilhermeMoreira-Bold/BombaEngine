#include "WindowAPI.h"
#include "OpenGlWindow.h"
#include "..\..\log\Log.h"

KongWindow::Window* KongWindow::WindowAPI::window;

void KongWindow::WindowAPI::create(KongWindow::WindowContext::Context context) {
	switch (context)
	{
	case KongWindow::WindowContext::OPEN_GL_WINDOW:
		window = new OpenGlWindow();
		break;
	default:
		Log::print("Window type doesn't exists", Log::ERROR);
		break;
	}
}

void KongWindow::WindowAPI::update() {
	window->update();
}

void KongWindow::WindowAPI::shutdown() {
	window->shutdown();
}

KongWindow::Window* KongWindow::WindowAPI::getWindow() {
	return window;
}

void KongWindow::WindowAPI::swapBuffers() {
	window->swapBuffers();
}