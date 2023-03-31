#pragma once
class Triangle : public Figure
{
	int* a = new int;
	int* b = new int;
	int* angle = new int;

public:
	Triangle();
	Triangle(int a0, int b0, int angle0);
	virtual ~Triangle();

	virtual void Show();
	virtual double CalcArea();

	virtual Figure* Copy();

	int Get_Ta();
	int Get_Tb();
	int Get_angle();
};