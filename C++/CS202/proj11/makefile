proj.out: 			card.o mainZcarlson11.o deck.o tableau.o waste.o foundation.o
				g++ -o game.out card.o mainZcarlson11.o deck.o tableau.o waste.o foundation.o

deck.o:				deck.cpp deck.h
				g++ -c deck.cpp

card.o:				card.cpp card.h
				g++ -c card.cpp

tableau.o:			tableau.cpp tableau.h
				g++ -c tableau.cpp

waste.o:			waste.cpp waste.h
				g++ -c waste.cpp

foundation.o:			foundation.cpp foundation.h
				g++ -c foundation.cpp


mainZcarlson11.o: 		mainZcarlson11.cpp card.cpp card.h deck.cpp deck.h tableau.cpp tableau.h waste.cpp waste.h foundation.cpp foundation.h
				g++ -c mainZcarlson11.cpp

clean: 				
				rm* .oproj2.out
