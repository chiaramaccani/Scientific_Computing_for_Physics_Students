CC=gcc
CFLAGS=-I. -lhdf5 -lgsl -lgslcblas -lm
DEPS = 
OBJ = vec_sum.C 
%.C: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

vec_sum:  $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)