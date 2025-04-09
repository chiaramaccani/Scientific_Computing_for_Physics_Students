#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector_sum.h>

#define MAX_LINE_LENGTH 256



int main(int argc, char** argv){

    
    char* filename_x = NULL;
    char* filename_y = NULL;
    char* prefix = NULL;
    char* format = NULL; 
    int N = 0;
    double a = 0;

    char *config_filename = argv[1];
    if (argc != 2) {
        printf("Usage: %s <config_filename>\n", argv[0]);
        return 1;
    }
   
   
    read_config(config_filename, &prefix, &N, &a, &format);
    printf("prefix: %s\n", prefix);
    printf("N: %d\n", N);
    printf("a: %d\n", a);
    printf("format: %s\n", format);

    printf("\nGenerating vectors...\n");
    generate(N, prefix, format);

    printf("\nComputing sum...\n");
    compute(prefix, N, a, format);





    return 0;
}