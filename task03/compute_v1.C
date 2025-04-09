#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LINE_LENGTH 256



void read_array(char* filename, double *array, int N) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        fscanf(file, "%lf", &array[i]);
    }
    fclose(file);
}

void save_array(char* filename, double *array, int N) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        fprintf(file, "%f\n", array[i]);
    }
    fclose(file);
}




int compute(char* prefix, int N, int a) {

    printf("prefix: %s\n", prefix);
    printf("N: %d\n", N);
    printf("a: %d\n", a);

    char* N_char = (char *)malloc(10);
    snprintf(N_char, 10, "%d", N);

    
    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));
    double *d = (double *)malloc(N * sizeof(double));

    char* filename_format_x = "%svector_N%d_x.dat";
    char* filename_format_y = "%svector_N%d_y.dat";
    int size = sizeof(filename_format_x) + sizeof(prefix) + sizeof(N_char);
    char* filename_x = (char *)malloc(size);
    char* filename_y = (char *)malloc(size);
    snprintf(filename_x, size, filename_format_x, prefix, N);
    snprintf(filename_y, size, filename_format_y, prefix, N);

    read_array(filename_x, x, N);
    read_array(filename_y, y, N);
    
    for (int i = 0; i < N; i++) {
        d[i] = a * x[i] + y[i];
    }

    char* filename_d = (char *)malloc(sizeof(filename_x));
    char* filename_format_d = "%svector_N%d_d.dat";
    snprintf(filename_d, size, filename_format_d, prefix, N);
    save_array(filename_d, d, N);



    printf("FILE %s succesfully created\n", filename_d);
    printf("%lf, %lf, %lf\n", x[0], y[0], d[0]);
    free(x);
    free(y);
    free(d);
    free(filename_x);
    free(filename_y);
    free(filename_d);

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
