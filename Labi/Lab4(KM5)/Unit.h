#pragma once
#include <math.h>
#include <stdio.h>
#include <string.h>

void input(FILE*& f, int& n, int*& arr);

bool recursion(int i, int* arr);

void output(int n, int* arr, bool flag, int l);

void output1(int n, int* arr, bool flag, int l, int ( *outf)(FILE* f, int n1, int* arr1));

int derevo(FILE* f, int n, int* arr);
