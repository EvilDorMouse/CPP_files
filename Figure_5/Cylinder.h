#pragma once
class Cylinder
{
	double *h;

protected:
    Figure* f;

public:
	Cylinder(Figure* f0, double h0);
	~Cylinder();

	double CalcVolume();
	void Show();
};
