#include "Unit1.h"

bool checker(matr *&M)
{
	if (M == NULL)
	{
		return (true); // матрица пуста
	}
	else
	{
		return (false); // матрица не пуста
	}
}

void CreateEmpty_void(matr *&M, int n, int m)
{
	M = new matr;
	TElem *NewElem;				  //TElem для создания нового элемента
	TElem *UpperString = NULL;	  // верхняя строка для заполнения ссылок на нижние элементы матрицы
	TElem *UpperStringDop = NULL; // дополнительный указатель на верхнюю строку
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			NewElem = new TElem; // выделение памяти
			NewElem->next = NULL;
			NewElem->down = NULL;
			if (i == 0 && j == 0) //запоминание первого элемнта
			{
				M->first = NewElem;
			}
			if (j == 0) // создание первого элемента в строке и запоминание первого элемента в строке
			{
				UpperStringDop = NewElem; // запоминание первого элемента в строке
				M->suk = NewElem;		  // тепрь это текущий элмент типо
			}
			else // создание связей в строке
			{
				M->suk->next = NewElem; //создаёмс связь со след
				M->suk = M->suk->next;	// говорим что тек теперь следующий
			}
			if (i != 0) // создание нижних связей в верхней строке
			{
				UpperString->down = NewElem;	 // создание самой связи
				UpperString = UpperString->next; // переход к некст элементу верхней строки
			}
		}
		UpperString = UpperStringDop; // присвоение первого элемента только что заполненной строки
	}
	M->n = n;
	M->m = m;
	M->suk = M->first;
	M->j = 0;
	M->i = 0;
}

void NextElemStr(matr *&M)
{
	M->suk = M->suk->next;
	M->j++;
}
void NextElemStolb(matr *&M)
{
	M->suk = M->suk->down;
	M->i++;
}
void MakeItI(matr *&M, int a) // текущий - 1 элемент строки а
{
	M->suk = M->first;
	for (int i = 0; i < a - 1; i++) // спуск до нудной строки
	{
		M->suk = M->suk->down;
	}
	M->i = a - 1;
	M->j = 0;
}

void MakeItJ(matr *&M, int b) // текущий - 1 элемент столба б
{
	M->suk = M->first;
	for (int i = 0; i < b - 1; i++) // a заменить на b до нужного столбца
	{
		M->suk = M->suk->next;
	}
	M->j = b - 1;
	M->i = 0;
}

void NewStroka(matr *&M)

{
	TElem *NewElem = NULL;
	MakeItI(M, M->n);		   // спуск до последней строки
	TElem *UpperElem = M->suk; //указатель на первый элемент верхней строки длля создания связей внзи
	for (int j = 0; j < M->m; j++)
	{
		NewElem = new TElem;
		NewElem->next = NULL;
		NewElem->down = NULL;
		UpperElem->down = NewElem;
		if (j == 0)
		{
			M->suk = NewElem;
			M->i++;
		}
		else
		{
			M->suk->next = NewElem;
			M->suk = M->suk->next;
			M->j++;
		}
		UpperElem = UpperElem->next;
	}
	M->n++;
}

void NewStolb(matr *&M)
{
	TElem *NewElem; // для создания новых элементов
	MakeItJ(M, M->m);
	TElem *LastStolb = M->suk; //последний существующий столбец шоб сделать связи next
	for (int i = 0; i < M->n; i++)
	{
		NewElem = new TElem;
		NewElem->next = NULL;
		NewElem->down = NULL;
		LastStolb->next = NewElem;
		if (i == 0)
		{
			M->suk = NewElem;
			M->j++;
		}
		else
		{
			M->suk->down = NewElem;
			M->suk = M->suk->down;
			M->i++;
		}
		LastStolb = LastStolb->down;
	}
	M->m++;
}

int FreeMem_int1(matr *&M)
{
	if (checker(M) == true)
	{
		printf("\nматрица уже пуста\n\n");
		return 0;
	}
	TElem *dop;
	M->suk = M->first; // перемещаем текущий на 1
	M->i = 0;
	M->j = 0;
	while (M->first != NULL)
	{
		M->suk = M->first;
		M->first = M->first->down;
		while (M->suk != NULL)
		{
			dop = M->suk;
			M->suk = M->suk->next;
			delete dop;
		}
	}
	M->m = 0;
	M->n = 0;
	printf("\nОчищено\n\n");
	return 0;
}

int ReadCurrent(matr *&M)
{
	return (M->suk->a);
}

void ChangeCur(matr *&M, int b)
{
	M->suk->a = b;
}

