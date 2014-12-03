all:	proj6main.o proj6.o
	g++ proj6main.o proj6.o -o run

proj6main.o:	proj6main.cpp
	g++ -c -g -Wall proj6main.cpp

proj6.o:	proj6.cpp proj6.h
	g++ -c -g -Wall proj6.cpp

clean:    
	rm *.o run
