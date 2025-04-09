#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int generate(int N, char* filename_prefix) {

    char* N_char = (char *)malloc(10);
    snprintf(N_char, 10, "%d", N);

    if (N <= 0) {
        printf("Invalid dimension size.\n");
        return 1;
    }

    char* filename_format_x = "%svector_N%d_x.dat";
    char* filename_format_y = "%svector_N%d_y.dat";
    int size = sizeof(filename_format_x) + sizeof(filename_prefix) + sizeof(N_char);
    char* filename_x = (char *)malloc(size);
    char* filename_y = (char *)malloc(size);
    snprintf(filename_x, size, filename_format_x, filename_prefix, N);
    snprintf(filename_y, size, filename_format_y, filename_prefix, N);

    double x_value = 0.1;
    double y_value = 7.1;
       
    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));

    for (long j = 0; j < N; j++) {
        x[j] = x_value;
        y[j] = y_value;
    }

    FILE *filex = fopen(filename_x, "w");  
    if (filex == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fprintf(filex, "%f\n", x[i]);  
    }
    fclose(filex);
    printf("FILE %s succesfully created\n", filename_x);

    FILE *filey = fopen(filename_y, "w");
    if (filey == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        fprintf(filey, "%f\n", y[i]);  
    }
    fclose(filey);
    printf("FILE %s succesfully created\n", filename_y);

    free(x);
    free(y);
    return 0;
}
