#include "Figure.h"
#include "Rectangle.h"
#include "Cylinder.h"
#include "RectCylinder.h"

#include <iostream>

using namespace std;

RectCylinder::RectCylinder(Rectangle* Ra, double h):Cylinder(Ra, h)
{
    cout << "RectCylinder::RectCylinder(Rectangle* Ra, double h):Cylinder(Ra, h)" << endl;
}

RectCylinder* RectCylinder::CreateInstance(int a, int b, double h)
{
    cout << "RectCylinder* RectCylinder::CreateInstance(int a, int b, double h)" << endl;

    Rectangle *Ra = new Rectangle(a, b);
    RectCylinder* Cy = new RectCylinder(Ra, h);
    delete Ra;
    return Cy;
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
