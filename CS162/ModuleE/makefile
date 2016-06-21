# Program Filename: makefile
# Author: Darlene Zouras
# Date: 5/6/2016
# Builds the executeable file for the Module E assignment.

PROGS := main

all: $(PROGS)

main: main.cpp Menu.cpp State.o
	g++ -std=c++11 main.cpp State.o -o main

State.o: State.hpp State.cpp
	g++ -c State.cpp

clean:
	rm -f $(PROGS) *.o
