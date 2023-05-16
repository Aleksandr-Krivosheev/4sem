#include <iostream>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <locale>
using namespace std;
#define nmax 100

void matr(float X[nmax][nmax], int n, int m, FILE *f)//Считаем матрицу из файла
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d\t", X[i][j]);// функция fscanf считывает из файла f, то что в "" это какой тип данных он считывает, куда записывает 
        }
        fscanf(f, "\n");// это следующая страка
    }
}

bool pr(float X[nmax][nmax], bool f, int n, int m)
{
    f = true;
    int i, j, d;
    for (i = 0; i < n; i++)
    {
        d = 0;
        for (j = 0; j < m; j++)
        {
            d = d + X[i][j];
        }
        if (d <= 0)
        {
            f = false;
        }
    }
    return f;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE *t1, *t2, *t3;
    int n, m, n2, m2, n3, m3, i;
    bool f1, f2, f3, h;
    float X1[nmax][nmax], X2[nmax][nmax], X3[nmax][nmax];
    n = 0;
    m = 0;
    n2 = 0;
    m2 = 0;
    n3 = 0;
    m3 = 0;
    h = true;

    cout << "Введите размерность 1-го массива: ";
    cin >> n;//размерность 
    cin >> m;
    t1 = fopen("f1.txt", "r"); //Открываем файл с матрицей
    matr(X1, n, m, t1);//считываем матрицу 

    cout << "Введите размерность 2-го массива: ";
    cin >> n2;
    cin >> m2;
    t2 = fopen("f2.txt", "r");
    matr(X2, n2, m2, t2);

    cout << "Введите размерность 3-го массива: ";
    cin >> n3;
    cin >> m3;
    t3 = fopen("f3.txt", "r");
    matr(X2, n2, m2, t3);

    cout << "Введите значение: ";

    f1 = pr(X1, h, n, m);
    f2 = pr(X2, h, n2, m2);
    f3 = pr(X3, h, n3, m3);
    cout << "\n"
         << f1 << "\n"
         << f2 << "\n"
         << f3;

    fclose(f1);
    fclose(f2);
    fclose(f3);
}