//Class written by Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include <stdint.h>
  #include "adt6.h"
  using namespace std;
  arrayListUNSorted::arrayListUNSorted(int s){
  	list = new int64_t[s];
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
  bool arrayListUNSorted::insert(int64_t temp, int& swaps, int& comparisons){
	
	//if arrayListUNSorted is full
	if(rear == size-1){
		return false;
	}
  	//if arrayListUNSorted is neither empty nor full
        
		//cout << rear << "AND" << size << endl;
		//add
		rear++;
                cursor = rear;
		list[rear] = temp;
		
		//return true
		return true;
	
  }
  void arrayListUNSorted::clear(){
  /*this function doesn't care about overwriting data so it sets rear and cursor to -1*/
   cursor =-1;
   rear = -1;
  }
  bool arrayListUNSorted::search(int64_t key, int& swaps, int& comparisons){
  	//check if cursor is -1
  	if(cursor == -1){
		//return false so user knows the search failed
		return false;
	}
 	//set cursor to 0
	cursor = 0;
	/*loop through array until A) key is found or B) cursor > rear*/
	while(cursor <= rear){
                comparisons++;
		if(key == list[cursor]){
		return true;
		}
	cursor++;
	}
	//cout << "NOT FOUND IN SEARCH" << endl;
	cursor = 0;
	return false;
  }
  bool arrayListUNSorted::getint(int64_t& temp){
	//this function should only be used after search has returned true
	temp = list[cursor];
  }
  void arrayListUNSorted::deleteInt(int64_t temp, int& swaps, int& comparisons){
    if(search(temp, swaps, comparisons)){
    int temp2 = cursor;
    	while(cursor < rear){
    	list[cursor]=list[cursor+1];
        swaps++;
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
