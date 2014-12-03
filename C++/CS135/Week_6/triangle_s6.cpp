/*//////////////////////////////////////////////////////////////////////////
  
    Triangle Analysis Program

    Name: Zachary Carlson    
    Code Written:        02/27/2012
    Most Recent Update:  03/5/2012- 12:40 p.m.
    Date Due for Review: 03/6/2012

/////////////////////////////////////////////////////////////////////////*/

//  Header Files  
#include "formatted_console_io_v16.h"
#include <cmath>
#include <iostream>

using namespace std;

//Global Constants
         //global color constants
         const short TITLE_COLOR = COLOR_GREEN;
         const short DISPLAY_BKGD_COLOR = COLOR_BLUE;
         const short TEXT_DISPLAY_COLOR = COLOR_GREEN;
         const short INPUT_TEXT_COLOR = COLOR_YELLOW;
         const short OUTPUT_COLOR = COLOR_MAGENTA;
         const short ERROR_MSG_TEXT_COLOR = COLOR_RED;

         //set frame locations and sides
         const int BOX_LEFT_POS = 4;
         const int BOX_TOP_POS = 3;
         const int BOX_WIDTH = 72;
         const int BOX_HEIGHT = 18;
         const int SIDE_ONE = 1;
         const int SIDE_TWO = 2;
         const int SIDE_THREE = 3;
//Function Prototypes

/*
Name: displayInputScreen
Process: clear screen, create box, set color for display text, 
         print strings of categories for user input
Input: none
Output/to screen: sets up screen for input and output
Dependencies: formatted console I/O tools
*/
void displayInputScreen();

/*
Name: promptForSide
Process: moves to the appropriate position, prompts user for triangle side, 
returns side.

Input: int side
output: triangle side
Dependencies: formatted console I/O tools
*/

int promptForSide (int sideCode );

/*
Name: calculateEquil
Process: Takes the three sides, and determines if Equilateral(TRUE), or 
Isos/Scalene(FALSE)

Input: sideOne(INT), sideTwo(INT), sideThree(INT)
Output: true or false
Dependencies: none
*/
bool calculateEquil (int sideOne, int sideTwo, int sideThree);

/*
Name: calculateIsos
Process: Takes the three sides if calculateEquil is false, and determines if 
Isosceles(TRUE), or Scalene(FALSE) This will be used as an else in main after if
calculateEquil

Input: sideOne(INT), sideTwo(INT), sideThree(INT)
Output: true or false
Dependencies: none
*/

bool calculateIsos( int sideOne, int sideTwo, int sideThree);

/*
Name: calculateRight
Process: Takes the three sides, and determines if Right(TRUE), or 
Obtuse/Acute(FALSE) This function will also sort the sides from largest to smallest.

Input: sideOne(INT), sideTwo(INT), sideThree(INT)
Output: true or false
Dependencies: none
*/
bool calculateRight( int sideOne, int sideTwo, int sideThree);

/*
Name: calculateAcute
Process: Takes the three sides, and determines if Acute(TRUE), or 
Obtuse(FALSE) This function will also sort the sides from largest to smallest.

Input: sideOne(INT), sideTwo(INT), sideThree(INT)
Output: true or false
Dependencies: none
*/
bool calculateAcute( int sideOne, int sideTwo, int sideThree);



//Main Program

