#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <stdlib.h>
void input_matr(int **arr, FILE* f, const int n);
void input_mass(int *arr, FILE* f, const int n);
void output_matr(int **arr, FILE* f, const int n);
void output_mass(int *arr, FILE* f, const int n);
bool prov(int *arr, const int n, const int P, const int T);
void summa(int **a, int *b, const int n);
int **getnew_matr( const int n);
int *getnew_mass( const int n);
void del_matr(int **&arr, const int n);
void del_mass(int *&arr, const int n);
#endif 