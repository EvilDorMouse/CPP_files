#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "CirCylinder.h"
#include "RectCylinder.h"
#include "MyCylinder.h"

#include <iostream>

using namespace std;

int main()
{
	cout << endl << " -----< 1 > Circle-----" << endl << endl;

		CirCylinder* CirCy = CirCylinder::CreateInstance(5, 10);

		CirCy->Show();
		cout << "V = " << CirCy->CalcVolume() << endl;

		delete CirCy;
	
	cout << endl << " -----< 2 > Rectangle-----" << endl << endl;

		RectCylinder* RectCy = RectCylinder::CreateInstance(2, 3, 10);

		RectCy->Show();

		cout << "V = " << RectCy->CalcVolume() << endl;

		delete RectCy;

	cout << endl << " -----< 3 > Triangle-----" << endl << endl;
	
		MyCylinder* TriCy = MyCylinder::CreateInstance(4, 3, 30, 5);

		TriCy->Show();

		cout << "V = " << TriCy->CalcVolume() << endl;

		delete TriCy;
	
	cout << endl << " -----< > End-----" << endl;

	return 0;
}
