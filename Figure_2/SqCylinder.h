#pragma once
class SqCylinder :public Cylinder
{
    double* h;

protected:
    Figure* f;

public:
    SqCylinder(Square* Sa, double h0);
    int GetA();
    ~SqCylinder();
};
