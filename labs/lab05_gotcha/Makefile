EXEFILE = deliver
CXXFLAGS = -c -Wall
SOURCES = $(wildcard *.cc)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cc=.o)

$(EXEFILE): $(OBJECTS)
	g++ $^ -o $@

%.o: %.cc
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o $(EXEFILE)

.PHONY: clean
