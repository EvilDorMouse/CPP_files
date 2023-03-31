#include "Cylinder.h"
#include "Figure.h"

#include <iostream>

using namespace std;

Cylinder::Cylinder(Figure* f0, double h0)
{
	cout << "Cylinder::Cylinder(Figure* f0, double h0)" << endl;
	f = f0->Copy();
	h = new double;
	*h = h0;
}

Cylinder::~Cylinder()
{
	cout << "Cylinder::~Cylinder()";
	delete f;
	delete h;
}

double Cylinder::CalcVolume()
{
	return f->CalcArea() * *h;
}

void Cylinder::Show()
{
	cout << "-----Cylinder::Show-----" << endl;
	cout << "\th = " << *h << endl;
	cout << "\tBase info:" << endl;
	f->Show();
}