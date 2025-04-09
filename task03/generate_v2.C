#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <hdf5.h>

#include <vector_sum.h>


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
       
    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));

    for (long j = 0; j < N; j++) {
        x[j] = x_value;
        y[j] = y_value;
    }

    if (strcmp(format, ".dat") == 0){
        save_array(filename_x, x, N);
        save_array(filename_y, y, N);
    } else if (strcmp(format, ".hdf5") == 0) {
        save_array_hdf(filename_x, x, N);
        save_array_hdf(filename_y, y, N);
    } else {
        printf("Invalid format.\n");
        return 1;
    } 
    free(x);
    free(y);
    return 0;
}
