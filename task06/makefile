CC=gcc
CFLAGS=-I. -lhdf5 -lgsl -lgslcblas -lm  -lfftw3
DEPS = 
OBJ = FT.C 
%.C: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

FT:  $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)