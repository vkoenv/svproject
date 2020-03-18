CC=gcc
CFLAGS=-Wall -g
LDLIBS=-lm

ALL=exo1 exo2
all: $(ALL)

exo1: exo1.c
exo2: exo2.c
exo3: exo3.c

clean:
	rm -rf $(ALL)
