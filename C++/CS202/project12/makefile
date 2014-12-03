proj.out: 			person.o mainZcarlson12.o student.o employee.o
				g++ -o game.out person.o mainZcarlson12.o student.o employee.o

student.o:			student.cpp student.h
				g++ -c student.cpp

person.o:			person.cpp person.h
				g++ -c person.cpp

employee.o:			employee.cpp employee.h
				g++ -c employee.cpp


mainZcarlson12.o: 		mainZcarlson12.cpp student.cpp student.h person.cpp person.h employee.cpp employee.h
				g++ -c mainZcarlson12.cpp

clean: 				
				rm* .oproj2.out
