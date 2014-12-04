makefile.out: 			prog.o adt2.o
				g++ adt2.o prog.o -o prog.out  
adt2.o:				
				g++ -c adt2.cpp

prog.o: 			prog.cpp adt2.cpp adt2.h
				g++ -c prog.cpp
clean:    
	rm *.o prog.out
