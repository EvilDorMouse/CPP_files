#include <iostream>
#include <time.h>

#include "vect.h"
#include "sort.h"

using namespace std;

void Random(double* v, int n, int MinNum, int MaxNum);

void Ex_sort()
{
	int n;
	int MinNum(-10), MaxNum(10);
	// часть ј
	do
	{
		cout << "Enter massive size n > 0 (int), n = ";
		cin >> n;
	} while (n <= 0);

	double* v = new double[n];

	cout << "A:" << endl;
	Random(v, n, MinNum, MaxNum);
	cout << "Vector v:" << endl;
	OutputDescVect(v, n);

	cout << "SelectSort:" << endl;
	SelectSort(v, n);
	cout << "Vector v:" << endl;
	OutputDescVect(v, n);

	Random(v, n, MinNum, MaxNum);
	cout << "Vector v:" << endl;
	OutputDescVect(v, n);

	cout << "InsertSort:" << endl;
	InsertSort(v, n);
	cout << "Vector v:" << endl;
	OutputDescVect(v, n);

	delete[] v; v = NULL;

	// часть ¬

	cout << "B:" << endl;

	// сортировка пузырьком
	n = 10;
	double* v10 = new double[n];

	cout << "BubbleSortAsc for n = 10:" << endl;

	for (int i = 0; i < n; i++)
		v10[i] = double(n - i);

	cout << "Vector v10:" << endl;
	OutputDescVect(v10, n);

	BubbleSortAsc(v10, n);
	cout << "Vector v10:" << endl;
	OutputDescVect(v10, n);

	delete[] v10; v10 = NULL;

	n = 100;
	double* v100 = new double[n];

	cout << "BubbleSortAsc for n = 100:" << endl;

	for (int i = 0; i < n; i++)
		v100[i] = double(n - i);

	BubbleSortAsc(v100, n);

	delete[] v100; v100 = NULL;

	n = 1000;
	double* v1000 = new double[n];

	cout << "BubbleSortAsc for n = 1000:" << endl;

	for (int i = 0; i < n; i++)
		v1000[i] = double(n - i);

	BubbleSortAsc(v1000, n);

	delete[] v1000; v1000 = NULL;


	n = 10;
	double* vr10 = new double[n];

	cout << "(Rand)BubbleSortAsc for n = 10:" << endl;

	Random(vr10, n, MinNum, MaxNum);

	cout << "Vector vr10:" << endl;
	OutputDescVect(vr10, n);

	BubbleSortAsc(vr10, n);
	cout << "Vector vr10:" << endl;
	OutputDescVect(vr10, n);

	delete[] vr10; vr10 = NULL;

	n = 100;
	double* vr100 = new double[n];

	cout << "(Rand)BubbleSortAsc for n = 100:" << endl;

	Random(vr100, n, MinNum, MaxNum);

	BubbleSortAsc(vr100, n);

	delete[] vr100; vr100 = NULL;

	n = 1000;
	double* vr1000 = new double[n];

	cout << "(Rand)BubbleSortAsc for n = 1000:" << endl;

	Random(vr1000, n, MinNum, MaxNum);

	BubbleSortAsc(vr1000, n);

	delete[] vr1000; vr1000 = NULL;


	// сортировка методом выбора
	n = 10;
	double* h10 = new double[n];

	cout << "SelectSort for n = 10:" << endl;

	for (int i = 0; i < n; i++)
		h10[i] = double(n - i);

	cout << "Vector v10:" << endl;
	OutputDescVect(h10, n);

	SelectSort(h10, n);
	cout << "Vector v10:" << endl;
	OutputDescVect(h10, n);

	delete[] h10; h10 = NULL;

	n = 100;
	double* h100 = new double[n];

	cout << "SelectSort for n = 100:" << endl;

	for (int i = 0; i < n; i++)
		h100[i] = double(n - i);

	SelectSort(h100, n);

	delete[] h100; h100 = NULL;

	n = 1000;
	double* h1000 = new double[n];

	cout << "SelectSort for n = 1000:" << endl;

	for (int i = 0; i < n; i++)
		h1000[i] = double(n - i);

	SelectSort(h1000, n);

	delete[] h1000; h1000 = NULL;


	n = 10;
	double* hr10 = new double[n];

	cout << "(Rand)SelectSort for n = 10:" << endl;

	Random(hr10, n, MinNum, MaxNum);

	cout << "Vector vr10:" << endl;
	OutputDescVect(hr10, n);

	SelectSort(hr10, n);
	cout << "Vector vr10:" << endl;
	OutputDescVect(hr10, n);

	delete[] hr10; hr10 = NULL;

	n = 100;
	double* hr100 = new double[n];

	cout << "(Rand)SelectSort for n = 100:" << endl;

	Random(hr100, n, MinNum, MaxNum);

	SelectSort(hr100, n);

	delete[] hr100; hr100 = NULL;

	n = 1000;
	double* hr1000 = new double[n];

	cout << "(Rand)SelectSort for n = 1000:" << endl;

	Random(hr1000, n, MinNum, MaxNum);

	SelectSort(hr1000, n);

	delete[] hr1000; hr1000 = NULL;


	// сортировка методом всавки
	n = 10;
	double* c10 = new double[n];

	cout << "InsertSort for n = 10:" << endl;

	for (int i = 0; i < n; i++)
		c10[i] = double(n - i);

	cout << "Vector v10:" << endl;
	OutputDescVect(c10, n);

	InsertSort(c10, n);
	cout << "Vector v10:" << endl;
	OutputDescVect(c10, n);

	delete[] c10; c10 = NULL;

	n = 100;
	double* c100 = new double[n];

	cout << "InsertSort for n = 100:" << endl;

	for (int i = 0; i < n; i++)
		c100[i] = double(n - i);

	InsertSort(c100, n);

	delete[] c100; c100 = NULL;

	n = 1000;
	double* c1000 = new double[n];

	cout << "InsertSort for n = 1000:" << endl;

	for (int i = 0; i < n; i++)
		c1000[i] = double(n - i);

	InsertSort(c1000, n);

	delete[] c1000; c1000 = NULL;


	n = 10;
	double* cr10 = new double[n];

	cout << "(Rand)InsertSort for n = 10:" << endl;

	Random(cr10, n, MinNum, MaxNum);

	cout << "Vector vr10:" << endl;
	OutputDescVect(cr10, n);

	InsertSort(cr10, n);
	cout << "Vector vr10:" << endl;
	OutputDescVect(cr10, n);

	delete[] cr10; cr10 = NULL;

	n = 100;
	double* cr100 = new double[n];

	cout << "(Rand)InsertSort for n = 100:" << endl;

	Random(cr100, n, MinNum, MaxNum);

	InsertSort(cr100, n);

	delete[] cr100; cr100 = NULL;

	n = 1000;
	double* cr1000 = new double[n];

	cout << "(Rand)InsertSort for n = 1000:" << endl;

	Random(cr1000, n, MinNum, MaxNum);

	InsertSort(cr1000, n);

	delete[] cr1000; cr1000 = NULL;
}

void Random(double* v, int n, int MinNum, int MaxNum)
{
	int i;

	srand(time(0));

	for (i = 0; i < n; i++)
	{
		v[i] = double(rand() * (MaxNum - MinNum) / RAND_MAX + MinNum);
		cout << endl;
	}
}