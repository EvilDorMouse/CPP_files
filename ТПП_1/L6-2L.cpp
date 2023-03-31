#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
	int n = pow(10, 9);
	int sum = 0;

	unsigned t0 = clock();

	for (int i = 0; i < n; i++)
	{
		sum += 1 / (1 + i);
	}

	unsigned t = clock();

	cout << "t0 = " << t0 << endl;
	cout << "t = " << t << endl;

	cout << "T = " << unsigned(t - t0) << "ms" << endl;

	return 0;
}