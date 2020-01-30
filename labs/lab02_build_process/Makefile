# mallard_duck.o: mallard_duck.h mallard_duck.cc
# 	g++ -c mallard_duck.cc

# rubber_duck.o: duck.h rubber_duck.h rubber_duck.cc
# 	g++ -c rubber_duck.cc

EXEFILE = ducks
CXXFLAGS = -c -Wall
SOURCES = duck.cc mallard_duck.cc decoy_duck.cc rubber_duck.cc quack_behavior.cc mute_quack.cc quack_quack.cc squeak_quack.cc main.cc
# SOURCES = $(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)

$(EXEFILE): $(OBJECTS)
	g++ $^ -o $@

# ducks: duck.o mallard_duck.o decoy_duck.o rubber_duck.o quack_behavior.o mute_quack.o quack_quack.o squeak_quack.o main.o
# 	g++ $^ -o $@

%.o: %.cc
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o $(EXEFILE)

.PHONY: clean


