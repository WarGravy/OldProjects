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
  if(suit == NULL){
  //this was used to help find the major error I detail in the documentation
  //cout << "Test" << endl;
  }
  else if(suit != NULL){
  //cout << "Calls the Card Destructor" << endl;
  //suit = NULL;
  //ERROR 1 is here
  //cout << "TEST"<<endl;
  delete[] suit;
  }
  next = NULL;
  rank = 0;
  color = '0';
}
bool card::setSuit(char* temp){
   int i;
   if(temp != NULL && suit != NULL){
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
void card::operator=(const card& rhs){
  //cout << " Calls the overloaded operator for card '=' "<< endl;
  if(this != &rhs){
  next = rhs.next;
  rank = rhs.rank;
  color = rhs.color;
  setSuit(rhs.suit);
  }
}
ostream& operator<<(ostream& out, const card& rhs){
  cout << rhs.rank << rhs.color << ' ' << rhs.suit;
  return out;
}
bool card::operator==(const card& rhs){
  int index = 0;
  //check if  everything besides the suit is equal
  if(rank == rhs.rank && color == rhs.color && next == rhs.next){
        //check if suit is equal
      	while((suit[index] != '\0') || (rhs.suit[index] != '\0')){
		if(suit[index] != rhs.suit[index]){
		return false;
		}
        index++;
	}
	//if it finishes the loop
    	return true;
  }
  else{
  	return false;
  }
}

