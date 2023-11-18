main: main.o
	g++ main.o -o anitype -lncurses


main.o: main.cpp
	g++ -c main.cpp 

clean:
	rm *.o main
