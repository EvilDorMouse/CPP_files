#include <iostream>
#include "matrio.h"

//#define n 5
//#define m 4

int** MemoryAllInt(int n, int m);
void MemoryDelInt(int** a, int n);
float** MemoryAllFloat(int n, int m);
void MemoryDelFloat(float** a, int n);


using namespace std;

void Ex_matrio()
{
	// part A
	int A = 0, B = 0;
	int nA(0), mA(0);
	int menuA(0);
	int** a;

	cout << "A:" << endl;

	if (nA <= 0 or mA <= 0)
	{
		cout << "Enter the size of int massive n*m(n, m > 0):" << endl;
		cin >> nA;
		cin >> mA;
	}

	a = MemoryAllInt(nA, mA);

	cout << "------Input Menu------" << endl;
	cout << "1. Screen input" << endl;
	cout << "2. File input" << endl;
	cout << "3. Random input" << endl;
	cin >> menuA;

	switch (menuA)
	{
	case 1:
		InputDescMatrInt(a, nA, mA);
		break;
	case 2:
		InputFileMatrInt(a, nA, mA);
		break;
	case 3:
		cout << "Enter the extreme values:" << endl;
		cin >> A;
		cin >> B;
		RandomMatrInt(a, nA, mA, A, B);
		break;
	default:
		cout << "Error" << endl;
		break;
	}

	OutputDescMatrInt(a, nA, mA);
	OutputFileMatrInt(a, nA, mA);

	MemoryDelInt(a, nA);

	//part B
	int nB(0), mB(0);
	int menuB(0);
	A = 0, B = 0;
	float** b;

	cout << "B:" << endl;

	if (nB <= 0 or mB <= 0)
	{
		cout << "Enter the size of float massive n*m(n, m > 0):" << endl;
		cin >> nB;
		cin >> mB;
	}

	b = MemoryAllFloat(nB, mB);

	cout << "------Input Menu------" << endl;
	cout << "1. Screen input" << endl;
	cout << "2. File input" << endl;
	cout << "3. Random input" << endl;
	cin >> menuB;

	switch (menuB)
	{
	case 1:
		InputDescMatrFloat(b, nB, mB);
		break;
	case 2:
		InputFileMatrFloat(b, nB, mB);
		break;
	case 3:
		cout << "Enter the extreme values:" << endl;
		cin >> A;
		cin >> B;
		RandomMatrFloat(b, nB, mB, A, B);
		break;
	default:
		cout << "Error" << endl;
		break;
	}

	OutputDescMatrFloat(b, nB, mB);
	OutputFileMatrFloat(b, nB, mB);

	MemoryDelFloat(b, nB);
}

int** MemoryAllInt(int n, int m)
{
	int** a = new int* [n];

	for (int i = 0; i < n; i++)
		a[i] = new int[m];

	return a;
}

void MemoryDelInt(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	a = NULL;
}

float** MemoryAllFloat(int n, int m)
{
	float** a = new float* [n];

	for (int i = 0; i < n; i++)
		a[i] = new float[m];

	return a;
}

void MemoryDelFloat(float** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	a = NULL;
}