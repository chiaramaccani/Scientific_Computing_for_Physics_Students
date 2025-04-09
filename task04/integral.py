import numpy as np
import scipy as sc

def read_config(config_filename):
    config = {}
    with open(config_filename, 'r') as f:
        for line in f:
            line = line.strip() 
            if line and not line.startswith("#"):  
                key, value = line.split("=")
                config[key.strip()] = float(value.strip()) 
    return config

def f(x):
    return np.exp(x)*np.cos(x)

def main():

    config_filename = "config.conf"
    config = read_config(config_filename)

    N = int(config["N"])
    x_inf = config["x_inf"]
    x_sup = config["x_sup"]

    print(f"N = {N}")
    print(f"x_inf = {x_inf}")
    print(f"x_sup = {x_sup}")

    analytical_result = (np.exp(np.pi/2) - 1)/2
    print(f"\nAnalytical Result: {analytical_result}\n")

    #x = np.linspace(x_inf, x_sup, N)
    #y = f(x)

    data = np.loadtxt('f_result.txt') 
    x = data[:, 0]
    y = data[:, 1]

    integral_trap = np.trapz(y, x)
    print(f"Trapezoidal Integral: {integral_trap}")
    print(f"Relative error: {(integral_trap/analytical_result)-1}")

    integral_sc, _ = sc.integrate.quad(f, x_inf, x_sup)
    print(f"\nScipy integral: {integral_sc}")
    print(f"Relative error: {(integral_sc/analytical_result)-1}")



if __name__ == "__main__":
    main()