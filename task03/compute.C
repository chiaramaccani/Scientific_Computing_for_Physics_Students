#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <hdf5.h>
#include <utils.h>
#include <gsl/gsl_vector.h>

#define MAX_LINE_LENGTH 256


int compute(char* prefix, int N, double a, char* format) {

    char* N_char = (char *)malloc(10);
    snprintf(N_char, 10, "%d", N);

    gsl_vector *x = gsl_vector_alloc(N);
    gsl_vector *y = gsl_vector_alloc(N);
    gsl_vector *d = gsl_vector_alloc(N); 

    const char* filename_format_x = "%svector_N%d_x%s";
    const char* filename_format_y = "%svector_N%d_y%s";
    int size = strlen(filename_format_x) + strlen(prefix) + strlen(N_char) + strlen(format)+1;
    char* filename_x = (char *)malloc(size);
    char* filename_y = (char *)malloc(size);
    snprintf(filename_x, size, filename_format_x, prefix, N, format);
    snprintf(filename_y, size, filename_format_y, prefix, N, format);

    read_hdf_array_into_gsl(filename_x, x);
    read_hdf_array_into_gsl(filename_y, y);

    gsl_vector_memcpy(d, y);
    gsl_vector_axpby(a, x, 1.0, d);


    char* filename_d = (char *)malloc(size); 
    const char* filename_format_d = "%svector_N%d_d%s";
    snprintf(filename_d, size, filename_format_d, prefix, N, format);
    

    write_gsl_array_to_hdf5(filename_d, d);


    printf("FILE %s succesfully created\n", filename_d);
    printf("x[0]: %lf, y[0]: %lf, d[0]: %lf\n", gsl_vector_get(x, 0), gsl_vector_get(y, 0), gsl_vector_get(d, 0));
    free(x); x = NULL;
    free(y); y = NULL;
    free(d); d = NULL;
    free(filename_x); filename_x = NULL;
    free(filename_y); filename_y = NULL;
    free(filename_d); filename_d = NULL;
    return 0;
}

