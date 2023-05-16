#include "Unit1.h"

int main()
{
	bool flag;
	FILE* log = fopen( "log.txt", "w+");
	matr* M1 = NULL; // первый элемент матрицы
	int v = 9;
	int k = 9;
	int t1 = 2;
	int t2 = 6;
	int a;
	char b[100];

	while (v != 0)
	{
		printf("1-очистить матрицу (освободить память)\n");
		printf("2-создать матрицу, считав размеры и значения элементов из текстового файла\n");
		printf("3-изменить один элемент по индексам, на основе данных введенных в интерактивном режиме\n");
		printf("4-изменить размер матрицы, добавив строку или столбец из 0(нулей)\n");
		printf("5-поиск: решить задачу\n");
		printf("0-выход\n");
		printf("вы выбираете: ");
		scanf("%d", &v);
		if (v == 1)
		{
			k = 9;
			printf("\n1-список\n2-файл");
			printf("\nВы выбираете: ");
			scanf("%d", &k);
			if ((k == 1))
			{
				FreeMem_int1(M1);
				Outlog(M1, log);
			}
			else if ((k == 2))
			{

			}
			else
			{
				fgets(b,100, log);
				printf("\nВы ввели неправильное значение\n\n");
			}
		}
		else if (v == 2)
		{
			k = 9;
			printf("\n1-список\n2-файл");
			printf("\nВы выбираете: ");
			scanf("%d", &k);
			if ((k == 1))
			{
				getchar();
				MainInput(M1);
				Outlog(M1, log);
			}
			else if ((k == 2))
			{
			}
			else
			{
				fgets(b,100, log);
				printf("\nВы ввели неправильное значение\n\n");
			}
		}
		else if (v == 3)
		{
			k = 9;
			printf("\n1-список\n2-файл");
			printf("\nВы выбираете: ");
			scanf("%d", &k);
			if ((k == 1))
			{
				getchar();
				MainChangeIndex(M1);
				Outlog(M1, log);
			}
			else if ((k == 2))
			{
			}
			else
			{
				fgets(b,100, log);
				printf("\nВы ввели неправильное значение\n\n");
			}
		}
		else if (v == 4)
		{
			k = 9;
			printf("\n1-список столб\n2-файл столб\n3-список строка\n4-файл строка");
			printf("\nВы выбираете: ");
			scanf("%d", &k);
			if ((k == 1))
			{
				getchar();
				MainStolb(M1);
				Outlog(M1, log);
			}
			else if ((k == 2))
			{

			}
			else if ((k == 3))
			{
				getchar();
				MainStroka(M1);
				Outlog(M1, log);
			}
			else if ((k == 4))
			{
			}
			else
			{
				fgets(b,100, log);
				printf("\nВы ввели неправильное значение\n\n");
			}
		}
		else if (v == 5)
		{
			int j = 0;
			k = 9;
			printf("\n1-список\n2-файл");
			printf("\nВы выбираете: ");
			scanf("%d", &k);

			printf("Введите T1: ");
			scanf("%d", &t1);
			printf("Введите T2: ");
			scanf("%d", &t2);
			if ((k == 1))
			{
				getchar();
				j = Solution(M1,t1,t2);
				
				Outlog(M1, log);
				if (j != 0)
				{
					printf("\nзадача решена\n\n");
					fprintf(log, "номер элемента: %d\n", j);
				}
			}
			else if ((k == 2))
			{
			}
			else
			{
				fgets(b,100, log);
				printf("\nВы ввели неправильное значение\n\n");
			}
		}
		else if (v == 0)
		{
			if (log != NULL)
			{
				fclose(log);
			}
		}
		else
		{
			fgets(b,100, log);
			printf("\nвы ввели неправильное значение\n\n");
		}
	}
	return 0;
}
