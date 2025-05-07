# Task 07 

Unit tests of the daxpy vector sum are performed in python using pytest for three different scenarios varying the dimension of the vectors and the scalar parameter a.
```pytest test_daxpy.py```.

A simpler version of a test is implemented in C using the library [Unity](https://github.com/ThrowTheSwitch/Unity) , that I have cloned from github in /home/cmaccani/python_pkgs/.
```
# in the /home/cmaccani/python_pkgs/ folder
git clone https://github.com/ThrowTheSwitch/Unity.git

# in the code folder
make
./test_daxpy 
```