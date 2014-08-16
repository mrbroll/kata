CXX = clang++
CFLAGS = -c -g -Wall -std=c++1y
LFLAGS = -g -Wall -std=c++1y

all: stack_queue

stack_queue: test.o stack.hh queue.hh stack_queue.hh queue_stack.hh
	$(CXX) $(LFLAGS) -o stack_queue test.o
	mv stack_queue ../bin/stack_queue

test.o: test.cc
	$(CXX) $(CFLAGS) -o test.o test.cc

.PHONY: clean

clean:
	rm -rf *.o
