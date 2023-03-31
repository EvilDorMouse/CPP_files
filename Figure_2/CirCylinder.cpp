#include "Figure.h"
#include "Circle.h"
#include "Cylinder.h"
#include "CirCylinder.h"

#include <iostream>

using namespace std;

CirCylinder::CirCylinder(Circle* c, double h0):Cylinder(c,h0)
{
    cout << "CirCylinder::CirCylinder(Circle* c, double h):Cylinder(c,h)" << endl;

    f = c->Copy();
    h = new double;
    *h = h0;
}

CirCylinder::~CirCylinder()
{
    cout << "CirCylinder::~CirCylinder()" << endl;
}

int CirCylinder::GetRadius()
{
    Circle * c = dynamic_cast<Circle*>(f);
    return c->Get_r();
}
