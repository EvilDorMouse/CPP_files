#pragma once
class Rectangle : public Figure
{
	int* a = new int;
	int* b = new int;

public:
	Rectangle();
	Rectangle(int a0, int b0);
	virtual ~Rectangle();

	virtual void Show();
	virtual double CalcArea();

	virtual Figure* Copy();

	int Get_Ra();
	int Get_Rb();
};