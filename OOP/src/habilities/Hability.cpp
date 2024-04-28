#include "Hability.h"
#include "Random.h"
#include <iostream>

Hability::Hability(int power, int chanceToSucess) {
	this->power = power;
	this->chanceToSucess = chanceToSucess;
}

int Hability::use(){
	return success() ? Random::result(power, 1) : 0;
}

bool Hability::success() {
	return Random::result(chanceToSucess,0) != 0 ? true : false;
}

int Hability::getPower() {
	return power;
}