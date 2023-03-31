#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Cylinder.h"

#include <iostream>

using namespace std;

int main()
{
	int k;
	Figure* f;

	cout << "-----Figure-----" << endl;

	do
	{
		cout << "Enter figure type:" << endl;
		cout << "\t< 1 > Circle" << endl;
		cout << "\t< 2 > Rectangle" << endl;
		cout << endl;

		cin >> k;
		if (k != 1 && k != 2)
			cout << "< ! > Bad choice, press 1 or 2" << endl;

	} while (k != 1 && k != 2);

	switch (k)
	{
	case 1:
		f = new Circle(5);
		break;
	case 2:
		f = new Rectangle(5, 10);
		break;
	default: cout << "< ! > Error, unknown object" << endl;
	}

	f->Show();
	cout << "S = " << f->CalcArea() << endl;

	cout << endl << "-----Cylinder-----" << endl;

	Cylinder* cyl = new Cylinder(f, 10);
	f->Show();
	cout << "V = " << cyl->CalcVolume() << endl;
	delete cyl;

	cout << endl << "----------" << endl;

	delete f;

	return 0;
}