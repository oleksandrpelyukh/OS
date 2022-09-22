#include <math.h>

double fx (int x){

	double f_x;

	f_x = exp(-fabs(x)) * sin(x);
	
	return f_x;
}
