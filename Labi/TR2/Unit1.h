#pragma once
#include <stdio.h>

struct TElem
{
	int a;
	TElem *next;
	TElem *down;
};

struct matr
{
	TElem *first; // первый элемент
	TElem *suk; // текущий элемент
	int n, m, i, j;
};

bool checker(matr*& M);					  // проверка на пустоту (TRUE -  пусто)
void CreateEmpty_void(matr*& M, int n, int m);	  // создание пустой матрицы размера nXm
void NewStroka(matr *&M);				  // создание новой строки (выделение памяти под новую строку)
void NewStolb(matr *&M);					  // создание нового столбца
int Outlog(matr *&M, FILE *log);			  // вывод в log файл
int cleaner(matr *&M);					  // очистка (освобождение памяти)
void MakeItI(matr *&M, int a);			  // сделать текущим первый элемент строки под номером a
void MakeItJ(matr *&M, int a);			  // сделать текущим первый элемент столбца под номером a
void NextElemStr(matr *&M);				  // сделать текущим следующий элемент в строке
void NextElemStolb(matr *&M);			  // сделать текущим первый элемент в столбце
int ReadCurrent(matr *&M);				  // считать значение текущего элемента
void ChangeCur(matr *&M, int a);			  // поменять значение текущего элемента
void Index(matr *&M, int n, int m, int a); // изменить значение элемента с индексами i и j на заданное значение а
int ReadMatrix(matr *&M, int n, int m);	  // считать значение элемента с индексами i  и  j

int MainChangeIndex(matr *&M);
int MainInput(matr *&M);
int Solution(matr *&M, int t1,int t2);
int MainStroka(matr *&M);
int MainStolb(matr *&M);
int FreeMem_int1(matr *&M);


