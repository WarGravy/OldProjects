makefile.out: 			htmlzack.o prog.o adt2.o zacks-standard.o
				g++ htmlzack.o adt2.o zacks-standard.o prog.o -o prog.out  

zacks-standard.o:		zacks-standard.cpp zacks-standard.h
				g++ -c zacks-standard.cpp

htmlzack.o:			htmlzack.cpp htmlzack.h
				g++ -c htmlzack.cpp

adt2.o:				
				g++ -c adt2.cpp

prog.o: 			prog.cpp htmlzack.cpp htmlzack.h adt2.cpp adt2.h
				g++ -c prog.cpp
clean:    
	rm *.o prog.out
