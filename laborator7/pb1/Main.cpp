#include<iostream>
using namespace std;

float operator"" _Kelvin(long double x)
{
	float y = x;
	return y - 273.15;
}
float operator""_Fahrenheit(long double x)
{
	float y = x - 32;
	return y / 1.8;
}
int main()
{
	float a = 300.0_Kelvin;
	float b = 120.0_Fahrenheit;
	cout << a << ' ' << b;
	return 0;
}