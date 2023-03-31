#pragma once

#include <iostream>

using namespace std;

class Barbershop
{
	int* AmountOfWorkers = new int[2];
	int* NumberOfHaircuts = new int[3];
	double* Price = new double[3];
	char Title[30];


public:

	//Amount Of Workers
	void setAmountOfWorkers(int* n)
	{
		cout << "setAmountOfWorkers(int* n)" << endl << endl;
		InitNumb_int(&AmountOfWorkers[0], n[0]);
		InitNumb_int(&AmountOfWorkers[1], n[1]);
	}

	void getAmountOfWorkers()
	{
		cout << "getAmountOfWorkers()" << endl;
		cout << AmountOfWorkers[0] << endl;
		cout << AmountOfWorkers[1] << endl << endl;
	}

	//Number Of Haircuts
	void setNumberOfHaircuts(int* n)
	{
		cout << "setNumberOfHaircuts(int* n)" << endl << endl;
		InitNumb_int(&NumberOfHaircuts[0], n[0]);
		InitNumb_int(&NumberOfHaircuts[1], n[1]);
		InitNumb_int(&NumberOfHaircuts[2], n[2]);
	}

	void getNumberOfHaircuts()
	{
		cout << "getNumberOfHaircuts()" << endl;
		cout << NumberOfHaircuts[0] << endl;
		cout << NumberOfHaircuts[1] << endl;
		cout << NumberOfHaircuts[2] << endl << endl;
	}

	//Price
	void setPrice(double* n)
	{
		cout << "setPrice(double* n)" << endl << endl;

		InitNumb_double(&Price[0], n[0]);
		InitNumb_double(&Price[1], n[1]);
		InitNumb_double(&Price[2], n[2]);
	}

	void getPrice()
	{
		cout << "getPrice()" << endl;
		cout << Price[0] << endl;
		cout << Price[1] << endl;
		cout << Price[2] << endl << endl;
	}

	//Title
	void setTitle(char* new_title)
	{

		cout << "setTitle(char* new_title)" << endl << endl;

		//если не работает strcpy_s на старой версии VS (1)

		/*int n = 0;
		for (int i = 0; new_title[i] != '\0'; i++)
		{
			title[i] = new_title[i];
			n++;
		}
		title[n] = new_title[n];*/

		InitTitle(new_title);
	}

	void getTitle()
	{
		cout << "getTitle" << endl;

		//если не работает strcpy_s на старой версии VS(2)

		/*for (int i = 0; title[i] != '\0'; i++)
		{
			cout << title[i];
		}
		cout << endl;*/

		cout << Title << endl << endl;
	}

	//Employee Salary
	void EmployeeSalary(int tax)
	{
		cout << "EmployeeSalary" << endl;
		double NoHP(0), AoW;

		for (int i = 0; i < 3; i++)
		{
			NoHP += double(NumberOfHaircuts[i]) * Price[i];
		}
		AoW = double(AmountOfWorkers[0]) + double(AmountOfWorkers[1]);


		double e = NoHP / AoW * (1 - double(tax) / 100);

		cout << e << endl;
	}

	//0. Barbershop()
	Barbershop()
	{
		cout << "Barbershop()" << endl;
		AmountOfWorkers[0] = 10;
		AmountOfWorkers[1] = 20;

		NumberOfHaircuts[0] = 10;
		NumberOfHaircuts[1] = 20;
		NumberOfHaircuts[2] = 30;

		Price[0] = 100;
		Price[1] = 200;
		Price[2] = 300;

		strcpy_s(Title, "No");
	}

	//1. Barbershop(int *AoW, char *n_title)
	Barbershop(int* AoW, char* n_title)
	{
		cout << "Barbershop(int *AoW, char *n_title)" << endl;

		while (!InitNumb_int(&AmountOfWorkers[0], AoW[0]) || !InitNumb_int(&AmountOfWorkers[1], AoW[1]))
		{
			cout << " --> Enter the numb > 0" << endl;
			cout << "numb[0] = ";
			cin >> AoW[0];
			cout << "numb[1] = ";
			cin >> AoW[1];
		}

		AmountOfWorkers[0] = AoW[0];
		AmountOfWorkers[1] = AoW[1];

		InitTitle(n_title);

		NumberOfHaircuts[0] = 11;
		NumberOfHaircuts[1] = 12;
		NumberOfHaircuts[2] = 13;
	}

	//2. Barbershop(int *NoH, double *P)
	Barbershop(int* NoH, double* P)
	{
		cout << "Barbershop(int *NoH, double *P)" << endl;

		while (!InitNumb_int(&NumberOfHaircuts[0], NoH[0]) || !InitNumb_int(&NumberOfHaircuts[1], NoH[1]) || !InitNumb_int(&NumberOfHaircuts[2], NoH[2]))
		{
			cout << " --> Enter the numb > 0" << endl;
			cout << "numb[0] = ";
			cin >> NoH[0];
			cout << "numb[1] = ";
			cin >> NoH[1];
			cout << "numb[2] = ";
			cin >> NoH[2];
		}

		NumberOfHaircuts[0] = NoH[0];
		NumberOfHaircuts[1] = NoH[1];
		NumberOfHaircuts[2] = NoH[2];

		while (!InitNumb_double(&Price[0], P[0]) || !InitNumb_double(&Price[1], P[1]) || !InitNumb_double(&Price[2], P[2]))
		{
			cout << " --> Enter the numb > 0" << endl;
			cout << "numb[0] = ";
			cin >> P[0];
			cout << "numb[1] = ";
			cin >> P[1];
			cout << "numb[2] = ";
			cin >> P[2];
		}

		Price[0] = P[0];
		Price[1] = P[1];
		Price[2] = P[2];

		AmountOfWorkers[0] = 21;
		AmountOfWorkers[1] = 22;
	}

	~Barbershop()
	{
		cout << "~Barbershop()" << endl;
		delete[]AmountOfWorkers;
		AmountOfWorkers = NULL;

		delete[]NumberOfHaircuts;
		NumberOfHaircuts = NULL;

		delete[]Price;
		Price = NULL;

		delete[]Title;

	}

	bool InitNumb_int(int* unchanged, int numb)
	{
		cout << "InitNumb_int(int *unchanged, int numb)" << endl;

		if (numb > 0)
		{
			*unchanged = numb;
			return true;
		}
		cout << "--!-- Set error, numb < 0" << endl;
		return false;
	}

	bool InitNumb_double(double* unchanged, double numb)
	{
		cout << "InitNumb_double(int *unchanged, int numb)" << endl;

		if (numb > 0)
		{
			*unchanged = numb;
			return true;
		}
		cout << "--!-- Set error, numb < 0" << endl;
		return false;
	}

	bool InitTitle(char* new_title)
	{
		cout << "InitTitle(char* new_title)" << endl;

		int l = strlen(new_title);
		if (l >= 30)
		{
			cout << "--!-- Warning: The word is too long" << endl;
		}

		int n = 0;

		for (int i = 0; i < 30; i++)
		{
			Title[i] = new_title[i];
			n++;
		}
		Title[n] = '\0';
		return true;
	}
};