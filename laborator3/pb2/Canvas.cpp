#include "Canvas.h"
#include<iostream>
using namespace std;
Canvas::Canvas(int width, int height)
{
	this->h = height;
	this->w = width;
	this->Clear();
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 1;i < 360;i++)
	{
		int xnou = x + ray * cos(i);
		int ynou = y + ray * sin(i);
		if (xnou >= 0 && xnou < this->w && ynou >= 0 && ynou < this->h)
			this->canvas[ynou][xnou] = ch;
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 1;i < 360;i++)
		for (int j = 0;j <= ray;j++) 
		{
			int xnou = x + j * cos(i);
			int ynou = y + j * sin(i);
			if (xnou >= 0 && xnou < this->w && ynou >= 0 && ynou < this->h)
				this->canvas[ynou][xnou] = ch;
		}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++)
		this->canvas[i][right] = this->canvas[i][left] = ch;
	for (int j = left;j <= right;j++)
		this->canvas[top][j] = this->canvas[bottom][j] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++)
		for (int j = left;j <= right;j++)
			this->canvas[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	this->canvas[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++) {
		this->canvas[y][x] = ch;
		slope_error_new += m_new;
		if (slope_error_new >= 0) 
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
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