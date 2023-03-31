#include "Exception.h"

#include <iostream>

using namespace std;

//Exception(int c, char* m);

Exception::Exception(int c, char* m)
{
	cout << "" << endl;
	code = c;
	mess = new char[strlen(m) + 1];
	for (int i = 0; i < strlen(m); i++)
	{
		mess[i] = m[i];
	}
	mess[strlen(m)] = '\0';
}

//~Exception();

Exception::~Exception()
{
	cout << "" << endl;
	//delete[] mess;
}

//void Show();

void Exception::Show()
{
	cout << endl;
	cout << "Error " << code << ":" << endl;
	cout << "\t" << mess << endl;
}