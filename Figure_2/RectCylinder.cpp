#include "Figure.h"
#include "Rectangle.h"
#include "Cylinder.h"
#include "RectCylinder.h"

#include <iostream>

using namespace std;

RectCylinder::RectCylinder(Rectangle* Ra, double h0):Cylinder(Ra, h0)
{
    cout << "RectCylinder::RectCylinder(Rectangle* Ra, double h):Cylinder(Ra, h)" << endl;

    f = Ra->Copy();
    h = new double;
    *h = h0;
}

int RectCylinder::GetAB()
{
    Rectangle * Ra = dynamic_cast<Rectangle*>(f);
    return Ra->Get_Ra();
    return Ra->Get_Rb();

}

RectCylinder::~RectCylinder()
{
    cout << "RectCylinder::~RectCylinder()" << endl;
}
