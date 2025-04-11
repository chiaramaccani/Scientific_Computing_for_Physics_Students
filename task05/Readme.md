# Task 05

## Part 1)
 The sum of elements o the vector [1.0; 1e-16; -1e-16; -0.5] is calculating using GSL, a simple loop and the Kahan algorithm. The expected result is `0.5`.
```
Sum of elements GSL: -0.50000000000000000000
Sum of array elements: -0.50000000000000000000
Sum of array elements (Kahan): -0.50000000000000000000
```
All methods fail to compute the correct result due to floating-point precision limits in IEEE 754 double precision. The large gap in magnitude between `1.0` and `1e-16` causes the smaller terms to be lost entirely when added. Specifically, when `1e-16` is added to `1.0`, the result is still `1.0` because `1e-16` is too small to affect the sum — it falls below the precision threshold.

The Kahan algorith, although designed to reduce numerical errors in summation, cannot recover values that were never captured due to the limitations of floating-point precision. It compensates for small errors in subtraction, but it cannot correct for values that are completely discarded during addition.


By increasing the precision to `long double`, the sum becomes accurate:
```
Sum with long double: 0.50000000000000000000
Sum with Kahan (long double): 0.50000000000000000000
```


## Part 2)

Two independent vectors `x` and `y` of length `N` are generated sampling from a standard normal distribution (mean = 0, variance = 1) using the GSL library. The vector `d` is then computed as
$\mathbf{d} = a \cdot \mathbf{x} + \mathbf{y}$, with `a=3`.

By comparing the empirical results with the expected values, we can verify the correctness of the computation.

- Expected values:
  
$$\mathbb{E}[d_i] = a \cdot \mathbb{E}[x_i] + \mathbb{E}[y_i] = a \cdot \mu_x + \mu_y$$

$$\mathrm{Var}(d_i) = a^2 \cdot \mathrm{Var}(x_i) + \mathrm{Var}(y_i) = a^2 \cdot \sigma_x^2 + \sigma_y^2$$

- Empirical resuts:

$$\hat{\mu_{d}} = \frac{1}{N} \sum_{i=1}^{N} d_i$$

$$\hat{\sigma}^2_d = \frac{1}{N} \sum_{i=1}^{N} d_i^2 - \hat{\mu}_d^2$$

As `N` increases the empirical estimates converge to the expected values. In fact:

- For  `N = 100`:
 ```
Empirical mean = 0.481297, Expected mean = 0
Empirical var  = 10.3071, Expected var  = 10
```
- For  `N = 1e6`:
```
Empirical mean = 0.000448168, Expected mean = 0
Empirical var  = 9.98735, Expected var  = 10
 ```
- For `N = 1e8`:
```
Empirical mean = -0.000255022, Expected mean = 0
Empirical var  = 9.99854, Expected var  = 10
```
