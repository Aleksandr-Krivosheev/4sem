#include "Unit1.h"

bool checker1(matr1*& M)
{
	if (M == NULL)
	{
		return (true); // матрица пуста
	}
	else
	{
		return (false);  // матрица не пуста
	}
}

void CreateEmpty1(matr1*& M, int n, int m)
{
	matr1* NewElem; // для создания нового элемента
	matr1* dop; // будет использоваться вместо M, чтобы не потерять первый элемент
	dop = M;
	matr1* UpperString = NULL; // верхняя строка для заполнения ссылок на нижние элементы матрицы
	matr1* UpperStringDop = NULL; // дополнительный указатель на верхнюю строку
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			NewElem = new matr1;
			NewElem->next = NULL;
			NewElem->under = NULL;
			if (i == 0 && j == 0) //создание самого самого первого элемента
			{
				M = NewElem;
			}

			if (j == 0)// создание первого элемента в строке и запоминание первого элемента в строке
			{
				UpperStringDop = NewElem; // запоминание первого элемента в строке
				dop = NewElem; // типо создание первого элемента в строке

			}
			else // создание связей в строке
			{
				dop->next = NewElem;
				dop = dop->next;
			}

			if (i != 0) // создание нижних связей в верхней строке
			{
				UpperString->under = NewElem; // создание самой связи
				UpperString= UpperString->next; // переход к некст элементу верхней строки
			}
		}
		UpperString = UpperStringDop; // присвоение первого элемента только что заполненной строки
	}
	M->n = n;
	M->m = m;
}

int out1(matr1*& M,  FILE*& log)
{
	fprintf(log, "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\nМатрица из списка:\n");
	if (M == NULL) // проверка на пустоту
	{
		fprintf(log, "матрица пуста\n");
		return 0;
	}
	matr1* elem; //дополнительный укзаатель для хождения по матрице
	matr1* FirstElem; // запоминает первый элемент в строке, чтобы при достижении конца строки перейти к началу следующей
	elem = M;
	FirstElem = elem;
	while (elem!=NULL)
	{
		while (elem!= NULL)
		{
			if (elem->a == -842150451) // если была выделена память, то самих значений не будет (вывод вместо значений NULL) 
			{
				fprintf(log, " NULL ");
			}
			else
			{
				fprintf(log, " %3d  ", elem->a);  // вывод значений в лог файл
			}
			elem = elem->next;
		}
		fprintf(log, "\n");
		elem = FirstElem->under; // переход к первому элементу некст строки
		if (elem!= NULL) // если есть элемент некст строки, то снова запоминаем его
			FirstElem = elem;
	}
	return 0;
}

void NewStroka1(matr1*& M)
{
	matr1* UpperElem = M; // указатель на первый элемент верхней строки длля создания связей внзи
	matr1* elem = NULL; // указатель, который будет идти по последней строке
	matr1* NewElem = NULL;

	while (UpperElem ->under != NULL) // спуск до последней строки
	{
		UpperElem = UpperElem->under;
	}

	while (UpperElem!= NULL) // содание нового строки
	{

		NewElem = new matr1;
		NewElem->next = NULL;
		NewElem->under = NULL;
		UpperElem->under = NewElem;
		if (elem == NULL) // создание первого элемента на новой строке
			elem = NewElem;
		else  // если элемент не первый, то продолжаем связь
		{
			elem->next = NewElem;
			elem = elem->next;
		}
		UpperElem = UpperElem->next;
	}
	M->n++;
}

void NewStolb1(matr1*& M)
{
	matr1* elem = NULL; // идет по новому столбцу и делает связи вниз
	matr1* NewElem; // для создания новых элементов
	matr1* LastStolb = M; // последний существующий столбец шоб сделать связи next
	while (LastStolb->next != NULL) // доходим до последнего столбца
	{
		LastStolb = LastStolb->next;
	}

	while (LastStolb != NULL)
	{
		NewElem = new matr1;
		NewElem->next = NULL;
		NewElem->under = NULL;
		if (elem == NULL)
			elem = NewElem;
		else
		{
			elem->under = NewElem;
			elem = elem->under;
		}
		LastStolb->next = NewElem;
		LastStolb = LastStolb->under;
	}
	M->m++;
}

