# CSCI3081 In-Class Exercise dynamic allocation and arrays

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = array_pointer_test.o duck.o

all: main.o $(OBJS)
	$(CC) $(LFLAGS) -o ducks main.o $(OBJS)

%.o : %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	\rm *.o *.*~ ducks
