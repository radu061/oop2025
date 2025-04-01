#pragma once
#include "Car.h"
class Volvo : 
	public Car
{
public:
	Volvo();
	void gettip();
	double maxdistance();
	int getrain();
	int getsunny();
	int getsnow();
};

