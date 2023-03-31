#include "Figure.h"
#include "Square.h"
#include "Cylinder.h"
#include "SqCylinder.h"

#include <iostream>

using namespace std;

SqCylinder::SqCylinder(Square* Sa, double h0) :Cylinder(Sa, h0)
{
    cout << "SqCylinder::SqCylinder(Square* Sa, double h) :Cylinder(Sa, h)" << endl;

    f = Sa->Copy();
    h = new double;
    *h = h0;
}

int SqCylinder::GetA()
{
    Square* Sa = dynamic_cast<Square*>(f);
    return Sa->Get_Sa();
}

SqCylinder::~SqCylinder()
{
    cout << "SqCylinder::~SqCylinder()" << endl;
}
