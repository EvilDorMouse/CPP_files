#include <iostream>

using namespace std;

void GetMaxNegative(int* v, int n, int& i_max)
{
	i_max = 0;
	int max = v[i_max];

	for (int i = 1; i < n; i++)
	{
		if ((max >= 0 && v[i] < 0) || (max < 0 && max < v[i] && v[i] < 0))
		{
			i_max = i;
			max = v[i_max];
		}
	}
}

void GetMinPositive(int* v, int n, int& i_min)
{
	i_min = 0;
	int min = v[i_min];

	for (int i = 1; i < n; i++)
	{
		if ((min <= 0 && v[i] > 0) || (min > 0 && min > v[i] && v[i] > 0))
		{
			i_min = i;
			min = v[i_min];
		}
	}
}

void SumFirstMin(int* v, int n)
{
	int sum(0);
	int i_min = 0;
	int min = v[i_min];

	for (int i = 1; i < n; i++)
	{
		if (min > v[i])
	
			i_min = i;
			min = v[i_min];
	
	}

	for (int i = 1; i < i_min; i++)
	{
		cout << "v1[" << i + 1 << "] = " << v[i] << endl;
		sum += v[i];
	}
	cout << "Sum First-Min: " << sum << endl;
}

void Sum_MaxPositive_MinNegative(int* v, int n)
{
	int m(0);
	int i_max(0), i_min(0);
	int max = v[i_max], min = v[i_min];

	for (int i = 1; i < n; i++)
	{
		if (max < v[i] && v[i] > 0)
		{
			i_max = i;
			max = v[i_max];
		}
		if (min > v[i] && v[i] < 0)
		{
			i_min = i;
			min = v[i_min];
		}
	}

	if (max < 0)
		max = 0;

	if (min > 0)
		min = 0;

	int from(0), before(0);

	if (i_max < i_min)
	{
		from = i_max;
		before = i_min;
	}
	else 
	{
		from = i_min;
		before = i_max;
	}

	cout << "MaxPositive: " << max << endl;
	cout << "MinNegative: " << min << endl;

	for (int i = from + 1; i < before; i++)
	{
		if (v[i] % 2 != 0)
		{
			cout << "v1[" << i + 1 << "] = " << v[i] << endl;
			m++;
		}
			
	}

	if (m == 0)
		cout << "No odd numbers";
}




void PermFirstMin(int* v, int n)
{
	int m;
	int i_min = 0;
	int min = v[i_min];

	for (int i = 0; i < n; i++)
	{
		if (v[i] < min)
		{
			i_min = i;
			min = v[i];
		}
	}

	m = v[0];
	v[0] = v[i_min];
	v[i_min] = m;
}

void PermMaxMin(int* v, int n)
{
	int m;
	int i_min = 0, i_max = 0;
	int min = v[i_min], max = v[i_max];

	for (int i = 0; i < n; i++)
	{
		if (v[i] < min)
		{
			i_min = i;
			min = v[i];
		}
		if (v[i] > max)
		{
			i_max = i;
			max = v[i];
		}
	}

	m = v[i_max];
	v[i_max] = v[i_min];
	v[i_min] = m;
}

void PermKthFirst0(int* v, int n, int k)
{
	int m;
	int i_zero = 0;
	int zero = v[i_zero];

	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0 && v[i] != zero)
		{
			i_zero = i;
			zero = v[i];
		}
	}

	if (zero == 0)
	{
		m = v[i_zero];
		v[i_zero] = v[k];
		v[k] = m;
	}
	else
	{
		cout << "No zero" << endl;
	}

}

void Perm01(int* v, int n)
{
	int m;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == v[i + 1])
		{
			for (int j = i + 2; j < n; j++)
			{
				if (v[i] != v[j])
				{
					m = v[i + 1];
					v[i + 1] = v[j];
					v[j] = m;
				}
			}
		}
	}
}