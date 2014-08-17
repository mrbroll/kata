CXX = clang
CFLAGS = -c -g -Wall -std=c11
LFLAGS = -g -Wall -std=c11

all: sorts

sorts: test.o merge_sort.o
	$(CXX) $(LFLAGS) -o sorts test.o merge_sort.o
	mv sorts ../bin/sorts

test.o: test.c
	$(CXX) $(CFLAGS) -o test.o test.c

merge_sort.o: merge_sort.c merge_sort.h
	$(CXX) $(CFLAGS) -o merge_sort.o merge_sort.c

.PHONY: clean

clean:
	rm -rf *.o
