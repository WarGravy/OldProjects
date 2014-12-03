//Class edited by Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include <stdint.h>
  #include "adt1.h"
    nodeSort::nodeSort(){
    next = NULL;
    
    }
    nodeSort::~nodeSort(){
    next = NULL;
    
    }
//linkedListSorted

linkedListSorted::linkedListSorted(){
  head = NULL;
  cursor = NULL;
}
//destructor
linkedListSorted::~linkedListSorted(){
  
  nodeSort* tempPtr;

  while (head != NULL)
  {
    tempPtr = head;
    head = head->next;
    if(tempPtr != NULL){
    delete tempPtr;
    }
    
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
bool linkedListSorted::find(int64_t& val, int& swaps, int& comparisons){
  cursor = head;
  while(cursor != NULL){
  if(cursor -> value == val){
    return true;
   }
   comparisons++;
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
bool linkedListSorted::insert(int64_t& val, int& swaps, int& comparisons){
 nodeSort* newNode;  	// pointer to node being inserted
  nodeSort* predLoc;  	// trailing pointer
  nodeSort* location; 	// traveling pointer
  bool moreToSearch;

  location = head;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    comparisons++;
    if(val > (location->value))
      {
	predLoc = location;
      	location = location->next;
        moreToSearch = (location != NULL);
      }
     else{ 
	moreToSearch = false;
      }
    
  }

  // Prepare node for insertion
  newNode = new nodeSort;
  newNode->value = val;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = NULL;
    head = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
    swaps++;
  }
  newNode = NULL;

}
bool linkedListSorted::insertAfter(int64_t& val){
  nodeSort* temp;
  	temp = cursor;
  	cursor = new nodeSort;
 	cursor -> value = val;
  	cursor -> next = temp -> next;
 	temp -> next = cursor;
	temp=NULL;
 	return true;
}
bool linkedListSorted::insertBefore(int64_t& val){
  nodeSort* temp;

  	temp = new nodeSort;
 	temp -> value = cursor -> value;
   	temp -> next = cursor -> next;
 	cursor -> value = val;
 	cursor -> next = temp;
	temp = NULL;
 	return true;
  
}

void linkedListSorted::remove(int64_t& item, int& swaps, int& comparisons){
  
  nodeSort* location = head;
  nodeSort* tempLocation;
  // Locate node to be deleted.
  if (item == (*head).value)
  {
    
    tempLocation = location;
    head = head->next;	// Delete first node.
  }
  else
  {
    while (item != (location->next->value) ){
      location = location->next;
	comparisons++;
	}

    // Delete node at location->next
    tempLocation = location->next;
    (*location).next = location->next->next;
    swaps++;
  }
  cout << tempLocation << endl;
  delete tempLocation;
  cursor = head;

}
bool linkedListSorted::replace(int64_t& rep){
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
void linkedListSorted::print(){
  cursor = head;
  while(cursor != NULL){
  	cout << cursor->value << endl;
  	cursor = cursor->next;
  }
}
