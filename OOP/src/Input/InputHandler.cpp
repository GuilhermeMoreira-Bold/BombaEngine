#include "InputHandler.h"

std::map<char, Command*> InputHandler::keyMap;

 void InputHandler::handle(char input,Entity &e) {
	 if (keyMap.find(input) != keyMap.end()) {
		 keyMap[input]->execute(e);
	}
}

 void InputHandler::setKey(char key,Command &command) 
 {
	 keyMap.insert({ key, &command});
 }

 void InputHandler::changeKey(char key, char oldKey)
 {
	 if (keyMap.find(oldKey) != keyMap.end()){ 
		 setKey(key, *keyMap[oldKey]);
		 keyMap.erase(oldKey);
	 }
	 else {
	 }
 }

 KeyCode InputHandler::charToKeyCode(KeyCode keyCode,char& input) {
	 std::map<char,KeyCode> charToEnum = {
		 {input,keyCode}
	 };
	 auto it = charToEnum.find(input);
	 if (it != charToEnum.end()) {
		 return charToEnum[0];
	 }
	 else {
		 return KeyCode::Attack;
	 }
 }