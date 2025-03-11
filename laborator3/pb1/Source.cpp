#include<iostream>
#include"Math.h"
using namespace std;
Math m;
int main()
{
	const char s[] = "Azi suntem";
	const char t[] = " la facultate";
	cout << m.Add(2, 3)<<'\n';
	cout << m.Add(2, 3 ,4)<<'\n';
	cout << m.Add(2.3, 3.5)<<'\n';
	cout << m.Add(2.3, 3.5,4.7)<<'\n';
	cout << m.Mul(2, 3)<<'\n';
	cout << m.Mul(2, 3, 4)<<'\n';
	cout << m.Mul(2.2, 3.4,4.7)<<'\n';
	cout << m.Mul(2.2, 3.4)<<'\n';
	cout << m.Add(5, 1, 2, 3, 4, 5)<<'\n';
	cout << m.Add(s,t) << '\n';
	return 0;
}