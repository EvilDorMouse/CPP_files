#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "CirCylinder.h"
#include "RectCylinder.h"
#include "MyCylinder.h"
#include "Exception.h"

#include <iostream>

using namespace std;

int main()
{
	cout << " -----< 1 > Circle-----" << endl << endl;
	try
	{
		CirCylinder* CirCy = CirCylinder::CreateInstance(5, 10);

		CirCy->Show();

		delete CirCy;
	}
	catch (Exception e)
	{
		e.Show();
	}
	catch(int e)
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
		RectCylinder* RectCy = RectCylinder::CreateInstance(2, -3, 10);

		RectCy->Show();

		delete RectCy;
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
		MyCylinder* TriCy = MyCylinder::CreateInstance(2, 3, -30, 3);

		TriCy->Show();

		delete TriCy;
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
	
	cout << endl << " -----< > End-----" << endl;

	return 0;
}
