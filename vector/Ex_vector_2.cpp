#include <iostream>
#include "vect.h"

using namespace std;

void Ex_vector_2()
{
	long long num, num_for;
	int n(0);

	cout << "Enter the number in binary notation: ";
	cin >> num;
	num_for = num;

	while (num_for != 0)
	{
		if (num_for % 10 == 0)
			n++;

		num_for = num_for / 10;
	}

	double* v = new double[n];

	InputDescVect(v, num);
	cout << "Vector v:\t";
	OutputDescVect(v, n);

	delete[]v; v = NULL;
}