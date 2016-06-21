# Program Filename: makefile
# Author: Darlene Zouras
# Date: 5/17/2016
# Builds the executeable file for the Module F assignment.

PROGS := main

all: $(PROGS)

main: main.cpp Menu.cpp State.o CarQueue.o
	g++ -std=c++11 main.cpp State.o CarQueue.o -o main

CarQueue.o: CarQueue.hpp CarQueue.cpp
	g++ -c CarQueue.cpp

State.o: State.hpp State.cpp CarQueue.o
	g++ -c State.cpp

clean:
	rm -f $(PROGS) *.o
