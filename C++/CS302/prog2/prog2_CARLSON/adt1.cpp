//Coded and Implemented by Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include <fstream>
  #include "adt1.h"
//CONSTRUCTORS
  booking::booking(){
  	archive = new item[10];
  	cursor = -1;
  	rear = -1;
        id = new char[21];
	id[0] = '\0';
  }
  booking::~booking(){
	//automatic destruction
  }
//PUBLIC FUNCTIONS
  void booking::resetCursor(){
  	if(cursor != -1){
	cursor = 0;
	}
  }
  bool booking::moveNext(){
 	if(cursor+1 > rear){
	return false;
	}
	cursor++;
	return true;
  }
  bool booking::insert(item temp){
	//if inventory is empty 
	if( rear == -1){
		//set cursor and rear to 0
		cursor = 0;
		rear = 0;
		//copy item at cursor
		copyItem(temp);
		//return true
		return true;
	}
	//if inventory is full
	else if(isFull()){
		return false;
	}
  	//if inventory is neither empty nor full
	else{
	int start = 0;
		while(start <= rear){
			//if the item needs to be sorted before the current position
			if(sortStringBefore(archive[start].customerName, temp.customerName)){
			cursor = rear+1;
				while(cursor > start){
				//copy item at cursor
				copyItem(archive[cursor-1]);
				cursor--;
				}
			//after loop cursor is at start, copy temp at cursor
			copyItem(temp);
			rear++;
			return true;
			}
		start++;
		}
	//insert item at the end of array
	rear++;
	cursor = rear;
	copyItem(temp);
	//return true
	return true;
	}
  }
//------------------------------
  void booking::clear(){
  /*this function doesn't care about overwriting data so it sets rear and cursor to -1*/
   cursor =-1;
   rear = -1;
  }
//------------------------------
  bool booking::search(char array[20]){
	int i = cursor;
  	//check if cursor is -1
  	if(cursor == -1){
		//return false so user knows the search failed
		return false;
	}
 	//set cursor to 0
	cursor = 0;
	/*loop through array until A) customer name is found or B) cursor > rear*/
	while(cursor <= rear){
		if(compareString(archive[cursor].customerName, array)){
		return true;
		}
	cursor++;
	}
	//cout << "NOT FOUND IN SEARCH" << endl;
	cursor = i;
	return false;
  }
//------------------------------
  bool booking::searchSpecial(char array[20]){
	int i = cursor;
  	//check if cursor is -1
  	if(cursor == -1){
		//return false so user knows the search failed
		return false;
	}
 	//set cursor to 0
	cursor = 0;
	/*loop through array until A) customer name is found or B) cursor > rear*/
	while(cursor <= rear){
		if(compareString(archive[cursor].specialName, array)){
		return true;
		}
	cursor++;
	}
	//cout << "NOT FOUND IN SEARCH" << endl;
	cursor = i;
	return false;
  }
//------------------------------
  bool booking::getItem(item& temp){
	//initialize i
	int i=0;
	//copy customer name
	while(archive[cursor].customerName[i] != '\0' ){
		temp.customerName[i] = archive[cursor].customerName[i];
		i++;
	}
	if(i != 21){
		//add null char
		temp.customerName[i] = '\0';
	}
	//copy special name
	i=0;
	while(archive[cursor].specialName[i] != '\0' ){
		temp.specialName[i] = archive[cursor].specialName[i];
		i++;
	}
	if(i != 21){
		//add null char
		temp.specialName[i] = '\0';
	}
  }

//------------------------------
  bool booking::isFull(){
	  if(rear == 9){
	  return true;
	  }
  return false;
  }
//------------------------------
  int booking::getLength(){
  return rear+1;
  }
//------------------------------
  void booking::status(){
    if(rear >=0){
	//initialize variables
	int i = 0;
  	//output id name:
  	if(id != NULL && id[0] !='\0'){
	cout << id << endl << "--------------------"<<endl<< endl;
  	}
	//loop through all the items
	while(i <= rear){
	cout << archive[i].specialName << endl;
	cout << archive[i].customerName<<endl;
	cout << "--------------------"<<endl;
	i++;
	}
    }
    else{
	if(id != NULL && id[0] !='\0'){
	cout << id << endl << "--------------------"<<endl<< endl;
  	}
	cout << "No events scheduled." << endl;
    }	
  }
