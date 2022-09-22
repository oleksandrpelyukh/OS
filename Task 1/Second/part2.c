#include <math.h>

double gx(int x){

	double g_x;

	g_x = exp(-fabs(x)) * cos(x);

	return g_x;
}
