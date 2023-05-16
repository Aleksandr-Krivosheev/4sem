#include "Unit2.h"

bool checker2(matr2& M)
{
	if (M.f == NULL)
	{
		return true;
	}
	int end;
	fseek(M.f, 0, SEEK_END);
	end = ftell(M.f);
	fseek(M.f, 0, SEEK_SET);
	if (end == 0)
	{
		return (true);  // файл пуст => нет элементов
	}
	else
	{
		return (false);
	}
}

int CreateEmpty2(matr2& M, int n, int m)
{
	fopen(&M.f, "MATR", "w+b");
	if (&M.f == NULL)
	{
		printf("Невозможно открыть файл\n");
		return 0;
	}
	int a;
	for (int i = 0; i < n; i++)
	{
		fwrite(&a, sizeof(int), m, M.f);
	}
	M.n = n;
	M.m = m;
	return 0;
}

void NewStroka2(matr2& M)
{
	int a;
	fseek(M.f, 0, SEEK_END);
	fwrite(&a, sizeof(int), M.m, M.f);
	M.n++;
	fseek(M.f, 0, SEEK_SET);
}

void NewStolb2(matr2& M)
{
	int a;
	int dop;
	fseek(M.f, 0, SEEK_END);         // выделяем место под новый столбец (например было 3 строки => нужно место под 3 новых переменных)
	fseek(M.f, (M.n - 1) * sizeof(int), SEEK_CUR); // сдвигаем к последнему доп элементу
	fwrite(&a, sizeof(int), 1, M.f); // записываем последний доп элемент (значение последнего столбца в последней строке)
	fseek(M.f, 0 - (M.n + 1) * sizeof(int), SEEK_CUR); // сдвигаем до последнего значения, которое было значально для сдвига к последнему доп элементу (для матрицы 3Х3 это будет (3,3) элемент)
	for (int i = 0; i < M.n - 1; i++) // идем построчно, начиная с последней строки 
	{
		for (int j = 0; j < M.m; j++) // сдвигаем строку строки
		{
			fread(&dop, sizeof(int), 1, M.f);   // считываем значение
			//printf("dop: %d\n", dop); 
			fseek(M.f, (M.n - 2 - i) * sizeof(int), SEEK_CUR); // перемещаем указатель на нужную позицию для этого элемента (для каждой строки переносится на своё значение ибо с каждой строкой появляется новый элемент)
			fwrite(&dop, sizeof(int), 1, M.f); // запись элемента
			fseek(M.f, 0 - (M.n + 1 - i) * sizeof(int), SEEK_CUR); // сдвигаемся назад до предшествующего элемента
		}
		fseek(M.f, (M.n - i - 1) * sizeof(int), SEEK_CUR);  // сдвиг для записи доп элемента ( нового элемента в столбце)
		//printf("pos1: %d\n", ftell(M.f));
		fwrite(&a, sizeof(int), 1, M.f); // запись этого доп элемента
		//printf("pos2: %d\n", ftell(M.f));
		fseek(M.f, 0 - (M.n - i) * sizeof(int), SEEK_CUR); // сдвиг назад до последнего элемента верхней строки
		//printf("pos3: %d\n", ftell(M.f));
	}
	M.m++;
}

int out2(matr2& M, FILE*& log)
{
	int a;
	fprintf(log, "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\nМатрица из файла:\n");
	if (M.f == NULL)
	{
		fprintf(log, "файл пуст\n");
		return 0;
	}
	fseek(M.f, 0, SEEK_END);
	if (ftell(M.f) == 0)
	{
		fprintf(log, "файл пуст\n");
		return 0;
	}
	fseek(M.f, 0, SEEK_SET);
	for (int i = 0; i < M.n; i++)
	{
		for (int j = 0; j < M.m; j++)
		{
			fread(&a, sizeof(int), 1, M.f);
			fprintf(log, " %3d  ", a);
		}
		fprintf(log, "\n");
	}
	return 0;
}

int cleaner2(matr2& M)
{
	if (checker2(M) == true)
	{
		printf("\nматрица уже пуста\n\n");
		return 0;
	}
	remove("Matr");
	fopen(&M.f, "Matr", "w+b");
	printf("\nочищено\n\n");
	return 0;
}

void MakeItI2(matr2& M, int a)
{
	fseek(M.f, (a - 1) * M.m * sizeof(int), SEEK_SET);
}

void MakeItJ2(matr2& M, int a)
{
	fseek(M.f, (a - 1) * sizeof(int), SEEK_SET);
}

void NextElemStr2(matr2& M)
{
	fseek(M.f, sizeof(int), SEEK_CUR);
}

void NextElemStolb2(matr2& M)
{
	fseek(M.f, M.m * sizeof(int), SEEK_CUR);
}

