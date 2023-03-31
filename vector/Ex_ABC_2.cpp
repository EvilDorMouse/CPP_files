#include <iostream>
#include "vect.h"
#include "ABC.h"

using namespace std;

void Ex_ABC_2()
{
	int n(0);
	int num(0);
	int k;

	cout << "Enter the size of the array" << endl;
	cin >> n;

	int* v = new int[n];

	IntScreenInput(v, n);
	cout << "Vector v:\t";
	IntOutputDescVect(v, n);

	cout << "A:" << endl;
	cout << "PermFirstMin:" << endl;
	PermFirstMin(v, n);
	cout << "Massive after changing:" << endl;
	IntOutputDescVect(v, n);

	cout << "PermMaxMin:" << endl;
	PermMaxMin(v, n);
	cout << "Massive after changing:" << endl;
	IntOutputDescVect(v, n);

	cout << "B:" << endl;
	cout << "Enter the number of the item you want to rearrange" << endl;
	cin >> k;
	if (k > n)
	{
		cout << "k - incorrect" << endl;
	}
	else
	{
		cout << "PermKthFirst0:" << endl;
		PermKthFirst0(v, n, k);
		cout << "Massive after changing:" << endl;
		IntOutputDescVect(v, n);
	}

	cout << "C:" << endl;
	int* v01 = new int[n];

	cout << "Enter the number = 0 or 1" << endl;

	IntScreenInput(v01, n);
	cout << "Vector v01:\t";
	IntOutputDescVect(v01, n);

	for (int i = 0; i < n; i++)
	{
		if (v01[i] != 0 && v01[i] != 1)
		{
			cout << "v[" << i << "] = " << v01[i] << " - incorrect";
			num++;
		}
	}

	if (num == 0)
		Perm01(v01, n);

	cout << "Massive after changing:" << endl;
	IntOutputDescVect(v01, n);

	delete[]v; v = NULL;
	delete[]v01; v01 = NULL;
}
