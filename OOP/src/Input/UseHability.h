#pragma once
#include "Command.h"

class UseHability : public Command {
public:
	void execute(Entity &e);
};