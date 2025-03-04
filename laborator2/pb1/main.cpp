#include<iostream>
#include "NumberList.h";
using namespace std;
NumberList a;
int main()
{
	a.Init();
	int x, y, z;
	cin >> x >> y >> z;
	if (!a.Add(x))cout << "adaugare nereusita" << '\n';
	if (!a.Add(y))cout << "adaugare nereusita" << '\n';
	if (!a.Add(z))cout << "adaugare nereusita" << '\n';
	a.Sort();
	a.Print();
	return 0;

}