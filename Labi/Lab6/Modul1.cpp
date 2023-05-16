#include <iostream>
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int **getnew_matr(const int n)
{
    int **arr = new int* [n];

    for (int i = 0; i < n; i++)
        (arr)[i] = new int[n];
    return (arr);
}

void del_matr(int **&arr, const int n)

{
    for (int i = 0; i < n; i++)
        delete[] (arr)[i];
    delete[] (arr);
}


void input_matr(int **arr, FILE *f, const int n)//Считаем матрицу из файла
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fscanf(f, "%4d\t", &arr[i][j]);
        }
        fscanf(f, "\n");
    }
}


void output_matr(int **arr, FILE *f, const int n)//Запись матрици в файл
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
           fprintf(f, "%4d\t", arr[i][j]);
        }
        fprintf(f, "\n");
    }
}

int max_min_res(int **arr, const int n)
{
    int max, min, res;
    max = arr[0][0];
    min = arr[0][0];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(max < arr[i][j]){
            max = arr[i][j];
            }
            else
            if(min > arr[i][j]){
            min = arr[i][j];
            }
        }
    }
    res = max - min;
    return res;
}


int new_matr(int **arr, const int n)
{
    int zam = 0;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(1 < arr[i][j]){
            arr[i][j] = 1;
            zam = zam + 1;
            }
            else
            if(0 > arr[i][j]){
            arr[i][j] = 0;
            zam = zam + 1;
            }
        }
    }  
    return zam;
}

