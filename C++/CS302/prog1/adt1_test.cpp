//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include<fstream>
#include "adt1.h"
using namespace std;


//TEST DRIVER
int main()
  {
   //declare test variables
   item object1, object2, object3, object4;
   bool response = false;
   inventory newInventory;
   int i;
   int input = 99999999;
	//set values for test struct items
		//OBJECT1
		object1.id = 1111;
		for(i=0; i < 11; i++){
		  object1.description[i] = 'A';
		}
		object1.description[i] = '\0';
		object1.tax = 'N';
		object1.price = 10.12;
		//OBJECT2
		object2.id = 2222;
		for(i=0; i < 11; i++){
		  object2.description[i] = 'B';
		}
		object2.description[i] = '\0';
		object2.tax = 'T';
		object2.price = 11.32;
		//OBJECT3
		object3.id = 3333;
		for(i=0; i < 11; i++){
		  object3.description[i] = 'C';
		}
		object3.description[i] = '\0';
		object3.tax = 'N';
		object3.price = 12.99;
	//TESTING FUNCTION insertAtEnd
	cout << "TESTING FUNCTION insertAtEnd"<< endl << endl;
  	response = newInventory.insertAtEnd(object1);
	cout << "boolean response to adding object1 to inventory: " << response << endl;
  	response = newInventory.insertAtEnd(object2);
	cout << "boolean response to adding object2 to inventory: " << response << endl;
  	response = newInventory.insertAtEnd(object3);
	cout << "boolean response to adding object3 to inventory: " << response << endl;
	if(response){
	cout << "function works!" << endl;
	}
	 //TESTING FUNCTION search(int);
	cout << "TESTING FUNCTION Search (please input the product number 1111)"<<endl<<endl;
	cin >> input;
	response = newInventory.search(input);
	if(response == true){
		response = newInventory.getItem(object4);
		if(response == true){
		cout << "TESTING FUNCTION getItem and printed that item to screen" <<endl<< endl;
		cout << "Product Number: " << object4.id << '|';
		cout << "Price: " << object4.price << '|';
		cout << "Tax: " << object4.tax << '|';
		cout << "Description: " << object4.description << endl;
		}
	}
	//TESTING FUNCTION PRINT
	cout << "TESTING FUNCTION print"<< endl << endl;
	newInventory.print();
	//TESTING FUNCTION CLEAR
	cout << "TESTING FUNCTION Clear and Print when cleared" << endl<< endl; 
  	newInventory.clear();
	newInventory.print();

   return 0;
  }


