CXX = clang++
CFLAGS = -c -g -Wall -std=c++1y
LFLAGS = -g -Wall -std=c++1y

all: data_munging

data_munging: main.o weather_data.o
	$(CXX) $(LFLAGS) -o data_munging main.o weather_data.o
	mv data_munging ../bin/data_munging

main.o: main.cc
	$(CXX) $(CFLAGS) -o main.o main.cc

weather_data.o: weather_data.cc weather_data.hh
	$(CXX $(CFLAGS) -o weather_data.o weather_data.cc

.PHONY: clean

clean:
	rm -rf *.o data_munging
