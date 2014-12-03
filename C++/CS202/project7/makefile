proj.out: 			cardWed.o projectSevenZCarlsonWed.o
				g++ -o card.out cardWed.o projectSevenZCarlsonWed.o

cardWed.o:				cardWed.cpp cardWed.h
				g++ -c cardWed.cpp

projectSixZCarlsonWed.o: 	projectSevenZCarlsonWed.cpp cardWed.cpp cardWed.h
				g++ -c projectSevenZCarlsonWed.cpp

clean: 				
				rm* .oproj2.out
