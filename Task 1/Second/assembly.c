#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "part1.c"
#include "part2.c"

int main(){

	double f_x, g_x;
	int x;

	printf("Enter x value: ");
	scanf("%d", &x);

	f_x = fx(x);
	g_x = gx(x);

	printf("F(x) = %lf|| G(x) = %lf \n", f_x, g_x);
	return 0;
}
