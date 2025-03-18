#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    int a = 3;
    double dim_list[] = {10, 1e6, 1e8};
    double x_value = 0.1;
    double y_value = 7.1;
    double d_expected = 3.0 * 0.1 + 7.1;
    
    for (int i = 0; i < 3; i++) {
        long dim = (long)dim_list[i];
        
        double *x = (double *)malloc(dim * sizeof(double));
        double *y = (double *)malloc(dim * sizeof(double));
        double *d = (double *)malloc(dim * sizeof(double));

        for (long j = 0; j < dim; j++) {
            x[j] = x_value;
            y[j] = y_value;
        }

        clock_t start_time = clock();

        for (long j = 0; j < dim; j++) {
            d[j] = a * x[j] + y[j];
        }

        clock_t end_time = clock();
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        bool test_passed = true;
        for (long j = 0; j < dim; j++) {
            if (d[j] != d_expected) {
                test_passed = false;
                break;
            }
        }

        if (test_passed) {
            printf("Test passed for dim = %ld\n", dim);
            printf("All elements of d are equal to %.2f\n", d_expected);
            printf("Time taken: %.6f seconds\n\n", time_taken);
        } else {
            printf("Test failed for dim = %ld\n", dim);
        }

        free(x);
        free(y);
        free(d);
    }

    return 0;
}
