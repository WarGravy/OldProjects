/*//////////////////////////////////////////////////////////////////////////
  
    Triangle Analysis Program

    Name: Zachary Carlson    
    Code Written:        02/27/2012
    Most Recent Update:  02/27/2012- 11:18 p.m.
    Date Due for Review: 02/28/2012

/////////////////////////////////////////////////////////////////////////*/

//  Header Files  
#include "formatted_console_io_v16.h"
#include <cmath>

using namespace std;

//Global Constants
         //global color constants

         //set frame locations and sides


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

int promptForSide ( int side );

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

       //start curses
         //function: startCurses
        
       //clear screen for outside background
         //function: clearScreen

       //create data input screen
         //function: displayInputScreen

    //input Data

       //prompt user for side 1
         //function: int propmtForSide ( int side );

       //prompt user for side 2
         //function: int propmtForSide ( int side );

       //prompt user for side 3
         //function: int propmtForSide ( int side );

    //Output Results
    
       // display error or display results
        // if user input sides 1, 2, and 3 are in range, display everything/////

              //start if {

           //output triangle sides and title
             //function: printStringAt, printIntAt, printCharAt, setColor
       
          //find what type of triangle
             // use if statements to determine if Equilateral, Isos, or Scalene
             //if equilateral 
             //function: bool calculateEquil (int sideOne, int sideTwo, int sideThree);

             
           //else if isos 
             // function: bool calculateIsos( int sideOne, int sideTwo, int sideThree);
            
           //else scalene                   
           
       //find angle type
         // use if statements to determine if Obtuse, Right, or Acute

           //if right 
             //function: bool calculateRight (int sideOne, int sideTwo, int sideThree);

           //else if Acute 
             // function: bool calculateAcute( int sideOne, int sideTwo, int sideThree);
           
           //else Obtuse 

        //end if }
                
      //else if sides are not in parameters display error//////////////////////

         //print error message
           //function printStringAt

 

      //move "press any key to continue . . ." aka cursor to bottom right corner
         //function: printStringAt

           
    //End Program
          //system pause

          // function: endCurses

          //return to zero
       return 0;
    }

//Function Implementations

void displayInputScreen()
     {
   
     }


int promptForSide ( int side )
    {

    //stub
    return 0;
    }


bool calculateEquil (int sideOne, int sideTwo, int sideThree)
     {

     //stub 
     return false;
     }


bool calculateIsos( int sideOne, int sideTwo, int sideThree)
     {
     //stub
     return false;
     }

bool calculateRight( int sideOne, int sideTwo, int sideThree)
     {
     //stub
     return false;
     }


bool calculateAcute( int sideOne, int sideTwo, int sideThree)
     {
     //stub
     return false;
     }

