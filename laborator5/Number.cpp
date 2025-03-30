#include"Number.h"
#include<cstring>
#include<iostream>
using namespace std;
Number::Number(const char* value, int base)
{
	this->nr = new char[strlen(value) + 1];
	for (int i = 0;value[i];i++)
		this->nr[i] = value[i];
	this->nr[strlen(value)] = 0;
	this->base = base;
}
Number::Number(int n)
{
	char nou[105];
	int lg = 0;
	while (n)
	{
		nou[lg++] = n % 10 + '0';
		n /= 10;
	}
	nou[lg] = 0;
	for (int i = 0;i < lg / 2;i++)
		swap(nou[i], nou[lg - i - 1]);
	this->nr = new char[lg + 1];
	for (int i = 0;nou[i];i++)
		this->nr[i] = nou[i];
	this->nr[lg] = 0;
	this->base = 10;
}
Number::~Number()
{
	delete this->nr;
	this->nr = nullptr;
}
int Number::GetBase()
{
	return this->base;
}
void Number::Print()
{
	for (int i = 0;this->nr[i];i++)
		cout << this->nr[i];
	cout << '\n';
}
int Number::GetDigitsCount()
{
	int ct = 0;
	for (int i = 0;this->nr[i];i++)
		ct++;
	return ct;
}
void Number::SwitchBase(int newBase)
{
	int nou = 0, p = 1;
	int n = strlen(this->nr);
	for (int i = n - 1;i >= 0;i--)
	{
		if (this->nr[i] >= '0' && this->nr[i] <= '9')
			nou = nou + p * (this->nr[i] - '0');
		else nou = nou + p * (this->nr[i] - 'A' + 10);
		p *= this->base;
	}
	int k = 0;
	while (nou)
	{
		int cif = n % this->base;
		if (cif > 9)
			this->nr[k++] = 'A' + cif - 10;
		else this->nr[k++] = '0' + cif;
		nou /= this->base;
	}
	this->nr[k] = 0;
	for (int i = 0;i < k / 2;i++)
		swap(this->nr[i], this->nr[k - i - 1]);
}
Number operator +(const Number& n1, const Number& n2)
{
	int nou1=0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else 
				nou1 = nou1 * n1.base + n1.nr[i] - 'A'+10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	int rez = nou1 + nou2;
	int bnou = max(n1.base, n2.base);
	int lg = 0;
	char nr[105];
	if (rez == 0)
	{
		Number nou("0", bnou);
		return nou;
	}
	while (rez)
	{
		int cif = rez % bnou;
		if (cif > 9)
			nr[lg++] = 'A' + cif - 10;
		else nr[lg++] = '0' + cif;
		rez /= bnou;
	}
	nr[lg] = 0;
	for (int i = 0;i < lg / 2;i++)
		swap(nr[i], nr[lg - i - 1]);
	Number nou(nr, bnou);
	return nou;
}
Number operator -(const Number& n1, const Number& n2)
{
	int nou1 = 0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else
				nou1 = nou1 * n1.base + n1.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	int rez = nou1 - nou2;
	int bnou = max(n1.base, n2.base);
	int lg = 0;
	char nr[105];
	if (rez == 0)
	{
		Number nou("0", bnou);
		return nou;
	}
	while (rez)
	{
		int cif = rez % bnou;
		if (cif > 9)
			nr[lg++] = 'A' + cif - 10;
		else nr[lg++] = '0' + cif;
		rez /= bnou;
	}
	nr[lg] = 0;
	for (int i = 0;i < lg / 2;i++)
		swap(nr[i], nr[lg - i - 1]);
	Number nou(nr, bnou);
	return nou;
}
bool operator >(const Number& n1, const Number& n2)
{
	int nou1 = 0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else
				nou1 = nou1 * n1.base + n1.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	return nou1 > nou2;

}
bool operator <(const Number& n1, const Number& n2)
{
	int nou1 = 0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else
				nou1 = nou1 * n1.base + n1.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	return nou1 < nou2;
}
bool operator <=(const Number& n1, const Number& n2)
{
	int nou1 = 0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else
				nou1 = nou1 * n1.base + n1.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	return nou1 <= nou2;
}
bool operator >=(const Number& n1, const Number& n2)
{
	int nou1 = 0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else
				nou1 = nou1 * n1.base + n1.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	return nou1 >= nou2;
}
bool operator ==(const Number& n1, const Number& n2)
{
	int nou1 = 0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else
				nou1 = nou1 * n1.base + n1.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	return nou1 == nou2;
}
bool operator !=(const Number& n1, const Number& n2)
{
	int nou1 = 0, nou2 = 0;
	if (n1.base != 10)
	{
		for (int i = 0;n1.nr[i];i++)
			if (n1.nr[i] >= '0' && n1.nr[i] <= '9')
				nou1 = nou1 * n1.base + n1.nr[i] - '0';
			else
				nou1 = nou1 * n1.base + n1.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n1.nr[i];i++)
			nou1 = nou1 * 10 + n1.nr[i] - '0';
	}
	if (n2.base != 10)
	{
		for (int i = 0;n2.nr[i];i++)
			if (n2.nr[i] >= '0' && n2.nr[i] <= '9')
				nou2 = nou2 * n2.base + n2.nr[i] - '0';
			else
				nou2 = nou2 * n2.base + n2.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n2.nr[i];i++)
			nou2 = nou2 * 10 + n2.nr[i] - '0';
	}
	return nou1 != nou2;
}
char Number::operator[](const int index)
{
	return this->nr[index];
}
void Number::operator --(int val)///n--
{
	this->nr[strlen(this->nr) - 1] = 0;
}
void Number::operator --()///--n
{
	int lg = strlen(this->nr);
	if (lg == 1)this->nr[0] = 0;
	else 
	{
	for (int i = 0;i < lg - 1;i++)
		this->nr[i] = this->nr[i + 1];
	this->nr[lg - 1] = 0;
	}
}
Number& Number:: operator = (const Number& n)
{
	this->base = n.base;
	int lg = strlen(n.nr);
	delete[] this->nr;
	this->nr = new char[lg+1];
	for (int i = 0;i < lg;i++)
		this->nr[i] = n.nr[i];
	this->nr[lg] = 0;
	return *this;
}
Number& Number:: operator = (int n)
{
	char nou[105];
	int lg = 0;
	while (n)
	{
		nou[lg++] = n % 10 + '0';
		n /= 10;
	}
	nou[lg] = 0;
	for (int i = 0;i < lg / 2;i++)
		swap(nou[i], nou[lg - i - 1]);
	delete[] this->nr;
	this->nr = new char[lg + 1];
	for (int i = 0;nou[i];i++)
		this->nr[i] = nou[i];
	this->nr[lg] = 0;
	this->base = 10;
	return *this;
}
Number& Number::operator = (const char* n)
{
	int lg = strlen(n);
	delete[] this->nr;
	this->nr = new char[lg + 1];
	for (int i = 0;i < lg;i++)
		this->nr[i] = n[i];
	this->nr[lg] = 0;
	this->base = 10;
	return *this;
}
void Number:: operator +=(const Number & n)
{
	int nou1 = 0, nou2 = 0;
	if (this->base != 10)
	{
		for (int i = 0;this->nr[i];i++)
			if (this->nr[i] >= '0' && this->nr[i] <= '9')
				nou1 = nou1 * this->base + this->nr[i] - '0';
			else
				nou1 = nou1 * this->base + this->nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;this->nr[i];i++)
			nou1 = nou1 * 10 + this->nr[i] - '0';
	}
	if (n.base != 10)
	{
		for (int i = 0;n.nr[i];i++)
			if (n.nr[i] >= '0' && n.nr[i] <= '9')
				nou2 = nou2 * n.base + n.nr[i] - '0';
			else
				nou2 = nou2 * n.base + n.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n.nr[i];i++)
			nou2 = nou2 * 10 + n.nr[i] - '0';
	}
	int rez = nou1 + nou2;
	int bnou = max(this->base, n.base);
	int lg = 0;
	char num[105];
	if (rez == 0)
	{
		this->nr[0] = '0';
		this->nr[1] = 0;
	}
	while (rez)
	{
		int cif = rez % bnou;
		if (cif > 9)
			num[lg++] = 'A' + cif - 10;
		else num[lg++] = '0' + cif;
		rez /= bnou;
	}
	num[lg] = 0;
	for (int i = 0;i < lg / 2;i++)
		swap(num[i], num[lg - i - 1]);
	cout << num[0] << num[1] << num[2] << '\n';
	delete[] this->nr;
	this->nr = new char[lg + 1];
	for (int i = 0;i < lg;i++)
		this->nr[i] = num[i];
	this->nr[lg] = 0;
	this->base = bnou;
}
void Number:: operator -=(const Number& n)
{
	int nou1 = 0, nou2 = 0;
	if (this->base != 10)
	{
		for (int i = 0;this->nr[i];i++)
			if (this->nr[i] >= '0' && this->nr[i] <= '9')
				nou1 = nou1 * this->base + this->nr[i] - '0';
			else
				nou1 = nou1 * this->base + this->nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;this->nr[i];i++)
			nou1 = nou1 * 10 + this->nr[i] - '0';
	}
	if (n.base != 10)
	{
		for (int i = 0;n.nr[i];i++)
			if (n.nr[i] >= '0' && n.nr[i] <= '9')
				nou2 = nou2 * n.base + n.nr[i] - '0';
			else
				nou2 = nou2 * n.base + n.nr[i] - 'A' + 10;
	}
	else
	{
		for (int i = 0;n.nr[i];i++)
			nou2 = nou2 * 10 + n.nr[i] - '0';
	}
	int rez = nou1 - nou2;
	int bnou = max(this->base, n.base);
	int lg = 0;
	char num[105];
	if (rez == 0)
	{
		this->nr[0] = '0';
		this->nr[1] = 0;
	}
	while (rez)
	{
		int cif = rez % bnou;
		if (cif > 9)
			num[lg++] = 'A' + cif - 10;
		else num[lg++] = '0' + cif;
		rez /= bnou;
	}
	num[lg] = 0;
	for (int i = 0;i < lg / 2;i++)
		swap(num[i], num[lg - i - 1]);
	delete[] this->nr;
	this->nr = new char[lg + 1];
	for (int i = 0;i < lg;i++)
		this->nr[i] = num[i];
	this->nr[lg] = 0;
	this->base = bnou;
}
Number::Number(const Number & n)
{
	this->base = n.base;
	int lg = strlen(n.nr);
	delete[] this->nr;
	this->nr = new char[lg + 1];
	for (int i = 0;i < lg;i++)
		this->nr[i] = n.nr[i];
	this->nr[lg] = 0;
}
Number::Number(Number&& n)
{
	this->base = n.base;
	int lg = strlen(n.nr);
	delete[] this->nr;
	this->nr = new char[lg + 1];
	for (int i = 0;i < lg;i++)
		this->nr[i] = n.nr[i];
	this->nr[lg] = 0;
	n.nr = 0;
}