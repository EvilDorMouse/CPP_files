#pragma once
class Circle : public Figure
{
	int* r = new int [1];

public:
	Circle();
	Circle(int r0);
	virtual ~Circle();

	virtual void Show();
	virtual double CalcArea();
	virtual Figure* Copy();

	int Get_r();
};