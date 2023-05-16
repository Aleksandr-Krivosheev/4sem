#pragma once
#include <stdio.h>

struct matr1
{
	int a; // значение
	matr1* next; // следующий элемент
	matr1* under; // нижний элемент
	int n, m;
};


bool checker1(matr1*& M);    // проверка на пустоту (TRUE -  пусто)

void CreateEmpty1(matr1*& M, int n, int m);   // создание пустой матрицы размера nXm

void NewStroka1(matr1*& M); // создание новой строки (выделение памяти под новую строку)

void NewStolb1(matr1*& M); // создание нового столбца

int out1(matr1*& M, FILE*& log); // вывод в log файл

int cleaner1(matr1*& M); // очистка (освобождение памяти)

void changeCur1(matr1*& Cur, int a); // поменять значение текущего элемента 

void MakeItI1(matr1*& M, matr1*& CurM, int a); // сделать текущим первый элемент строки под номером a

void MakeItJ1(matr1*& M, matr1*& CurM, int a); // сделать текущим первый элемент столбца под номером a

void NextElemStr1(matr1*& M); // сделать текущим следующий элемент в строке

void NextElemStolb1(matr1*& M); // сделать текущим первый элемент в столбце

int read1(matr1*& M); // считать значение текущего элемента

int Index1(matr1*& M, int n, int m, int a); // изменить значение элемента с индексами i и j на заданное значение а

int ReadMatr1(matr1*& M, int n, int m); // считать значение элемента с индексами i  и  j
/////////////////////////////////////////////////////////4main
int MainCleaner1(matr1*& M); //

int MainInput1(matr1*& M);

int MainChangeIndex1(matr1*& M);

int MainStolb1(matr1*& M);

int MainStroka1(matr1*& M);

int MainSolution1(matr1*& M);
