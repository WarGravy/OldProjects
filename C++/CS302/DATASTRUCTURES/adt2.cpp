//Class written by 
//INCLUDE FILES
  #include <iostream>
  #include "adt2.h"


//linkedListUNSorted

linkedListUNSorted::linkedListUNSorted(){
  head = NULL;
  cursor = NULL;
}
//destructor
linkedListUNSorted::~linkedListUNSorted(){
  cursor = head->next;
  while(cursor != NULL){
  	delete head;
  	head = cursor;
  	cursor = head->next;
  }
}
bool linkedListUNSorted::goToBeginning(){
  cursor = head;
  if( empty()){
  return false;
  }
  else
  return true;
}
bool linkedListUNSorted::goToEnd(){
  if(full()){
  return false;
  }
  else if(empty()){
  return false;
  }
  else{
  	while(cursor -> next != NULL){
  	cursor = cursor -> next;
  	}
	return true;
  }
}
bool linkedListUNSorted::find(int val){
  cursor = head;
  while(cursor != NULL){
  if(cursor -> value == val){
    return true;
   }
  cursor = cursor -> next;
  }
return false;
}

bool linkedListUNSorted::goToPrior(){
  node* temp;
  if(empty()){
  return false;
  }
  else if(cursor == head){
  return false;
  }
  else{
  	temp = cursor -> next;
  	cursor = head;
  	while(cursor -> next != temp){
  	cursor = cursor -> next;
  	}
  }
}
bool linkedListUNSorted::insert(int val){
  node* temp;
  if(full()){
  return false;
  }
  else if(empty()){
  	head = new node;
  	head -> value = val;
  	cursor = head;
  	return true;
  }
  else{
  	temp = cursor;
  	cursor = new node;
 	cursor -> value = val;
  	cursor -> next = temp -> next;
 	temp -> next = cursor;
 	return true;
  }
}

int linkedListUNSorted::remove(){
  node* temp, temp2;
  int returnint;
  if(empty()){
  return '0';
  }
  else if(head -> next == NULL){
  returnint = head -> value;
  delete head;
  head = NULL;
  return returnint;
  }
  else if(cursor -> next == NULL){
  returnint = cursor -> value;
  delete cursor;
  cursor = head;
  return returnint;
  }
  else{
  temp = cursor;
  temp -> next = cursor->next;
  goToPrior();
  cursor->next = temp->next;
  delete temp;
  
  }
}
bool linkedListUNSorted::replace(int rep){
  if( cursor == NULL){
  return false;
  }
  else{
  cursor->value = rep;
  return true;
  }
}
int linkedListUNSorted::getCursor(){
  return cursor->value;
}
bool linkedListUNSorted::empty(){
  if(head == NULL){
  return true;
  }
  else{
  return false;
  }
}
bool linkedListUNSorted::full(){
  node* location;
  try
  {
    location = new node;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }

}
void linkedListUNSorted::clear(){
  cursor = head->next;
  while(head != NULL){
  	delete head;
  	head = cursor;
  	cursor = head->next;
  }
}
