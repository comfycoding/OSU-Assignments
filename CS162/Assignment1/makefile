PROGS := main

all: $(PROGS)


main: Main.o Grid.o Ant.o
	g++ -std=c++11 Main.o Grid.o Ant.o -o main

main.o: Main.cpp Menu.cpp
	g++ -c Main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Grid.o: Grid.cpp Grid.hpp
	g++ -c Grid.cpp


clean:
	rm -f $(PROGS) *.o