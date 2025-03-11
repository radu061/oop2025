#include"Canvas.h"
using namespace std;

int main()
{
	Canvas c(50, 50);
	c.DrawRect(5, 5, 25, 25,'1');
	c.Print();
	c.FillRect(5, 5, 25, 25,'2');
	c.Print();
	c.Clear();
	c.SetPoint(0, 0, 'a');
	c.Print();
	c.Clear();
	c.DrawCircle(10, 10, 5,'a');
	c.Print();
	c.FillCircle(10, 10, 5, 'b');
	c.Print();
	c.Clear();
	c.DrawLine(5, 5, 10, 10, 'c');
	c.Print();
}