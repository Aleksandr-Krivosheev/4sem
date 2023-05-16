#include <iostream>
#include <stdio.h> // printf, scanf
#include "Header.h"
using namespace std;


int main(int argc, const char* argv[])
{
    FILE *f1, *f2;
    int   E, N, res, zam;
    bool flag;
    int **arrA;


    printf("Введите N: ");
    scanf("%d", &N);
    printf("Введите E: ");
    scanf("%d", &E);

    arrA = getnew_matr(N);

    f1 = fopen("f1.txt", "r"); 
    f2 = fopen("f2.txt", "w");
    fprintf(f2, "Входные данные:\nN = %d\n", N);
    fprintf(f2, "E = %d\n", E);
    fprintf(f2, "Массив А:\n");
    input_matr(arrA, f1, N);
    output_matr(arrA, f2, N);

    res = max_min_res(arrA, N);

        if (res > E) {
            fprintf(f2, "Измененная матрица А:\n");
            zam = new_matr(arrA, N);
            output_matr(arrA, f2, N);
            fprintf(f2, "Количество сделанных замен:%d\n", zam);


    }
        else{
             fprintf(f2, "\n Значение E > разность  максимального  и  минимального элемента матрицы А\n");
            
        }

 del_matr(arrA, N);

    fclose(f1);
    fclose(f2);
}
