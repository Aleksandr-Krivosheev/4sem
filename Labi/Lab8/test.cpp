#include "Unit.h"


int main()
{
    double x;
    x = 1;

	double res =(pow(exp(-x), 1.0 / 7.0) + ((pow(x, 1.0 / 7.0) * pow(sin(x), 2)) / (1 + log(x + 3))));
    printf(" %-13.f \n",res);

	return 0;
}
