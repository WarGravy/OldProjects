//NAME: Zachary Carlson

//INCLUDE FILES
  #include <iostream>
  #include"list2.h"
  using namespace std;
//IMPLEMENTATION
//node constructor
node::node(){
  value = '0';
  next = NULL;
}

//constructor
list::list(){
  head = NULL;
  cursor = NULL;
}
//copy constructor
//list::list(const list&);
//destructor
list::~list(){
  cursor = head->next;
  while(cursor != NULL){
  	delete head;
  	head = cursor;
  	cursor = head->next;
  }
}
bool list::goToBeginning(){
  cursor = head;
  if( empty()){
  return false;
  }
  else
  return true;
}
bool list::goToEnd(){
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
bool list::goToNext(){
  if(empty()){
  return false;
  }
  else if(cursor->next == NULL){
  return false;
  }
  else{
  cursor = cursor -> next;
  return true;
  }
}
bool list::goToPrior(){
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
bool list::insertAfter(char val){
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
bool list::insertBefore(char val){
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
  	temp = new node;
 	temp -> value = cursor -> value;
   	temp -> next = cursor -> next;
 	cursor -> value = val;
 	cursor -> next = temp;
 	return true;
  }
}

char list::remove(){
  node* temp, temp2;
  char returnchar;
  if(empty()){
  return '0';
  }
  else if(head -> next == NULL){
  returnchar = head -> value;
  delete head;
  head = NULL;
  return returnchar;
  }
  else if(cursor -> next == NULL){
  returnchar = cursor -> value;
  delete cursor;
  cursor = head;
  return returnchar;
  }
  else{
  temp = cursor;
  temp -> next = cursor->next;
  goToPrior();
  cursor->next = temp->next;
  delete temp;
  
  }
}
bool list::replace(char rep){
  if( cursor == NULL){
  return false;
  }
  else{
  cursor->value = rep;
  return true;
  }
}
char list::getCursor(){
  return cursor->value;
}
bool list::empty(){
  if(head == NULL){
  return true;
  }
  else{
  return false;
  }
}
bool list::full(){
  return false;
}
void list::clear(){
  cursor = head->next;
  while(head != NULL){
  	delete head;
  	head = cursor;
  	cursor = head->next;
  }
}
/*
  //overloaded operators
  //operator =
  //list operator=(const list& rhs);
  //operator <<
ostream& operator<< (ostream& out, const list& rhs){
  node* index1, index2;
  index1 = rhs.head;
  index1 -> next = rhs.head->next;
  while(index1 != NULL){
	out << index1 -> value;
    	//index1 = index1 -> next;
   
  }
  return out;
}
  //operator ==
  //bool operator==(const list&);*/
