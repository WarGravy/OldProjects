makefile.out: 			adt1.o adt2.o adt3.o adt4.o adt5.o adt6.o adt7.o prog4.o QueType.o

				g++ -o prog4.out adt1.o adt2.o adt3.o adt4.o adt5.o adt6.o adt7.o prog4.o QueType.o

adt1.o:				adt1.cpp adt1.h
				g++ -c adt1.cpp

adt2.o:				adt2.cpp adt2.h
				g++ -c adt2.cpp

QueType.o:			QueType.cpp QueType.h
				g++ -c QueType.cpp

adt3.o:				adt3.cpp adt3.h 
				g++ -c adt3.cpp
				
adt4.o:				adt4.h adt4.cpp
				g++ -c adt4.cpp

adt5.o:				adt5.cpp adt5.h
				g++ -c adt5.cpp

adt6.o:				adt6.cpp adt6.h
				g++ -c adt6.cpp

adt7.o:				adt7.cpp adt7.h
				g++ -c adt7.cpp

prog4.o: 			prog4.cpp adt1.cpp adt1.h adt7.cpp adt7.h adt6.cpp adt6.h adt5.cpp adt5.h adt4.h adt3.cpp adt3.h adt2.cpp adt2.h 
				g++ -c prog4.cpp
