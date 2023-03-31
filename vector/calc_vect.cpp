#include <cmath>
#include <iostream>
#include "vect.h"
#include "calc_vect.h"

using namespace std;

double ScalarProduct(double* v1, double* v2, int n)
{
	double res(0);

	for (int i = 0; i < n; i++)
		res += v1[i] * v2[i];

	return res;
}

void MixedProduct(double* v1, double* v2, double* v3, int n, double* res)
{
	*res = v1[0] * (v2[1] * v3[2] - v2[2] * v3[1]) - v1[1] * (v2[0] * v3[2] - v2[2] * v3[0]) + v1[2] * (v2[0] * v3[1] - v2[1] * v3[0]);
}

double Length(double* v, int n)
{
	double res(0);

	for (int i = 0; i < n; i++)
		res = res + pow(v[i], 2);

	res = pow(res, 0.5);

	return res;
}

double CosAngle(double* v1, double* v2, int n, double& angle)
{
	double ScalarP(0);
	double L_v1(0), L_v2(0);
	double cosAngle(0);

	for (int i = 0; i < n; i++)
	{
		ScalarP += v1[i] * v2[i];
		L_v1 += pow(v1[i], 2);
		L_v2 += pow(v2[i], 2);
	}

	L_v1 = pow(L_v1, 0.5);
	L_v2 = pow(L_v2, 0.5);

	cosAngle = ScalarP / L_v1 / L_v2;
	angle = acos(cosAngle);

	return cosAngle;
}