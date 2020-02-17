# CSCI3081

CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o
	$(CC) $(LFLAGS) main.o -o inherit

main.o : main.cc object.h composed.h derived.h
	$(CC) $(CFLAGS) main.cc -o main.o

clean:
	\rm -f *.o *.*~ inherit
