#include "Fiat.h"
#include<iostream>
using namespace std;
Fiat::Fiat()
{
	this->cap = 60;
	this->con = 0,7;
	this->avgsunny = 55;
	this->avgrain = 50;
	this->avgsnow = 45;
}
void Fiat::gettip()
{
	cout << "Fiat ";
}
double Fiat::maxdistance()
{
	return this->cap / this->con;
}
int Fiat::getrain()
{
	return this->avgrain;
}
int Fiat::getsunny()
{
	return this->avgsunny;
}
int Fiat::getsnow()
{
	return this->avgsnow;
}