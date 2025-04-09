CC=gcc
CFLAGS=-I. -lhdf5 -lgsl -lgslcblas -lm
DEPS = vector_sum.h
OBJ = main.C generate.C compute.C utils.C

%.C: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

vec:  $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)