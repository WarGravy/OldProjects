/*//////////////////////////////////////////////////////////////////////////
  
    Triangle Analysis Program

    Name: Zachary Carlson    
    Code Written:        02/27/2012
    Most Recent Update:  02/28/2012- 3:58 p.m.
    Date Due for Review: 02/28/2012

/////////////////////////////////////////////////////////////////////////*/

//  Header Files  
#include "formatted_console_io_v16.h"
#include <cmath>

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
         const int BOX_LEFT_POS = 8;
         const int BOX_TOP_POS = 5;
         const int BOX_WIDTH = 63;
         const int BOX_HEIGHT = 14;
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
        int xPos = 55;
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
             printStringAt (xPos + 2, yPos - 5, "TRIANGLE ANALYSIS RESULTS", "CENTER");
             printStringAt (xPos + 2, yPos - 4, "=========================", "CENTER");
             setColor( OUTPUT_COLOR, DISPLAY_BKGD_COLOR, true);
             printStringAt (xPos, yPos - 2, "Triangle sides     : ", "CENTER");
             printIntAt ( xPos + 11, yPos - 2, sideOneMain, "CENTER");
             printCharAt ( xPos + 12, yPos - 2, ',');  
             printIntAt ( xPos + 14, yPos - 2, sideTwoMain, "CENTER");
             printCharAt ( xPos + 15, yPos - 2, ','); 
             printIntAt ( xPos + 17, yPos - 2, sideThreeMain, "CENTER");        
          //find what type of triangle
             // use if statements to determine if Equilateral, Isos, or Scalene
             //if equilateral 
             //function: bool calculateEquil (int sideOne, int sideTwo, int sideThree);
             if( calculateEquil(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos, "Triangle side type : ", "CENTER");
             printStringAt( xPos + 11, yPos, "Equilateral", "LEFT");
             }
             
           //else if isos 
             // function: bool calculateIsos( int sideOne, int sideTwo, int sideThree);
             else if( calculateIsos(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos, "Triangle side type : ", "CENTER");
             printStringAt( xPos + 11, yPos, "Isosceles", "LEFT");
             }             
           //else scalene 
             else
             {
             printStringAt( xPos, yPos, "Triangle side type : ", "CENTER");
             printStringAt( xPos + 11, yPos, "Scalene", "LEFT");
             }                   
           
       //find angle type
         // use if statements to determine if Obtuse, Right, or Acute

           //if right 
             //function: bool calculateRight (int sideOne, int sideTwo, int sideThree);
             if( calculateRight(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos + 2, "Triangle angle type: ", "CENTER");
             printStringAt( xPos + 11, yPos + 2, "Right", "LEFT");
             }
           //else if Acute 
             // function: bool calculateAcute( int sideOne, int sideTwo, int sideThree);
             else if( calculateAcute(sideOneMain, sideTwoMain, sideThreeMain))
             {
             printStringAt( xPos, yPos + 2, "Triangle angle type: ", "CENTER");
             printStringAt( xPos + 11, yPos + 2, "Acute", "LEFT");
             }             
           //else Obtuse 
             else
             {
             printStringAt( xPos, yPos + 2, "Triangle angle type: ", "CENTER");
             printStringAt( xPos + 11, yPos + 2, "Obtuse", "LEFT");
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
           printStringAt( SCRN_MAX_X - 38 , yPos + 5, 
                         "       Program Stopped        ","RIGHT");
         }
 

      //move "press any key to continue . . ." aka cursor to bottom right corner
         //function: printStringAt
           printStringAt( SCRN_MAX_X - 33 , yPos + 5, " ","RIGHT");
           
    //End Program

       // end curses
          //system pause
           system ("PAUSE");
          // function: endCurses
           endCurses();
          //return to zero
           return 0;
    }

//Function Implementations

void displayInputScreen()
     {
     //initialize function/variables
     
     //set color and clear screen
       //function: setColor, clearScreen

     //print title
       //printStringAt
     
     //print triangle analysis input title
       //printStringAt
     
     //print yellow input display( leave the actual integers to promptForSide
       //printStringAt, setColor   
     }


int promptForSide ( int sideCode )
    {
    //initialize function/variables

    //set x location of the prompt
      //check sideCode = SIDE_ONE
              //assign y loc
      
      //check sideCode = SIDE_TWO
              //assign y loc

      //assume sideCode = SIDE_THREE
               //assign y loc
      
      //setColor 

      //promptForIntAt
      
    //stub aka return value
    return 0;
    }


bool calculateEquil (int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables

     // determine if all sides are equal

       //if yes, return true

       //else return false

     //stub
     return false;
     }


bool calculateIsos( int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables

     // deterimine if any two sides are equal using or

       // if yes, return true

       // else return false

     //stub
     return false;
     }

bool calculateRight( int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables

     //find the hyp aka largest side
        //operation math

       // use trig functions to determine if the largest angle is == 90 degrees
         //operation: math

         //if yes return true

         //else return false

     //stub
     return false;
     }


bool calculateAcute( int sideOne, int sideTwo, int sideThree)
     {
     //initialize function/variables

     //find the hyp aka largest side
        //operation math

       // use trig functions to determine if the largest angle is < 90 degrees
         //operation: math

         //if yes return true

         //else return false

     //stub
     return false;
     }

