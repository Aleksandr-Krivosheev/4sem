#include "Unit.h"

void input(FILE *&f, int &n, double *&arr)
{
	fscanf(f, "%d", &n);
	arr = new double[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%lf", &arr[i]);
	}
}

void output(FILE *&ff, int &n, double *&arr)
{
	fprintf(ff, "N = ");
	fprintf(ff, "%d\n", n);

	fprintf(ff, "Введенный массив X: \n");
	for (int i = 0; i < n; i++)
	{
		fprintf(ff, "%.1f", arr[i]);
		fprintf(ff, ", ");
	}
}

bool recurs(double *x, int a, int n)
{
	if (n - a == 0)
	{
		if (cos(x[a] * M_PI / 180) > 0)
			return true;
		else
			return false;
	}
	if(n - a == 1){
	if ((cos(x[a] * M_PI / 180) > 0) && (cos(x[n] * M_PI / 180) > 0))
			return true;
		else
			return false;
		}
	int mid = a + (n - a) / 3;
	bool right = false;
	bool left = recurs(x, a, mid);
	if (left)
		right = recurs(x, mid + 1, n);
	if (left && right)
		return true;
	else
		return false;
}
