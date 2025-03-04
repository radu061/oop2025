#include"Student.h";
#include<iostream>
#include<cstring>
using namespace std;
void Student::Init()
{
	this->name[0] = 0;
	this->grade_math = 0;
	this->grade_his = 0;
	this->grade_eng = 0;
}
void Student::set_name(char new_name[])
{
	int n = 0;
	while (new_name[n])n++;
	for (int i = 0;i < n;i++)
		this->name[i] = new_name[i];
	name[n] = 0;
}
void Student::get_name(char destinatie[])
{
	int n = 0;
	while (this-name[n])n++;
	for (int i = 0;i<=n;i++)
		destinatie[i] = this->name[i];
}
float Student::get_math()
{
	return this->grade_math;
}
float Student::get_eng()
{
	return this->grade_eng;
}
float Student::get_his()
{
	return this->grade_his;
}
bool Student::set_math(float new_grade)
{
	if (new_grade >= 1 && new_grade <= 10)
	{
		this->grade_math = new_grade;
		return 1;
	}
	else return 0;
}
bool Student::set_eng(float new_grade)
{
	if (new_grade >= 1 && new_grade <= 10)
	{
		this->grade_eng = new_grade;
		return 1;
	}
	else return 0;
}
bool Student::set_his(float new_grade)
{
	if (new_grade >= 1 && new_grade <= 10)
	{
		this->grade_his = new_grade;
		return 1;
	}
	else return 0;
}
float Student::average()
{
	float avg = this->grade_math + this->grade_his + grade_eng;
	avg /= 3;
	return avg;
}