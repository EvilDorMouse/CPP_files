#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"
#include "Cylinder.h"
#include "CirCylinder.h"
#include "RectCylinder.h"
#include "MyCylinder.h"
#include "SqCylinder.h"

#include <iostream>

using namespace std;

int main()
{
	cout << endl << " -----< 1 > Circle-----" << endl << endl;

	Circle *c = new Circle;
	CirCylinder* cc = new CirCylinder(c, 2);

	cc->Show();
	cout << "V = " << cc->CalcVolume() << endl;

	cout << endl << " -----< 2 > Rectangle-----" << endl << endl;

	Rectangle* r = new Rectangle;
	RectCylinder* cr = new RectCylinder(r, 4);

	cr->Show();
	cout << "V = " << cr->CalcVolume() << endl;

	cout << endl << " -----< 3 > Triangle-----" << endl << endl;
	
	Triangle* t = new Triangle;
	MyCylinder* ct = new MyCylinder(t, 3);

	ct->Show();
	cout << "V = " << ct->CalcVolume() << endl;

	cout << endl << " -----< 4 > Square-----" << endl << endl;

	Square* s = new Square;
	SqCylinder* cs = new SqCylinder(s, 6);

	cs->Show();
	cout << "V = " << cs->CalcVolume() << endl;
	
	cout << endl << " -----< > End-----" << endl;

	return 0;
}
