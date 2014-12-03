makefile.out: 			intervalTree.o prog5.o
				g++ intervalTree.o prog5.o  -o prog5.out


intervalTree.o:			intervalTree.cpp intervalTree.h
				g++ -c intervalTree.cpp

prog5.o: 			prog5.cpp intervalTree.cpp intervalTree.h
				g++ -c prog5.cpp


