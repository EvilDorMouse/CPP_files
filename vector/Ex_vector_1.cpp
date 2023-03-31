#include <iostream>
#include <fstream>
#include "vect.h"

using namespace std;

char menu(char Num);

void Ex_vector_1()
{
	int n(0);
	char ItemNum(0);
	int MinNum(0), MaxNum(100);

	while (n <= 0)
	{
		cout << "Enter the length of the vector: ";
		cin >> n;
		cout << endl;
	}

	double* v = new double[n];

	ItemNum = menu(ItemNum);

	switch (ItemNum)
	{
	case '1':

		ScreenInput(v, n);
		cout << "Vector v:\t";
		OutputDescVect(v, n);

		break;

	case '2':

		InputFile(v, n);

		if (!InputFile(v, n))
		{
			cout << "Error";
		}
		else
		{
			cout << "Vector v:\t";
			OutputDescVect(v, n);
		}

		break;

	case '3':

		cout << "Enter min and max:\n";
		cout << "min = ";
		cin >> MinNum;
		cout << "\nmax = ";
		cin >> MaxNum;
		cout << endl;

		RandomNumbers(v, n, MinNum, MaxNum);

		cout << "Vector v:\t";
		OutputDescVect(v, n);
		break;

	default:
		break;
	}

	if ((ItemNum == '1') || (ItemNum == '2') || (ItemNum == '3'))
	{
		ofstream file("result.txt", ios::app);

		file << "v[" << n << "]\n";

		for (int i = 0; i < n; i++)
			file << v[i] << " ";

		file << "\n";
		file.close();
	}

	delete[]v; v = NULL;

}

char menu(char Num)
{
	while ((Num != '1') && (Num != '2') && (Num != '3'))
	{
		//Выводим список пунктов меню
		cout << "How to fill an array?\n";
		cout << "1. Screen input\n";
		cout << "2. Input from a file\n";
		cout << "3. Filling in random numbers\n";
		cout << "->";
		cin >> Num; //Запрашиваем на ввод пункт меню
		if ((Num != '1') && (Num != '2') && (Num != '3'))
		{
			cout << "Ups, invalid input\n";
		}
	}
	return Num;
}