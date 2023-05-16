#pragma once
#include <stdio.h>
#include <math.h>

int input(float& A, float&B, int &N);

double formula1(double x);

double formula2(double x);

double proizv(double(*res)(double x), double x1, double e);

double func1(double x);

double func2(double x);

int checker(double(*res)(double x), float a, float b);

void SolFunc1(double(*res)(double x), double a, double b, int n, double& arr, int& m, double e);

void SolFunc2(double(*res)(double x), double(*pr)(double(*resx)(double x), double xx, double e),double (*func)(double x), double a, double b, int n, double& arr, int& m, double e);

void output(int n, double* arr, int* m, double* arr1, int* m1);
