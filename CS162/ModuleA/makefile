PROGS := main

all: $(PROGS)


main: main.o Critter.o Path.o
	g++ -std=c++11 main.o Critter.o Path.o -o main

main.o: main.cpp 
	g++ -c main.cpp

Critter.o: Critter.cpp Critter.hpp
	g++ -c Critter.cpp

Path.o: Path.cpp Path.hpp
	g++ -c Path.cpp

clean:
	rm -f $(PROGS) *.o