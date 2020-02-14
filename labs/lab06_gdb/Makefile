all: date
CXXFLAGS = -Wall -g

date:	main.cc Date.o Exceptions.o
	g++ $(CXXFLAGS) -o date main.cc Date.o Exceptions.o

Date.o:	Date.cc Date.h Debug.h
	g++ $(CXXFLAGS) -c Date.cc

Exceptions.o:	Exceptions.cc Exceptions.h
	g++ $(CXXFLAGS) -c Exceptions.cc

clean:
	rm -f *date *.o
