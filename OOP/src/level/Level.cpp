#include "Level.h"

Level::Level(int &level) {
	this->level = &level;
}

void Level::setLevel(int &xp) {
	this->level = &xp;
}

int Level::getLevel() {
	return *level;
}