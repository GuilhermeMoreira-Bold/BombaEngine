#include "GameLoop.h"
#include "Engine.h"


int main() {
	//CaptureIt::run();
	SmartKong::Engine::init();
	SmartKong::Engine::update();
	return 0;
}