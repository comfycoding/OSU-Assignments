# Program Filename: makefile
# Author: Darlene Zouras
# Date: 4/29/2016
# Builds the executeable file for the Module 1 assignment.

PROGS := main

all: $(PROGS)

main: main.cpp reverseString.cpp addArray.cpp triangle.cpp Menu.cpp
	g++ -std=c++11 main.cpp -o main

clean:
	rm -f $(PROGS) *.o
