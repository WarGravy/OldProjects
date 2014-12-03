//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include "deck.h"
using namespace std;
//GLOBAL
const int MAX_NAME = 50;
//PROTOTYPES

//MAIN PROGRAM
int main()
  {
   //initialize variables
   char* filename;
   filename = new char[MAX_NAME];
   deck deck1, deck2;
   bool test = false;
   //prompt for filename
   cout <<"Enter the filename with extension .txt: ";
   cin >> filename;
   //read in deck
   cout << "Reads in deck1 from file" << endl;
   test = deck1.readDeck(filename);
   cout << "deck2 = deck1" << endl; 
   deck2 = deck1;
   cout << "print deck 2" << endl;
   cout << deck2;
   cout << "shuffle deck1" << endl;
   test = deck1.shuffleDeck();
   //test
   cout << deck1;

   	//TESTING TABLEAU
	//tableau tab1;
	//deck1.loadTabAndWaste(tab1);
  	//print tableau
 	  //cout << tab1 << endl;
   //end
   return 0;
  }
//IMPLEMENTATION


