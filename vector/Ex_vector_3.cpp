#include <iostream>
#include "vect.h"

using namespace std;

void Ex_vector_3()
{
	long long num, num_for;
	int n(0);

	cout << "Enter the number in binary notation: ";
	cin >> num;

	Size(num, n);

	double* v = Array(n);

	InputDescVect(v, num);
	cout << "Vector v:\t";
	OutputDescVect(v, n);


	delete[]v; v = NULL;
}