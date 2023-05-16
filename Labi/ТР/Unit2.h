#pragma once
#include <stdio.h>

struct matr2 {
	FILE* f; // файл
	int m, n;
};



bool checker2(matr2& M); // проверка на пустоту (TRUE -  пусто)

int CreateEmpty2(matr2& M, int n, int m); // создание пустой матрицы размера nXm

void NewStroka2(matr2& M); // создание новой строки (выделение памяти под новую строку)

void NewStolb2(matr2& M); // создание нового столбца

int out2(matr2& M, FILE*& log); // вывод в log файл

int cleaner2(matr2& M); // очистка (освобождение памяти)

void MakeItI2(matr2& M, int a); // сделать текущим первый элемент строки под номером a 

void MakeItJ2(matr2& M, int a); // сделать текущим первый элемент столбца под номером a

void NextElemStr2(matr2& M); // сделать текущим следующий элемент в строке

void NextElemStolb2(matr2& M); // сделать текущим первый элемент в столбце

int read2(matr2& M); // считать значение текущего элемента

void ChangeCur2(matr2& M, int a); // поменять значение текущего элемента 

void Index2(matr2& M, int n, int m, int a); // изменить значение элемента с индексами i и j на заданное значение а

int ReadMatr2(matr2& M, int n, int m); // считать значение элемента с индексами i  и  j
/////////////////////////////////////////////////4main
void MainCleaner2(matr2& M);

int MainInput2(matr2& M);

int MainChangeIndex2(matr2& M);

int MainStolb2(matr2& M);

int MainStroka2(matr2& M);

int MainSolution2(matr2& M);
