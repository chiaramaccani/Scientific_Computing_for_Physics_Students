#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_vector.h>


int main(int argc, char** argv) {

    gsl_vector *vec = gsl_vector_alloc(4);
    gsl_vector_set(vec, 0, 1.0);
    gsl_vector_set(vec, 1, 1.0e16);
    gsl_vector_set(vec, 2, -1.0e16);
    gsl_vector_set(vec, 3, -0.5);

    double sum = 0.0;
    for (int i = 0; i < vec->size; i++) {
        sum += gsl_vector_get(vec, i);
    }
    printf("Sum of elements GSL: %.20lf\n", sum);

    double v[4] = {1.0,1.0e16, -1.0e16, -0.5};

    double sum2 = 0.0;
    for (int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
        sum2 += v[i];
    }
    printf("Sum of array elements: %.20lf\n", sum2);

    double sum_Kahan = 0.0;
    double c = 0.0; 
    for (int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
        //printf("i = %d, sum  = %.20lf v[i] = %.20lf, c = %.20lf, \n", i, sum_Kahan, v[i], c );
        double y = v[i] - c; 
        double t = sum_Kahan + y; 
        c = (t - sum_Kahan) - y; 
        //printf("y = %.20lf, t = %.20lf, c = %.20lf\n", y, t, c);
        sum_Kahan = t; 
    }
    printf("Sum of array elements (Kahan): %.20lf\n", sum_Kahan);


    long double sum_ld = 0.0;
    for (int i = 0; i < 4; i++) {
        sum_ld += (long double)v[i];
    }
    printf("\nSum with long double: %.20Lf\n", sum_ld);


    long double sum_Kahan_ld = 0.0;
    long double c1 = 0.0;

    for (int i = 0; i < 4; i++) {
        long double y = (long double)v[i] - c1;
        long double t = sum_Kahan_ld + y;
        c1 = (t - sum_Kahan_ld) - y;
        sum_Kahan_ld = t;
    }

    printf("Sum with Kahan (long double): %.20Lf\n", sum_Kahan_ld);


return 0;
}