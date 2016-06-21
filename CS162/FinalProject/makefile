# Program Filename: makefile
# Author: Darlene Zouras
# Date: 5/28/2016
# Builds the executeable file for the Final Assignment.

PROGS := main

all: $(PROGS)

main: main.o MoveMap.o Lobby.o FannyPack.o Courtyard.o Corners.o Greenhouse.o Sides.o
	g++ -std=c++11 main.o MoveMap.o Lobby.o FannyPack.o Courtyard.o Corners.o Greenhouse.o Sides.o -o main

main.o: main.cpp Menu.cpp
	g++ -c main.cpp

FannyPack.o: FannyPack.cpp FannyPack.hpp
	g++ -c FannyPack.cpp

MoveMap.o: MoveMap.hpp MoveMap.cpp
	g++ -c MoveMap.cpp

Lobby.o: Lobby.cpp Lobby.hpp
	g++ -c Lobby.cpp

Courtyard.o: Courtyard.cpp Courtyard.hpp
	g++ -c Courtyard.cpp

Sides.o: Sides.cpp Sides.hpp
	g++ -c Sides.cpp

Corners.o: Corners.cpp Corners.hpp
	g++ -c Corners.cpp

Greenhouse.o: Greenhouse.cpp Greenhouse.hpp
	g++ -c Greenhouse.cpp

clean:
	rm -f $(PROGS) *.o
