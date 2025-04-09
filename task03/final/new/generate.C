#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <hdf5.h>
#include <utils.h>


int generate(int N, char* filename_prefix, char* format) {

    char* N_char = (char *)malloc(10);
    snprintf(N_char, 10, "%d", N);

    if (N <= 0) {
        printf("Invalid dimension size.\n");
        return 1;
    }

    const char* filename_format_x = "%svector_N%d_x%s";
    const char* filename_format_y = "%svector_N%d_y%s";
    int size = strlen(filename_format_x) + strlen(filename_prefix) + strlen(N_char) + strlen(format)+1;
    char* filename_x = (char *)malloc(size);
    char* filename_y = (char *)malloc(size);
    snprintf(filename_x, size, filename_format_x, filename_prefix, N, format);
    snprintf(filename_y, size, filename_format_y, filename_prefix, N, format);

    double x_value = 0.1;
    double y_value = 7.1;
       
    gsl_vector *x = gsl_vector_alloc(N);
    gsl_vector *y = gsl_vector_alloc(N);

    for (int i = 0; i < N; i++) {
        gsl_vector_set(x, i, x_value);
        gsl_vector_set(y, i, y_value);
    }

    printf("x[0]: %lf, y[0]: %lf\n", gsl_vector_get(x, 0), gsl_vector_get(y, 0));

    write_gsl_array_to_hdf5(filename_x, x);
    write_gsl_array_to_hdf5(filename_y, y);

    free(x);
    free(y);
    return 0;
}
