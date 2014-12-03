//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include <fstream>
  #include "deck.h"
  #include <time.h>
  #include <stdio.h>
  #include <stdlib.h>
  using namespace std;

//DECK IMPLEMENTATION
deck::deck(){
  head = NULL;
  cursor = NULL; 
}
deck::~deck(){
  cout<< "Calls the deck destructor" << endl;
  cursor = NULL;
  if(head != NULL){
  //ERROR 2 IS HERE
  //delete []head;
  }
}

bool deck::readDeck(char* filename){
  //initialize variables
  head = new card[52];
  cursor = head;  
  ifstream fin;
  int i;
  //open file
  fin.clear();
  fin.open(filename);
  if(fin.good()){
  	for(i = 0; i < 52; i++, cursor++){
	   fin >> (*cursor).color;
	   fin >> (*cursor).rank;
 	   fin >> (*cursor).suit;
  	}
  cursor = head;
  fin.close();
  return true;
  }
  else
  return false;
}
bool deck::shuffleDeck(){
  //check to see if deck has been created
  if(head == NULL){
  return false;
  }
  //initialize function
   //initialize variables
   int count;
   int randomNum;
   int randomNum2;
   card temp1;
   //initialize pointer
   card* ptr;
   card* ptr2;
   card* home;
   //assign home pointers
   home = head;
   ptr = home;
   ptr2 = home;
   //initialize random
   srand( time(NULL));

       	//output to user, telling them the game is shuffling the deck
       	cout<< "Shuffling Cards Please wait..."<<endl;
  	//shuffle the deck
  	for(count = 0; count < 160; count++){
      	//generate the two random cards that will be swapped
      	randomNum = rand() % 100 + 1;
      	randomNum = randomNum / 2;
      	randomNum2 = rand() % 100 + 1;
      	randomNum2 = randomNum2 / 2;
      	//swap two cards in the deck
      	if(randomNum < 52 && randomNum2 <52 && randomNum != randomNum2){
	 	//incremement the first pointer by the first randomNum
	 	ptr += randomNum;
	 	//incremement the second point by the second randomNum2
	 	ptr2 += randomNum2;
	 	//temp1 = ptr
         	temp1.setSuit((*ptr).suit);
         	temp1.rank = (*ptr).rank;
         	temp1.color = (*ptr).color;
	 	//trade cards
         		//ptr = ptr2
	 		(*ptr).setSuit((*ptr2).suit);
         		(*ptr).rank = (*ptr2).rank;
         		(*ptr).color = (*ptr2).color;
         		//ptr2 = temp
	 		(*ptr2).setSuit(temp1.suit);
         		(*ptr2).rank = temp1.rank;
         		(*ptr2).color = temp1.color;
	 //set pointers back to home	
	 ptr = ptr2 = home;
	 }
	//end for loop
    	}
  //output the function has finished shufflinf the deck
  cout<<"Finished"<<endl;
  temp1.suit = NULL;
  return true;
}

//for testing purposes
ostream& operator<< (ostream& out, const deck& rhs){
   card* temp;
   temp = rhs.head;
   int i;
   for(i = 0; i < 52; i++, temp++){
   cout << *temp << endl;
   }
   return out;
}
deck deck::operator=(const deck& rhs){
  cout << "Calls the overloaded operator '=' for deck" << endl;
  int i,j, count;
  if(rhs.head != NULL){
  head = new card[52];
  cursor = head;
  	//copy across cards
  	for(i = 0; i < 52; i++){
  	head[i] = rhs.head[i];
  	//check for cursor
  		if(rhs.head[i] == rhs.cursor[0]){
		count = i;
  		}
  	}
   	//increment cursor
	cursor = head;
   	for(j= 0; j < count; j++){
  	cursor++;
 	}
  //end if
  }
  else{
  head = NULL;
  cursor = NULL;
  }
}

//LOAD WASTE AND TABLEAU
void deck::loadTabAndWaste(tableau &tab){
  int i;
  int j = 1;
  	//add cards to the tableau
  	for(i = 0; i < 28; i++){
  		if(i == 1 || i == 3 || i == 6 || i == 10 || i == 15 || i == 21){
		j++;
  		}
  	tab.insertAfter(head[i], j);
    	}
  //ADD WASTE

}
