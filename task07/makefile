CC = gcc
CFLAGS = -Wall -I/home/cmaccani/python_pkgs/Unity/src
SRC = ./test_daxpy.C /home/cmaccani/python_pkgs/Unity/src/unity.c
OUT = test_daxpy

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OUT)