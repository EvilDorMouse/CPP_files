#pragma once
class RectCylinder:public Cylinder
{
    RectCylinder(Rectangle* Ra, double h);

public:
    static RectCylinder* CreateInstance(int a, int b, double h);
    int GetAB();
    ~RectCylinder();
};
