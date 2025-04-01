#include "Volvo.h"
#include<iostream>
using namespace std;
Volvo::Volvo()
{
	this->cap =80;
	this->con = 0,2;
	this->avgsunny = 40;
	this->avgrain = 35;
	this->avgsnow = 30;
}
void Volvo::gettip()
{
	cout << "Volvo ";
}
double Volvo::maxdistance()
{
	return this->cap / this->con;
}
int Volvo::getrain()
{
	return this->avgrain;
}
int Volvo::getsunny()
{
	return this->avgsunny;
}
int Volvo::getsnow()
{
	return this->avgsnow;
}