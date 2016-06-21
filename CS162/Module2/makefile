# Program Filename: makefile
# Author: Darlene Zouras
# Date: 5/11/2016
# Builds the executeable file for the Module 2 assignment.

PROGS := main

all: $(PROGS)

main: main.cpp Menu.cpp Stack.o Queue.o
	g++ -std=c++11 main.cpp Stack.o Queue.o -o main

Stack.o: Stack.hpp Stack.cpp
	g++ -c Stack.cpp

Queue.o: Queue.hpp Queue.cpp
	g++ -c Queue.cpp

clean:
	rm -f $(PROGS) *.o
