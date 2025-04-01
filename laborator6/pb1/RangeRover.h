#pragma once
#include "Car.h"
class RangeRover :public Car
{
public:
	RangeRover();
	void gettip();
	double maxdistance();
	int getrain();
	int getsunny();
	int getsnow();
};

