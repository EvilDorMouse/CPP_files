#include "Figure.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "MyCylinder.h"

#include <iostream>

using namespace std;

MyCylinder::MyCylinder(Triangle* t, double h):Cylinder(t, h)
{
    cout << "MyCylinder::MyCylinder(Triangle* t, double h):Cylinder(t, h)" << endl;
}

MyCylinder* MyCylinder::CreateInstance(int a, int b, int angle, double h)
{
    cout << "MyCylinder* MyCylinder::CreateInstance(int a, int b, int angle, double h)" << endl;

    Triangle *t = new Triangle(a, b, angle);
    MyCylinder* Cy = new MyCylinder(t,h);
    delete t;
    return Cy;
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
