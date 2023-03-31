#pragma once
class Rectangle : public Figure
{
	int* a = new int [1];
	int * b = new int [1];

public:
	Rectangle();
	Rectangle(int a0, int b0);
	virtual ~Rectangle();

	virtual void Show();
	virtual double CalcArea();
	virtual Figure* Copy();

	int Get_a();
	int Get_b();
};