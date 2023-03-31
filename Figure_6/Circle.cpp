#include "Figure.h"
#include "Circle.h"

#include <iostream>

using namespace std;

Circle::Circle()
{
	cout << "Circle::Circle()" << endl;
	*r = 10;
}

Circle::Circle(int r0)
{
	cout << "Circle::Circle(int r0)" << endl;
	*r = r0;
}

Circle::~Circle()
{
	cout << "Circle::~Circle()" << endl;
	delete []r;
}

void Circle::Show()
{
	cout << "-----Circle::Show-----" << endl;
	cout << "\tr = " << *r << endl;
}

double Circle::CalcArea()
{
	return acos(-1) * *r * *r;
}

Figure* Circle::Copy()
{
	cout << "Figure* Circle::Copy()" << endl;
	Figure* c = new Circle(*r);
	return c;
}

int Circle::Get_r()
{
	cout << "int Circle::Get_r()" << endl;
	return *r;
}