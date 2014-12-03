//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include<fstream>
#include "nodeList.h"
using namespace std;
//GLOBAL

//PROTOTYPES

//MAIN PROGRAM
int main()
  {
  //initialize variables
  ifstream fin;
  nodeList n1;
  arrayList a1(20);
  int temp;
  	//index integer used for binary search
	int index1 = 7;
	int index2 = 14;
  //open file
  fin.clear();
  fin.open("numbers.txt");
  if(fin.good()){
  cout << "OPENED FILE!" << endl;
  	//read in integers into node based list and sort integers
	fin >> temp;
	while(fin.good()){
	n1.insert(temp);
	fin >> temp;
	}
	//TEST: See what the node list looks like
   	cout << "SORTED NODE LIST: " << endl << n1 << endl;
  	//load integers from node based list to array based list
	temp = n1.removeInt();
  	while(temp != 0){
	a1.insertAfter(temp);
	temp = n1.removeInt();
	}
	cout << "SORTED ARRAY LIST: " << endl << a1 << endl;
  //do a binary search for the index1
  temp = a1.setPivot();
  temp = a1.binarySearch(index1, temp);
  //output the value to screen
  cout << "The Index for " << index1 << " is: " << temp << endl;
  //do a binary search for the index2
  temp = a1.setPivot();
  temp = a1.binarySearch(index2, temp);
  //output the value to screen
    cout << "The Index for " << index2 << " is: " << temp << endl;
    //do a binary search for 10
  temp = a1.setPivot();
  temp = a1.binarySearch(10, temp);
  //output the value to screen
    cout << "The Index for 10 is: " << temp << endl;
  }
  fin.close();
  return 0;
  }

