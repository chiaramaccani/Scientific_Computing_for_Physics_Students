#include "unity.h"
#include <stdlib.h>


void daxpy(double* x, double* y, double a, int n, double* d) {
    for (int i = 0; i < n; ++i) {
        d[i] = a * x[i] + y[i];
    }
}

void setUp(void) {
}

void tearDown(void) {
}

void test_daxpy(void) {
    int N = 10;
    double a = 3.0;
    double x_val = 0.1;
    double y_val = 7.1;
    double expected = a * x_val + y_val;

    double *x = (double *)malloc(N * sizeof(double));
    double *y = (double *)malloc(N * sizeof(double));
    double *d = (double *)malloc(N * sizeof(double));

    for (int i = 0; i < N; ++i) {
        x[i] = x_val;
        y[i] = y_val;
    }

    daxpy(x, y, a, N, d);

    for (int i = 0; i < N; ++i) {
        //TEST_ASSERT_EQUAL_DOUBLE(expected, d[i]);
        TEST_ASSERT_FLOAT_WITHIN(1e-6, expected, d[i]);
    }

    free(x);
    free(y);
    free(d);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_daxpy);
    return UNITY_END();
}