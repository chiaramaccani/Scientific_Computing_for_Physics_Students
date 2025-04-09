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

void read_config(char* config_filename, char** filename_x, char** filename_y, char** prefix_output, int* N, int* a) {
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
        printf("key: %s, value: %s\n", key, value);
        if (strcmp(key, "filename_x") == 0) {
            *filename_x = strdup(value);
        } else if (strcmp(key, "filename_y") == 0) {
            *filename_y = strdup(value);
        } else if (strcmp(key, "prefix_output") == 0) {
            *prefix_output = strdup(value);
        } else if (strcmp(key, "N") == 0) {
            *N = atoi(value);
        } else if (strcmp(key, "a") == 0) {
            *a = atoi(value);
        }
    }
    fclose(fconfig);
}


int main(int argc, char** argv) {

    char* filename_x = NULL;
    char* filename_y = NULL;
    char* prefix_output = NULL;
    int N = 0;
    int a = 0;

    char *config_filename = argv[1];
    if (argc != 2) {
        printf("Usage: %s <config_filename>\n", argv[0]);
        return 1;
    }
   
   
    read_config(config_filename, &filename_x, &filename_y, &prefix_output, &N, &a);

    printf("filename_x: %s\n", filename_x);
    printf("filename_y: %s\n", filename_y);
    printf("prefix_output: %s\n", prefix_output);
    printf("N: %d\n", N);
    printf("a: %d\n", a);

    
    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));
    double *d = (double *)malloc(N * sizeof(double));

    read_array(filename_x, x, N);
    read_array(filename_y, y, N);
    
    for (int i = 0; i < N; i++) {
        d[i] = a * x[i] + y[i];
    }

    char* filename_d = (char *)malloc(sizeof(filename_x));
    char* filename_format_d = "%svector_N%d_d.dat";
    char* N_char = (char *)malloc(10);
    snprintf(N_char, 10, "%d", N);
    int size = sizeof(filename_format_d) + sizeof(prefix_output) + sizeof(N_char);
    snprintf(filename_d, size, filename_format_d, prefix_output, N);



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
