
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <hdf5.h>

#define DATASET_NAME "dataset"

#define MAX_LINE_LENGTH 256

void read_config(char* config_filename, char** prefix, int* N, double* a, char** format) {
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
        //printf("key: %s, value: %s\n", key, value);
        if (strcmp(key, "prefix") == 0) {
            *prefix = strdup(value);
        } else if (strcmp(key, "N") == 0) {
            *N = atoi(value);
        } else if (strcmp(key, "a") == 0) {
            *a = atof(value);
        }else if(strcmp(key, "format") == 0) {
            *format = strdup(value);
        }
    }
    fclose(fconfig);
}


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




void read_array_hdf(char* filename, double *array, int N) {
    hid_t  file_id, dataset_id;
    herr_t status;

    file_id = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        perror("Error opening HDF5 file");
        exit(1);
    }

    dataset_id = H5Dopen(file_id, DATASET_NAME, H5P_DEFAULT);
    if (dataset_id < 0) {
        perror("Error opening dataset");
        exit(1);
    }

    status = H5Dread(dataset_id, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, array);
    if (status < 0) {
        perror("Error reading dataset");
        exit(1);
    }

    H5Dclose(dataset_id);
    H5Fclose(file_id);
}


void save_array_hdf(char* filename, double *array, int N) {
    hid_t file_id, dataset_id, dataspace_id;
    herr_t status;
    

    hsize_t dims[1] = {(hsize_t)N};
    
    file_id = H5Fcreate(filename, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);
    if (file_id < 0) {
        perror("Error creating HDF5 file");
        exit(1);
    } 

    dataspace_id = H5Screate_simple(1, dims, NULL);
    if (dataspace_id < 0) {
        perror("Error creating dataspace");
        exit(1);
    }
    
    dataset_id = H5Dcreate(file_id, DATASET_NAME, H5T_NATIVE_DOUBLE, dataspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    if (dataset_id < 0) {
        perror("Error creating dataset");
        exit(1);
    }
    
    status = H5Dwrite(dataset_id, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, array);
    if (status < 0) {
        perror("Error writing dataset");
        exit(1);
    }
    
    H5Dclose(dataset_id);
    H5Sclose(dataspace_id);
    H5Fclose(file_id);
}