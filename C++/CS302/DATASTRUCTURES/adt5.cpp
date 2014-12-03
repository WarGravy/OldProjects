//Class written by 
//INCLUDE FILES
  #include <iostream>
  #include "adt5.h"
  using namespace std;
  arrayListSorted::arrayListSorted(int s){
  	list = new int[s];
	size = s;
  	cursor = -1;
  	rear = -1;
  }
  arrayListSorted::~arrayListSorted(){
	//check to make sure list isn't null
   	if(list != NULL){
	delete[] list;
   	}
  }
  bool arrayListSorted::insert(int temp){
	int i = 0;
	int j;
	//if arrayListSorted is empty 
	if( rear == -1){
		//add
		cursor = 0;
		rear = 0;
		list[rear] = temp;
		//return true
		return true;
	}
	//if arrayListSorted is full
	else if(rear == size-1){
		return false;
	}
  	//if arrayListSorted is neither empty nor full
	else{
		while(temp >= list[i]){
		i++;
		}
		//add and move everything down
		rear++;
		for( j = rear; j > i; j--){
                list[j] = list[j-1];
                }
		list[i] = temp;
		}
		cursor = i;
		//return true
		return true;
	
  }
  void arrayListSorted::clear(){
  /*this function doesn't care about overwriting data so it sets rear and cursor to -1*/
   cursor =-1;
   rear = -1;
  }
  bool arrayListSorted::search(int key){
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
  bool arrayListSorted::getint(int& temp){
	//this function should only be used after search has returned true
	temp = list[cursor];
  }
  void arrayListSorted::deleteInt(int temp){
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
  void arrayListSorted::print(){
  	int index = 0;
	if(index > rear){
 	cout << "arrayListSorted is empty or has been cleared." << endl;
	}
  	while(index <= rear){
        cout << list[index]<<endl;
  	}
  }
