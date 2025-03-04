#include<iostream>
#include"Student.h";
#include<cstring>;
using namespace std;
Student a;

int main()
{
	a.Init();
	char nume[105],nou[105];
	cin.getline(nume, 105);
	a.set_name(nume);
	a.get_name(nou);
	cout << nou << '\n';
	nume[0] = 'A';
	nume[1] = 'n';
	nume[2] = 'd';
	nume[3] = 'r';
	nume[4] = 'e';
	nume[5] = 'i';
	nume[6] = 0;
	a.set_name(nume);
	a.get_name(nou);
	cout << nou << '\n';
	a.set_eng(5.6);
	a.set_eng(7.8);
	a.set_math(10);
	if (!a.set_math(11))cout << "Nota gresita" << '\n';
	a.set_his(4.6);
cout << a.get_math() << ' ' << a.get_eng() << ' ' << a.get_his() << ' ' << a.average() << '\n';
}