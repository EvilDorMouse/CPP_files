#pragma once
class MyCylinder:public Cylinder
{
    double* h;

protected:
    Figure* f;

public:
    MyCylinder(Triangle* t, double h0);
    int GetABangle();
    ~MyCylinder();
};
