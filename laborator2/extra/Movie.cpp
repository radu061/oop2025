#include "Movie.h"
#include<cstring>
#include<memory>
const char* Movie::get_name()
{
	return this->name;
}
void Movie::set_name(const char* nou)
{
	int size = strlen(nou);
	this->name = new char[size + 1];
	memcpy(this->name, nou,size);
	this->name[size] = 0;
}
int Movie::get_year()
{
	return this->year;
}
void Movie::set_year(int x)
{
	this->year = x;
}
double Movie::get_IMDB()
{
	return this->IMDB;
}
void Movie::set_IMDB(double IMDBnou)
{
	if(IMDBnou>=1&&IMDBnou<=10)
	this->IMDB = IMDBnou;
}
int Movie::get_length()
{
	return this->length;
}
void Movie::set_length(int lg)
{
	this->length = lg;
}
int Movie::passyear()
{
	return 2025 - this->year;
}

