﻿/*Для заданной схемы разбить её на две части таким образом, чтобы
первым элементом в первую часть поместить элемент, входящий в
максимальное число цепей.*/

#include <iostream>

using namespace std;

const int e = 14;
const int c = 20;
const int matr[c][e] = {
    //------------------элементы-------------------—
            //1  2  3  4  5  6  7  8  9  10 11 12 13 14 |
            { 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0 }, //1 |
            { 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, //2 |
            { 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1 }, //3 |
            { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 }, //4 |
            { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 }, //5 |
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 }, //6 |
            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, //7 |
            { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 }, //8 ц
            { 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 }, //9 е
            { 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1 }, //10 п
            { 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 }, //11 и
            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0 }, //12 |
            { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 }, //13 |
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 }, //14 |
            { 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, //15 |
            { 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1 }, //16 |
            { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //17 |
            { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 }, //18 |
            { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1 }, //19 |
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 }, //20 |
};

int main()
{
    cout << "matr:" << endl << endl;

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < e; j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }

    int kol = 0, count = 0, max_num = 0;
    for (int i = 0; i < c; i++) {
        if (matr[i][0] == 1) {
            kol++;
        }
    }

    for (int j = 0; j < e; j++) 
    {
        for (int i = 0; i < c; i++)
        {
            if (matr[i][j] == 1) 
                count++;
        }
        if (count > kol)
        {
            max_num = j + 1;
            kol = count;
        }
        cout << "count " << count << endl;
        count = 0;
    }
    cout << "max " << max_num;

    int matr1[c][e - max_num + 1];
    int k = 0;
    for (int i = 0; i < c; i++) {
        for (int j = max_num - 1; j < e + 1; j++) {
            matr1[i][k] = matr[i][j];
            k++;
        }
        k = 0;
    }
    cout << endl << "first: " << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < (e - max_num + 1); j++) {
            cout << matr1[i][j] << " ";
        }
        cout << endl;
    }
    int matr2[c][max_num];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < max_num - 1; j++) {
            matr2[i][j] = matr[i][j];
        }
    }
    cout << endl << "second: " << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < max_num - 1; j++) {
            cout << matr2[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}