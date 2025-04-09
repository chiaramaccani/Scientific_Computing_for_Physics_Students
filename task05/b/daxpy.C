#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#define MAX_LINE_LENGTH 256




int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <N vector length>\n", argv[0]);
        return 1;
    }


    int N = atoi(argv[1]);

    const float a = 3.0;

    gsl_vector *x = gsl_vector_alloc(N);
    gsl_vector *y = gsl_vector_alloc(N);
    gsl_vector *d = gsl_vector_alloc(N); 

    gsl_rng_env_setup();
    gsl_rng *r = gsl_rng_alloc(gsl_rng_default);
    const double sigma = 1.0;

    printf("N: %d\n", N);

    double g;
    for (size_t i = 0; i < N; ++i) {
        g = gsl_ran_gaussian(r, sigma); // mean = 0, std dev = sigma
        //printf("g: %lf\n", g);
        gsl_vector_set(x, i, g);
        g = gsl_ran_gaussian(r, sigma); // mean = 0, std dev = sigma
        gsl_vector_set(y, i, g);
    }


    gsl_vector_memcpy(d, y);
    gsl_vector_axpby(a, x, 1.0, d);

    printf("x[0]: %lf, y[0]: %lf, d[0]: %lf\n", gsl_vector_get(x, 0), gsl_vector_get(y, 0), gsl_vector_get(d, 0));



    // Compute empirical mean and variance of d
    double sum = 0.0, sumsq = 0.0;
    for (size_t i = 0; i < N; ++i) {
        double di = gsl_vector_get(d, i);
        sum += di;
        sumsq += di * di;
    }
    double mean = sum / N;
    double var = (sumsq / N) - (mean * mean);

    const double mu_x = 0.0, sigma_x = 1.0;
    const double mu_y = 0.0, sigma_y = 1.0;
    // Expected values
    double expected_mean = a * mu_x + mu_y;
    double expected_var = a * a * sigma_x * sigma_x + sigma_y * sigma_y;

    printf("Empirical mean = %g, Expected mean = %g\n", mean, expected_mean);
    printf("Empirical var  = %g, Expected var  = %g\n", var, expected_var);


    gsl_vector_free(x);
    gsl_vector_free(y);
    gsl_vector_free(d);
    

    return 0;
}
