store.out: 			adt1.o prog1.o adt1_test.o
				g++ -o cash.out adt1.o prog1.o
				g++ -o runtest.out adt1.o adt1_test.o

adt1.o:				adt1.cpp adt1.h
				g++ -c adt1.cpp

prog1.o: 			prog1.cpp adt1.cpp adt1.h 
				g++ -c prog1.cpp

adt1_test.o: 			adt1_test.cpp adt1.cpp adt1.h 
				g++ -c adt1_test.cpp
