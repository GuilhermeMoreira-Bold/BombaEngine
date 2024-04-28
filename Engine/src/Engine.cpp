#include "Engine.h"

#include <GL/glew.h>

#include <GLFW/glfw3.h>


#include "core/window/WindowAPI.h"


#include "log/log.h"
#include "core/event/EventAPI.h"
#include "core/event/Event.h"

#include "core/utils/loader/LoadAPI.h"
#include "core/renderer/RenderAPI.h"
#include "core/ecs/GameObject.h"


void event() {
	Log::print("FUNCIONEIII", Log::INFO);
}


std::vector<unsigned int> indices = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

std::vector<float> vertices = {
	0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};

void SmartKong::Engine::init() {
	initializeWindow();
	initializeGlew();

	KongGraphics::RenderAPI::init(KongLoad::LoadAPI::loadShader("vertexShader.vs", "fragment.fs"));
	KongEcs::GameObject triangle;
	triangle.addComponent(KongLoad::LoadAPI::loadGraphic(KongLoad::LoadAPI::loadMesh(vertices, indices)));
	//triangle.addComponent(new KongEcs::Input(triangle.getTransform()));
	KongGraphics::RenderAPI::addGameObject(triangle);
}

void SmartKong::Engine::initializeGlew() {
	Log::print("Initalizing Glew", Log::INFO);
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		Log::print("GLEW error:" + reinterpret_cast<const char>(glewGetErrorString(err)), Log::ERROR);
	}
	else {
		Log::print("Glew initialized succefully", Log::INFO);
	}

}

void SmartKong::Engine::initializeWindow() {
	#ifdef _DEBUG
		Log::print("Initalizing window", Log::INFO);
	#endif		
		KongWindow::WindowAPI::create(KongWindow::WindowContext::OPEN_GL_WINDOW);
}

void SmartKong::Engine::update() {
	bool canClose = false;
	KongEvents::Event<> windowEvent(event);
	KongEvents::EventAPI::subscribeListener(windowEvent, *getWindow());
	

	while (!canClose) {
		KongWindow::WindowAPI::update();
		KongGraphics::RenderAPI::update();
		KongWindow::WindowAPI::swapBuffers();
	}
}

KongWindow::Window* SmartKong::Engine::getWindow() {
	return KongWindow::WindowAPI::getWindow();
}