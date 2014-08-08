CXX = clang++
CFLAGS = -c -g -Wall -std=c++1y
LFLAGS = -g -Wall -std=c++1y

all: karate_chop

karate_chop: main.o first_chop.o
	$(CXX) $(LFLAGS) -o karate_chop main.o first_chop.o
	mv karate_chop ../bin/karate_chop

main.o: main.cc
	$(CXX) $(CFLAGS) -o main.o main.cc

first_chop.o: first_chop.cc first_chop.hh
	$(CXX) $(CFLAGS) -o first_chop.o first_chop.cc

.PHONY: clean

clean:
	rm -rf *.o karate_chop
