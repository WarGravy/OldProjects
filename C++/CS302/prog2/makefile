store.out: 			adt1.o adt1_test.o prog2.o
				g++ -o adt1.out adt1.o adt1_test.o
				g++ -o prog2.out adt1.o prog2.o

adt1.o:				adt1.cpp adt1.h
				g++ -c adt1.cpp

adt1_test.o: 			adt1_test.cpp adt1.cpp adt1.h 
				g++ -c adt1_test.cpp

prog2.o: 			prog2.cpp adt1.cpp adt1.h 
				g++ -c prog2.cpp
