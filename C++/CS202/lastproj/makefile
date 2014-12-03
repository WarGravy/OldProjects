proj.out: 			nodeList.o mainZcarlson13.o arrayList.o node.o
				g++ -o game.out nodeList.o mainZcarlson13.o arrayList.o node.o

nodeList.o:			nodeList.cpp nodeList.h
				g++ -c nodeList.cpp

node.o:				node.cpp node.h
				g++ -c node.cpp

arrayList.o:			arrayList.cpp arrayList.h
				g++ -c arrayList.cpp


mainZcarlson13.o: 		mainZcarlson13.cpp nodeList.cpp nodeList.h arrayList.cpp arrayList.h node.h node.cpp
				g++ -c mainZcarlson13.cpp

clean: 				
				rm* .oproj2.out
