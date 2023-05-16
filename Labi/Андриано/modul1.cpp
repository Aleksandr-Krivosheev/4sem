#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int **getnew_matr(const int n)
{
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    return (arr);
}

int *getnew_mass(const int n)
{
        int  *arr = new int[n];
        return arr;
}

void del_matr(int **&arr, const int n)
{
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}

void del_mass(int *&arr, const int n)
{
    delete[] arr;
}

void input_matr(int **arr, FILE *f, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /*try
            {*/
                fscanf_s(f, "%d", &arr[i][j]);
            /*}
            catch (exception &e)
            {
                cout << e.what();
            }*/
        }
        fscanf_s(f, "\n");
    }
}

void input_mass(int *arr, FILE *f, const int n)
{
    for (int i = 0; i < n; i++)
        fscanf_s(f, "%d", &arr[i]);
}

void output_matr(int **arr, FILE *f, const int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf_s(f, "%4d\t", arr[i][j]);
        }
        fprintf_s(f, "\n");
    }
}

void output_mass(int *arr, FILE *f, const int n)
{
    for (int i = 0; i < n; i++) 
        fprintf_s(f, "%d %c",arr[i], ' ');
}

bool prov(int *arr, const int n, const int P, const int T)
{
    bool F = true;
    int i = 0;
    while ((F) && (i < n))
    {
        if ((arr[i] <= P) || (arr[i] >= T)) {
            F = false;
        }
        i++;
    }
    return F;
}

void summa(int **a, int *b, const int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = 0; 
        for (int j = 0; j < n; j++)
            b[i] += a[i][j];
    }
}
