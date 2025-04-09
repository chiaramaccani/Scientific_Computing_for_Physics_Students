#ifndef VECTOR_SUM_H
#define VECTOR_SUM_H

#include <stdio.h>
#include <stdlib.h>
#include <hdf5.h>



int generate(int N, char* filename_prefix, char* format);
int compute(char* prefix, int N, double a, char* format);
void read_array(char* filename, double *array, int N);
void save_array(char* filename, double *array, int N);
void read_config(char* config_filename, char** prefix, int* N, double* a, char** format);
void read_array_hdf(char* filename, double *array, int N);
void save_array_hdf(char* filename, double *array, int N);




#endif
