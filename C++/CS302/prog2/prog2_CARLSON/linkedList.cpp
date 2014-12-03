// HEADER FILES
#include <iostream>
#include <fstream>
#include <string.h>
#include "linkedList.h"

using namespace std;

// NODE CLASS IMPLEMENTATION

// constructor
node::node()
   {
    data1 = new char[40];
    data2 = new char[40];
    next = NULL;
   }

// copy constructor
node::node(const node &rhs)
   {
	data1 = rhs.data1;
    data2 = rhs.data2;
	next = rhs.next;
   }

// destructor
node::~node()
   {
    data1 = NULL;
    data2 = NULL;
	next = NULL;
   }


// LINKEDLIST CLASS IMPLEMENTATION

// constructor
linkedList::linkedList()
   {
	head = NULL;
	cursor = NULL;
   }

// destructor
linkedList::~linkedList()
   {
    cursor = head;
    while ( cursor != NULL )
      {
       node* temp = cursor;
       cursor = cursor->next;
       head = cursor;
       delete temp;
      }
   }

// add  name to rear of list
void linkedList::addRear( char* newData1, char* newData2 )
   {
    node* temp;

    if( head == NULL )
      {
       head = cursor = new node;
      }
   else
      {
       cursor = head;
       while( cursor->next != NULL )
         {
          cursor = cursor->next;
         }
       temp = new node;
       cursor->next = temp;
       cursor = cursor->next;
      }
    strcpy( cursor->data1, newData1 );
    strcpy( cursor->data2, newData2 );
    temp = NULL;
   }

// add name to front of list
void linkedList::addFront( char* newData1, char* newData2 )
   {

    if( head == NULL )
       {
        head = cursor = new node;
       }
    else
       {
        cursor = new node;
        cursor->next = head;
        head = cursor;
       }
    strcpy( cursor->data1, newData1 );
    strcpy( cursor->data2, newData2 );
   }

// get name at front of list and remove
void linkedList::getFront( char* newData1, char* newData2 )
   {
    node* temp;
    char empty[] = "empty";

    if( head == NULL )
       {
        strcpy( newData1, empty );
        strcpy( newData2, empty );
       }
	else{
    strcpy( newData1, head->data1 );
    strcpy( newData2, head->data2 );
    temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
	}
   }

// get name at rear of list and remove
void linkedList::getRear( char* newData1, char* newData2 )
   {
    node* previousNodePtr;
    char empty[] = "empty";

    if( head == NULL )
       {
        strcpy( newData1, empty );
        strcpy( newData2, empty );
       }
	else{
    cursor = head;
    while( cursor->next != NULL )
       {
        previousNodePtr = cursor;
        cursor = cursor->next;
       }
    strcpy( newData1, cursor->data1 );
    strcpy( newData2, cursor->data2 );
    previousNodePtr->next = cursor->next;
    delete cursor;
	}
   }

// display current list
void linkedList::displayList()
   {
    cursor = head;
    while( cursor != NULL )
      {
       cout << cursor->data1 << " " << cursor->data2 << endl;
       cursor = cursor->next;
      }
   }
