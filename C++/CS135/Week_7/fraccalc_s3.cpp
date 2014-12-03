/*//////////////////////////////////////////////////////////////////////////
  
    Fraction Calculator

    Name: Zachary Carlson    
    Code Written:        03/7/2012
    Most Recent Update:  03/12/2012- 7:32 p.m.
    Date Due for Review: 03/12/2012

/////////////////////////////////////////////////////////////////////////*/

//Include Files
#include <cmath>
#include "digits_v01.h"
using namespace std;

//Global Constants
  //none

//Function Prototypes

/*
name:displayInputScreen
process: clear screen, create title, create outline boxes, set color for 
display text
input: none
output/to screen: the screen
output/returned: none
dependencies:clearScreen, setColor, printStringAt
*/
void displayInputScreen();

/*
name:promptAndOutputInt
process: prompts for int 0 < int < 9
         (depending on numerator or denominator), moves to appropriate x and y 
         location to prints digit determined by int locInt, returns int value.
         locInt = 1 for numOne location
         locInt = 2 for denOne location
         locInt = 3 for numTwo location
         locInt = 4 for denTwo location
input: 0 < int < 9
output/to screen: prompt and the int result as a digit
output/returned: int value
dependencies: printDigit, promptForCharAt, charToInt
*/
int promptAndOutputInt( int locInt);

/*
name:promptAndOutputChar
process: prompts for char -, +, /, *, prints it as a digit, return char
input: operation sign
output/to screen: the operation sign
output/returned: char operation
dependencies: printDigit, promptForCharAt, charToInt
*/
char promptAndOutputChar();

/*
name:calcAnsw
process: takes in 4 int, 1 char and calculates the answer. operation determined
         by the char. calculates the numerator and denominator seperately, uses
         printAnsw to output the fraction.
input: first numerator
input: first denominator
input: second numerator
input: second denominator
input: operation
output/to screen: none, this is done through printAnsw
output/returned: none
dependencies: printAnsw
*/
void calcAnsw (int firstNum, int firstDen, int secondNum, int secondDen, char operation);

/*
name:checkForNegAnsw
process: checks a value to see if a number to find if it is negative, returns 
         true or false.
input: integer
output/to screen: none
output/returned: true if it is negative, false if positive 
dependencies: none
*/ 
bool checkForNegAnsw ( int value);

/*
name:checkForTwoDigits
process: checks a value to see if a number is between 9 and 100
input: integer
output/to screen: none
output/returned: true if 9<integer<100, false if else
dependencies: none
*/ 
bool checkForTwoDigits ( int value);

/*
name:checkForThreeDigits
process: checks a value to see if a number is between 99 and 1000
input: integer
output/to screen: none
output/returned: true if 99<integer<1000, false if else
dependencies: none
*/ 
bool checkForThreeDigits ( int value);

/*
name:printAnsw
process: checks if the fraction is negative, checks for the number of digits, 
         prints the solution
input: numerator of the solution
input: denominator of the solution
output/to screen: displays the final solution
output/returned: none
dependencies: printDigit, checkForNegAnsw, checkForTwoDigits, checkForThreeDigits
*/ 
void printAnsw ( int finalNum, int finalDen);


/*
Name: findFirstDigit
process: uses math to find the integer in the hundreds place
input: an integer between 99 and 1000(not included)
output/returned value: returns the single integer in the hundreds place
dependencies: none
*/
int findFirstDigit (int value);
/*
Name: findSecondDigit
process: uses math to find the integer in the tens place
input: an integer between 10 and 999 included
output/returned value: returns the single integer in the tens place
dependencies: none
*/
int findSecondDigit (int value);
/*
Name: findThirdDigit
process: uses math to find the integer in the ones place
input: an integer between 10 and 999 included
output/returned value: returns the single integer in the ones place
dependencies: none
*/
int findThirdDigit ( int value);


//Main Program
int main()
  {
   //initialize program///////////////////////////////////////////////////
     //initialize local variables
   
     //start curses
       //function: startCurses()

     //clear screen 
       //function: clearScreen( int uprLeftX, int uprLeftY, int lwrRightX, int lwrRightY )

     //displayInputScreen(title included)
       //function: displayInputScreen

   ////////input and output///////////////////////////////////////////////
   //Prompt for numOne
     //function: promptAndOutputInt (numOne)

     //if (parameters for numOne)

     //{ Starting bracket for if (numOne)

     //Prompt for denTwo
       //function: promptAndOutputInt (denOne)

        //if(parameters for denTwo)

        //{ starting bracket for if (denTwo)

        //Prompt for operator
          //function: promptAndOutputChar (denOne)

          //if(parameters for operator)

          //{ starting bracket for if (oper)

          //Prompt for numTwo
            //function: promptAndOutputInt (numTwo)

             //if (parameters for second numerator)

             //{ starting bracket for if (numTwo)

             //Prompt for denTwo
               //function: promptAndOutputInt (denTwo)

               //if(parameters for second denominator)

               //{ starting bracket for if (denTwo)

                 /* Calculate answer
                 the function will output the answer as well
                 function: calcAnsw( int one, int two, char oper, int three, int four)
                 numOne, denTwo, oper, numTwo, denTwo
                 */

               //} ending bracket for if(denTwo)

               //else(ending else for second denominator)

               //{ else bracket start denTwo

               //submit error message

               //} else bracket end denTwo      
  
             //} end bracket for if (num Two)

             //else(ending else for second numerator)

             //{ else bracket start numTwo

             //submit error message

             //} else bracket end numTwo

          //} ending bracket for if (oper)

          //else(ending else for parameter operator)

          //{ else bracket start oper

          //submit error message

          //} else bracket end oper

        //} ending bracket for if (denOne)

        //else(ending else for parameter denOne)

        //{ else bracket start denOne

        //submit error message

        //} else bracket end denOne

     //} ending bracket for if (numOne)

     //else(ending else for parameter numOne)

     //{ else bracket start numOne

     //submit error message

     //} else bracket end numOne

 
   //end program//////////////////////////////////////////////////////////

     // print "Press any key to end program . . ."
       //function: printStringAt( int xPos, int yPos, const string &outString, 
                //const string &justify )

     //wait for input(-7)
       //function: waitForInput( int timedWait )

     //end curses
       //function: endCurses()

     //stub
     return 0;
  }
//Function Implementations

void displayInputScreen()
{


}

int promptAndOutputInt( int locInt)
{

  //stub
  return 0;
}

char promptAndOutputChar()
{
   //stub
   return '-';
}

void calcAnsw (int firstNum, int firstDen, int secondNum, int secondDen, char operation)
{

}

bool checkForNegAnsw ( int value)
{

   //stub
   return false;
}

bool checkForTwoDigits ( int value)
{

   //stub
   return false;
}

bool checkForThreeDigits ( int value)
{

   //stub
   return false;
}

void printAnsw ( int finalNum, int finalDen)
{

}
int findFirstDigit (int value)
{
  //stub
  return 0;
}

int findSecondDigit (int value)
{
  //stub
  return 0;
}

int findThirdDigit ( int value)
{
  //stub
  return 0;
}
