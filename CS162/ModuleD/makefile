# Program Filename: makefile
# Author: Darlene Zouras
# Date: 4/26/2016
# Description: Module D makefile

PROGS := main

all: $(PROGS)


main: main.o Critter.o Path.o Ant.o Doodlebug.o
	g++ -std=c++11 main.o Ant.o Doodlebug.o Critter.o Path.o -o main

main.o: main.cpp Menu.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	g++ -c Doodlebug.cpp

Critter.o: Critter.cpp Critter.hpp
	g++ -c Critter.cpp

Path.o: Path.cpp Path.hpp
	g++ -c Path.cpp

clean:
	rm -f $(PROGS) *.o