#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <fftw3.h>

#define MAX_LINE_LENGTH 256




int main(int argc, char** argv) {



    int N = 1000; // Size of the matrix (N x N)
    
    // Allocate memory for the matrix (input and output)
    fftw_complex *A = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N * N); // Original matrix
    fftw_complex *C = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N * N); // Frequency domain matrix (FFT result)
    fftw_complex *A_reconstructed = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N * N); // Reconstructed matrix

    // Initialize A with Gaussian random numbers (mean = 1, std = 1)
    for (int i = 0; i < N * N; i++) {
        A[i][0] = 1.0 + (rand() / (RAND_MAX / 2.0)) - 1.0;  // Real part (mean = 1, std = 1)
        A[i][1] = 0.0;  // Imaginary part (set to 0 for real input)
    }

    // Step 1: Perform Forward FFT (c2c)
    fftw_plan plan_forward = fftw_plan_dft_2d(N, N, A, C, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan_forward);  // Execute the FFT

    // Step 2: Perform Inverse FFT (Reconstruct A)
    fftw_plan plan_backward = fftw_plan_dft_2d(N, N, C, A_reconstructed, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan_backward);  // Execute the inverse FFT

    // After the inverse FFT, the real part of A_reconstructed should be close to the original A

    // Step 3: Calculate the absolute and relative errors (for verification)
    double absolute_error_sum = 0.0;
    double relative_error_sum = 0.0;
    for (int i = 0; i < N * N; i++) {
        double absolute_error = fabs(A[i][0] - A_reconstructed[i][0]);
        double relative_error = absolute_error / fabs(A[i][0]);

        absolute_error_sum += absolute_error;
        relative_error_sum += relative_error;
    }

    // Compute Mean Absolute Error (MAE) and Mean Relative Error (MRE)
    double mean_absolute_error = absolute_error_sum / (N * N);
    double mean_relative_error = relative_error_sum / (N * N);

    // Print results
    printf("Mean Absolute Error (MAE): %.20lf\n", mean_absolute_error);
    printf("Mean Relative Error (MRE): %.20lf\n", mean_relative_error);

    // Clean up
    fftw_free(A);
    fftw_free(C);
    fftw_free(A_reconstructed);

    return 0;
}


/*
    const float a = 3.0;

    gsl_vector *x = gsl_vector_alloc(N);
    gsl_vector *y = gsl_vector_alloc(N);
    gsl_vector *d = gsl_vector_alloc(N); 

    gsl_rng_env_setup();
    gsl_rng *r = gsl_rng_alloc(gsl_rng_default);
    const double sigma = 1.0;

    printf("N: %d\n", N);

    double g;
    for (size_t i = 0; i < N; ++i) {
        g = gsl_ran_gaussian(r, sigma); 
        gsl_vector_set(x, i, g);
        g = gsl_ran_gaussian(r, sigma); 
        gsl_vector_set(y, i, g);
    }
    printf("x[0]: %lf, y[0]: %lf, d[0]: %lf\n", gsl_vector_get(x, 0), gsl_vector_get(y, 0), gsl_vector_get(d, 0));
*/