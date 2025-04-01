#include "Circuit.h"
#include<iostream>
using namespace std;
Circuit::Circuit()
{
	this->nrcar = 0;
	this->lg = 0;
	this->cars = new Car*[15];
	this->w = Weather::Sunny;
}
void Circuit::SetLength(int length)
{
	this->lg = length;
}
void Circuit::AddCar(Car *c)
{
	this->cars[this->nrcar++] = c;
}
void Circuit::Race()
{
	if (this->w == Weather::Sunny)
	{
		bool ok = 0;
		while (!ok)
		{
			ok = 1;
			for (int i = 0;i < this->nrcar - 1;i++)
				if ((this->cars[i]->maxdistance() < this->lg && this->cars[i + 1]->maxdistance() >= this->lg) || (this->cars[i]->getsunny() < this->cars[i]->getsunny()))
				{
					swap(this->cars[i], this->cars[i + 1]);
					ok = 0;
				}
		}
	}
	else if (this->w == Weather::Rain)
	{
		bool ok = 0;
		while (!ok)
		{
			ok = 1;
			for (int i = 0;i < this->nrcar - 1;i++)
				if ((this->cars[i]->maxdistance() < this->lg && this->cars[i + 1]->maxdistance() >= this->lg) || (this->cars[i]->getrain() < this->cars[i]->getrain()))
				{
					swap(this->cars[i], this->cars[i + 1]);
					ok = 0;
				}
		}
	}
	else
	{
		bool ok = 0;
		while (!ok)
		{
			ok = 1;
			for (int i = 0;i < this->nrcar - 1;i++)
				if ((this->cars[i]->maxdistance() < this->lg && this->cars[i + 1]->maxdistance() >= this->lg) || (this->cars[i]->getsnow() < this->cars[i]->getsnow()))
				{
					swap(this->cars[i], this->cars[i + 1]);
					ok = 0;
				}
		}
	}
}
void Circuit::ShowFinalRanks()
{
	for(int i=0;i<this->nrcar;i++)
			if (this->cars[i]->maxdistance() < this->lg)
			{
				this->cars[i]->gettip();
				cout << "nu a ajuns la finis \n";
			}
			else {
				this->cars[i]->gettip();
				if(this->w==Weather::Sunny)
				cout << "a ajuns in" << this->lg / this->cars[i]->getsunny()<<'\n';
				else if(this->w==Weather::Rain)
					cout << "a ajuns in " << (float)(this->lg) / this->cars[i]->getrain() << '\n';
				else 
					cout << "a ajuns in " << this->lg / this->cars[i]->getsnow() << '\n';
			}
}
void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0;i < this->nrcar;i++)
		if (this->cars[i]->maxdistance() < this->lg)
		{
			this->cars[i]->gettip();
			cout << "nu a ajuns la finis \n";
		}
}
void Circuit::SetWeather(Weather nou)
{
	this->w = nou;
}