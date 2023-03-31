#pragma once
class Triangle : public Figure
{
	int* a = new int[1];
	int* b = new int[1];
	int* angle = new int[1];

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