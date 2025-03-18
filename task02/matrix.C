#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    double dim_list[] = {10, 100, 10000};
    double A_value = 3;
    double B_value = 7.1;
    double C_expected = A_value * B_value;

    for (int i = 0; i < 3; i++) {
        long dim = (long)dim_list[i];

        double **A = (double **)malloc(dim * sizeof(double *));
        double **B = (double **)malloc(dim * sizeof(double *));
        double **C = (double **)malloc(dim * sizeof(double *));
        for (long j = 0; j < dim; j++) {
            A[j] = (double *)malloc(dim * sizeof(double));
            B[j] = (double *)malloc(dim * sizeof(double));
            C[j] = (double *)malloc(dim * sizeof(double));
        }

        for (long j = 0; j < dim; j++) {
            for (long k = 0; k < dim; k++) {
                A[j][k] = A_value;
                B[j][k] = B_value;
            }
        }

        clock_t start_time = clock();

        for (long j = 0; j < dim; j++) {
            for (long k = 0; k < dim; k++) {
                C[j][k] = A[j][k] * B[j][k];
            }
        }

        clock_t end_time = clock();
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        bool test_passed = true;
        for (long j = 0; j < dim; j++) {
            for (long k = 0; k < dim; k++) {
                if (C[j][k] != C_expected) {
                    test_passed = false;
                    break;
                }
            }
            if (!test_passed) break;
        }

        if (test_passed) {
            printf("Test passed for dim = %ld\n", dim);
            printf("All elements of C are equal to %.2f\n", C_expected);
            printf("Time taken: %.6f seconds\n\n", time_taken);
        } else {
            printf("Test failed for dim = %ld\n", dim);
        }

        for (long j = 0; j < dim; j++) {
            free(A[j]);
            free(B[j]);
            free(C[j]);
        }
        free(A);
        free(B);
        free(C);
    }

    return 0;
}
