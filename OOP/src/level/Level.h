#pragma once
class Level {
private:
	int* level;
public:
	void setLevel(int &xp);
	int getLevel();
	Level(int &level);
};