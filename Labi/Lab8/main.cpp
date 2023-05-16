#include "Unit.h"


int main()
{
	float a, b;
	int n;
	double* arr;
	double* arr1;
	int* m;
	int* m1;
	int flag = input(a, b, n);
	if (flag == -1)
	{
		return 0;
	}
	flag = checker(formula1, a, b);
	if (flag == 0)
	{
		double e = 1.0;
		m = new int[n];
		arr = new double[n];
		m1 = new int[n];
		arr1 = new double[n];
		for (int i = 0; i < n; i++)
		{
			e = e * 0.1;
			m[i] = 0;
			m1[i] = 0;
			arr1[i] = (a + b) / 2.0;
			arr[i] = 0;
			SolFunc1(formula1, a, b, n, arr[i], m[i], e);
			SolFunc2(formula1, proizv, func1, a, b, n, arr1[i], m1[i], e);
	    }
		output(n, arr, m, arr1, m1);
	}

	printf("\n");
	flag = 0;
	flag = checker(formula2, a, b);
	if (flag == 0)
	{
		double e = 1;
		m = new int[n];
		arr = new double[n];
		m1 = new int[n];
		arr1 = new double[n];
		for (int i = 0; i < n; i++)
		{
			e = e * 0.1;
			m[i] = 0;
			m1[i] = 0;
			arr[i] = 0;
			arr1[i] = a + b / 2.0;
			SolFunc1(formula2, a, b, n, arr[i], m[i], e);
			SolFunc2(formula2, proizv, func2, a, b, n, arr1[i], m1[i], e);
		}
		output(n, arr, m, arr1, m1);
	}

	return 0;
}
