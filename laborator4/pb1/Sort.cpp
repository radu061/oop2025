#include "Sort.h"
#include<iostream>
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
Sort::Sort(int nr, int m, int M)
{
	this->n = nr;
	this->a = new int[nr];
	for(int i=0;i<this->n;i++)
	     this->a[i]=m + (rand() % (M - m + 1));
}
Sort::Sort(initializer_list<int> v)
{
	this->a = new int[v.size()];
	this->n = v.size();
	memcpy(this->a, v.begin(), v.size() * sizeof(int));
}
void quickSort(int* v, int st, int dr)
{
	if (st < dr)
	{
		int aux;
		int pivot = v[st];
		int i = st + 1;
		int j = dr;
		while (i <= j)
		{
			if (v[i] <= pivot)
				i++;
			if (pivot <= v[j])
				j--;
			if (i < j && v[i] > pivot && pivot > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				i++;
				j--;
			}
		}
		aux = v[st];
		v[st] = v[i - 1];
		v[i - 1] = aux;
		quickSort(v, st, i - 2);
		quickSort(v, i, dr);
	}
}
void Sort::QuickSort(bool ascendent)
{
	quickSort(this->a, 0, this->n - 1);
	ascendent = true;
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 0; i < this->n; i++)
	{
		int aux = this->a[i];
		int j = i - 1;
		while (j >= 0 && this->a[j] > aux) {
			this->a[j + 1] = this->a[j];
			j = j - 1;
		}
		this->a[j + 1] = aux;
	}
}
Sort::Sort(const int *v,int k)
{
	this->n = k;
	this->a = new int[k];
	for (int i = 0;i < k;i++)
		a[i] = v[i];
}
Sort::Sort(const char *s)
{
	int ct = 0;
	for (int i = 0;s[i];i++)
		if (s[i] == ',')ct++;
	this->n = ct+1;
	this->a = new int[this->n];
	int i = 0;
	for (int j = 0;j <= ct;j++)
	{
		int num = 0;
		while (s[i] != ','&&s[i])
		{
			num = num * 10 + s[i] - '0';
			i++;
		}
		a[j] = num;
		i++;
	}
}
Sort::Sort(int nr,...)
{
	va_list num;
	this->n = nr;
	va_start(num, nr);
	this->a = new int[nr];
	for (int i = 0;i < nr;i++)
		this->a[i] = va_arg(num, int);
	va_end(num);
}
void Sort::BubbleSort(bool ascendent)
{ 
	bool ok = 0;
	while (!ok)
	{
		ok = 1;
		for(int i=0;i<n-1;i++)
			if (a[i] > a[i + 1])
			{
				ok = 0;
				swap(a[i], a[i + 1]);
			}
	}
}
void Sort::Print()
{
	for (int i = 0;i < this->n;i++)
		cout << a[i]<<' ';
	cout << '\n';
}
int Sort::GetElementsCount()
{
	return this->n;
}
int Sort::GetElementFromIndex(int index)
{
	if (index < this->n)return this->a[index];
	else {
		cout << "Nu exista acest index";
		return 0;
	}
}