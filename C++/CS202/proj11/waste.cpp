//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "waste.h"
  using namespace std;
//IMPLEMENTATION
waste::waste(){
size = 0;
front = rear = NULL;
}

waste::~waste(){
  //cout << "CALLING WASTE DESTRUCTOR" <<endl;
  if(front != NULL){
  rear = front->next;
  delete front;
        //loop through the next pointers until null
	while(rear != NULL){
	front = rear;
	rear = front->next;
	delete front;
	}
  }
}

void waste::empty(){
  size = 0;
  if(front != NULL){
  rear = front->next;
  delete front;
        //loop through the next pointers until null
	while(rear != NULL){
	front = rear;
	rear = front->next;
	delete front;
	}
  }
  front = rear = NULL;
}

card waste::deQueue(){
  //initialize temp card pointer
  card* temp;
  temp = new card;
  //check if empty
  if(front == NULL){
      cout << "ERROR: wastepile is empty, returning blank card!" << endl;
      return (*temp);
  }
  else{
  //decrement size
  size--;
  //set temp pointer to front
  (*temp) = (*front);
  //set front to second card(the new front)
  front = front -> next;
  return (*temp);
  }
}
bool waste:: isEmpty(){
  if(size == 0){
  return true;
  }
  else
  return false;
}
bool waste::endQueue(card newCard){
   card* temp;
   //cout << "CALLING endQueue for waste" << endl;
   //check if empty
   if(front == NULL){
     size++;
     front = new card;
     rear = front;
     (*front) = newCard;
     front-> next = NULL;
     //cout << "TEST" << (*front) << endl;
     return true;
   }
   //add newCard at the end of the queue FILO
   if(front != NULL){
     //increment size
     size++;
     temp = new card;
     (*temp) = newCard;
     rear-> next = temp;
     rear = temp;
     //set temp to null to be safe from destructors
     temp = NULL;
     rear -> next = NULL;
     //cout << "TEST" << (*rear) << endl;	
     return true;
   }
   else{
   return false;
   }
}

//OVERLOADED OPERATORS
void waste::operator=(const waste& rhs){
  //cout << "START IS HERE" << endl;
  //initialize variables
  card *temp, *temp2, *temp3;
  size = 0;
  //initial precautions
  if(this != &rhs){
        //delete any existing cards
   	if(front != NULL){
   	rear = front->next;
   	delete front;
        //loop through the next pointers until null
		while(rear != NULL){
		front = rear;
		rear = front->next;
		delete front;
		}
   	}
  	//empty wastepile case
  	if(rhs.front == NULL){
  	front = rear = NULL;
  	}
        //Full wastepile case
        else{
    	//create first card
        front = new card;
	//increments size by 1
	size++;
	//sets temp to front
	temp = front;
	//sets temp to rhs front
  	temp2 = rhs.front;
	//assign the card it's value
 	(*temp) = (*temp2);
		//cout << "FIRST CARD !!!!" <<(*temp) << endl;
	//move temp2 to next card down
        temp2 = temp2 -> next;
	//set temp1 -> next to NULL
	temp->next = NULL;
		//loop for the rest of the cards
		while(temp2 != NULL){
 		temp3 = new card;
		size++;
		//link the card
		temp -> next = temp3;
		//set temp to current card
		temp = temp3;
		//assign the card it's value
 		(*temp) = (*temp2);
			//cout << "Second CARD !!!!" <<(*temp) << endl;
		//move temp2 to next card down
        	temp2 = temp2 -> next;
		//set temp-> next to NULL just in case loop ends
		temp->next = NULL;
 		}
	//set rear
	rear = temp;
        }
  temp = NULL;
  temp2 = NULL;
  temp3 = NULL;
  //end for this!=&rhs
  }
  	//cout << "END IS HERE" << endl;
  	//cout << "TEST DUMP" << (*this) << endl;
}

ostream& operator<< (ostream& out, const waste& rhs){
  card* temp;
  temp = rhs.front;
  //if the waste pile exists print title 
  if(rhs.size > 0){
   cout << "WASTE PILE: " << endl;
  }
  while(temp != NULL){
      //print temp
      cout << (*temp) << endl;
      //point temp to the next card
      temp = temp -> next;
  }
  return out;
}
