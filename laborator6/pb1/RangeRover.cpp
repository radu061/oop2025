#include "RangeRover.h"
#include<iostream>
using namespace std;
RangeRover::RangeRover()
{
	this->cap = 40;
	this->con = 0,5;
	this->avgsunny = 60;
	this->avgrain=50;
	this->avgsnow=40;
}
void RangeRover::gettip()
{
	cout << "RangeRover ";
}
double RangeRover::maxdistance()
{
	return this->cap / this->con;
}
int RangeRover::getrain()
{
	return this->avgrain;
}
int RangeRover::getsunny()
{
	return this->avgsunny;
}
int RangeRover::getsnow()
{
	return this->avgsnow;
}