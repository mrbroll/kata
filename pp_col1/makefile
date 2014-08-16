CXX = clang++
CFLAGS = -c -g -Wall -std=c++1y
LFLAGS = -g -Wall -std=c++1y

all: pp_col1

pp_col1: test.o bit_vector.o number_generator.o bit_vector_2pass.o
	$(CXX) $(LFLAGS) -o pp_col1 test.o bit_vector.o number_generator.o bit_vector_2pass.o
	mv pp_col1 ../bin/pp_col1

test.o: test.cc
	$(CXX) $(CFLAGS) -o test.o test.cc

bit_vector.o: bit_vector.cc bit_vector.hh
	$(CXX) $(CFLAGS) -o bit_vector.o bit_vector.cc

bit_vector_2pass.o: bit_vector_2pass.cc bit_vector_2pass.hh
	$(CXX) $(CFLAGS) -o bit_vector_2pass.o bit_vector_2pass.cc

number_generator.o: number_generator.cc number_generator.hh
	$(CXX) $(CFLAGS) -o number_generator.o number_generator.cc

.PHONY: clean

clean:
	rm -rf *.o pp_col1 ./bin/*
