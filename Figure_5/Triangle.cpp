#include "Figure.h"
#include "Triangle.h"

#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle()
{
	cout << "Triangle::Triangle()" << endl;
	*a = 1;
	*b = 1;
	*angle = 30;
}

Triangle::Triangle(int a0, int b0, int angle0)
{
	cout << "Triangle::Triangle(int r0)" << endl;

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
	return 0.5 * *a * *b * sin(double(*angle) * 3.14 / 180);
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
