#pragma once
class Cylinder
{
	Figure* f;
	double *h;

public:
	Cylinder(Figure* f0, double h0);
	~Cylinder();

	double CalcVolume();
	void Show();
};