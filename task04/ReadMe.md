


# **How to Use the Code**
After unzipping the compressed folder you will find the  code **`integral.C`** and a **`config.conf`** where the number of sampling point `N`, and the integral limits `x_inf` and `x_sup` can be set.   A python script **`integral.py`** can also be found. Compile the C code running the `make` command, then run

```
./integral config.conf
```
and 

```
python integral.py
```
The following integral will be calculated using different methods:
$$I = \int_{x_{inf}}^{x_{sup}} e^xcos(x) dx$$

## **Question 1**
>how far are I from the realsolution?

For $x_{inf} = 0$ and $x_{sup}=\pi/2$ the analitical result can be computed as 
$$I_{true} = \frac{e^{\pi/2}-1}{2}$$
`Analitical result: 1.9052386904826757`

The relative error can be computed as 
$$\epsilon_{rel} = \frac{I}{I_{true} } -1$$

For `N=100` the C code will output: 
```
Trapezoidal Integral (N=100) = 1.9051192179747314
Relative error: 0.0000627073702320

GSL integration...
GLS result: 1.9052386904826757
Relative error: 0.0000000000000000
```
The relative error for trapezoidal method is $o(10^{-5})$.





## **Question 2**
> How can you reduce the relative error?

When calculating the integral with the trapezoidal method the relative error can be reduced by increasing the number of sampling points, in fact for  `N=1000000` 
```
Trapezoidal Integral (N=1000000) = 1.9052386904814171
Relative error: 0.0000000000006606

GSL integration...
GLS result: 1.9052386904826757
Relative error: 0.0000000000000000
```

The relative error for trapezoidal method is now $o(10^{-13})$.



## **Question 3**
>Which is the minimum relative error you can find?

One can use other algorithms, for example the **QAGS algorithm** already implemented in the GSL library, which is one of the most robust and widely used methods for **numerical integration** over finite intervals. Even with only `N= 100`  points, this algorithm can achieve a relative error equal to zero.



## **Question 4**
>use an interpreted language to calculate the same integral: is this output similar to the one in point 1? And how close it is?

The trapezoidal rule can be implemented also in python. 

- For `N= 100`:
```
Trapezoidal Integral: 1.9051167922122334
Relative error: -6.398057684386949e-05

Scipy integral: 1.9052386904826757
Relative error: 0.0
```
in this case the difference between the integral computed with C and the one computed with python using the trapezoidal rule is  `2.425762497981765e-06`. 

- For `N=1000000`:

```
Trapezoidal Integral: 1.9052386904814815
Relative error: -6.267208974009009e-13

Scipy integral: 1.9052386904826757
Relative error: 0.0
```
in this case the difference between the integral computed with C and the one computed with python using the trapezoidal rule is `-6.439293542825908e-14`.

One can also use the method `scipy.integrate.quad` in the library **`scipy`**  which performs   adaptive quadratur  using **QUADPACK**, a Fortran library.
