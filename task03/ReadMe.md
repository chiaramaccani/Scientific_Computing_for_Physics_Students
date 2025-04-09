# **How to Use the Code**


## **1. Extract the Code**

Unzip the compressed folder:

```bash
tar  -xvf  vector_sum.tar
```

After extracting, you will find the following files:

## **2. Files and Their Purpose**

  

-  **`main.C`** – Executes the vector sum operation:

$$d = a \cdot x + y $$

 

-  **`config.conf`** – Configuration file where you can set:

	- The **path** where files will be stored

	- The **parameter**  `a`

	- The **dimension**  `N` of the vectors

	- The **file extension** (default: `.hdf5`)

  

-  **`generate.C`** – Generates two `.hdf5` files in the specified path:

	- One file contains the vector **x**, initialized as an **N-dimensional vector of 0.1**.

	- The other file contains the vector **y**, also initialized as an **N-dimensional vector of 0.1**.

  

-  **`compute.C`** – Reads the generated `.hdf5` files, performs the vector sum using the **GSL library**, and saves the resulting **N-dimensional vector** as an `.hdf5` file in the same path.

  

-  **`utils.h` & `utils.C`** – Contain helper functions for:

	- Reading the **configuration file**

	- Reading and writing **GSL vectors** in HDF5 format

  

-  **`Makefile`** – Used to compile the code.

  

## **3. Compile the Code**

Run the following command to compile:

```bash
make
```

This will generate an executable named `vec` in the folder.

  

## **4. Run the Program**

  

- Modify `config.conf` to adjust parameters as needed.

  

- Execute the program:

```bash
./vec config.conf
```