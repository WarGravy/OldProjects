//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "nodeList.h"
  using namespace std;
//IMPLEMENTATION
nodeList::nodeList(){
  cursor = NULL;
  data = NULL;
}
nodeList::~nodeList(){
  if(data != NULL){
  cursor = data->next;
  delete data;
   	while(cursor != NULL){
	data = cursor;
  	cursor = cursor->next;
  	delete data;		
 	}
  }
  cursor = NULL;
  data = NULL;
}
int nodeList::removeInt(){
  int temp = 0;
  //check if empty
  if(empty()){
  //return 0
  return temp;
  }
  else{
  //set cursor to the second node, aka new head
  cursor = data;
  cursor = data -> next;
  //set temp to int
  temp = data -> value;
  	//if there is only one node
 	if(cursor == NULL){
  	delete data;
 	data = cursor = NULL;
	return temp;
 	}
  	//else if there is more than 1 node.
	else{
 	delete data;
	//set data to new head
  	data = cursor;
	return temp;
	}
  }
}
bool nodeList::insert(int x){
  //create new node
  node *temp, *temp2;
  temp = new node;
  (*temp).value = x;
  //check if empty
  if(empty()){
  //error possibility, may need to write overloaded operator for node
  data = cursor = temp;
  temp = NULL;
  data -> next = NULL;
  return true;
  }
  /*if not empty sort through list to find the correct location starting from   start*/
  else{
	//if there is only one node
	if(data->next == NULL){
		//if value is less than the head(insert before)
		if(data->value >= x){
		temp -> next = data;
		data = cursor = temp;
		temp = NULL;
		}
		//else value is greater than the head(insert after)
		else{
		data->next = temp;
		temp = NULL;
		cursor = data->next;
		}
	return true; 	
	}
	//else if there is more than one node
	else{
	cursor = data;
		//loop so we are sorting from least to greatest
		while(cursor-> value < x && cursor -> next !=NULL){
		cursor = cursor->next;
		}
		//if last node
		if(cursor-> next == NULL){
			//if cursor -> value  > temp -> value(insert before)
			if(cursor -> value > x){
			/*cout << "The Value is: " << x << "and is being sorted before" << cursor -> value << endl;*/
			temp2 = data;
				while( temp2 -> next != cursor){
				temp2 = temp2 -> next;
				}
			temp2 -> next = temp;
			temp -> next = cursor;
			cursor = temp;
			}
			//else cursor value is less than temp value(insert after)
			else{
			/*cout << "The Value is: " << x << "and is being sorted after" << cursor -> value << endl;*/
			cursor -> next = temp;
			cursor = cursor -> next;
			}
		temp = NULL;
		return true;
		}
		//if not last node
		else{
		//go to previous node
		temp2 = data;
			while( temp2 -> next != cursor){
			temp2 = temp2 -> next;
			}
		//TEST:cout << temp2 -> value;
		//TEST:cout <<'|' <<x <<'|'<< cursor -> value << '|' << endl;
		temp2 -> next = temp;
		temp -> next = cursor;
		cursor = temp;
		temp = NULL;
		return true;
		}
	}
  }
  
}
bool nodeList::empty()const{
  if(data == NULL){
  return true;
  }
  return false;
} 
ostream& operator<< (ostream& out, const nodeList& rhs){
  node* temp;
  temp = rhs.data;
  while(temp != NULL){
	cout << temp->value << endl;
	temp = temp -> next;
  }
  temp = NULL;
  return out;
}
