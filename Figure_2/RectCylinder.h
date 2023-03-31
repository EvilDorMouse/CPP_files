#pragma once
class RectCylinder:public Cylinder
{
    double* h;

protected:
    Figure* f;

public:
    RectCylinder(Rectangle* Ra, double h0);
    int GetAB();
    ~RectCylinder();
};
