#include "Figure.h"
#include "Triangle.h"
#include "Exception.h"

#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle()
{
	cout << "Triangle::Triangle()" << endl;
	*a = 1;
	*b = 1;
	*angle = 10;
}

Triangle::Triangle(int a0, int b0, int angle0)
{
	cout << "Triangle::Triangle(int r0)" << endl;

	if (a0 <= 0 || b0 <= 0 || angle0 <= 0)
	{
		char str[] = "--> Error: triangle side a or b or angle <= 0";
		throw Exception(3, str);
	}

	*a = a0;
	*b = b0;
	*angle = angle0;
}

Triangle::~Triangle()
{
	cout << "Triangle::~Triangle()" << endl;
	delete[]a;
	delete[]b;
	delete[]angle;
}

void Triangle::Show()
{
	cout << "-----Triangle::Show-----" << endl;
	cout << "\ta = " << *a << endl;
	cout << "\tb = " << *b << endl;
	cout << "\tangle = " << *angle << endl;
}

double Triangle::CalcArea()
{
	return double(1 / 2) * *a * *b * sin(double(*angle) * 3.14 / 180);
}

Figure* Triangle::Copy()
{
	cout << "Figure* Triangle::Copy()" << endl;

	Figure* tri = new Triangle(*a, *b, *angle);
	return tri;
}

int Triangle::Get_Ta()
{
	cout << "int Triangle::Get_a()" << endl;
	return *a;
}

int Triangle::Get_Tb()
{
	cout << "int Triangle::Get_b()" << endl;
	return *b;
}

int Triangle::Get_angle()
{
	cout << "int Triangle::Get_angle()" << endl;
	return *angle;
}