void IznpozCurrent(matr *&M, int a, int b) // сделать текущим элемент[a - 1, b - 1]
{
	MakeItI(M, a);					// перемещаем текущий на [a -1, 0]
	for (int i = 0; i < b - 1; i++) // идём построке до нужного элемента
	{
		M->suk = M->suk->next;
		M->j++;
	}
}

void Index(matr*& M, int n, int m, int a)
{
	TElem* dop;
	dop = M->first;
	M->i = 0;
	for (int i = 0; i < n - 1; i++) // спуск до нужной строки
	{
		dop = dop->next;
	}
	for (int i = 0; i < m - 1; i++) // переход до нужного столбца
	{
		dop = dop->down;
	}
	dop->a = a; // изменение значения
	
}

int ReadMatrix(matr *&M, int n, int m)
{
	IznpozCurrent(M, n, m);
	return (ReadCurrent(M));
}

int Outlog(matr *&M, FILE *log)
{
	fprintf(log, "\nМатрица из списка:\n");
	if (checker(M)) // проверка на пустоту
	{
		fprintf(log, "матрица пуста\n");
		return 0;
	}
	for (int i = 0; i < M->n; i++)
	{
		for (int j = 0; j < M->m; j++)

			fprintf(log, " %3d ", ReadMatrix(M, i + 1, j + 1)); // вывод значений в лог файл
		fprintf(log, "\n");
	}

	return 0;
}

//Программный код процедуры для решения задачи (фильтр/поиск)
int Solution(matr *&M, int t1, int t2)
{
	if (checker(M) == true)
	{
		printf("\nматрица пуста => нельзя найти решение\n\n");
		return 0;
	}
	int nom = 0;
	int minnom = 0;
	int min;
	int a;
	bool flag, flag2 = true;
	for (int j = 1; j <= M->m; j++)
	{
		for (int i = 1; i <= M->n; i++)
		{
			nom++;
			if (ReadMatrix(M, i, j) == t2 && !flag)
			{
				flag = true;
			}
			else if ((ReadMatrix(M, i, j) > t1) && (flag))
			{

				if (flag2)
				{
					min = ReadMatrix(M, i, j);
					flag2 = false;
				}
				if ((ReadMatrix(M, i, j) <= min))
				{
					minnom = nom;
					min = ReadMatrix(M, i, j);
				}
			}
		}
	}
	return minnom;
}
//Программный код процедуры добавление столба из 0
int MainStolb(matr *&M)
{
	if (checker(M) == true)
	{
		printf("\nматрица пуста => нельзя создать новый столбец\n\n");
		return 0;
	}
	NewStolb(M);
	for (int i = 1; i <= M->n; i++)
	{
		Index(M, i, M->m, 0);
	}
	printf("\nстолбец создан\n");
	getchar();
	return 0;
}
//Программный код процедуры добавление строки  из 0
int MainStroka(matr *&M)
{
	if (checker(M) == true)
	{
		printf("\nматрица пуста => нельзя создать новую строку\n\n");
		return 0;
	}
	NewStroka(M);
	for (int i = 1; i <= M->m; i++)
	{
		Index(M, M->n, i, 0);
	}
	printf("\nстрока создана\n");
	getchar();
	return 0;
}
//Программный код процедуры считывание из файла
int MainInput(matr *&M)
{
	int n, m;
	char name[20];
	printf("Введите название файла: ");
	//gets(name);
	FILE *f;
	f = fopen("f.txt", "r");
	if (f == NULL)
	{
		printf("\nневозможно открыть файл\n\n");
		return 0;
	}
	fseek(f, 0, SEEK_END);
	int end1 = ftell(f);
	fseek(f, 0, SEEK_SET);
	int end2 = ftell(f);
	if (end1 == end2)
	{
		printf("\nФайл пуст\n\n");
		return 0;
	}
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);

	CreateEmpty_void(M, n, m);
	int a;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= m - 1; j++)
		{
			fscanf(f, "%d", &a);
			printf("%d ", a);
			Index(M, i +1, j +1, a);
		}
	}
	fclose(f);
	printf("\nсоздали\n\n");
	return 0;
}

//Программный код процедуры для изменения значения по индексу
int MainChangeIndex(matr *&M)
{
	if (checker(M) == true)
	{
		printf("\nМатрица пуста => нечего менять\n\n");
		return 0;
	}
	int i, j;
	int a;
	printf(" Введите значение i: ");
	scanf("%d", &i);
	getchar();
	printf(" Введите значение j: ");
	scanf("%d", &j);
	getchar();
	printf(" Введите значение a: ");
	scanf("%d", &a);
	Index(M, i, j, a);
	printf("\n Изменили\n");
	getchar();
	return 0;
}
