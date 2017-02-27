/* -------------------------------------------------------------------
    				Estimation of an integral
    			    using Monte Carlo method
 -------------------------------------------------------------------- */

/* Sergi Roca Bonet, Barcelona 2016 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int n, i;
double r, integral, xi, xf;
double integrand(double r);
double random_generator();
//#define pi acos(-1.);

/* This is the function we are going to integrate */
double integrand (double x){
	double f = x + sin(x);
	return f;
}

int main(void) {

	double pi = acos(-1.);
/* limits of the integration */
	xi = 0. ; xf = pi ;

	printf("--------------------------------------------------\n");
	printf("  Number of random numbers :  ");
	scanf("%d", &n);  //scan how many random numbers we want to use
/* begin with the loop : send random numbers to the integrand */
	for (i = 0; i < n; i++) {
		r = pi*random_generator();
/* multiply by the maximum x given that random_generator() only goes
  from 0 to 1 */
		integral += integrand(r);
	}
	integral *= (xf-xi)/(double)(n);
	printf("  I = %f\n", integral);
	printf("--------------------------------------------------\n");
}

/* random number generator (a very basic one) */
double random_generator() {
    return (double)rand() / (double)RAND_MAX ;
}
