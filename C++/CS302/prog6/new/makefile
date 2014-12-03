all:    proj6main.o proj6.o 
	g++ proj6.o proj6main.o -o run

proj6.o:	proj6.h proj6.cpp 
	g++ -c -g proj6.cpp


proj6main.o:	proj6main.cpp proj6.h proj6.cpp
	g++ -c -g -Wall proj6main.cpp proj6.h proj6.cpp

clean:    
	rm *.o run
