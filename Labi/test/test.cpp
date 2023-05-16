
#pragma argsused
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

    double f1(double x)
{
    return ((log(1.0 + x) + 10.0 / 3.0 * exp(0.01 * x)) / (2 * sqrt(x)) - x);
}

double f2(double x)
{
    //double z = (sin(x) + cos(x));
    return (pow(exp(-x), 1.0 / 5.0) + (pow(x, 1.0 / 7.0) * sin(x) * sin(x)) / (1.0 + log(x + 3.0)) - x);
}

double func1(double x)
{
    return 1.0 / 2.0 * f1(x) + x;
}

double func2(double x)
{
    return x + 1.0 / 2.0 * f2(x);
}

//Метод деления отрезка пополам
double aboba (double a, double b, double e, int &i1, int j, double (*f)(double))
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
double eboba (double a, double b, double e, int &i2, int j, double (*func)(double))
{
    i2 = 0;
    a = (a + b) / 2.0; //значение начального приближения
    do
    {
        a = b;
        b = func(a); //Следующее приближение
        i2++;
    } while (fabs(b - a) >= e);
    return b;
}

int main()
{
    int k, l, i1, i2, j, N;

    int flg2 = 1, flg3 = 1, flg1 = 1;
    double a, b, e, x1, x2, x3, x4;
    printf("В таблице:\n I - кол-во итераций цикла при методе бисекций \n");
    printf("II - кол-во итераций цикла при методе простых итераций \n");
    printf("Введите число N: ");
    while (flg1)
    {
        while (!fflush(stdin) && !scanf("%d", &N)) // проверка на число
            printf("N - не число. Повторите ввод: ");
        while (N < 1 || N > 10)
        {
            printf("N выходит за границы допустимого диапазона. Введите N[1...10]: ");
            scanf("%d", &N);
        }
        flg1 = 0;
    }
    printf("Введите число a: ");
    while (flg2)
    {
        while (!fflush(stdin) && !scanf("%lf", &a))
            printf("a - не число. Повторите ввод: ");
        while ((a >= 2) || (a <= 0))
        {
            printf("a за пределами диапазона 0<a<2. Введите a:");
            scanf("%lf", &a);
        }
        flg2 = 0;
    }
    printf("введите число b: ");
    while (flg3)
    {
        while (!fflush(stdin) && !scanf("%lf", &b))
            printf("b - не число. Повторите ввод: ");
        while ((b >= 2) || (b <= 0) || (b <= a))
        {
            printf("b за пределами диапазона 0<a<b<2. Введите b: ");
            scanf("%lf", &b);
        }
        flg3 = 0;
    }
    printf(" \n");

    if (f1(a) * f1(b) > 0)
    {
        printf("У f1 корня на отрезке AB нет\n");
    }
    else
    {
        printf("Для первой функции:\n");
        printf(" Погрешность | Корень I | I | Корень II | II |\n");
        for (j = 1; j <= N; j++)
        {
            e = 1 / pow(10, j);
            x1 = aboba(a, b, e, i1, j, f1);
            x3 = eboba(a, b, e, i2, j, func1);
            printf("%14.*lf|%14.*lf|%5d|%14.*lf|%5d|\n", j, e, j, x1, i1, j, x3, i2);
        }
        printf("\n");
    }

    if (f2(a) * f2(b) > 0)
    {
        printf("У f2 корня на отрезке AB нет\n");
    }
    else
    {
        printf("Для второй функции:\n");
        printf(" Погрешность  | Корень I    | I    | Корень II   | II   |\n");
        for (j = 1; j <= N; j++)
        {
            e = 1 / pow(10, j);
            x2 = aboba(a, b, e, i1, j, f2);
            x4 = eboba(a, b, e, i2, j, func2);
            printf("%14.*lf|%14.*lf|%5d|%14.*lf|%5d|\n", j, e, j, x2, i1, j, x4, i2);
        }
        printf("\n");
    }
    printf("Press any key to exit");
    return (0);
}
