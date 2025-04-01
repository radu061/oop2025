#pragma once
#include"Car.h"
class Fiat :public Car
{
public:
	Fiat();
	void gettip();
	double maxdistance();
	int getrain();
	int getsunny();
	int getsnow();
};