//------------------------------
  bool booking::deleteItem(){
    //declare temps
    int i;
    int cursorStart = cursor;
  //check if empty
  if(rear == -1){
  	//do nothing
  	return false;
  }
  //check if last in array
  else if( cursor == rear){
	rear --;
	cursor --;
  	return true;
  }
  //else overwrite at cursor position and shuffle down
  else{
	rear--;
	for(i=cursor+1;cursor <=rear;i++){
	copyItem(archive[i]);
	cursor++;
	}
	cursor = cursorStart;
	return true;
      }
  }
//------------------------------
  bool booking::outputToFile(ofstream& fout){
  int index = 0;
  if(fout.good()){
	if(id != NULL && id[0] != '\0'){
	fout << id << ' ' << getLength() << endl;
	}
	while(index <= rear){
	fout << archive[index].specialName <<' '<<archive[index].customerName << endl;
	index++;
	}
  return true;
  }
  else
  return false;
  }
//------------------------------
  void booking::operator=(const booking& rhs){
    if(this != &rhs){
	cursor = 0;
	int i;
	rear = rhs.rear;
	for(i = 0; i <= rear; i++){
	copyItem(rhs.archive[i]);
	cursor++;
	}
	cursor = rhs.cursor;
    }
    else{
	rear = -1;
	cursor = -1;
	}
    
  }
//------------------------------
//only used when using arrays of bookings
//-----------------------------
  void booking::setID(char* newID){
    {
    //initialize function
    int i = 0;
    char* home;
    home = id;
    //run the loop copying each char over one by one 
	while(i < 20 && *newID != '\0')
	  {
	  *id = *newID;
	  newID++;
	  id++;
	  i++;
	  }
	if(i == 20 && *newID!= '\0'){
	*id = *newID;
	}
	*id = '\0';
	id = home;	
  }

  }
//PRIVATE
  void booking::copyItem(item temp){
   	int i = 0;
	//add customer name
		while(temp.customerName[i] != '\0' ){
			archive[cursor].customerName[i] = temp.customerName[i];
			i++;
		}
		archive[cursor].customerName[i] = '\0';
	//add special name
		i=0;
		while(temp.specialName[i] != '\0' ){
			archive[cursor].specialName[i] = temp.specialName[i];
			i++;
		}
		archive[cursor].specialName[i] = '\0';
  }
//IMPLEMENTATIONS for arrays of bookings

/*This is serves the purpose of adding a booking into an array of bookings and inserts it in
the correctly sorted position by alphabetical IDs.*/
  bool addBooking(booking array[], booking newList, int size){
  //Pre: THERE HAS TO BE ROOM IN THE ARRAY FOR THE NEWLIST
    //initialize
    if(size == 0){
	array[0]=newList;
	return true;
    }
    int i = 0;
    while(!(sortStringBefore(array[i].id, newList.id)) && (i <= size)){
	i++;
    }
    //check if to sort at the end of the array
    if((!(sortStringBefore(array[i].id, newList.id))) && (i==size)){
	array[size] = newList;
	return true;
    }
    //sort and shuffle
    else{
  	size++;
  	while(size > i +1){
		array[size-1] = array[size-2];
		size--;
	}
	array[i] = newList;
	return true;
    }
  }
//------------------------
/*This functions searches for matching c style strings and returns the integer of where 
in the array the booking is.*/
  int searchId(char* id, booking array[], int size){
  //pre: cannot be NULL and array cannot be empty.
  int i;
	for(i = 0; i < size; i++){
		if(compareString(array[i].id, id)){
		return i;
		}
	} 
  return -1;
  }
//-------------------------
  bool sortStringBefore(char* original, char* newString){
  //Pre: both pointers cannot be null
  //initialize variables
  int i = 0;
  //find point of no match
  while((newString[i] == original[i]) && (newString[i] != '\0') && (original[i] != '\0')){
	/*check if new string is smaller than original(this also will take care of the case if they are both the same string and just default to sorting the new one before the original*/
	if(newString[i] == '\0'){
		return true;
	}
	//check if original string is shorter than new string, sort after
	if(original[i] == '\0'){
		return false;
	}
	//increment index to point where the strings differ	
	i++;
	}
  //check and see if newString should be sorted before
  if(newString[i] < original[i]){
	return true;
  }
  //else return false
  return false;
  }
//--------------------------
bool compareString(char* original, char* rhs){
  int i = 0;
  while((rhs[i] == original[i]) && (rhs[i] != '\0') && (original[i] != '\0')){
	i++;
  }
  if(rhs[i] == '\0' && original[i] == '\0'){
	return true;
  }
  return false;
}
