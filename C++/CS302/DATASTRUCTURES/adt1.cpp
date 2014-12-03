//Class written by 
//INCLUDE FILES
  #include <iostream>
  #include "adt1.h"
//linkedListSorted

linkedListSorted::linkedListSorted(){
  head = NULL;
  cursor = NULL;
}
//destructor
linkedListSorted::~linkedListSorted(){
  cursor = head->next;
  while(cursor != NULL){
  	delete head;
  	head = cursor;
  	cursor = head->next;
  }
}
bool linkedListSorted::goToBeginning(){
  cursor = head;
  if( empty()){
  return false;
  }
  else
  return true;
}
bool linkedListSorted::goToEnd(){
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
bool linkedListSorted::find(int val){
  cursor = head;
  while(cursor != NULL){
  if(cursor -> value == val){
    return true;
   }
  cursor = cursor -> next;
  }
return false;
}
bool linkedListSorted::goToPrior(){
  nodeSort* temp;
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
bool linkedListSorted::insert(int val){
  nodeSort* temp;
  if(full()){
  return false;
  }
  else if(empty()){
  	head = new nodeSort;
  	head -> value = val;
  	cursor = head;
  	return true;
  }
  else{
      cursor = head;
      while(cursor -> next != NULL){
         if(val >= cursor -> value){
	  cursor = cursor -> next;
	 }
	 else if(val < cursor -> value){
	 return insertBefore(val);
	 }
      }
      return insertAfter(val);
  }
}
bool linkedListSorted::insertAfter(int val){
  nodeSort* temp;
  	temp = cursor;
  	cursor = new nodeSort;
 	cursor -> value = val;
  	cursor -> next = temp -> next;
 	temp -> next = cursor;
 	return true;
}
bool linkedListSorted::insertBefore(int val){
  nodeSort* temp;

  	temp = new nodeSort;
 	temp -> value = cursor -> value;
   	temp -> next = cursor -> next;
 	cursor -> value = val;
 	cursor -> next = temp;
 	return true;
  
}

int linkedListSorted::remove(){
  nodeSort* temp, temp2;
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
bool linkedListSorted::replace(int rep){
  if( cursor == NULL){
  return false;
  }
  else{
  cursor->value = rep;
  return true;
  }
}
int linkedListSorted::getCursor(){
  return cursor->value;
}
bool linkedListSorted::empty(){
  if(head == NULL){
  return true;
  }
  else{
  return false;
  }
}
bool linkedListSorted::full(){
  nodeSort* location;
  try
  {
    location = new nodeSort;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }

}
void linkedListSorted::clear(){
  cursor = head->next;
  while(head != NULL){
  	delete head;
  	head = cursor;
  	cursor = head->next;
  }
}
