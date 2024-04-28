#include "string"
#pragma once
#include "entities/Entity.h"

class Battle {
private:
	std::string name;
	Entity* player;
	Entity* enemy;
public:
	void start();
};