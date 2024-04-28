#include "Input/InputHandler.h"
#include "GameLoop.h"
#include "Input/UseHability.h"
#include <string>

void GameLoop::run() {
	UseHability use;
	InputHandler::setKey('1', use);
	bool exit = true;
	char input;
	std::cin >> input;
	InputHandler::handle(input, *e);

	std::cin >> input;
	InputHandler::changeKey(input,static_cast<char>(KeyCode::Attack));

	while (true) {
		std::cin >> input;
		InputHandler::handle(input, *e);
	}
};

GameLoop::GameLoop(){
	this->e = new Enemy("jubileu", 0, 10, new BasicAtack(200, 1));
}

GameLoop::~GameLoop() {
	delete e;
}

void CaptureIt::run() {
	GameLoop g;
	g.run();
}