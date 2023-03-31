#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Size(long long num, int& n)
{

	while (num != 0)
	{
		if (num % 10 == 0)
			n++;

		num = num / 10;
	}

}

double* Array(int& n)
{
	return new double[n];
}


void InputDescVect(double* v, int num)
{
	int i(0), r(0);

	while (num != 0)
	{
		if (num % 10 == 0)
		{
			v[i] = r;
			i++;
		}

		num = num / 10;
		r++;
	}
}

void ScreenInput(double* v, int n)
{
	cout << "\n Piease enter the vector (double) sized " << n << ":" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "< " << i << " >";
		cin >> v[i];
		cout << endl;
	}
}

void IntScreenInput(int* v, int n)
{
	cout << "\n Piease enter the vector (int) sized " << n << ":" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "< " << i << " >";
		cin >> v[i];
		cout << endl;
	}
}

bool InputFile(double* v, int n)
{
	ifstream file("vect.txt");

	if (!file) return false;

	for (int i = 0; i < n; i++)
		file >> v[i];

	file.close();
	return true;
}

void RandomNumbers(double* v, int n, int MinNum, int MaxNum)
{
	srand(time(0));

	for (int i = 0; i < n; i++)
	{

		v[i] = double(rand() * (MaxNum - MinNum) / RAND_MAX) + MinNum;
		cout << endl;
	}
}

void OutputDescVect(double* v, int n)
{
	/*
		cout.setf(ios::fixed);
		cout.precision(2);

		for (int i = 0; i < n; i++)
			cout << setw(5) << v[i];
	*/

	for (int i = 0; i < n; i++)
		cout << ' ' << v[i];

	cout << endl << endl;
}

void IntOutputDescVect(int* v, int n)
{
	for (int i = 0; i < n; i++)
		cout << ' ' << v[i];

	cout << endl << endl;
}