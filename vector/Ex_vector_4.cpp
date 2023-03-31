#include <iostream>
#include "vect.h"
#include "calc_vect.h"

using namespace std;

void Ex_vector_4()
{
	int n = 3;
	double res(0);

	double* v1 = new double[n];
	double* v2 = new double[n];
	double* v3 = new double[n];

	ScreenInput(v1, n);
	ScreenInput(v2, n);

	cout << "Vector v1:\t";
	OutputDescVect(v1, n);

	cout << "Vector v2:\t";
	OutputDescVect(v2, n);

	cout << "\n------------------------------------\n";

	res = ScalarProduct(v1, v2, n);
	cout << "Result of ScalarProduct:\t" << res << endl;

	cout << "\n------------------------------------\n";

	ScreenInput(v3, n);

	cout << "Vector v3:\t";
	OutputDescVect(v3, n);

	cout << "\n------------------------------------\n";

	MixedProduct(v1, v2, v3, n, &res);
	cout << "Result of MixedProduct:\t" << res << endl;

	cout << "\n------------------------------------\n";

	int l;
	cout << "Enter the length of the vector: ";
	cin >> l;

	double* v4 = new double[l];

	ScreenInput(v4, l);

	cout << "Vector v4:\t";
	OutputDescVect(v4, l);

	cout << "\n------------------------------------\n";

	res = 0;
	res = Length(v4, l);
	cout << "Result of Length: " << res << endl;

	cout << "\n------------------------------------\n";

	cout << "Enter the length of the vector: ";
	cin >> l;

	double* v5 = new double[l];
	double* v6 = new double[l];

	ScreenInput(v5, l);
	ScreenInput(v6, l);

	cout << "Vector v5:\t";
	OutputDescVect(v5, l);

	cout << "Vector v6:\t";
	OutputDescVect(v6, l);

	cout << "\n------------------------------------\n";

	double angle(0), cosAngle(0);

	cosAngle = CosAngle(v5, v6, l, angle);
	cout << "Result of CosAngle:\n";
	cout << "cos(A) = " << cosAngle << endl;
	cout << "Angle = " << angle << endl;


	delete[]v1; v1 = NULL;
	delete[]v2; v2 = NULL;
	delete[]v3; v3 = NULL;
	delete[]v4; v4 = NULL;
	delete[]v5; v5 = NULL;
	delete[]v6; v6 = NULL;
}