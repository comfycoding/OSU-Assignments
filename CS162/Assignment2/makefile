#Filename: makefile
#Name: Darlene Zouras
#Description: Assignment 2 makefile

PROGS := main

all: $(PROGS)


main: Main.o List.o Item.o
	g++ -std=c++11 Main.o List.o Item.o -o main

main.o: Main.cpp
	g++ -c Main.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

List.o: List.cpp List.hpp Menu.cpp
	g++ -c List.cpp


clean:
	rm -f $(PROGS) *.o