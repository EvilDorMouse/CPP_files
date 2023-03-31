#include "Figure.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "MyCylinder.h"

#include <iostream>

using namespace std;

MyCylinder::MyCylinder(Triangle* t, double h0):Cylinder(t, h0)
{
    cout << "MyCylinder::MyCylinder(Triangle* t, double h):Cylinder(t, h)" << endl;

    f = t->Copy();
    h = new double;
    *h = h0;
}

int MyCylinder::GetABangle()
{
    Triangle * t = dynamic_cast<Triangle*>(f);
    return t->Get_Ta(), t->Get_Tb(), t->Get_angle();

}

MyCylinder::~MyCylinder()
{
    cout << "MyCylinder::~MyCylinder()" << endl;
}
