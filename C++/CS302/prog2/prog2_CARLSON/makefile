store.out:				adt1.o adt1_test.o prog2.o linkedList.o listTest.o
						g++ -o adt1.out adt1.o adt1_test.o
						g++ -o prog2.out adt1.o prog2.o linkedList.o
						g++ -o linkedList.out linkedList.o listTest.o

adt1.o:					adt1.cpp adt1.h
						g++ -c adt1.cpp

linkedList.o:			linkedList.cpp linkedList.h
						g++ -c linkedList.cpp


adt1_test.o:			adt1_test.cpp adt1.cpp adt1.h 
						g++ -c adt1_test.cpp

listTest.o:				listTest.cpp linkedList.cpp linkedList.h
						g++ -c listTest.cpp

prog2.o:				prog2.cpp adt1.cpp adt1.h 
						g++ -c prog2.cpp
