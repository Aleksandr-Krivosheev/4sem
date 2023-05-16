#include "Unit.h"

//Ввод значений
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

double form1(double x)
{
    return ((log(1.0 + x) + 10.0 / 3.0 * exp(0.01 * x)) / (2 * sqrt(x)) - x);
}

double form2(double x)
{
    //double z = (sin(x) + cos(x));
    return (pow(exp(-x), 1.0 / 5.0) + (pow(x, 1.0 / 7.0) * sin(x) * sin(x)) / (1.0 + log(x + 3.0)) - x);
}

double func1(double x)
{
    return 1.0 / 2.0 * form1(x) + x;
}

double func2(double x)
{
    return x + 1.0 / 2.0 * form2(x);
}

//Метод деления отрезка пополам
double Metod1 (double a, double b, double e, int &i1, int j, double (*f)(double))
{
    double c = 0;
    i1 = 0;
    do
    {
        c = (a + b) / 2.0;        //делим промежуток пополам
        if ((f(b)) * (f(c)) >= 0) //в зависимости от знака
            b = c;                //двигаемся к правому концу
        else
            a = c; //к левому концу промежукта
        i1++;
    } while (fabs(b - a) >= e);
    return b;
}

//Метод простых итераций
double Metod2 (double a, double b, double e, int &i2, int j, double (*func)(double))
{
    i2 = 0;
    b = (a + b) / 2.0; //значение начального приближения
    do
    {
        a = b;
        b = func(a); //Следующее приближение
        i2++;
    } while (fabs(b - a) >= e);
    return b;
}
