#pragma once
#include "../entities/Entity.h"
class Command {
	public:
		virtual void execute(Entity &e) = 0;
};