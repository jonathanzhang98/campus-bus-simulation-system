# CSCI3081 robot exercise makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o robot.o
	$(CC) $(LFLAGS) main.o robot.o -o robot

main.o : main.cc
	$(CC) $(CFLAGS) main.cc -o main.o

robot.o : robot.cc
	$(CC) $(CFLAGS) robot.cc -o robot.o

clean:
	\rm *.o *.*~ robot
