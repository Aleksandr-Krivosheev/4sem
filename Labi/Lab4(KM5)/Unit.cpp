#include "Unit.h"

void input(FILE*& f, int& n, int*& arr)
{
	char Name[20];
	printf("Введите название входного файла: ");
	fgets(Name, 20, stdin);
	fopen(Name, "r");
	fscanf(f, "%d", &n);
	if (f == NULL)
	{
		printf("slomalos'");
	}
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(f,"%d", &arr[i]);
	}
}

bool recursion(int i, int* arr)
{
	if (i == 0)
	{
		return false;
	}
	if ( fabs(arr[i-1]) > (i) )
	{
		return true;
	}
	return (recursion(i - 1, arr));
}

void output(int n, int* arr, bool flag, int l)
{
	printf("\nНазвание выходного файла: ");
	char Name[20];
	fgets(Name, 20, stdin);
	FILE* ff;
	fopen(Name, "w");
	fprintf(ff, "Количество переменных N = %d\n", n);
	fprintf(ff, "         i: ");
	for (int i = 1; i <= n; i++)
	{
		fprintf(ff, "%4d", i);
	}
	fprintf(ff, "\nСам массив: ");
	for (int i = 0; i < n; i++)
	{
		fprintf(ff, "%4d", arr[i]);
	}
	if (flag == 0)
	{
		fprintf(ff, "\nНет элементов, удовлетворяющих условию");
	}
	else 
	{
		fprintf(ff, "\nЕсть элементы, удовлетворяющих условию");
	}
	fprintf(ff, "\nГлубина: %d", l);
	fprintf(ff, "\nОбъем: %d", l-1);

	// вывод типо дерева

	fclose(ff);
}
/*
void output1(int n, int* arr, bool flag, int l, int (*outf)(FILE* f, int n1, int* arr1))
{
	printf("\nНазвание выходного файла: ");
	char Name[20];
	fgets(Name, 20, stdin);
	FILE* ff;
	fopen(Name, "w");
	fprintf(ff, "Количество переменных N = %d\n", n);
	fprintf(ff, "Сам массив: ");
	for (int i = 0; i < n; i++)
	{
		fprintf(ff, "%2d ", i);
	}
	fprintf(ff, "\n            ");
	for (int i = 0; i < n; i++)
	{
		fprintf(ff, "%2d ", arr[i]);
	}
	if (flag == 0)
	{
		fprintf(ff, "\nНет элементов, удовлетворяющих условию");
	}
	else
	{
		fprintf(ff, "\nЕсть элементы, удовлетворяющих условию");
	}
	fprintf(ff, "\nГлубина: %d", l);
	fprintf(ff, "\nОбъем: %d", l - 1);

	// вывод типо дерева
	fprintf(ff,"\n");
	outf(ff, n, arr);
	fclose(ff);
}
int derevo(FILE* f, int n, int* arr)
{
	fprintf(f,"\n///////////\\\\\\\\\\\\\\\\\\\\\\\\");
	if (fabs(arr[n - 1]) > n-1)
	{
		fprintf(f,"\n// recurison(  Q, %2d)\\\\",  n);
		fprintf(f,"\n//    result=TRUE    \\\\");
		fprintf(f,"\n///////////\\\\\\\\\\\\\\\\\\\\\\\\ \n");
		return 1;
	}
	else
	{
		fprintf(f,"\n// recurison(  Q, %2d)\\\\", n);
		if (n == 1) 
		{
			//fprintf(f, "\n//    result=FALSE   \\\\", n);
		}
		fprintf(f,"\n///////////\\\\\\\\\\\\\\\\\\\\\\\\ \n");
		if (( n - 1) != 0)
		{
			fprintf(f,"         |  ^\n         v  |");
		}
		if (n == 1)
		{
			return 0;
		}
		return (derevo(f, n - 1, arr));
	}
}

*/