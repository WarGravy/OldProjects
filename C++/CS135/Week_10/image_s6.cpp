/*
Name: Zachary Carlson
Latest Update: 04/09/2012 - 9:40 pm

Program Name: Design Assignment 3/ Program Assignment 6: image
*/

//include files
#include <iostream>
#include <fstream>
#include "formatted_console_io_v16.h"
using namespace std;

//global constants

  const int INNER_BACKGROUND = COLOR_BLUE;
  const int INNER_X_LEFT = 12;
  const int INNER_X_RIGHT = SCRN_MAX_X - 13;
  const int INNER_Y_TOP = 3;
  const int INNER_Y_BOTTOM = SCRN_MAX_Y -4;
  const int TITLE_X = 30;
  const int TITLE_Y = 4;

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
bool readTextLine( int &color, int &number, ifstream &theFileTwo);

//main program
int main()
  {
  //initialize variables and main function
    //declare variables
    string filename;
    ifstream fin;
    int xOff, yOff;
    int xLoc = 16;
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
    //none

    //set color for background border      
      //function: setColor
      setColor(COLOR_BLACK, COLOR_WHITE, false);

    //clear screen
      //function: clearScreen
      clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y);

  //print inner box
    //set color
      //function: setColor
      setColor(COLOR_WHITE, COLOR_BLUE, true);
    //clear screen
      //function: clearScreen
      clearScreen( INNER_X_LEFT, INNER_Y_TOP, INNER_X_RIGHT, INNER_Y_BOTTOM);
    //print title 
      //printStringAt
      printStringAt( TITLE_X, TITLE_Y, "Image Data Information", "LEFT");
  }


void printImage(int xOffset, int yOffset, ifstream &theFile)
  {
  //initialie function
  bool lineRead;
  int color, number, yLineLoc, xLineLoc;
  char ascII;
  //if x offset and y offsets are above the parameter, set to 0
  if (xOffset < 0 || xOffset >=27)
    {
    xOffset = 0;
    }
  if (yOffset < 0 || yOffset >= 17)
    {
    yOffset = 0;
    }
/*
Added in step 6 for neatness to clear the screen for room to print the image.

*/

//print inner box
    //set color
      //function: setColor
      setColor(COLOR_WHITE, COLOR_BLUE, true);
    //clear screen
      //function: clearScreen
      clearScreen( INNER_X_LEFT, INNER_Y_TOP, INNER_X_RIGHT, INNER_Y_BOTTOM);
    //print title 
      //printStringAt
      printStringAt( TITLE_X, TITLE_Y, "Image Data Information", "LEFT");

/*
END UP ADDITION
*/
  //read line from text file
    //function: bool readTextLine(int &color, int &number, ifstream &theFile);
    lineRead = readTextLine( color, number, theFile); 
    //loop if true
    while( lineRead == true)
    //{
    {
    //remove ASCII
      //function:char removeASCII(int &value);
      ascII = removeASCII(number);
    //remove Y
      //function:int removeY(int &value);
      yLineLoc = removeY(number);
    //remove X
      //function:int removeX(int &value);
      xLineLoc = removeX(number);
    // print char in correct color
      //function: setColor and printCharAt
      setColor( color, INNER_BACKGROUND, true);
      printCharAt(xLineLoc + xOffset + INNER_X_LEFT, yLineLoc + yOffset + INNER_Y_TOP, ascII);
    //read line from text file
      //function: bool readTextLine(string &color, int &number, ifstream &theFile);
      lineRead = readTextLine( color, number, theFile); 
    //}
    }
  }

char removeASCII(int &value)
  {
   //initialize function and variables
   char returnedChar = 'X';
   int lastThreeDigits;
   //take the last 3 numbers from value and assign them to returnChar
   lastThreeDigits = value % 1000;
   //assign value to the remaining value
   value /= 1000;
    //char returnChar
    returnedChar = lastThreeDigits;
    //stub
    return returnedChar;
  }

int removeY(int &value)
  {
   //initialize function and variables
   int returnedY;

   //take the last 3 numbers from value and assign them to returnY
   returnedY = value % 1000;
   //assign value to the remaining value
   value /= 1000;
    //returnY
    return returnedY;
  }

int removeX(int value)
  {
    //initialize variables
      int returnedX;
    //assign returnX to the correct value
    returnedX = value;
    //returnX
    return returnedX;
  }

bool readTextLine(int &color, int &number, ifstream &theFileTwo)
  {
    //initialize function and variables
    char dummy;
    char colorChar;
    string dummyStr;
    string colorStr;
    //read nummber
    theFileTwo >> number;
    //read dummy char
    theFileTwo >> dummy;
    //read dummy string
    theFileTwo >> dummyStr;
    //read color
    theFileTwo >> colorChar;
    theFileTwo >> colorStr;

    //if theFile.good()
    if( theFileTwo.good() )
      //{
      {

    //assign color to color
    switch(colorChar)
    {
      case 'M':
      color = COLOR_MAGENTA;
      break;
      
      case 'C':
      color = COLOR_CYAN;
      break;

      case 'Y':
      color = COLOR_YELLOW;
      break;

      case 'B':
      color = COLOR_BLUE;
      break;

      case 'R':
      color = COLOR_RED;
      break;

      case 'W':
      color = COLOR_WHITE;
      break;

      default:
      color = COLOR_GREEN;
     
    }
      //return true
      return true;
      //}
      }
    //else
    else
      //{
      {
      //return false
      return false;
      //}
      }
 
  }
