#include "Unit.h"


int main()
{
    int k, l, i1, i2, j, N;
	float a, b;
    double  e, x1, x2, x3, x4;

    int flag = input(a, b, N);
	if (flag == -1)
	{
		return 0;
	}
   if (form1(a) * form1(b) > 0)
    {
        printf("Корня на отрезке AB нет\n");
    }
    else
    {
        printf("Формула №9      |     Метод деления отрезками     |     Метод простых итераций\n");
		printf("Погрешность     |   Корень             Интераций  |  Корень           Интераций\n");
        for (j = 1; j <= N; j++)
        {
            e = 1 / pow(10, j);
            x1 = Metod1(a, b, e, i1, j, form1);
            x3 = Metod2(a, b, e, i2, j, func1);
            printf("%-13.*f       %-13.*f         %2d        %-13.*f        %2d\n", j, e, j, x1, i1, j, x3, i2);
        }
        printf("\n");
    }

    if (form2(a) * form2(b) > 0)
    {
        printf("Корня на отрезке AB нет\n");
    }
    else
    {
		printf("Формула №12     |     Метод деления отрезками     |     Метод простых итераций\n");
		printf("Погрешность     |   Корень             Интераций  |  Корень           Интераций\n");
		for (j = 1; j <= N; j++)
        {
            e = 1 / pow(10, j);
            x2 = Metod1(a, b, e, i1, j, form2);
            x4 = Metod2(a, b, e, i2, j, func2);
            printf("%-13.*f       %-13.*f         %2d        %-13.*f        %2d\n", j, e, j, x2, i1, j, x4, i2);
        }
        printf("\n");
    }
   
    return 0;
}
