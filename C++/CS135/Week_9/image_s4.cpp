/*
Name: Zachary Carlson
Latest Update: 04/02/2012 - 10:04 pm

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
input: ifstream, x offset, yoffset
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
    string filename;
    ifstream fin;
    int xOff, yOff;
    int xLoc = 20;
    int yLoc = 6;
    //stub, this is to be determined after the image is printed in step 6
    int yLocEnd = 20;
    //start curses
      //function: startCurses();
      startCurses();
    //display screen
      //function: displayScreen();
      displayScreen();
  //input

    //prompt for filename
      //function: promptForStringAt
      filename = promptForStringAt( xLoc, yLoc, "Enter filename    :");
      //clear fstream and open file
      fin.clear();
      fin.open( filename.c_str() );
      //if .good
      if( fin.good() )
       //{
       {
        //prompt for x offset
          //function: promptForIntAt
          xOff = promptForIntAt( xLoc, yLoc + 2, "Enter the X offset: ");
        //prompt for y offset
          //function: promptForIntAt
          yOff = promptForIntAt( xLoc, yLoc + 4, "Enter the X offset: ");
           //output image data

             //print the character in the correct color
               //function: printImage(int xOffset, int yOffset, string fileName);
               printImage( xOff, yOff, fin);
           //close file
           fin.close();
         //}
         }
      //else
      else
       //{    
       {
        //display error message
          //function: printStringAt
          printStringAt( xLoc, yLoc + 4, "Failure to access file, process aborted", "LEFT");
            //end program
              // print "Press any key to end program . . ."
               //function: printStringAt
               printStringAt( xLoc, yLoc + 6, "Press any key to end program . . .", "LEFT");
              //wait for input
               //function: waitForInput();
               waitForInput(-7);
              //end curses
               //function: endCurses();
               endCurses();
              //return 0
              return 0;
       //}
       }
  //end program
    // print "Press any key to end program . . ."
      //function: printStringAt
      printStringAt( xLoc, yLocEnd, "Press any key to end program . . .", "LEFT");
    //wait for input
      //function: waitForInput();
      waitForInput(-7);
    //end curses
      //function: endCurses();
      endCurses();
  //return 1
  return 1;
  }

//function implementations

void displayScreen()
  {
  //initialize function and variables
    //variables

    //set color for background border

    //clear screen

  //print background border

  //print inner box
    //set color

    //clear screen

    //print title 

  }


void printImage(int xOffset, int yOffset, ifstream &theFile)
  {
  //initialie function

  //if x offset and y offsets are above the parameter, set to 0

  //read line from text file

    //loop if true
    
    //{

    //remove ASCII
    
    //remove Y

    //remove X

    // print char in correct color

    //read line from text file

    //}
  }

char removeASCII(int &value)
  {
   //initialize function and variables

   //take the last 3 numbers from value and assign them to returnChar

   //assign value to the remaining value

    //char returnChar

    //stub
    return 'X';
  }

int removeY(int &value)
  {
   //initialize function and variables

   //take the last 3 numbers from value and assign them to returnY

   //assign value to the remaining value

    //returnY

    //stub
    return 0;
  }

int removeX(int value)
  {
    //initialize variables

    //assign returnX to the correct value

    //returnX

    //stub
    return 0;
  }

bool readTextLine(string &color, int &number, ifstream &theFile)
  {
    //initialize function and variables

    //read nummber

    //assign number to number

    //read dummy char

    //read dummy string

    //read color

    //assign color to color

    //if theFile.good()
    
      //{

      //return true
      
      //}

    //else

      //{

      //return false

      //}

  //stub

  return false;
  }
