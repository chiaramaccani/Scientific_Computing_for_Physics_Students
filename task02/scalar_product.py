import numpy as np
import time

a = 3
dim_list = [10, 1e6, 1e8]
x_value = 0.1
y_value = 7.1
d_expected = 3.0*0.1+7.1

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
    