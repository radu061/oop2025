#pragma once
#include"Car.h"
class Seat :public Car
{
public:
	Seat();
	void gettip();
	double maxdistance();
	int getrain();
	int getsunny();
	int getsnow();
};

