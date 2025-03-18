# Task 02 – Computational Hello World

## Exercise 1. Python implementation using numpy
```
import numpy as np
import time

a = 3
dim_list = [10, 1e6, 1e8]
x_value = 0.1
y_value = 7.1
d_expected = a * x_value + y_value

for dim in dim_list:
    x = np.full(int(dim), x_value)
    y = np.full(int(dim), y_value)
    start_time = time.time()
    d = a * x + y
    end_time = time.time()
    if  np.all(d==d_expected):
        print(f"Test passed for dim = {dim}")
        print(f"All elements of d are equal to {d_expected}")
        print(f"Time taken: {end_time-start_time}\n")
    else:
        print(f"Test failed for dim = {dim}")

```

Output 

```
Test passed for dim = 10
All elements of d are equal to 7.3999999999999995
Time taken: 1.049041748046875e-05

Test passed for dim = 1000000.0
All elements of d are equal to 7.3999999999999995
Time taken: 0.0024709701538085938

Test passed for dim = 100000000.0
All elements of d are equal to 7.3999999999999995
Time taken: 0.29442930221557617
```

## Exercise 2. C implementation

```
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

```

Output 

```
Test passed for dim = 10
All elements of d are equal to 7.40
Time taken: 0.000001 seconds

Test passed for dim = 1000000
All elements of d are equal to 7.40
Time taken: 0.004741 seconds

Test passed for dim = 100000000
All elements of d are equal to 7.40
Time taken: 0.222804 seconds

```
## Exercise 3.
### Python implementation with numpy 
```
import numpy as np
import time

dim_list = [10, 100, 10000]
A_value = 3 
B_value = 7.1
C_expected = A_value*B_value

for dim in dim_list:
    A = np.full((int(dim), int(dim)), A_value)
    B = np.full((int(dim), int(dim)), B_value)
    start_time = time.time()
    C = A * B
    end_time = time.time()
    if  np.all(C==C_expected):
        print(f"Test passed for dim = {dim}")
        print(f"All elements of d are equal to {C_expected}")
        print(f"Time taken: {end_time-start_time}\n")
    else:
        print(f"Test failed for dim = {dim}")
```

Output 
```
Test passed for dim = 10
All elements of d are equal to 21.299999999999997
Time taken: 1.1205673217773438e-05

Test passed for dim = 100
All elements of d are equal to 21.299999999999997
Time taken: 6.318092346191406e-05

Test passed for dim = 10000
All elements of d are equal to 21.299999999999997
Time taken: 0.29546642303466797
```

### C implemantation 

```

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

```

Output 

```
Test passed for dim = 10
All elements of C are equal to 21.30
Time taken: 0.000003 seconds

Test passed for dim = 100
All elements of C are equal to 21.30
Time taken: 0.000100 seconds

Test passed for dim = 10000
All elements of C are equal to 21.30
Time taken: 0.341929 seconds
```

## Exercise 4.

1. Did you find any problems in running the codes for some N. If so, do you have an idea why?

It was possible to run the code for large values of N, even in Python, with times comparable to C. This surprised me initially, but it’s thanks to the NumPy library, which is also written in C. Unlike my C code, NumPy can execute operations in parallel, allowing it to run more efficiently, especially for large dimensions.

2. Where you able to test correctly the sum and product of points 1-3? If so, how? If not, what was the problem?

My Python code initially failed due to an issue with floating-point precision. I wrote the condition as `np.all(d == 7.4)` instead of computing the expected value (`d_expected = a * x_value + y_value`). however the best approach would be to use `np.isclose()` and set a tolerance.
