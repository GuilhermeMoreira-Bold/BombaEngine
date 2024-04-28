#include <string>
#include "..\habilities\Hability.h"
#include "..\level\Level.h"
#pragma once
class Entity {
private:
	std::string name;
	Level* level;
	int hp;
	Hability* hability;
public:
	int atack();
	void setHability(Hability &hability);
	Entity(std::string name,int level, int hp,Hability* hability);
	std::string getName();
	Hability getHability();
	Level *getLevel();
};