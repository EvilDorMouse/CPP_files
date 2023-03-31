#pragma once
class CirCylinder:public Cylinder
{
    CirCylinder(Circle* c, double h);
public:
    static CirCylinder* CreateInstance(int r, double h);
    int GetRadius();
    ~CirCylinder();
};


