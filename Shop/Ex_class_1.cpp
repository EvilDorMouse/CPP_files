#include <iostream>
#include "Shop.h"

using namespace std;

void Ex_class_1()
{
	//class Barbershop* Shop = new class Barbershop[3];


	int* AofW = new int[2];
	AofW[0] = 3;
	AofW[1] = 8;

	int* NofH = new int[3];
	NofH[0] = 23;
	NofH[1] = 76;
	NofH[2] = 189;

	double* P = new double[3];
	P[0] = 587.237;
	P[1] = 458.56;
	P[2] = 879.12;

	char T[] = "Strand";
	int tax = 25;

	class Barbershop* Shop[4];

	cout << "-----------Shop[0]-----------" << endl;
	Shop[0] = new Barbershop{};
	Shop[0]->getTitle();
	Shop[0]->getAmountOfWorkers();
	Shop[0]->getNumberOfHaircuts();
	Shop[0]->getPrice();

	Shop[0]->EmployeeSalary(tax);

	cout << "-----------Shop[1]-----------" << endl;
	Shop[1] = new Barbershop{ AofW, T };
	Shop[1]->getTitle();
	Shop[1]->getAmountOfWorkers();
	Shop[1]->getNumberOfHaircuts();

	Shop[1]->setPrice(P);
	Shop[1]->getPrice();

	Shop[1]->EmployeeSalary(tax);

	cout << "-----------Shop[2]-----------" << endl;
	Shop[2] = new Barbershop{ NofH, P };
	Shop[2]->getNumberOfHaircuts();
	Shop[2]->getPrice();
	Shop[2]->getAmountOfWorkers();

	Shop[2]->setTitle(T);
	Shop[2]->getTitle();

	Shop[2]->EmployeeSalary(tax);

	cout << "-----------Shop[3]-----------" << endl;
	Shop[3] = new Barbershop;
	Shop[3]->setTitle(T);
	Shop[3]->setAmountOfWorkers(AofW);
	Shop[3]->setNumberOfHaircuts(NofH);
	Shop[3]->setPrice(P);

	Shop[3]->getTitle();
	Shop[3]->getAmountOfWorkers();
	Shop[3]->getNumberOfHaircuts();
	Shop[3]->getPrice();

	Shop[3]->EmployeeSalary(tax);
}