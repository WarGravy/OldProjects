#include <iostream>
#include "proj6.h"

using namespace std;


queue::queue()
{
  front = NULL;
  rear = NULL;
}


void queue::MakeEmpty()
   {
    person* tempPtr;

    while (front != NULL)
       {
        tempPtr = front;
        front = front->bfsnext;
        delete tempPtr;
       }
    rear = NULL;
   }


queue::~queue()
   {
    MakeEmpty();
   }


bool queue::IsFull() const
   {
    person* location;
    try
       {
        location = new person( (char*)"jim", 'm', 0 );
        delete location;
        return false;
       }
    catch(bad_alloc exception)
       {
        return true;
       }
   }


bool queue::IsEmpty() const
   {
    return (front == NULL);
   }


void queue::Enqueue( person newItem ) 
   {
   int index = 0;
    person* newNode = new person(newItem.name, newItem.gender, newItem.level);
    newNode -> mother = newItem.mother;
    newNode -> father = newItem.father;
    newNode -> spouse = newItem.spouse;
    newNode -> next = newItem.next;
    newNode -> numberOfChildren = newItem.numberOfChildren;
    //loop through children
    for(index =0; index < newNode->numberOfChildren; index++){
	newNode->child[index] = newItem.child[index];
    }
    newNode->bfsnext = NULL;
    if (rear == NULL)
      front->bfsnext = newNode;
    else
      rear->next = newNode;
    rear->bfsnext = newNode;
   }


void queue::Dequeue( person& newNode )
   {
    person* newItem;
    newItem = front;
    int index = 0;
    newNode.mother = newItem -> mother;
    newNode.father = newItem -> father;
    newNode.spouse = newItem -> spouse;
    newNode.next = newItem -> next;
    newNode.numberOfChildren = newItem -> numberOfChildren;
    //loop through children
    for(index =0; index < newNode.numberOfChildren; index++){
	newNode.child[index] = newItem->child[index];
    }
    front = front->bfsnext;
    newNode.bfsnext = NULL;
    if (front == NULL)
      rear = NULL;
    delete newItem;
   }
