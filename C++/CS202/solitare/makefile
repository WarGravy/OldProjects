proj.out: 			cardThurs.o projectEightZCarlsonThurs.o
				g++ -o card.out cardThurs.o projectEightZCarlsonThurs.o

cardMon.o:			cardThurs.cpp cardThurs.h
				g++ -c cardThurs.cpp

projectEightZCarlsonThurs.o: 	projectEightZCarlsonThurs.cpp cardThurs.cpp cardThurs.h
				g++ -c projectEightZCarlsonThurs.cpp

clean: 				
				rm* .oproj2.out
