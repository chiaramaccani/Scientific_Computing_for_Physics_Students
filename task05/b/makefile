CC=gcc
CFLAGS=-I. -lhdf5 -lgsl -lgslcblas -lm
DEPS = 
OBJ = daxpy.C 
%.C: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

daxpy:  $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)