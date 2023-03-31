#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "Exception.h"

#include <iostream>

using namespace std;

int main()
{
	Figure* t = new Triangle(1, 2, 60);

	cout << " -----< 1 > Circle-----" << endl << endl;
	try
	{
		Circle *c = new Circle(-8);
		c->Get_r();
		c->Show();
		c->CalcArea();
	}
	catch (Exception e)
	{
		e.Show();
	}
	catch (int e)
	{
		cout << "Some int error: " << e << endl;
	}
	catch (...)
	{
		cout << "---> I catch something..." << endl;
	}
	

	cout << endl << " -----< 2 > Rectangle-----" << endl << endl;

	try
	{
		Rectangle *re = new Rectangle (-5, 7);
		re->Get_Ra();
		re->Get_Rb();
		re->Show();
		re->CalcArea();
	}
	catch (Exception e)
	{
		e.Show();
	}
	catch (int e)
	{
		cout << "Some int error: " << e << endl;
	}
	catch (...)
	{
		cout << "---> I catch something..." << endl;
	}

	cout << endl << " -----< 3 > Triangle-----" << endl << endl;

	try
	{
		Triangle* t0 = new Triangle (6, -9, -30);
		
		t0->Show();
		t0->CalcArea();
	}
	catch (Exception e)
	{
		e.Show();
	}
	catch (int e)
	{
		cout << "Some int error: " << e << endl;
	}
	catch (...)
	{
		cout << "---> I catch something..." << endl;
	}

	cout << endl << " -----< 4 > Cylinder-----" << endl << endl;

	try
	{
		Cylinder* cy = new Cylinder(t, -3);

		cy->Show();
		cy->CalcVolume();
	}
	catch (int e)
	{
		cout << "Some int error: " << e << endl;
	}
	catch (...)
	{
		cout << "---> I catch something..." << endl;
	}

	cout << endl << " -----< > End-----" << endl;

	return 0;
}