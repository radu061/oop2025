#include"Sort.h"
#include<iostream>
using namespace std;
int main()
{
	srand(time(NULL));
	bool ascendent=0;
	const char s[105] = "2,3,1";
	Sort nou(s);
	cout << nou.GetElementFromIndex(1) << " " << nou.GetElementsCount() <<'\n';
	nou.Print();
	nou.InsertSort(ascendent);
	nou.Print();
	Sort a{ 45, 3,8 ,6 ,10, 19 };
	a.Print();
	a.QuickSort(ascendent);
	a.Print();
	int* v = new int[10];
	v[0] = 43;
	v[1] = 32;
	v[2] = 54;
	v[3] = 2;
	v[4] = 3;
	int n = 5;
	Sort D(v, n);
	D.Print();
	D.InsertSort(ascendent);
	D.Print();
	cout << endl;
	return 0;
}