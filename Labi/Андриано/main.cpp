#include "Header.h"
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "main.h"

int main(int argc, const char* argv[]) {
    setlocale(LC_ALL, "Rus");
    FILE *f1, *f2;
    int **arrA, *arrC, *arrX, N, P, T;
    bool flag;

    printf("������� N: ");
    scanf_s("%d", &N);
    printf("������� P: ");
    scanf_s("%d", &P);
    printf("������� T: ");
    scanf_s("%d", &T);

    arrA = getnew_matr(N);
    arrC = getnew_mass(N);
    arrX = getnew_mass(N);
    
    f1 = fopen("f3.txt", "r");
    f2 = fopen("f2.txt", "w");
    fprintf(f2, "������� ������:\nN = %d\n������ �:\n", N);
    input_matr(arrA, f1, N);
    output_matr(arrA, f2, N);
 
    fprintf(f2, "P = %d\n", P);
    fprintf(f2, "T = %d\n", T);

    input_mass(arrC, f1, N);
    fprintf(f2, "������ �: ");
    output_mass(arrC, f2, N);
    
    flag = prov(arrC, N, P, T);
    if (flag == true) 
    {
        fprintf(f2, "\n�������� ���� ��������� ������� � ����� ����� � = %d � � = %d\n", P, T);
        summa(arrA, arrX, N);
        fprintf(f2, "�������� ����� ��������� ������ ������ ������� �:\n");
        output_mass(arrX, f2, N);
        del_mass(arrX, N);
        del_matr(arrA, N);
        del_mass(arrC, N);
    }
    else
    {
        fprintf(f2, "\n�� ��� �������� ��������� ������� � ����� ����� � = %d � � = %d\n", P, T);
    }
    fclose(f1);
    fclose(f2);
}