int cleaner1(matr1*& M)
{
	if (checker1(M) == true)
	{
		printf("\nматрица уже пуста\n\n");
		return 0;
	}
	matr1* NextStroka;
	matr1* dop;
	while (M != NULL)
	{
		if (M->under != NULL)
			NextStroka = M->under;
		else
			NextStroka = NULL;

		while (M != NULL)
		{
			dop = M;
			M = M->next;
			delete dop;
		}
		M = NextStroka;
	}
	printf("\nОчищено\n\n");
	return 0;
}

void MakeItI1(matr1*& M, matr1*& CurM, int a)
{
	matr1* dop;
	dop = M;
	for (int i = 0; i < a - 1; i++) // спуск до нудной строки
	{
		dop = dop->under;
	}
	CurM = dop;
}

void MakeItJ1(matr1*& M, matr1*& CurM, int a)
{
	matr1* dop;
	dop = M;
	for (int i = 0; i < a - 1; i++) // до нужного столбца
	{
		dop = dop->next;
	}
	CurM = dop;
}

void NextElemStr1(matr1*& M)
{
	M = M->next;
}

void NextElemStolb1(matr1*& M)
{
	M = M->under;
}

int read1(matr1*& M)
{
	return M->a;
}

void changeCur1(matr1*& Cur, int a)
{
	Cur->a = a;
}

int Index1(matr1*& M, int n, int m, int a)
{
	matr1* dop;
	dop = M;
	for (int i = 0; i < n - 1; i++) // спуск до нужной строки
	{
		dop = dop->under;
	}
	for (int i = 0; i < m - 1; i++) // переход до нужного столбца
	{
		dop = dop->next;
	}
	dop->a = a; // изменение значения
	return 0;
}

int ReadMatr1(matr1*& M, int n, int m)
{
	matr1* dop;
	dop = M;
	for (int i = 0; i < n - 1; i++) // спуск до нужной строки
	{
		dop = dop->under;
	}
	for (int i = 0; i < m - 1; i++)  // переход до нужного столбца
	{
		dop = dop->next;
	}
	return dop->a;
}
///////////////////////////////////////////////////////////////////////////////////////////4main
int MainCleaner1(matr1*& M)
{
	cleaner1(M);
	return 0;
}

int MainInput1(matr1*& M)
{
	int n, m;
	char name[20];
	printf("Введите название файла: ");
	//fgetc(name);
	FILE* f = fopen("f.txt", "r");
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
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
	CreateEmpty1(M, n, m);
	int a;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= m - 1; j++)
		{
			fscanf(f, "%d", &a);
			Index1(M, i + 1, j + 1, a);
		}
	}
	fclose(f);
	printf("\nсоздали\n\n");
	return 0;
}

int MainChangeIndex1(matr1*& M)
{
	if (checker1(M) == true)
	{
		printf("\nМатрица пуста => нечего менять\n\n");
		return 0;
	}
	int i, j;
	int a;
	printf("Введите значение i: ");
	scanf("%d", &i);
	getchar();
	printf("Введите значение j: ");
	scanf("%d", &j);
	getchar();
	printf("Введите значение a: ");
	scanf("%d", &a);
	Index1(M, i, j, a);
	printf("\nизменили\n\n");
	return 0;
}

int MainStolb1(matr1*& M)
{
	if (checker1(M) == true)
	{
		printf("\nматрица пуста => нельзя создать новый столбец\n\n");
		return 0;
	}
	NewStolb1(M);
	for (int i = 1; i <= M->n; i++)
	{
		Index1(M, i, M->m, 0);
	}
	printf("\nстолбец создан\n\n");
	return 0;
}

int MainStroka1(matr1*& M)
{
	if (checker1(M) == true)
	{
		printf("\nматрица пуста => нельзя создать новую строку\n\n");
		return 0;
	}
	NewStroka1(M);
	for (int i = 1; i <= M->m; i++)
	{
		Index1(M, M->n, i, 0);
	}
	printf("\nстрока создана\n\n");
	return 0;
}

int MainSolution1(matr1*& M)
{
	if (checker1(M) == true)
	{
		//printf("\nматрица пуста => нельзя найти решение\n\n");
		return 0;
	}
	int schet = 0;
	int minschet = 0;
	int min = 999;
	int a;
	for (int i = 1; i <= M->n; i++)
	{
		for (int j = 1; j <= M->m; j++)
		{
			if (ReadMatr1(M, i, j) % 5 == 0)
			{
				return minschet;
			}
			schet++;
			if ((ReadMatr1(M, i, j) > 0) && (ReadMatr1(M, i, j) < min))
			{
				minschet = schet;
				min = ReadMatr1(M, i, j);
			}
		}
	}
	return 0;
}