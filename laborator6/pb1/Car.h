#pragma once
class Car
{
protected:
	int cap;
	double con;
	int avgrain, avgsunny, avgsnow;
public:
	virtual void gettip()=0;
	virtual double maxdistance()=0;
	virtual int getrain()=0;
	virtual int getsunny()=0;
	virtual int getsnow()=0;
};
