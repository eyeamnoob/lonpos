CC = gcc
CFLAGS = -Wall -Wextra

all: solver

solver: solver.c
	$(CC) $(CFLAGS) -o bin/solver solver.c

.PHONY: clean
clean:
	rm -f solver