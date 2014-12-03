//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "arrayList.h"
  using namespace std;
//IMPLEMENTATION
 //constructor
arrayList::arrayList(int size){
  data = new int[size];
  max = size;
  actual = 0;
  cursor = 0;
  pivot = 0;
}
//copy constructor
arrayList::arrayList(const arrayList& rhs){
  //initialize variables
  cursor = rhs.cursor;
  actual = rhs.actual;
  max = rhs.max;
  data = new int[max];
  int i = 0;
  //fill array
  for(i = 0; i < max; i++){
	data[i] = rhs.data[i];
  }
}
//destructor
arrayList::~arrayList(){
  delete[] data;
  actual = 0;
  cursor = 0;
  max = 0;
}

bool arrayList::goToBeginning(){
   if(empty()){
   return false;
   }
   
   else{
   cursor = 0;
   return true;
   }
}
bool arrayList::goToEnd(){
  if(empty()){
  return false;
  }
  
  else{
  cursor = actual - 1;
  return true;
  }
}
bool arrayList::goToNext(){
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
bool arrayList::goToPrior(){
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
bool arrayList::insertAfter(int value){
  //initialize temp variables
  int temp1, temp2;
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
bool arrayList::insertBefore(int value){
   //variables
   int temp1, temp2;
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
int arrayList::remove(){
  //declare temps
  int temp1, temp2, returnVal;
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
bool arrayList::replace(int value){
   if(empty()){
   return false;
   }
   else{
   data[cursor] = value;
   return true;
   }
}
int arrayList::getCursor(){
   return cursor;
}

bool arrayList::empty(){
  if(actual == 0){
  return true;
  }
  
  else{
  return false;
  }
}
bool arrayList::full(){
  if(actual == max){
  return true;
  }
  else{
  return false;
  }
}
void arrayList::clear(){
  cursor = 0;
  actual = 0;
}
//BINARY SEARCH
int arrayList::setPivot(){
pivot = actual / 2;
return pivot;
}
int arrayList::binarySearch(int x, int index){
  if( index < 0 || index > actual){
  cout << "The value was not found, returning 0" << endl;
  return 0;
  }
  //bottom half
  if(x <= data[index]){

	  if(x == data[index]){
	  return index;
	  }
	  else{
	  return binarySearch( x, index - 1); 
	  }
  }
  //top half
  else{

	  if(x == data[index]){
	  return index;
	  }
	  else{
	  return binarySearch( x, index + 1); 
	  }
  }
}
//OVERLOADED OPERATOR
ostream& operator<< (ostream& out, const arrayList& rhs){
  int i = 0;
  while(i < rhs.actual){
	cout << rhs.data[i] << endl;
	i++;
  }
  return out;
}

