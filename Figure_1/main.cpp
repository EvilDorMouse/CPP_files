#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include <iostream>

using namespace std;

int main()
{
	cout << " -----< 1 > Circle-----" << endl << endl;
	Circle c;
	c.Get_r();
	c.Show();
	c.CalcArea();

	cout << endl << " -----< 2 > Rectangle-----" << endl << endl;

	Rectangle re;
	re.Get_Ra();
	re.Get_Rb();
	re.Show();
	re.CalcArea();

	cout << endl << " -----< 3 > Triangle-----" << endl << endl;

	Triangle t;
	t.Get_Ta();
	t.Get_Tb();
	t.Show();
	t.CalcArea();

	cout << endl << " -----< > End-----" << endl;

	return 0;
}