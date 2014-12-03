//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include <fstream>
  #include "adt1.h"
  inventory::inventory(){
  	archive = new item[50];
  	cursor = -1;
  	rear = -1;
  }
  inventory::~inventory(){
	//check to make sure archive isn't null
   	if(archive != NULL){
	delete[] archive;
   	}
  }
  bool inventory::insertAtEnd(item temp){
	int i = 0;
	//if inventory is empty 
	if( rear == -1){
		//add
		cursor = 0;
		rear = 0;
		archive[rear] = temp;
		//add description
		while(temp.description[i] != '\0' ){
			archive[rear].description[i] = temp.description[i];
			i++;
		}
		archive[rear].description[i] = '\0';
		//return true
		return true;
	}
	//if inventory is full
	else if(rear == 49){
		return false;
	}
  	//if inventory is neither empty nor full
	else{
		//add
		rear++;
		archive[rear] = temp;
		//add description
		while(temp.description[i] != '\0' ){
			archive[rear].description[i] = temp.description[i];
			i++;
		}
		archive[rear].description[i] = '\0';
		//return true
		return true;
	}
  }
  void inventory::clear(){
  /*this function doesn't care about overwriting data so it sets rear and cursor to -1*/
   cursor =-1;
   rear = -1;
  }
  bool inventory::search(int productnumber){
  	//check if cursor is -1
  	if(cursor == -1){
		//return false so user knows the search failed
		return false;
	}
 	//set cursor to 0
	cursor = 0;
	/*loop through array until A) productnumber is found or B) cursor > rear*/
	while(cursor <= rear){
		if(productnumber == archive[cursor].id){
		return true;
		}
	cursor++;
	}
	//cout << "NOT FOUND IN SEARCH" << endl;
	cursor = 0;
	return false;
  }
  bool inventory::getItem(item& temp){
	//initialize variables
	int i=0;
	//this function should only be used after search has returned true
	temp.id = archive[cursor].id;
	temp.price = archive[cursor].price;
	temp.tax = archive[cursor].tax;
	//copy item description
	while(archive[cursor].description[i] != '\0' ){
		temp.description[i] = archive[cursor].description[i];
		i++;
	}
	if(i != 13){
		//add null char
		temp.description[i] = '\0';
	}
  }
  void inventory::print(){
  	int index = 0;
	if(index > rear){
 	cout << "Inventory is empty or has been cleared." << endl;
	}
  	while(index <= rear){
		cout << "Inventory Slot " << index + 1 << endl;
		cout << "Product Number: " << archive[index].id << '|';
		cout << "Price: " << archive[index].price << '|';
		cout << "Tax: " << archive[index].tax << '|';
		cout << "Description: " << archive[index].description << endl;
  	index++;
  	}
  }
