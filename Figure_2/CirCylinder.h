#pragma once
class CirCylinder:public Cylinder
{
    double* h;

protected:
    Figure* f;
   
public:
    CirCylinder(Circle* c, double h0);
    int GetRadius();
    ~CirCylinder();
};


