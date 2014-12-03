//Class written by Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "adt6.h"
  using namespace std;
  arrayListUNSorted::arrayListUNSorted(int s){
  	list = new int[s];
	size = s;
  	cursor = -1;
  	rear = -1;
  }
  arrayListUNSorted::~arrayListUNSorted(){
	//check to make sure list isn't null
   	if(list != NULL){
	delete[] list;
   	}
  }
  bool arrayListUNSorted::insertAtEnd(int temp){
	int i = 0;
	//if arrayListUNSorted is empty 
	if( rear == -1){
		//add
		cursor = 0;
		rear = 0;
		list[rear] = temp;
		//return true
		return true;
	}
	//if arrayListUNSorted is full
	else if(rear == size-1){
		return false;
	}
  	//if arrayListUNSorted is neither empty nor full
	else{
		//add
		rear++;
		list[rear] = temp;
		}
		//return true
		return true;
	
  }
  void arrayListUNSorted::clear(){
  /*this function doesn't care about overwriting data so it sets rear and cursor to -1*/
   cursor =-1;
   rear = -1;
  }
  bool arrayListUNSorted::search(int key){
  	//check if cursor is -1
  	if(cursor == -1){
		//return false so user knows the search failed
		return false;
	}
 	//set cursor to 0
	cursor = 0;
	/*loop through array until A) key is found or B) cursor > rear*/
	while(cursor <= rear){
		if(key == list[cursor]){
		return true;
		}
	cursor++;
	}
	//cout << "NOT FOUND IN SEARCH" << endl;
	cursor = 0;
	return false;
  }
  bool arrayListUNSorted::getint(int& temp){
	//this function should only be used after search has returned true
	temp = list[cursor];
  }
  void arrayListUNSorted::deleteInt(int temp){
    if(search(temp)){
    int temp2 = cursor;
    while(cursor < rear){
    list[cursor]=list[cursor+1];
    cursor++;
    
    }
    cursor = temp2;
    rear--;
    }
  }
  void arrayListUNSorted::print(){
  	int index = 0;
	if(index > rear){
 	cout << "arrayListUNSorted is empty or has been cleared." << endl;
	}
  	while(index <= rear){
        cout << list[index]<<endl;
  	}
  }
