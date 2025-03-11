#include "Canvas.h"
#include<iostream>
#include<stdarg.h>
using namespace std;
Canvas::Canvas(int width, int height)
{
	this->h = height;
	this->w = width;
	this->Clear();
}
void Canvas::Set_pixel(int x, int y, char ch)
{
	this->canvas[x][y] = ch;
}
void Canvas::set_pixels(int count, ...)
{
	va_list nr;
	va_start(nr, count);
	for (int i = 0;i < count;i++)
	{
		int x = va_arg(nr, int);
		int y = va_arg(nr, int);
		char c = va_arg(nr, char);
		this->Set_pixel(x, y, c);
	}
	va_end(nr);
}
void Canvas::Print()
{
	for (int i = 0;i < this->h;i++)
	{
		for (int j = 0;j < this->w;j++)
			cout << this->canvas[i][j] << ' ';
		cout << '\n';
	}
}
void Canvas::Clear()
{
	for (int i = 0;i < this->h;i++)
		for (int j = 0;j < this->w;j++)
			this->canvas[i][j] = 32;
}