#include <iostream>
#include "vect.h"
#include "ABC.h"

using namespace std;

void Ex_ABC_1()
{
	int n(0);
	int num(0);

	cout << "Input syze vect: ";
	cin >> n;
	cout << endl << endl;

	int* v1 = new int[n];

	IntScreenInput(v1, n);
	cout << "Vector v1:\t";
	IntOutputDescVect(v1, n);

	cout << "A:" << endl;
	GetMaxNegative(v1, n, num);
	if (v1[num] < 0)
		cout << "MaxNegative: v1[" << num + 1 << "] = " << v1[num] << endl;
	else
		cout << "No negative numbers" << endl;

	GetMinPositive(v1, n, num);
	if (v1[num] > 0)
		cout << "MinPositive: v1[" << num + 1 << "] = " << v1[num] << endl;
	else
		cout << "No positive numbers" << endl;

	cout << "B:" << endl;
	SumFirstMin(v1, n);

	cout << "C:" << endl;
	Sum_MaxPositive_MinNegative(v1, n);

	delete[]v1; v1 = NULL;
}
