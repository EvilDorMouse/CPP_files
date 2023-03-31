#include "Figure.h"
#include "Triangle.h"
#include "Exception.h"

#include <iostream>

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

	if (a0 <= 0 && b0 > 0 && angle0 > 0)
	{
		char str[] = "--> Error: triangle side a <= 0";
		throw Exception(5, str);
		delete[] str;
	}
	else if (b0 <= 0 && a0 > 0 && angle0 > 0)
	{
		char str[] = "--> Error: triangle side b <= 0";
		throw Exception(6, str);
		delete[] str;
	}
	else if (angle0 <= 0 && b0 > 0 && a0 > 0)
	{
		char str[] = "--> Error: triangle angle <= 0";
		throw Exception(7, str);
		delete[] str;
	}
	else if (a0 <= 0 && b0 <= 0 && angle0 > 0)
	{
		char str[] = "--> Error: triangle side a, b <= 0";
		throw Exception(8, str);
		delete[] str;
	}
	else if (a0 <= 0 && angle0 <= 0 && b0 > 0)
	{
		char str[] = "--> Error: triangle side a and angle <= 0";
		throw Exception(9, str);
		delete[] str;
	}
	else if (b0 <= 0 && angle0 <= 0 && a0 > 0)
	{
		char str[] = "--> Error: triangle side b and angle <= 0";
		throw Exception(10, str);
		delete[] str;
	}
	else if (b0 <= 0 && angle0 <= 0 && a0 <= 0)
	{
		char str[] = "--> Error: triangle side a, b and angle <= 0";
		throw Exception(11, str);
		delete[] str;
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