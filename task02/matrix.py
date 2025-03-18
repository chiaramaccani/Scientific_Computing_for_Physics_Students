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
    