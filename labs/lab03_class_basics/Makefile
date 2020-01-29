EXEFILE = cluster
CXXFLAGS = -c -Wall
SOURCES = main.cc point2.cc
OBJECTS = $(SOURCES:.cc=.o)

$(EXEFILE): $(OBJECTS)
	g++ $^ -o $@

%.o: %.cc
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o $(EXEFILE)

.PHONY: clean
