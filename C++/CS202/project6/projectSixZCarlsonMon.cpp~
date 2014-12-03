//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include<fstream>
#include "cardMON.h"
using namespace std;
//GLOBAL

//PROTOTYPES

/*readIn: (reads in cards from file)
*/

/*print: (prints the entire deck of cards - this is not the card print member function)
*/

/*swap: swaps two cards in the deck
*/

/*compareStr: compares two strings
*/
bool compareStr(char* firPtr, char* secPtr);
/*strlen: finds the string length*/
int strlen(char*);
/*copyStr: copys from pointer 2 to destination*/
void copystr(char*, char*);

//MAIN PROGRAM
int main()
  {
   //initialize variables

   //read in

   //print

   //swap (prompt user for two cards to swap)

   //print

  return 0;
  }
//IMPLEMENTATION

bool compareStr(char* firPtr, char* secPtr)
  {
  //initialize function
  int index = 0;
  char null = '\0';
  bool result = false;
  bool stop = false;
  //loop through the pointers
    while(stop != true)
      {
       //check if they are both nulls
       if(*firPtr == null && *secPtr == null)
	 {
	   result = true;
	   stop = true;
	 }
      //else check if the characters are the same and not the null char
      else if( *firPtr == *secPtr && *firPtr != null)
         {
           index++;
	   firPtr += index;
	   secPtr += index;
	 }

       //last else, they aren't the same
       else
	 {
	   stop = true;
	  }
	}
  //end program
  return result;
  }
int strlen(char* c)
  {
  int ctr = 0;
  
  while(*c != '\0')
    {
    c++;
    ctr++;
    }
  return ctr;
  }
void copystr(char* dest, char* cpy)
  {
  while(*cpy != '\0')
   {
   *dest = *cpy;
    dest++;
    cpy++;
   }
  }
