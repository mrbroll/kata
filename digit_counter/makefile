CXX = clang
CFLAGS = -c -g -Wall -std=c11
LFLAGS = -g -Wall -std=c11

all: digit_counter

digit_counter: test.o digit_counter.o
	$(CXX) $(LFLAGS) -o digit_counter test.o digit_counter.o
	mv digit_counter ../bin/digit_counter

test.o: test.c
	$(CXX) $(CFLAGS) -o test.o test.c

digit_counter.o: digit_counter.c digit_counter.h
	$(CXX) $(CFLAGS) -o digit_counter.o digit_counter.c

.PHONY: clean

clean:
	rm -rf *.o
