#pragma once
#include <iostream>
#include "entities/Enemy.h"
#include "Input/InputHandler.h"
#include "habilities/BasicAtack.h"

class GameLoop {
private:
	Entity* e;

public:
	void run();
	GameLoop();
	~GameLoop();
};

namespace CaptureIt {
	void run();
}