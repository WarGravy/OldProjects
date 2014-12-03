all:			main.o stack$(TYPE).o
			g++ -o stack.out main.o stack$(TYPE).o

main.o:			main.cpp
			g++ -c main.cpp -DTYPE=$(TYPE)

stack$(TYPE).o:		stack$(TYPE).h stack$(TYPE).cpp
			g++ -c stack$(TYPE).cpp
