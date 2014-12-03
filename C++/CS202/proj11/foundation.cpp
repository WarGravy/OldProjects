//NAME: Zachary Carlson
#include<iostream>
#include "foundation.h"
using namespace std;

foundation::foundation(){
  top = -1;
  pile = new card[13];
}
foundation::~foundation(){
  if(pile != NULL){
 	delete[] pile;
  }
}
card foundation::pop(){
  int temp;
  //check empty
  if(top == -1){
	cout << "Cannot Pop from the foundation pile because it is empty. Returning blank card." << endl;
	card defaultCard;
	return defaultCard;
  }
  //if last card
  else if(top == 0){
 	top = -1;
	return pile[0];
  }
  else{
  //save the location of the top card
  temp = top;
  top--;
  return pile[temp];
  }
}
bool foundation::push(card& newCard){
   card temp;
   temp = newCard;
  //check full
  if(top != 12){
    top++;
    pile[top] = temp;
    pile[top].next = NULL;
    return true;
    }
  //else return false
  else{
  return false;
  }
}

ostream& operator<< (ostream& out, const foundation& rhs){
   if(rhs.top != -1){
   int i = rhs.top;
   cout << "Foundation Stack Top Card: " << rhs.pile[i] << endl;
   i--;
   cout << "Rest of the pile:" << endl;
 	while(i > 1){
	cout << rhs.pile[i] << " | ";
	i--;
 	}
	if(i == 0){
	cout << rhs.pile[i] << endl;
	}
   }
   return out;
}
