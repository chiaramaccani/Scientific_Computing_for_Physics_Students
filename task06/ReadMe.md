
# Task 06

## Question 1-2
A  matrix A of dimension 1000x1000 filled with values sampled from a standard Gaussian is created. Then the FFT complex to complex is computed  with the method `np.fft.fft2` to generate the matrix C.  The reconstructed matrix is computed back.
```
Mean Absolute Error      = 5.147e-16
Median Absolute Error    = 3.747e-16
Mean Relative Error      = 1.290e-13
Median Relative Error    = 3.471e-16
```

## Question 3-4
The FFT reat to complex is computed with the method `np.fft.rfft2` to generate the matrix R .  The reconstructed matrix is computed back.

```
Mean Absolute Error      = 5.925e-16
Median Absolute Error    = 4.441e-16
Mean Relative Error      = 3.222e-13
Median Relative Error    = 3.894e-16
```

## Question 5

When computing the mean and median errors, we observe that the values are very close to, but still slightly above, the floating-point limit ( machine precision: `2.220446e-16`). This indicates that the FFT algorithms are numerically stable for this type of input.

The mean relative error  is larger because some matrix entries may be close to zero; when normalizing by these small values, the relative error becomes amplified. The mean is more sensitive to outliers than the median, which explains why it tends to be larger.


## Question 6 
The first element of both `C` and `R` is equal to the sum of all elements in matrix `A`.  
In a 2D FFT, the `[0, 0]` component is the so called DC (zero-frequency) term, which represents the overall average of the signal.  
Since matrix `A` is filled with values close to 1, the first element is expected to be around `1 × 1000 × 1000 = 1000000`.

```
C[0,0]: 1001512.1465155362384394+0.0000000000000000j
R[0,0]: 1001512.1465155362384394+0.0000000000000000j
Sum of all elements in matrix A: 1001512.1465155363548547
```


## Question 7
Knowing that the FFT of a real matrix is hermitian, `np.fft.rfft2` stores only the non-redundant elements. In fact, negative frequency terms are just the complex conjugates of the corresponding positive-frequency terms (see [numpy documentation](https://numpy.org/doc/stable/reference/generated/numpy.fft.rfft2.html)). The full complex matrix C can be reconstructed by taking the complex conjugate of those elements (pay attention to indexing).  The reconstructed matrix is very similar to the original one computed with `np.fft.fft2`, in fact:
```
Mean Absolute Error      = 1.125e-15
Median Absolute Error    = 8.882e-16
Mean Relative Error      = 3.160e-16
Median Relative Error    = 1.526e-16
```