int main()
    {
    //initialize program


       //initialize variables
        int sideOneMain = 1, sideTwoMain = 2, sideThreeMain = 3;
        int xPos = 54;
        int yPos = 15;


       //start curses
         //function: startCurses
           startCurses();        
       //clear screen for outside background
         //function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       //create data input screen
         //function: displayInputScreen
         displayInputScreen();
    //input Data

       //prompt user for side 1
         //function: int propmtForSide ( int side );
         sideOneMain = promptForSide (SIDE_ONE);

       //prompt user for side 2
         //function: int propmtForSide ( int side );
         sideTwoMain = promptForSide (SIDE_TWO);
       //prompt user for side 3
         //function: int propmtForSide ( int side );
         sideThreeMain = promptForSide (SIDE_THREE);
    //Output Results
    
       // display error or display results
         // if user input sides 1, 2, and 3 are in range, display everything

           if( (1 <= sideOneMain) 
              && (sideOneMain <= 999)
              && (1<= sideTwoMain)
              && (sideTwoMain <= 999) 
              && (1 <= sideThreeMain)
              && (sideThreeMain <= 999))
              //start if {
           {
           //output triangle sides and title
             //function: printStringAt, printIntAt, printCharAt, setColor
             setColor( TITLE_COLOR, DISPLAY_BKGD_COLOR, true);
             printStringAt (xPos + 2, yPos - 6, "TRIANGLE ANALYSIS RESULTS", "CENTER");
             printStringAt (xPos + 2, yPos - 5, "=========================", "CENTER");
             setColor( OUTPUT_COLOR, DISPLAY_BKGD_COLOR, true);


             /* I tried adjusting how this(below) was outputted but I can't seem 
             to get it exactly the same as the example. When trying to use cout,
             setColor does not work at all. When I try to use the getLineAt or 
             getCharAt and then try to print the values I end up only seeing a 
             blank space, where the color seems to actually work. Because of 
             this I have changed the placement of each side(sideOneMain, 
             sideTwoMain, and sideThreeMain) so that there is room for values >99
             */
             printStringAt (xPos, yPos - 3, "Triangle sides     : ", "CENTER");
             printIntAt ( xPos + 11, yPos - 3, sideOneMain, "LEFT");
             printCharAt ( xPos + 14, yPos - 3, ',');  
             printIntAt ( xPos + 15, yPos - 3, sideTwoMain, "LEFT");
             printCharAt ( xPos + 18, yPos - 3, ','); 
             printIntAt ( xPos + 19, yPos - 3, sideThreeMain, "LEFT");        
             


          //find what type of triangle
             // use if statements to determine if Equilateral, Isos, or Scalene
             //if equilateral 
             //function: bool calculateEquil (int sideOne, int sideTwo, int sideThree);
             if( calculateEquil(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos - 1, "Triangle side type : ", "CENTER");
             printStringAt( xPos + 11, yPos - 1, "Equilateral", "LEFT");
             }
             
           //else if isos 
             // function: bool calculateIsos( int sideOne, int sideTwo, int sideThree);
             else if( calculateIsos(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos - 1, "Triangle side type : ", "CENTER");
             printStringAt( xPos + 11, yPos - 1, "Isosceles", "LEFT");
             }             
           //else scalene 
             else
             {
             printStringAt( xPos, yPos - 1, "Triangle side type : ", "CENTER");
             printStringAt( xPos + 11, yPos - 1, "Scalene", "LEFT");
             }                   
           
       //find angle type
         // use if statements to determine if Obtuse, Right, or Acute

           //if right 
             //function: bool calculateRight (int sideOne, int sideTwo, int sideThree);
             if( calculateRight(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos + 1, "Triangle angle type: ", "CENTER");
             printStringAt( xPos + 11, yPos + 1, "Right", "LEFT");
             }
           //else if Acute 
             // function: bool calculateAcute( int sideOne, int sideTwo, int sideThree);
             else if( calculateAcute(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos + 1, "Triangle angle type: ", "CENTER");
             printStringAt( xPos + 11, yPos + 1, "Acute", "LEFT");
             }             
           //else Obtuse 
             else
             {
             printStringAt( xPos, yPos + 1, "Triangle angle type: ", "CENTER");
             printStringAt( xPos + 11, yPos + 1, "Obtuse", "LEFT");
             } 

        //end if }
        }                 
       //else if sides are not in parameters display error
         else
         {
         //print error message
           //function printStringAt
           setColor( ERROR_MSG_TEXT_COLOR, DISPLAY_BKGD_COLOR, true);
           printStringAt( SCRN_MAX_X - 3 , yPos + 4, 
                         "ERROR: Input data values entered are outside specified boundaries",
                          "RIGHT");
           printStringAt( SCRN_MAX_X - 38 , yPos + 6, 
                         "       Program Stopped        ","RIGHT");
         }
 

      //move "press any key to continue . . ." aka cursor to bottom right corner
         //function: printStringAt
           setColor( TEXT_DISPLAY_COLOR, DISPLAY_BKGD_COLOR, true);
           printStringAt( SCRN_MAX_X - 35 , yPos + 6, "Press any key to continue . . .  ","LEFT");
           
    //End Program

       // end curses
          //system pause
          waitForInput(-7);
          // function: endCurses
           endCurses();
          //return to zero
           return 0;
    }

//Function Implementations

