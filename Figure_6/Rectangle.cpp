#include "Figure.h"
#include "Rectangle.h"

#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
	cout << "Rectangle::Rectangle()" << endl;
	*a = 1;
	*b = 1;
}

Rectangle::Rectangle(int a0, int b0)
{
	cout << "Rectangle::Rectangle(int r0)" << endl;
	*a = a0;
	*b = b0;
}

Rectangle::~Rectangle()
{
	cout << "Rectangle::~Rectangle()" << endl;
	delete []a;
	delete []b;
}

void Rectangle::Show()
{
	cout << "-----Rectangle::Show-----" << endl;
	cout << "\ta = " << *a << endl;
	cout << "\tb = " << *b << endl;
}

double Rectangle::CalcArea()
{
	return *a * *b;
}

Figure* Rectangle::Copy()
{
	cout << "Figure* Rectangle::Copy()" << endl;
	Figure* re = new Rectangle(*a, *b);
	return re;
}

int Rectangle::Get_a()
{
	cout << "int Rectangle::Get_a()" << endl;
	return *a;
}

int Rectangle::Get_b()
{
	cout << "int Rectangle::Get_b()" << endl;
	return *b;
}