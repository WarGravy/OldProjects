//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include "deck.h"
using namespace std;
//GLOBAL
const int MAX_NAME = 50;
//PROTOTYPES
/*note for the flip function, it will give the top card so it will need to be endQueued onto the dump pile if it will not be moved.
*/
void flip(waste&, waste&, card&);

//MAIN PROGRAM
int main()
  {
   //initialize variables
   card *removed, removed2;
   removed = new card;
   char* filename;
   filename = new char[MAX_NAME];
   deck deck, unshuffledDeck;
   waste wastepile, dump;
   bool test = false;
   foundation heart, diamond, club, spade;
   tableau tab1, tab2;
   //prompt for filename
   cout <<"Enter the filename with extension .txt: ";
   cin >> filename;
   //read in deck
   cout << "Reads in deck1 from file" << endl;
   test = deck.readDeck(filename);
   cout << "deck2 = deck1" << endl; 
   unshuffledDeck = deck;
   cout << "print deck 2" << endl;
   cout << unshuffledDeck;
   cout << "shuffle deck1" << endl;
   test = deck.shuffleDeck();
   //test
   cout << deck;
   	//TESTING TABLEAU
	deck.loadTabAndWaste(tab1, wastepile);
  	//print tableau
 	  cout << tab1 << endl;
	//Testing Remove and return
	(*removed) = tab1.removeAndReturn(4, 4);
	cout <<"here is the card from column 4 row 4: "<< (*removed)<<endl;
	//cout << "Here is the tableau again: "<<endl <<tab1 << endl;

	//TESTING Waste Pile
	//initialize to waste piles so that when one is dequeued it can float, 
	//then go straight to endqueue of the other pile
        cout << wastepile << endl;
	dump = wastepile;
	cout << wastepile << "DUMP:" << dump << endl;
	dump.empty();
	cout << "TESTING FLIP FUNCTION: "<< endl;
	flip(wastepile, dump, (*removed));
	//dump.endQueue((*removed));	
	cout << "TESTING FLIP FUNCTION: "<< endl;
	flip(wastepile, dump, (*removed));
	//dump.endQueue((*removed));	
	cout << "TESTING FLIP FUNCTION: "<< endl;
	flip(wastepile, dump, (*removed));


	//FOUNDATION TEST USING UNSHUFFLED DECK
	dump.empty();
	wastepile.empty();
	unshuffledDeck.loadTabAndWaste(tab2, wastepile);
	cout << tab2 << endl;
	//move a card from the tableau to the foundation
	removed2 = tab2.removeAndReturn(1, 1);
	test = heart.push(removed2);
	cout << heart << endl;
	//move a card from foundation to tableau
	cout << "Using the Pop Function" << endl;
	removed2 = heart.pop();
		
   //end
   delete[] filename;
   delete removed;
   return 0;
  }
//IMPLEMENTATION
void flip(waste& pile, waste& dump, card& top){
   int i = 0;
   card* temp;
   temp = new card;
   if(pile.isEmpty()){
   //transfer all the cards from dump to pile if empty
   pile = dump;
   dump.empty();
   }
      //flip 2 cards over to dump unless it's the pile is empty
      while(i < 2){
	if(pile.isEmpty()){
		i = 4;
	}
	else{
   		//increment
 		i++;
		//swap card
		(*temp) = pile.deQueue();
   		top = (*temp);
			if(!pile.isEmpty()){
			//if not last card in deck transfer it to the dump
			//cout << "CALLS endQueue in flip" << top<< endl;
			dump.endQueue((*temp));	
			}
	}
       }
	//if pile is not empty flip and display the top card on waste
	if(!pile.isEmpty()){
	top = pile.deQueue();
	cout << "Top card of the waste pile: " << top << endl;
	}
	else{
	//this is the last card in the pile 
	cout << "Top card of the waste pile: " << top << endl;
	}	
	temp = NULL;     
}

