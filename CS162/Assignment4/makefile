#Filename: makefile
#Name: Darlene Zouras
#Date: May 16, 2016
#Description: Assignment 4 makefile

PROGS := main

all: $(PROGS)

main: Main.o CreatureList.o LoserList.o Medusa.o Barbarian.o BabaYaga.o BlueMen.o HarryPotter.o
	g++ -std=c++11 Main.o CreatureList.o LoserList.o Medusa.o Barbarian.o BabaYaga.o BlueMen.o HarryPotter.o -o main

Main.o: main.cpp Menu.cpp Tournament.cpp
	g++ -c main.cpp

CreatureList.o: CreatureList.hpp CreatureList.cpp
	g++ -c CreatureList.cpp

LoserList.o: LoserList.hpp LoserList.cpp
	g++ -c LoserList.cpp

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
