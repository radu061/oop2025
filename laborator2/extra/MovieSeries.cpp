#include "MovieSeries.h"
#include<iostream>
using namespace std;
void MovieSeries::init()
{
	this->ct = 0;
	this->a = nullptr;
}
void MovieSeries::add(Movie *nou)
{
	if (this->ct == 16)  return;
	Movie** new_movies = new Movie * [this->ct + 1];
	for (int i = 0;i < this->ct;i++)
		new_movies[i] = this->a[i];
	new_movies[this->ct] = nou;
	delete[] this->a;
	this->a = new_movies;
	this->ct++;
}
void MovieSeries::print()
{
	for (int i = 0;i <this->ct;i++)
		cout << this->a[i]->get_name()<<' '<<this->a[i]->get_IMDB()<<'\n';
}
void MovieSeries::sort()
{
	bool ok = 0;
	while (!ok)
	{
		ok = 1;
		for (int i = 0;i < this->ct - 1;i++)
			if (this->a[i]->passyear()<this->a[i + 1]->passyear())
			{
				ok = 0;
				swap(this->a[i],this->a[i+1]);
		}
	}

}