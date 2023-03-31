#include "Figure.h"
#include "Circle.h"
#include "Cylinder.h"
#include "CirCylinder.h"

#include <iostream>

using namespace std;

CirCylinder::CirCylinder(Circle* c, double h):Cylinder(c,h)
{
    cout << "CirCylinder::CirCylinder(Circle* c, double h):Cylinder(c,h)" << endl;

}

CirCylinder* CirCylinder::CreateInstance(int r, double h)
{
    cout << "CirCylinder* CirCylinder::CreateInstance(int r, double h)" << endl;

    Circle *c = new Circle(r);
    CirCylinder* Cy = new CirCylinder(c, h);
    delete c;
    return Cy;
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
