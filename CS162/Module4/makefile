# Program Filename: makefile
# Author: Darlene Zouras
# Date: 5/30/2016
# Builds the executeable file for the Module 4 assignment.

PROGS := main

all: $(PROGS)

main: main.cpp TimeTests.o
	g++ -std=c++11 main.cpp TimeTests.o -o main

TimeTests.o: TimeTests.hpp TimeTests.cpp Factorial.cpp Fibonacci.cpp Menu.cpp
	g++ -std=c++11 -c TimeTests.cpp

clean:
	rm -f $(PROGS) *.o