void displayInputScreen()
     {
     //initialize function/variables
     int xLoc = BOX_LEFT_POS, yLoc = BOX_TOP_POS;
     //set color and clear screen
       //function: setColor, clearScreen
        setColor( TEXT_DISPLAY_COLOR, DISPLAY_BKGD_COLOR, SET_BRIGHT );
       clearScreen( BOX_LEFT_POS, BOX_TOP_POS, 
                    BOX_LEFT_POS + BOX_WIDTH, BOX_TOP_POS + BOX_HEIGHT );
     //print title
       //printStringAt
       printStringAt(xLoc + 23, yLoc + 3, "TRIANGLE ANALYSIS PROGRAM", "LEFT");
       printStringAt(xLoc + 23, yLoc + 4, "=========================", "LEFT");
     //print triangle analysis input title
       //printStringAt
       printStringAt(xLoc + 8, yLoc + 6, "TRIANGLE ANALYSIS INPUT", "LEFT");
       printStringAt(xLoc + 8, yLoc + 7, "=======================", "LEFT");
         
     }


int promptForSide ( int sideCode )
    {
    //initialize function/variables
    int xLoc = BOX_LEFT_POS + 8;
    int yLoc = BOX_TOP_POS + 7;
    int result;

    //setColor 
    setColor( INPUT_TEXT_COLOR, DISPLAY_BKGD_COLOR, SET_BRIGHT );

    //set x location of the prompt
      //check sideCode = SIDE_ONE
      if (sideCode == SIDE_ONE)
      {
       //assign y loc
       yLoc += 2;
       result = promptForIntAt( xLoc, yLoc, "Enter triangle side 1: " );              
      }
      //check sideCode = SIDE_TWO
      else if (sideCode == SIDE_TWO)
      {
       //assign y loc
       yLoc += 4;
       result = promptForIntAt( xLoc, yLoc, "Enter triangle side 2: " );
      }
      //assume sideCode = SIDE_THREE
      else
      {
       //assign y loc
       yLoc += 6;     
       result = promptForIntAt( xLoc, yLoc, "Enter triangle side 3: " ); 
      }
      
    //stub aka return value
    return result;
    }


bool calculateEquil (int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables
       //none

     // determine if all sides are equal
     if (sideOne == sideTwo
        && sideTwo == sideThree)
       //if yes, return true
       {
       return true;
       }
       //else return false

     else
     {
     return false;
     }
     }


bool calculateIsos( int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables
       //none

     // deterimine if any two sides are equal using or
     if ( ((sideOne == sideTwo) && (sideTwo != sideThree))
         || ((sideOne == sideThree) && (sideThree != sideTwo))
         || ((sideTwo == sideThree) && (sideThree != sideOne)))
       // if yes, return true
       {
       return true;
       }
       // else return false
       else
       {
       return false;
       }
     }

bool calculateRight( int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables
     int sideC, sideA, sideB;
     int leftSide, rightSide;
     //find the hyp aka largest side
        //operation math
        if (sideOne >= sideTwo && sideOne >= sideThree)
          {
          sideC = sideOne;
          sideA = sideTwo;
          sideB = sideThree;
          }
        else if ( sideTwo >= sideOne && sideTwo >= sideThree)        
          {
          sideC = sideTwo;
          sideA = sideOne;
          sideB = sideThree;
          }
        else
          {
          sideC = sideThree;
          sideA = sideOne;
          sideB = sideTwo;
          }
       // use trig functions to determine if the largest angle is == 90 degrees
         //operation: math
         leftSide = sideC * sideC;
         rightSide = (sideA * sideA) + (sideB * sideB);
         if ( leftSide == rightSide)
         //if yes return true
         {
         return true;
         }
         //else return false
         else
         {
         return false;
         }
     }


bool calculateAcute( int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables
     int sideC, sideA, sideB;
     double angle, num, den;
     //find the hyp aka largest side
        //operation math
        if (sideOne >= sideTwo && sideOne >= sideThree)
          {
          sideC = sideOne;
          sideA = sideTwo;
          sideB = sideThree;
          }
        else if ( sideTwo >= sideOne && sideTwo >= sideThree)        
          {
          sideC = sideTwo;
          sideA = sideOne;
          sideB = sideThree;
          }
        else
          {
          sideC = sideThree;
          sideA = sideOne;
          sideB = sideTwo;
          }
       // use trig functions to determine if the largest angle is < 90 degrees
         //operation: math
         num = ((sideA * sideA)+(sideB * sideB) - (sideC * sideC));
         den = (2 * sideA * sideB);
         angle = acos(num / den);
         if ( angle < 90 )
         //if yes return true
         {
         return true;
         }
         //else return false
         else
         {
         return false;
         }
     }


