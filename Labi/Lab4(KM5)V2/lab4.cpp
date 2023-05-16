#include "Unit.h"

int main() {

	FILE* fin = fopen("1.txt", "r");
	FILE* fout = fopen("2.txt", "w");

	int n;
	bool fl;
	double* x;

	input(fin, n, x);
	output(fout, n, x);
	fprintf(fout, "\n");
	fl = recurs(x, 0, n-1);
	if (fl == true) 
		fprintf(fout, "Условие выполняется для всех элементов массива \n");
	else
		fprintf(fout, "Условие не выполняется  \n");
	
	fclose(fin);
	fclose(fout);

	return 0;
}
