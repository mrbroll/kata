CXX = clang++
CFLAGS = -c -g -Wall -std=c++1y
LFLAGS = -g -Wall -std=c++1y

all: pp_col1

pp_col1: main.o bit_vector.o
	$(CXX) $(LFLAGS) -o pp_col1 main.o bit_vector.o
	mv pp_col1 ../bin/pp_col1

main.o: main.cc
	$(CXX) $(CFLAGS) -o main.o main.cc

bit_vector.o: bit_vector.cc bit_vector.hh
	$(CXX) $(CFLAGS) -o bit_vector.o bit_vector.cc

.PHONY: clean

clean:
	rm -rf *.o pp_col1
