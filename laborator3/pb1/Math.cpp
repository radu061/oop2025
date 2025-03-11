#include "Math.h"
#include<cstring>
#include<stdarg.h>
int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y,int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return (int)(x + y);
}
int Math::Add(double x, double y,double z)
{
	return int(x + y + z);
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return (int)(x * y);
}
int Math::Mul(double x, double y, double z)
{
	return int(x * y * z);
}
int Math::Add(int count, ...)
{
	int s = 0;
	va_list nr;
	va_start(nr, count);
	for (int i = 0;i < count;i++)
		s += va_arg(nr, int);
	va_end(nr);
	return s;
}
char* Math::Add(const char* x, const char* y)
{
	int lx = strlen(x), ly = strlen(y);
	char* p;
	if (x == nullptr || y == nullptr) {
		p = nullptr;
		return p;
	}
	p = new char(lx + ly + 1);
	strcpy_s(p, lx+ly+1,x);
	strcat_s(p, ly+lx+1,y);
	return p;
}