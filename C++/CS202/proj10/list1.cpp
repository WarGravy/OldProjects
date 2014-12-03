//NAME: Zachary Carlson

//INCLUDE FILES
  #include <iostream>
  #include"list1.h"
  using namespace std;
//IMPLEMENTATION

//constructor
list::list(int size){
  data = new char[size];
  max = size;
  actual = 0;
  cursor = 0;
}
//copy constructor
list::list(const list& rhs){
  //initialize variables
  cursor = rhs.cursor;
  actual = rhs.actual;
  max = rhs.max;
  data = new char[max];
  int i = 0;
  //fill array
  for(i = 0; i < max; i++){
	data[i] = rhs.data[i];
  }
}
//destructor
list::~list(){
  delete[] data;
  actual = 0;
  cursor = 0;
  max = 0;
}

bool list::goToBeginning(){
   if(empty()){
   return false;
   }
   
   else{
   cursor = 0;
   return true;
   }
}
bool list::goToEnd(){
  if(empty()){
  return false;
  }
  
  else{
  cursor = actual - 1;
  return true;
  }
}
bool list::goToNext(){
  //check if empty
  if(empty()){
  return false;
  }
  //check if cursor can go any further
  else if(cursor == (max - 1) && cursor >= actual){
  return false;
  }
  //move to next
  else{
  cursor++;
  return true;
  }
}
bool list::goToPrior(){
  if(empty()){
  return false;
  }

  else if( cursor == 0){
  return false;
  }

  else{
  cursor--;
  return true;
  }
}
bool list::insertAfter(char value){
  //initialize temp variables
  char temp1, temp2;
  int i;
  //check if full return false
  if(full()){
  	return false;
  }
  //check if empty for easy case of inserting
  else if(empty()){
  	actual++;
  	cursor == 0;
  	data[cursor] = value;
  	return true;
  }
  //else shift everything after down one and insert
  else{
	if( cursor == actual - 1){
 		actual++;
 		cursor++;
 		data[cursor] = value;
 		return true;
  	}
 	//shuffle down
 	else{
  		cursor++;
        	actual++;
		temp1 = data[cursor];
		data[cursor] = value;
		for(i = cursor+1; i < actual; i++){
		temp2 = data[i];
		data[i] = temp1;
		if( i +1 < actual){
		temp1 = data[i+1];
		}
		}
  		return true;
	}
  }
}
bool list::insertBefore(char value){
   //variables
   char temp1, temp2;
   int i;
  //check if full return false
  if(full()){
  	return false;
  }
  //check if empty for easy case of inserting
  else if(empty()){
  	actual++;
  	cursor == 0;
  	data[cursor] = value;
  	return true;
  }
  //insert before
  else{
	//if cursor is at head
	if( cursor == actual - 1){
 		actual++;
		temp1 = data[cursor];
 		data[cursor+1] = temp1;
 		data[cursor] = value;
 		return true;
  	}
 	//shuffle down
 	else{
  		cursor++;
        	actual++;
		temp1 = data[cursor];
		data[cursor] = value;
		for(i = cursor+1; i < actual; i++){
			temp2 = data[i];
			data[i] = temp1;
			if( i +1 < actual){
			temp1 = data[i+1];
			}
		}
  		return true;
	}
  }
}
char list::remove(){
  //declare temps
  char temp1, temp2, returnVal;
  int i;
  //check if empty
  if(empty()){
  	//do nothing
  	return '0';
  }
  //check if last in array(this works as well if actual = 1)
  else if( cursor == actual - 1){
  	returnVal = data[cursor];
  	cursor = 0;
  	actual--;
  	return returnVal;
  }
  //else remove and shuffle
  else{
  	returnVal = data[cursor];
	temp1 = data[cursor+1];
  	for(i = cursor + 1; i < actual; i++){
	temp2 = data[i];
	data[i-1] = temp1;
			if( i +1 < actual){
			temp1 = data[i+1];
			} 
  	}
	actual--;
	return returnVal;
  }
}
bool list::replace(char value){
   if(empty()){
   return false;
   }
   else{
   data[cursor] = value;
   return true;
   }
}
int list::getCursor(){
   return cursor;
}

bool list::empty(){
  if(actual == 0){
  return true;
  }
  
  else{
  return false;
  }
}
bool list::full(){
  if(actual == max){
  return true;
  }
  else{
  return false;
  }
}
void list::clear(){
  cursor = 0;
  actual = 0;
}

//overloaded operators
list list::operator=(const list& rhs){
  //initialize variables
  cursor = rhs.cursor;
  actual = rhs.actual;
  max = rhs.max;
  data = new char[max];
  int i = 0;
  //fill array
  for(i = 0; i < max; i++){
	data[i] = rhs.data[i];
  }
}
ostream& operator<<(ostream& out, const list& rhs){
  int index;
  for(index=0; index < rhs.actual; index ++){
	if( index == rhs.cursor){
 	out << '|' << rhs.data[index] << '|';
  	}
   	else{
	out << rhs.data[index];
  	}
  }
  return out;
}
bool list::operator==(const list& rhs){
  int index;
  if(cursor == rhs.cursor && max == rhs.max && actual == rhs.actual){
      	for(index = 0; index < actual; index++){
		if(data[index] != rhs.data[index]){
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
