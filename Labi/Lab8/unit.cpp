#include "Unit.h"

int input(float &A, float &B, int &N)
{
	printf("Введите значение А(0,2): ");
	scanf("%f", &A);
	if ((A <= 0) || (A >= 2))
	{
		printf("Вы ввели неправильное значение А");
		printf("\n");
		return -1;
	}
	printf("\nВведите значение B(0,2): ");
	scanf("%f", &B);
	if ((B <= 0.0 || B >= 2.0))
	{
		printf("Вы ввели неправильное значение B");
		printf("\n");
		return -1;
	}
	if (A >= B)
	{
		printf("А должно быть меньше B");
		printf("\n");
		return -1;
	}
	printf("\nВведите значение N(0,10]: ");
	scanf("%d", &N);
	if ((N <= 0 || N > 10))
	{
		printf("Вы ввели неправильное значение N");
		printf("\n");
		return -1;
	}

	return 0;
}

double formula1(double x)
{
	return ((log(1.0 + x) + 10.0 / 3.0 * exp(0.01 * x)) / (2 * sqrt(x)) - x);
}

double formula2(double x)
{
	return (pow(exp(-x), 1.0 / 5.0) + (pow(x, 1.0 / 7.0) * sin(x) * sin(x)) / (1.0 + log(x + 3.0)) - x);
}

double proizv(double (*resx)(double x), double xx, double e)
{
	return ((resx(xx + e / 2.0) - resx(xx - e / 2.0)) / e);
}

int checker(double (*res)(double x), float a, float b)
{
	if (res(a) * res(b) > 0)
	{
		//printf_s("resa:  %f   resb:    %f", res(a), res(b));
		printf("\nНет корня\n");
		return -1;
	}
	return 0;
}
//Метод деления отрезка пополам
void SolFunc1(double (*res)(double x), double a, double b, int n, double &arr, int &m, double e)
{
	/*double e = 1.0;
	m = new int[n];
	arr = new double[n];
	double a1 = a;
	double b1 = b;
	for (int i = 0; i < n; i++)
	{
		e = e * 0.1;
		m[i] = 0;
		a1 = a;
		b1 = b;
	*/
	//printf_s("1:   %.13f\n", e);
	do
	{
		m = m + 1;
		arr = (a + b) / 2.0;
		if (((res(arr) > 0) && (res(b) > 0)) || ((res(arr) < 0) && (res(b) < 0)))
		{
			b = arr;
		}
		else
		{
			a = arr;
		}
	} while ((b - a) > e);
}


double func1(double x){
return ( 1.0/2.0*formula1(x)+x );
}

double func2(double x){
return ( x + 1.0/2.0*formula2(x) );
}

//Метод простых итераций
void SolFunc2(double (*res)(double x), double (*pr)(double (*resx)(double x), double xx, double e), double (*func)(double x), double a, double b, int n, double &arr, int &m, double e)
{
	int s = 0;
	b = (a + b) / 2.0; //значение начального приближения
	do
	{
		a = b;
		b = func(a); //Следующее приближение
		m ++;
	} while (fabs(b - a) >= e);
	arr = b;

	/*double x = 0;
	do
	{
		m = m + 1;
		x = arr;
		arr = x - (res(x) / pr(res, x, e));
	} while (fabs(arr - x) > e);
	//}*/
}

void output(int n, double *arr, int *m, double *arr1, int *m1)
{
	double e = 1;
	printf("Погрешность     |     Метод деления отрезками     |     Метод простых итераций\n");
	printf("                |   Корень             Интераций  |  Корень           Интераций\n");
	for (int i = 0; i < n; i++)
	{
		e = e * 0.1;
		printf("%-13.*f      %-13.*f          %2d           %-13.*f     %2d\n", i + 1, e, i + 1, arr[i], m[i], i + 1, arr1[i], m1[i]);
	}
	delete[] arr;
	delete[] arr1;
	delete[] m;
	delete[] m1;
}