int read2(matr2& M)
{
	int a;
	fread(&a, sizeof(int), 1, M.f);
	fseek(M.f, 0 - sizeof(int), SEEK_CUR);
	return a;
}

void ChangeCur2(matr2& M, int a)
{
	fwrite(&a, sizeof(int), 1, M.f);
	fseek(M.f, 0 - sizeof(int), SEEK_CUR);
}

void Index2(matr2& M, int n, int m, int a)
{
	int CurPos = ftell(M.f); // запоминаем текущую позицию
	fseek(M.f, ((n - 1) * M.m + m - 1) * sizeof(int), SEEK_SET); // откатываем до позиции по индексам
	fwrite(&a, sizeof(int), 1, M.f); // записываем туды значения a
	fseek(M.f, CurPos, SEEK_SET); // откатывает обратно в текущую позицию
}

int ReadMatr2(matr2& M, int n, int m)
{
	int CurPos = ftell(M.f); // запоминаем позицию 
	fseek(M.f, ((n - 1) * M.m + m - 1) * sizeof(int), SEEK_SET); // перемещаемся в нужную заданую позицию
	int a; 
	fread(&a, sizeof(int), 1, M.f); // считываем значение
	fseek(M.f, CurPos, SEEK_SET); // откат обратно
	return a;
}
//////////////////////////////////////////////////////////////////////4main
void MainCleaner2(matr2& M)
{
	cleaner2(M);
}

int MainInput2(matr2& M)
{
	{
		char name[20];
		printf("Введите название файла: ");
		gets_s(name);
		FILE* f;
		fopen(&f, name, "r");
		if (f == NULL)
		{
			printf("\nневозможно открыть файл\n\n");
			return 0;
		}
		fseek(f, 0, SEEK_END);
		int end = ftell(f);
		fseek(f, 0, SEEK_SET);
		if (end == 0)
		{
			printf("\nФайл пуст\n\n");
			return 0;
		}
		fscanf_s(f, "%d", &M.n);
		fscanf_s(f, "%d", &M.m);
		CreateEmpty2(M,M.n,M.m);
		int a;
		for (int i = 0; i < M.n; i++)
		{
			for (int j = 0; j < M.m; j++)
			{
				fscanf_s(f, "%d", &a);
				Index2(M, i + 1, j + 1, a);
			}
		}
		printf("\nсоздали\n\n");
		fclose(f);
		return 0;
	}
}

int MainChangeIndex2(matr2& M)
{
	if (checker2(M) == true)
	{
		printf("\nМатрица пуста => нечего менять\n\n");
		return 0;
	}
	int i, j;
	int a;
	printf("Введите значение i: ");
	scanf_s("%d", &i);
	getchar();
	printf("Введите значение j: ");
	scanf_s("%d", &j);
	getchar();
	printf("Введите значение a: ");
	scanf_s("%d", &a);
	Index2(M, i, j, a);
	printf("\nизменили\n\n");
	return 0;
}

int MainStolb2(matr2& M)
{
	if (checker2(M) == true)
	{
		printf("\nфайл пуст => нельзя создать новый столбец\n\n");
		return 0;
	}
	NewStolb2(M);
	for (int i = 1; i <= M.n; i++)
	{
		Index2(M, i, M.m, 0);
	}
	printf("\nстолбец создан\n\n");
	return 0;
}

int MainStroka2(matr2& M)
{
	if (checker2(M) == true)
	{
		printf("\nфайл пуст => нельзя создать новую строку\n\n");
		return 0;
	}
	NewStroka2(M);
	for (int i = 1; i <= M.n; i++)
	{
		Index2(M, M.n, i, 0);
	}
	printf("\nстрока создана\n\n");
	return 0;
}

int MainSolution2(matr2& M)
{
	if (checker2(M) == true)
	{
		//printf("\nфайл пуст => нельзя найти решение\n\n");
		return 0;
	}
	int schet = 0;
	int minschet = 0;
	int min = 0;
	int i = 1,  j = 1;
	while (min == 0 && (i != M.n+1 || j != M.m+1))
	{
		j = 1;
		while (j != M.m+1)
		{
			if (ReadMatr2(M, i, j) > 0)
			{
				min = ReadMatr2(M, i, j);
			}
			j++;
		}
		i++;
	}
	if (min == 0)
	{
		return 0;
	}
	int a;
	for (int i = 1; i <= M.n; i++)
	{
		for (int j = 1; j <= M.m; j++)
		{
			if (ReadMatr2(M, i, j) % 5 == 0)
			{
				return minschet;
			}
			schet++;
			if ((ReadMatr2(M, i, j) > 0) && (ReadMatr2(M, i, j) < min))
			{
				minschet = schet;
				min = ReadMatr2(M, i, j);
			}
		}
	}
	return 0;
}