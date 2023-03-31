#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "matrio.h"

using namespace std;

//part A

bool InputFileMatrInt(int **M, int n, int m)
{
	ifstream f("input.txt");

	if (!f)
	{
		cout << "Error, there are no file to input matrix" << endl;
		cout << "Input" << endl;
		InputDescMatrInt(M, n, m);
		return false;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!(f >> M[i][j]))
			{
				cout << "Error: not enough data or bed data in the file" << endl;
				f.close();
				cout << "Input" << endl;
				InputDescMatrInt(M, n, m);
				return false;
			}
	f.close();
	return true;
}

void OutputFileMatrInt(int **M, int n, int m)
{
	ofstream f("output.txt");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			f << M[i][j] << " ";
	}
	f << endl;
	f.close();
}

void InputDescMatrInt(int **M, int n, int m)
{
	cout << "\n Piease enter the matrix sized " << n << " x " << m << " :" << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> M[i][j];
	cout << endl;
}

void OutputDescMatrInt(int **M, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout.setf(ios::fixed);
			//cout.precision(3);
			//cout << setw(9) << M[i][j];
			cout << '\t' << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void RandomMatrInt(int** M, int n, int m, int A, int B)
{
	srand(time(0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M[i][j] = rand() % (B - A + 1) + A;
}

//part B

bool InputFileMatrFloat(float** M, int n, int m)
{
	ifstream f("input.txt");

	if (!f)
	{
		cout << "Error, there are no file to input matrix" << endl;
		cout << "Input" << endl;
		InputDescMatrFloat(M, n, m);
		return false;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!(f >> M[i][j]))
			{
				cout << "Error: not enough data or bed data in the file" << endl;
				f.close();
				cout << "Input" << endl;
				InputDescMatrFloat(M, n, m);
				return false;
			}
	f.close();
	return true;
}

void OutputFileMatrFloat(float** M, int n, int m)
{
	ofstream f("output.txt");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			f << M[i][j] << " ";
	}
	f << endl;
	f.close();
}

void InputDescMatrFloat(float** M, int n, int m)
{
	cout << "\n Piease enter the matrix sized " << n << " x " << m << " :" << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> M[i][j];
	cout << endl;
}

void OutputDescMatrFloat(float** M, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout.setf(ios::fixed);
			//cout.precision(3);
			//cout << setw(5) << M[i][j];
			cout << '\t' << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void RandomMatrFloat(float** M, int n, int m, int A, int B)
{
	srand(time(0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M[i][j] = rand() % (B - A + 1) + A;
}