#pragma once
class Circle : public Figure
{
	int* r = new int;

public:
	Circle();
	Circle(int r0);
	virtual ~Circle();

	virtual void Show();
	virtual double CalcArea();

	virtual Figure* Copy();

	int Get_r();
};