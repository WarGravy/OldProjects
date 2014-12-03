//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include<fstream>
#include "adt1.h"
using namespace std;
//GLOBAL

//PROTOTYPES
void stringcpy(char*, char*);

//MAIN PROGRAM
int main()
  {
   //initialize testing variables
   bool result;
   //string names
   char name1[] = "bcustomerone";
   char name2[] = "acustomertwo";
   char name3[] = "zcustomerthree";
   char name4[] = "holidayone";
   char name5[] = "holidaytwo";
   char name6[] = "holidaythree";
   char fileName[] = "TESTschedule.txt";
   char id[] = "jeffmagic";
   //initialize items
   item jeff1;
  	stringcpy(jeff1.customerName, name1);
	stringcpy(jeff1.specialName, name4);
   item jeff2;
  	stringcpy(jeff2.customerName, name2);
	stringcpy(jeff2.specialName, name5);
   item jeff3;
  	stringcpy(jeff3.customerName, name3);
	stringcpy(jeff3.specialName, name6);
   item resultItem;
   //initialize arrays of bookings
	booking magician; 
   	booking magicians[10];
   	int sizeMagicians = 0;
   //TESTING
	//INSERT
  	cout << "TESTING insert" <<endl<<endl;
  	if(magician.insert(jeff1)){
	  cout << "inserted at front successfully" << endl;
	}
  	if(magician.insert(jeff2)){
	  cout << "inserted before front successfully" << endl;
	}
  	if(magician.insert(jeff3)){
	  cout << "inserted at end successfully" << endl;
	}
	cout << "USING STATUS TO DOUBLE CHECK" << endl << endl;
	magician.status();
	//GETITEM
   	cout << "TESTING getitem" <<endl<<endl;
	if(magician.getItem(resultItem)){
	cout << "get item works" <<endl;
	}
	//SEARCH
	cout << "TESTING search" << endl<< endl;
	if(magician.search(name2)){
	cout<< "search works!" << endl;
	}
	//DELETE ITEM
   	cout << "TESTING deleteItem" <<endl<<endl;
	if(magician.deleteItem()){
	cout << "delete item works" <<endl;
	}
	cout << "USING STATUS TO DOUBLE CHECK" << endl << endl;
	magician.status();
	//SET ID
	cout << "TESTING: setting an id" << endl;
	magician.setID(id);
	cout << magician.id << endl;
	//OUTPUT TO FILE
	cout << "TESTING output to file, check for TESTschedule.txt" << endl<<endl;
 	ofstream fout;
	fout.clear();
	fout.open(fileName);
	fout.clear();
	magician.outputToFile(fout);
	fout.close();
	//CLEAR
	cout << "TESTING clear" <<endl<<endl;
	magician.clear();
	cout << "USING STATUS TO CHECK CLEAR" << endl << endl;
	magician.status();
	//TESTING ARRAYS OF BOOKING FUNCTIONS
	cout << "TESTING ARRAYS OF BOOKING FUNCTIONS" << endl <<endl;
	cout << "TESTING add booking" <<endl<< endl;
	if(addBooking(magicians, magician, sizeMagicians)){
	cout << "Added Magician Successfully!" << endl;
	sizeMagicians++;
	}
	cout << "TESTING searchId" <<endl<< endl;
	if(searchId(id, magicians, sizeMagicians) != -1){
	cout << "SEARCHID worked" <<endl;
	}

   //end program
   return 0;
  }

//IMPLEMENTATION
void stringcpy(char* name, char* newname){
  int i;
  for (i = 0; newname[i] !='\0';i++){
  name[i] = newname[i];
  }
  name[i] = '\0'; 
}

