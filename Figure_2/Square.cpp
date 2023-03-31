#include "Figure.h"
#include "Square.h"

#include <iostream>

using namespace std;

Square::Square()
{
	cout << "Square::Square()" << endl;
	*a = 1;
}

Square::Square(int a0)
{
	cout << "Square::Square(int a0)" << endl;

	*a = a0;
}

Square::~Square()
{
	cout << "Square::~Square()" << endl;
	delete[]a;
}

void Square::Show()
{
	cout << "-----Square::Show-----" << endl;
	cout << "\ta = " << *a << endl;
}

double Square::CalcArea()
{
	return *a * *a;
}

Figure* Square::Copy()
{
	cout << "Figure* Rectangle::Copy()" << endl;
	Figure* rec = new Square(*a);
	return rec;
}

int Square::Get_Sa()
{
	cout << "int Square::Get_Sa()" << endl;
	return *a;
}