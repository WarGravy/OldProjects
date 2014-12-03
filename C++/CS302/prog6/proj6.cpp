#include <iostream>
#include "proj6.h"

using namespace std;

//prototypes
bool compareCstyle(char* key, char* source);
//class person
person::person( char* newName, char newGender, int newLevel )
   {
    name = newName;
    gender = newGender;
    level = newLevel;
    numberOfChildren = 0;
    father = NULL;
    mother = NULL;
    spouse = NULL;
    next = NULL;
   }


person::~person()
   {
    delete []name;
    father = NULL;
    mother = NULL;
    spouse = NULL;
    next = NULL;
    gender = '\0';
    level = 0;
   }

char* person::getName()
   {
    return name;
   }


char person::getGender()
   {
    return gender;
   }


int person::getLevel()
   {
    return level;
   }

//class graph
graph::graph()
   {
    root = NULL; 
    cursor1 = NULL;
    cursor2 = NULL;
    //zack: I need this
    lowLevel = 0;
   }


graph::~graph()
   {
    //dynamically delete all nodes traversing through the next pointer
    person* temp = root;
    temp = root -> next;
    	if(root != NULL){
 	delete root;
    	}

    	while(temp != NULL){
	root = temp;
	temp = root -> next;
	delete root;
    	}
    lowLevel = 0;
   }


bool graph::addVert( char* newName, char newGender)
   {
    if(lowLevel == 0){
    	lowLevel = 1;
    	//create root
    	root = new person(newName, newGender, lowLevel);
    	
    	}
    else{
	person* temp = new person(newName, newGender, lowLevel);
	//search through next pointers until NULL
		//set last person's next pointer to temp
		//set temp to NULL
    	}    
    return 0;
   }


void graph::bfs( )
   {
   //no references to next should be made in this function at all

   }


bool graph::setChild( char* name, char* child )
   {
    //search for the person node using name
	//if found 
		//increment the parent's number of children
		//set child -> level = parent's -> level+1
			//if parent is male
				//set child's father
				//set child's mother through the father's spouse pointer
			//if parent is female
				//set child's mother
				//set child's father through the mother's spouse pointer
	//else the person is not found 
    	return false;
   }
bool graph::setSpouse( char* name, char* spouse)
   {
    //search for the person node using name
	//if the person's spouse node is NULL
		//set spouse for name node = to spouse node

		//set spouse's spouse pointer to name node

	//else if person's spouse node is NOT NULL aka already married 
	return false;
   }
bool compareCstyle(char* key, char* source){
    int index = 0;
	while((key[index] != '\0') && (source[index] != '\0') && 
	(key[index] == source[index])){ 
	index++;
	}
	if(index > 0 && (key[index] == source[index])){
	return true;
	}
	return false;
}
