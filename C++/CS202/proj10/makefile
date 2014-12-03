all:			main.o list$(TYPE).o
			g++ -o list.out main.o list$(TYPE).o

main.o:			main.cpp
			g++ -c main.cpp -DTYPE=$(TYPE)

list$(TYPE).o:		list$(TYPE).h list$(TYPE).cpp
			g++ -c list$(TYPE).cpp
