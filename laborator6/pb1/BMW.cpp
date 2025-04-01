#include "BMW.h"
#include<iostream>
using namespace std;
BMW::BMW()
{
	this->cap = 40;
	this->con = 0, 8;
	this->avgsunny = 90;
	this->avgrain = 20;
	this->avgsnow = 20;
}
void BMW::gettip()
{
	cout << "BMW ";
}
double BMW::maxdistance()
{
	return this->cap / this->con;
}
int BMW::getrain()
{
	return this->avgrain;
}
int BMW::getsunny()
{
	return this->avgsunny;
}
int BMW::getsnow()
{
	return this->avgsnow;
}