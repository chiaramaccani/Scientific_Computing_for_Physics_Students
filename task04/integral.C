#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_vector.h>

#define MAX_LINE_LENGTH 256

void read_config(char* config_filename, int* N, double* x_inf, double* x_sup) {
    char line[MAX_LINE_LENGTH];
    FILE *fconfig = fopen(config_filename, "r");
    if (fconfig == NULL) {
        perror("Error opening config file");
        exit(1);
    }
    while (fgets(line, sizeof(line), fconfig)) {
        
        char key[MAX_LINE_LENGTH];
        char value[MAX_LINE_LENGTH];
        sscanf(line, "%s = %s", key, value);
        if (strcmp(key, "N") == 0) {
            *N = atoi(value);
        } else if (strcmp(key, "x_inf") == 0) {
            *x_inf = atof(value);
        }else if(strcmp(key, "x_sup") == 0) {
            *x_sup = atof(value);
        }
    }
    fclose(fconfig);
}


double f(double x, void *params) {
    return exp(x)*cos(x);
}


double trapezoidal_rule(double (*func)(double, void*), double a, double b, int N) {
    double h = (b - a) / N;  
    double sum = 0.5 * (func(a, NULL) + func(b, NULL));  
    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += func(x, NULL);
    }
    return sum * h;
}


int main(int argc, char** argv) {
    
    if (argc != 2) {
        printf("Usage: %s <config_filename>\n", argv[0]);
        return 1;
    }


    // Read parameters from config file
    char *config_filename = argv[1];
    int N = 0;
    double x_inf = 0, x_sup = 0;
   
    read_config(config_filename, &N, &x_inf, &x_sup);
    printf("\nRead parameters from config file:\n");
    printf("N: %d\n", N);
    printf("x_inf: %.16lf\n", x_inf);
    printf("x_sup: %.16lf\n\n", x_sup);

    // Generate N sampling points (x, f(x)) and save to file
    printf("Generating %d sampling points...\n", N);
    gsl_vector *x = gsl_vector_alloc(N);
    gsl_vector *f_x = gsl_vector_alloc(N);
    double step = (x_sup - x_inf) / (N - 1);

    for (int i = 0; i < N; i++) {
        double xi = x_inf + i * step;
        gsl_vector_set(x, i, xi);
        gsl_vector_set(f_x, i, f(xi, NULL));
    }

    FILE *file = fopen("f_result.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        fprintf(file, "%.16lf %.16lf\n", gsl_vector_get(x, i), gsl_vector_get(f_x, i));
    }
    fclose(file);

    printf("Sampling points saved to f_result.txt\n");

    // Calculate the integrals
    printf("\nCalculating integral...");

    double analitical_result = (exp(M_PI/2)-1)/2;
    printf("\nAnalitical result: %.16lf\n", analitical_result);

    
    // Trapezoidal rule
    double result_trap = trapezoidal_rule(f, x_inf, x_sup, N);
    printf("\nTrapezoidal Integral (N=%d) = %.16f\n", N, result_trap);
    printf("Relative error: %.16lf\n", fabs(result_trap/analitical_result - 1));


    // GSL integration
    printf("\nGSL integration...");
    gsl_function F;
    F.function = &f;
    F.params = NULL;

    double result, error;
    gsl_integration_workspace *w = gsl_integration_workspace_alloc(1000);
    //gsl_integration_qag(&F, x_inf, x_sup, 1e-7, 1e-7, N, GSL_INTEG_GAUSS61, w, &result, &error);
    gsl_integration_qags(&F, x_inf, x_sup, 1e-7, 1e-7, 1000, w, &result, &error);
    printf("\nGLS result: %.16lf\n", result);
    //printf("Error: %.16lf\n", error);
    printf("Relative error: %.16lf\n", fabs(result/analitical_result - 1));



    gsl_vector_free(x);
    gsl_vector_free(f_x);
    gsl_integration_workspace_free(w);

    return 0;
}