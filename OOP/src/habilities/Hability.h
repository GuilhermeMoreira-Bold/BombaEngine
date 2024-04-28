#pragma once

class Hability {
private:
	int power;
	int chanceToSucess;
public:
	Hability(int power, int chanceToSucess);
	int getPower();
	virtual int use();
private:
	virtual bool success();
};