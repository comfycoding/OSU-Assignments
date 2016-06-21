#Filename: makefile
#Name: Darlene Zouras
#Date: May 2, 2016
#Description: Assignment 3 makefile

PROGS := main

all: $(PROGS)


main: Main.o Medusa.o Barbarian.o BabaYaga.o BlueMen.o HarryPotter.o
	g++ -std=c++11 main.o Medusa.o Barbarian.o BabaYaga.o BlueMen.o HarryPotter.o -o main

Main.o: main.cpp Menu.cpp
	g++ -c main.cpp

Medusa.o: Medusa.hpp Medusa.cpp
	g++ -c Medusa.cpp

Barbarian.o: Barbarian.hpp Barbarian.cpp
	g++ -c Barbarian.cpp

BabaYaga.o: BabaYaga.hpp BabaYaga.cpp
	g++ -c BabaYaga.cpp

BlueMen.o: BlueMen.hpp BlueMen.cpp
	g++ -c BlueMen.cpp

HarryPotter.o: HarryPotter.hpp HarryPotter.cpp
	g++ -c HarryPotter.cpp

clean:
	rm -f $(PROGS) *.o