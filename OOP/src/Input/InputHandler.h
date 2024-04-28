#pragma once
#include "Command.h"
#include "..\entities\Entity.h"
#include <map>

enum class KeyCode {
	Attack = '1', Jump, Defend
};

class InputHandler {
	static std::map<char, Command*> keyMap;
public:
	static void setKey(char key, Command &command);
	static void changeKey(char key,char oldKey);
	static void handle(char input,Entity& e);
	static KeyCode charToKeyCode(KeyCode keyCode, char& input);
};