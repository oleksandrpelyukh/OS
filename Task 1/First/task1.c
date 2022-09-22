#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

	double f_x, g_x;
	int x;

	printf("Enter x value: ");
	scanf("%d", &x);

	f_x = exp(- abs(x) ) * sin(x);
	g_x = exp(- abs(x) ) * cos(x);

	printf("F(x) = %lf|| G(x) = %lf \n", f_x, g_x);
	return 0;
}
