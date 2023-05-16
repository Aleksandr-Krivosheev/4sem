#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <stdlib.h>
void input_matr(int **arr, FILE* f, const int n);
void output_matr(int **arr, FILE* f, const int n);
int **getnew_matr( const int n);
void del_matr(int **&arr, const int n);
int max_min_res(int **arr, const int n);
int new_matr(int **arr, const int n);

#endif 