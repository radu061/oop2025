#pragma once
#include<iostream>
using namespace std;
template<class T>
class Vector
{
private:
	T *v;
	int size;
public:
	Vector()
	{
		this->size = 0;
	}
	Vector<T>(const Vector<T>& a)
	{
		delete[] this->v;
		this->size = a.size;
		this->v = new T[a.size];
		for (int i = 0;i < a.size;i++)
			this->v[i] = a.v[i];
	}
	Vector<T>(Vector<T>&& a)
	{
		this->size = a.size;
		delete[]this->v;
		this->v = a.v;
	}
	void insert(int poz,T info)
	{
		if (poz < 0 || poz > size) 
		{ 
			cout << "Pozitie invalida \n";
			return;
		}
		T *a = new T[this->size + 1];
		for (int i = 0;i < poz;i++)
			a[i] = this->v[i];
		a[poz] = info;
		for (int i = poz + 1;i < this->size;i++)
			a[i+1] = this->v[i];
		delete[] this->v;
		this->v = a;
		this->size = this->size + 1;
	}
	void remove(int poz)
	{
		if (poz < 0 || poz >= size)
		{
			cout << "Pozitie invalida";
			return;
		}
		T *a = new T[this->size-1];
		for (int i = 0;i < poz;i++)
			a[i] = this->v[i];
		for (int i = poz+1;i < this->size;i++)
			a[i-1] = this->v[i];
		delete[] this->v;
		this->v = a;
		this->size--;
	}
	T operator[](int index)
	{
		return this->v[index];
	}
	void print()
	{
		for (int i = 0;i < this->size;i++)
			cout << v[i] << ' ';
		cout << '\n';
	}
	void sort(int (*cmp)(T x, T y))
	{
		bool ok = 0;
		while (!ok)
		{
			ok = 1;
			for(int i=0;i<this->size-1;i++)
				if (cmp(this->v[i], this->v[i + 1])==1)
				{
					ok = 0;
					swap(this->v[i], this->v[i + 1]);
				}
		}
	}
	void sort()
	{
		bool ok = 0;
		while (!ok)
		{
			ok = 1;
			for (int i = 0;i < this->size - 1;i++)
				if (this->v[i]<this->v[i + 1])
				{
					ok = 0;
					swap(this->v[i], this->v[i + 1]);
				}
		}
	}
};