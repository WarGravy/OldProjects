//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "card.h"
  using namespace std;
//CARD IMPLEMENTATION
card::card(){
  next = NULL;
  rank = 0;
  suit = new char[10];
  color = '0';
  }
card::~card(){
  if(suit != NULL){
  cout << "Calls the Card Destructor" << endl;
  suit = NULL;
  //ERROR 1 is here
  //delete[] suit;
  }
  next = NULL;
  rank = 0;
  color = '0';
}
bool card::setSuit(char* temp){
     int i;
     if(temp != NULL || suit != NULL){
       		for(i = 0; temp[i] != '\0'; i++){
 		suit[i] = temp[i];
		}
  	 	suit[i] = '\0';
       	return true;
       	}
     else
      	return false;
}
//overloaded operators
card card::operator=(const card& rhs){
  cout << " Calls the overloaded operator for card '=' "<< endl;
  next = rhs.next;
  rank = rhs.rank;
  color = rhs.color;
  setSuit(rhs.suit);
}
ostream& operator<<(ostream& out, const card& rhs){
  cout << rhs.rank << rhs.color << ' ' << rhs.suit;
  return out;
}
bool card::operator==(const card& rhs){
  int index;
  if(rank == rhs.rank && color == rhs.color && next == rhs.next){
      	for(index = 0; (suit[index] != '\0') || (rhs.suit[index] != '\0'); index++){
		if(suit[index] != rhs.suit[index]){
		return false;
		}
	}
	//if it finishes the loop
    	return true;
  }
  else{
  	return false;
  }
}

