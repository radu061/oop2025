#include "Seat.h"
#include<iostream>
using namespace std;
Seat::Seat()
{
	this->cap = 50;
	this->con = 1;
	this->avgsunny = 70;
	this->avgrain = 60;
	this->avgsnow = 30;
}
void Seat::gettip()
{
	cout << "Seat ";
}
double Seat::maxdistance()
{
	return this->cap / this->con;
}
int Seat::getrain()
{
	return this->avgrain;
}
int Seat::getsunny()
{
	return this->avgsunny;
}
int Seat::getsnow()
{
	return this->avgsnow;
}