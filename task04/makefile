CC=gcc
CFLAGS=-I. -lhdf5 -lgsl -lgslcblas -lm
DEPS = 
OBJ = integral.C 
%.C: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

integral:  $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)