#pragma once
#include<iostream>
template<class K,class V>
class Pair
{
public:
	K key;
	V value;
};
template<class K, class V>
struct Item 
{
	K key;
	V value;
	int index;
};
template<class K, class V>
class Iterator
{
public:
	Pair<K, V>* p;
	int poz;
	Iterator(Pair<K, V>* nou, int noup)
	{
		this->p = nou;
		this->poz = noup;
	}
	bool operator!=(Iterator& p)
	{
		return p.poz!=this->poz;
	}
	Item<K,V> operator*()
	{
		return Item<K,V>{this->p->key,this->p->value,this->poz};
	}
	Iterator& operator++()
	{
		this->p++;
		this->poz++;
		return *this;
	}
};
template<class K, class V>
class Map
{
	Pair<K, V> * a;
	int ct;
public:
	Map()
	{
		this->ct = 0;
	}
	Iterator<K,V> begin()
	{
		return Iterator(this->a,0);
	}
	Iterator<K,V> end()
	{
		if (this->ct > 0)
			return Iterator(this->a+this->ct, this->ct);
	}
	void Set(const K k, V v)
	{
		for (int i = 0;i < this->ct;i++)
			if (this->a[i].key == k)
			{
				this->a[i].value = v;
				return;
			}
		Pair<K, V> *nou=new Pair<K,V>[this->ct+1];
		for (int i = 0;i < this->ct;i++)
			nou[i] = this->a[i];
		this->ct++;
		this->a[this->ct-1].key = k;
		this->a[this->ct-1].value = v;
	}
	bool Get(const K& k, V& v)
	{
		for(int i=0;i<this->ct;i++)
			if (k == this->a[i].key)
			{
				v = this->a[i].value;
				return 1;
			}
		return 0;
	}
	int Count()
	{
		return this->ct;
	}
	void Clear()
	{
		this->ct = 0;
		delete[] this->a;
	}
	bool Delete(const K& k)
	{
		Pair<K, V>* nou = new Pair<K, V>[this->ct];
		bool ok = 0;
		int m=0;
		for (int i = 0;i < this->ct;i++)
			if (k != this->a[i].key)
				nou[m++] = this->a[i];
			else ok = 1;
		if (ok)
		{
			this->Clear();
			this->a = new Pair<K, V>[m];
			for (int i = 0;i < m;i++)
				this->a[i] = nou[i];
			this->ct = m;
			return 1;
		}
		else return 0;
	}
	V& operator[](const K k)
	{
		for (int i = 0; i < this->ct; i++) 
			if (this->a[i].key == k) 
				return this->a[i].value;
		Pair<K, V>* nou = new Pair<K, V>[this->ct + 1];
		for (int i = 0;i < this->ct;i++)
			nou[i] = this->a[i];
		this->ct++;
		int n = this->ct;
		nou[this->ct - 1].key = k;
		nou[this->ct - 1].value = V{};
		this->Clear();
		this->a = nou;
		this->ct = n;
		return this->a[this->ct - 1].value;
	}
	bool Includes(const Map<K, V>& map)
	{
		V val;
		for (auto i : map)
			if (!map.Get(i.key, val))
				return 0;
		return 1;
				
	}
};

