//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include<fstream>
#include "cardThurs.h"
using namespace std;
//GLOBAL

//PROTOTYPES

/*print: (prints the entire waste pile and tableau - this is not the card print member function)
*/
void print(card*, card*);

//MAIN PROGRAM
int main()
  {
   //initialize variables
   deck deckOfCards;
   card* tableau = new card[49];
   card* wastepile = new card[24];
   deckOfCards.createDeck();
   deck deckOfCardsUnshuffled(deckOfCards);
   //output unshuffled deck
   cout << "Unshuffled Deck:"<<endl;
   deckOfCardsUnshuffled.printDeck();
   cout << endl;
   //output shuffled
   deckOfCards.shuffle();
   cout << "Shuffled Deck:"<<endl;
   deckOfCards.printDeck();
   cout << endl;
   //deal deck to waste and tableau
   deckOfCards.dealDeck(wastepile, tableau);
   //print waste and tableau
   print(wastepile, tableau);
   //end
   delete[]tableau;
   delete[]wastepile;
   return 0;
  }
//IMPLEMENTATION
void print(card* waste, card* tab)
  {
  	int indexW = 24;
  	int indexT = 49;
  	int i, j;
	//output waste pile	
	cout << "Waste Pile: "<<endl;
  	for (i=0; i < indexW; i++, waste++){
	(*waste).print();
	cout<<endl;
	}
	cout << endl;
	//output tableau
	cout<< "Tableau: "<<endl;
	cout << "|COL 1 | COL 2 | COL 3 | COL 4 | COL 5 | COL 6 | COL 7 |"<<endl;
	for (j = 0; j < indexT; j++, tab++){
	(*tab).print();
	cout <<' '<< '|' <<' ';
	  //add endlines to start new columns
	  if(j == 6 || j == 13 || j == 20 || j == 27 || j == 34 || j == 41 || j ==48){
	  cout << endl;
	  }
	}
  }
