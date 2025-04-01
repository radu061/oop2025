#pragma once
#include"Car.h"
#include"Weather.h"
class Circuit
{
	int nrcar;
	Car **cars;
	int lg;
	Weather w;
public:
	void SetWeather(Weather nou);
	Circuit();
	void SetLength(int length);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

