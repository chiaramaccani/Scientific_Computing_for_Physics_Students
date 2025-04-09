#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <hdf5.h>
#include <vector_sum.h>
#include <gsl/gsl_vector.h>

#define MAX_LINE_LENGTH 256


int compute(char* prefix, int N, double a, char* format) {

    char* N_char = (char *)malloc(10);
    snprintf(N_char, 10, "%d", N);

    
    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));
    double *d = (double *)malloc(N * sizeof(double));

    const char* filename_format_x = "%svector_N%d_x%s";
    const char* filename_format_y = "%svector_N%d_y%s";
    int size = strlen(filename_format_x) + strlen(prefix) + strlen(N_char) + strlen(format)+1;
    char* filename_x = (char *)malloc(size);
    char* filename_y = (char *)malloc(size);
    snprintf(filename_x, size, filename_format_x, prefix, N, format);
    snprintf(filename_y, size, filename_format_y, prefix, N, format);

    if (strcmp(format, ".dat") == 0){
        read_array(filename_x, x, N);
        read_array(filename_y, y, N);
    } else if (strcmp(format, ".hdf5") == 0) {
        read_array_hdf(filename_x, x, N);
        read_array_hdf(filename_y, y, N);
    } else {
        printf("Invalid format.\n");
        return 1;
    } 

  
    for (int i = 0; i < N; i++) {
      d[i] = a * x[i] + y[i];
    }

    char* filename_d = (char *)malloc(size); 
    const char* filename_format_d = "%svector_N%d_d%s";
    snprintf(filename_d, size, filename_format_d, prefix, N, format);
    

    if (strcmp(format, ".dat") == 0){
        save_array(filename_d, d, N);
    } else if (strcmp(format, ".hdf5") == 0) {
        save_array_hdf(filename_d, d, N);
    } else {
        printf("Invalid format.\n");
        return 1;
    }



    printf("FILE %s succesfully created\n", filename_d);
    printf("%lf, %lf, %lf\n", x[0], y[0], d[0]);
    free(x); x = NULL;
    free(y); y = NULL;
    free(d); d = NULL;
    free(filename_x); filename_x = NULL;
    free(filename_y); filename_y = NULL;
    free(filename_d); filename_d = NULL;
    return 0;
}

/*    // Find the position of "_x" in filename_x
    char *pos = strstr(filename_x, "_x");
    if (pos != NULL) {
        int length = pos - filename_x;
        strncpy(filename_d, filename_x, length);
        filename_d[length] = '\0';  
        strcat(filename_d, "_d.dat");
        save_array(filename_d, d, N);
    } else {
        printf("Error: '_x' not found in filename_x\n");
    }*/
