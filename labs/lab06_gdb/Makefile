all: date

date:	main.cc Date.o Exceptions.o
	g++ -Wall -o date main.cc Date.o Exceptions.o

Date.o:	Date.cc Date.h Debug.h
	g++ -Wall -c -o Date.o Date.cc

Exceptions.o:	Exceptions.cc Exceptions.h
	g++ -Wall -c -o Exceptions.o Exceptions.cc

clean:
	rm -f *date *.o
