#include "Random.h"
#include <iostream>
#include <random>

int Random::result(int habilityRange,int initialRange) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(initialRange, habilityRange);
	return dis(gen);
}