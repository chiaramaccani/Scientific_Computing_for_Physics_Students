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
    printf("Vector elements:\n");
    double sum = 0.0;
    for (int i = 0; i < vec->size; i++) {
        sum += gsl_vector_get(vec, i);
    }
    printf("Sum of vector elements: %.20lf\n", sum);

    double v[] = {1.0,1.0e16, -1.0e16, -0.5};
    double sum2 = 0.0;
    for (int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
        sum2 += v[i];
    }
    printf("Sum of array elements: %.20lf\n", sum2);

    double sum_Kahan = 0.0;
    double c = 0.0; 
    for (int i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
        double y = v[i] - c; 
        double t = sum_Kahan + y; 
        c = (t - sum_Kahan) - y; 
        sum_Kahan = t; 
    }
    printf("Sum of array elements (Kahan): %.20lf\n", sum_Kahan);


return 0;
}