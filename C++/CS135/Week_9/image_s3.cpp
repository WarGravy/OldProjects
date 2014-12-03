/*
Name: Zachary Carlson
Latest Update: 04/02/2012 - 08:55 pm

Program Name: Design Assignment 3/ Program Assignment 6: image
*/

//include files
#include <iostream>
#include <fstream>
#include "formatted_console_io_v16.h"
using namespace std;

//global constants

  //none

//function prototypes

/*
name: displayScreen
process: clears screen after setting color and printing title
input: none
output/returned: none
dependencies: setColor & clearScreen
*/
void displayScreen();

/*
name: printImage
process: reads a line from the text file using readTextLine to get the color and
         the number, removes the x value, removes y value, removes the character
         and prints the character in the appropriate color and correct x and y 
         location determined by what it removed and the offsets.
input: file name, x offset, yoffset
output/returned: none
dependencies: removeX, removeY, removeASCII, readTextLine
*/
void printImage(int xOffset, int yOffset, ifstream &theFile);

/*
name: removeASCII
process: removes the last three digits of value and converts it to a char, returning
         the char and leaving the remaining value.
input: value
output/returned: the character and the remaining number
dependencies: none
*/
char removeASCII(int &value);

/*
name: removeY
process: removes the last three digits of value returning the int and leaving 
         the remaining value.
input: value
output/returned: the y location and the remaining number
dependencies: none
*/
int removeY(int &value);

/*
name: removeX
process: takes in a number, and determines x, returning x
input: value
output/returned: the x location
dependencies: none
*/
int removeX(int value);

/*
name: readTextLine
process: reads a line of the file, returning the color and number from the line
output/returned: color, and number
dependencies: none
*/
bool readTextLine(ifstream &theFile, string &color, int &number);

//main program
int main()
  {
  //initialize variables and main function
    //declare variables

    //start curses
      //function: startCurses();

    //display screen
      //function: displayScreen();

  //input

    //prompt for filename
      //function: promptForStringAt
      
      //clear fstream and open file
      
      //if .good
      
       //{
       
        //prompt for x offset
          //function: promptForIntAt
          
        //prompt for y offset
          //function: promptForIntAt
          
           //output image data

             //print the character in the correct color
               //function: printImage(int xOffset, int yOffset, string fileName);
               
           //close file
           
         //}
         
      //else
      
       //{    
       
        //display error message
          //function: printStringAt
         
            //end program
              // print "Press any key to end program . . ."
               //function: printStringAt
               
              //wait for input
               //function: waitForInput();
               
              //end curses
               //function: endCurses();
              
              //return 0
              
       //}
      
  //end program
    // print "Press any key to end program . . ."
      //function: printStringAt
    
    //wait for input
      //function: waitForInput();
      
    //end curses
      //function: endCurses();
      
  //stub
  return 0;
  }

//function implementations

void displayScreen()
  {

  }


void printImage(int xOffset, int yOffset, ifstream &theFile)
  {

  }

char removeASCII(int &value)
  {

    //stub
    return 'X';
  }

int removeY(int &value)
  {

    //stub
    return 0;
  }

int removeX(int value)
  {

    //stub
    return 0;
  }

bool readTextLine(ifstream &theFile, string &color, int &number)
  {

  //stub
  return false;

  }
