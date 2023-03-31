#pragma once
class MyCylinder:public Cylinder
{
    MyCylinder(Triangle* t, double h);
public:
    static MyCylinder* CreateInstance(int a, int b, int angle, double h);
    int GetABangle();
    ~MyCylinder();
};
