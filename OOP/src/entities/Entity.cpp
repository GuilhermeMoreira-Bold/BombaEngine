 #include "Entity.h"
#include "..\habilities\Hability.h"
int Entity::atack() {
	return	hability->use();
}

void Entity::setHability(Hability& hability) {
	this->hability = &hability;
}

Entity::Entity(std::string name,int level, int hp,Hability* hability)
{
	this->name = name;
	this->hp = hp;
	this->hability = hability;
	Level level2(level);
	this->level = &level2;
}

std::string Entity::getName(){
	return this->name;
}

Level* Entity::getLevel() {
	return this->level;
}

Hability Entity::getHability(){
	return *hability;
}