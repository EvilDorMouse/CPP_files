#pragma once
class Figure
{
public:
	Figure();
	virtual ~Figure();

	virtual void Show() = 0;
	virtual double CalcArea() = 0;
	virtual Figure* Copy() = 0;
};
