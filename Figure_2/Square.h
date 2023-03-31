#pragma once
class Square : public Figure
{
	int* a = new int;

public:
	Square();
	Square(int a0);
	virtual ~Square();

	virtual void Show();
	virtual double CalcArea();

	virtual Figure* Copy();

	int Get_Sa();
};