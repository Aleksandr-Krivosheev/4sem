#include "Unit.h"

int main()
{
    FILE* f;
    int* Q;
    int N;
    int l = 0;
    input(f, N, Q);
    bool flag;
    flag = recursion(N, Q);
    output(N, Q, flag, l);
    //output1(N, Q, flag, l,derevo);
    delete[] Q;
    fclose(f);
}

