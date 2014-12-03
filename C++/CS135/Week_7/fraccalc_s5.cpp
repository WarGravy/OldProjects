/*//////////////////////////////////////////////////////////////////////////
  
    Fraction Calculator

    Name: Zachary Carlson    
    Code Written:        03/7/2012
    Most Recent Update:  03/12/2012-7:37 p.m.
    Date Due for Review: 03/12/2012

/////////////////////////////////////////////////////////////////////////*/

//Include Files
#include <cmath>
#include "digits_v01.h"
using namespace std;

//Global Constants
   
  //Global colors
   const short TITLE_COLOR = COLOR_WHITE;
   const short BACKGROUND_COLOR = COLOR_BLUE;
   const short BORDER_COLOR = COLOR_RED;
   const short INPUT_TEXT_COLOR = COLOR_WHITE;
   const short OUTPUT_COLOR = COLOR_GREEN;
   const short ERROR_COLOR = COLOR_YELLOW;
   const short OPERATION_COLOR = COLOR_CYAN;
   const short FRACTION_COLOR = COLOR_MAGENTA;

  //X and Y locations
  const int MAX_X = 79;
  const int MAX_Y = 24;
  const int MIN_X = 0;
  const int MIN_Y = 0;

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
process: prompts for char 0 < char < 9
         (depending on numerator or denominator), moves to appropriate x and y 
         location to prints digit determined by int locInt, returns int value.
         locInt = 1 for numOne location
         locInt = 2 for denOne location
         locInt = 3 for numTwo location
         locInt = 4 for denTwo location
         it then reports error  if needed
input: 0 < int < 9
output/to screen: prompt and the int result as a digit
output/returned: int value
dependencies: printDigit, promptForCharAt, charToInt
*/
int promptAndOutputInt( int locInt);

/*
name:promptAndOutputChar
process: prompts for char -, +, /, *, prints it as a digit, return char, it then
         reports error  if needed
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
     int numOne, denOne, numTwo, denTwo; 
     char oper = '+';
   
     //start curses
       //function: startCurses()
       startCurses();

     //clear screen 
       //function: clearScreen( int uprLeftX, int uprLeftY, int lwrRightX, int lwrRightY )
       clearScreen( MIN_X, MIN_Y, MAX_X, MAX_Y );

     //displayInputScreen(title included)
       //function: displayInputScreen
       displayInputScreen();

   ////////input and output///////////////////////////////////////////////
   //Prompt for numOne
     //function: promptAndOutputInt (numOne)
     numOne = promptAndOutputInt(1);

     //if (parameters for numOne)
     if (numOne <=9 && numOne >= 0)

     //{ Starting bracket for if (numOne)
     {

     //Prompt for denTwo
       //function: promptAndOutputInt (denOne)
       denTwo = promptAndOutputInt(2);

        //if(parameters for denTwo)
        if (denTwo <= 9 && denTwo > 0)

        //{ starting bracket for if (denTwo)
        {

        //Prompt for operator
          //function: promptAndOutputChar (oper)
          oper = promptAndOutputChar ();

          //if(parameters for operator)
          if( oper == '+' || oper == '-' || oper == '/' || oper == '*')

          //{ starting bracket for if (oper)
          {

          //Prompt for numTwo
            //function: promptAndOutputInt (numTwo)
            numTwo = promptAndOutputInt (3);

             //if (parameters for second numerator)
             if ( numTwo >= 0 && numTwo <= 9 )

             //{ starting bracket for if (numTwo)
             {

             //Prompt for denTwo
               //function: promptAndOutputInt (denTwo)
               denTwo = promptAndOutputInt (4);

               //if(parameters for second denominator)
               if ( denTwo > 0 && denTwo <= 9)

               //{ starting bracket for if (denTwo)
               {

                 /* Calculate answer
                 the function will output the answer as well
                 function: calcAnsw( int one, int two, char oper, int three, int four)
                 numOne, denTwo, oper, numTwo, denTwo
                 */
                 calcAnsw( numOne, denOne, numTwo, denTwo, oper);

               //} ending bracket for if(denTwo)
               }

               //else(ending else for second denominator)
               else

               //{ else bracket start denTwo
               {

               /*submit error message(this was removed in step 5 because 
                 promptAndOutput now outputs the error message if the value is not
                 in the correct parameters*/
           
               //} else bracket end denTwo      
               }

             //} end bracket for if (num Two)
             }

             //else(ending else for second numerator)
             else

             //{ else bracket start numTwo
             {

             /*submit error message(this was removed in step 5 because 
             promptAndOutput now outputs the error message if the value is not
             in the correct parameters*/
           
             //} else bracket end numTwo
             }

          //} ending bracket for if (oper)
          }

          //else(ending else for parameter operator)
          else
          //{ else bracket start oper
          {

          /*submit error message(this was removed in step 5 because promptAndOutput now 
          outputs the error message if the value is not in the correct parameters*/
        
          //} else bracket end oper
          }

        //} ending bracket for if (denOne)
        }

        //else(ending else for parameter denOne)
        else

        //{ else bracket start denOne
        {

        /*submit error message(this was removed in step 5 because promptAndOutput now 
        outputs the error message if the value is not in the correct parameters*/
      
        //} else bracket end denOne
        }

     //} ending bracket for if (numOne)
     }

     //else(ending else for parameter numOne)
     else

     //{ else bracket start numOne
     {
     
     /*submit error message(this was removed in step 5 because promptAndOutput now 
     outputs the error message if the value is not in the correct parameters*/
   
     //} else bracket end numOne
     }

 
   //end program//////////////////////////////////////////////////////////

     // print "Press any key to end program . . ."
       //function: printStringAt( int xPos, int yPos, const string &outString, 
                //const string &justify )
       setColor( INPUT_TEXT_COLOR, BACKGROUND_COLOR, true );
       printStringAt (MAX_X - 1, MAX_Y, "Press any key to end program . . . ", "RIGHT");

     //wait for input(-7)
       //function: waitForInput( int timedWait )
       waitForInput(-7);

     //end curses
       //function: endCurses()
       endCurses();

     //stub
     return 0;
  }
//Function Implementations

void displayInputScreen()
{
     //initialize function/variables

     //set color and clear screen
       //function: setColor, clearScreen

     //print title
       //function: printStringAt
     
     //print title underline
       //function: printStringAt

     //set color for borders
       //function: setcolor

         //print horizontal borders
           //function: printStringAt
     
         //print vertical borders
           //function: printVerticalString
}

int promptAndOutputInt( int locInt)
{
  //initialize function/variables
      //variables(note to self, make sure to assign x and y loc for prompt here
      
      //setColor for prompt
        //function: printDigit
        
      //promptForCharAt
        //function: promptForCharAt

      //convert char to int
        //function:charToInt

  //assign x and y location for output & print digit (switch (locInt))

  //{

      //case locInt = 1:
        //if int returned from prompt is not less than 10 and greater than or equal to 0

        //{

          /*submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
     printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
          */

        //}
        
        //else
        
        //{

        //assign second x and y location
        
        // set color for output 
          //function: setColor

        //printDigit
          //function: printDigit
          
        //}
  
      //break
  
      //case locInt = 2:
          
        //if int = 0

           //{

           //submit error message for dividing by zero
             //function: printStringAt & setColor

           //}

        //else if integer returned from prompt is not greater than 0, less than 10
          //{

          /*submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
     printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
          */

          //}

        //else 
        
        //{
        
        //assign second x and y location
        
        // set color for output 
          //function: setColor

        //printDigit
          //function: printDigit
  
        //}
  
      //break
  
      //case locInt = 3:

        //if int returned from prompt is not less than 10 and greater than or equal to 0

        //{

          /*submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
     printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
          */

        //}
        
        //else
        
        //{

        //assign second x and y location
        
        // set color for output 
          //function: setColor

        //printDigit
          //function: printDigit
          
        //}
  
      //break
      
      //case locInt = 4:

        //if int = 0

           //{

           //submit error message for dividing by zero
             //function: printStringAt & setColor

           //}

        //else if integer returned from prompt is not greater than 0, less than 10
          //{

          /*submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
     printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
          */

          //}

        //else 
        
        //{
        
        //assign second x and y location
        
        // set color for output 
          //function: setColor

        //printDigit
          //function: printDigit
  
        //}
  
      //break

      //default:

        //submit error message
          //function setColor, printStringAt

    //}

  //stub
  return 0;
}

char promptAndOutputChar()
{
   //initialize function/variables
     //variables
     
     //setColor for prompt
     
   //promptForCharAt

   //switch (operation)

   //{

     //case operation = '+':
     
       /*convert char to int(make sure to use seperate variables to prevent 
         errors for returning a char)
         function: charToInt*/
     
       //print digit

       //return char
     
     //break

     //case operation = '*':
     
       /*convert char to int(make sure to use seperate variables to prevent 
         errors for returning a char)
         function: charToInt*/
     
       //print digit

       //return char
     
     //break

     //case operation = '-':
     
       /*convert char to int(make sure to use seperate variables to prevent 
         errors for returning a char)
         function: charToInt*/
     
       //print digit

       //return char
     
     //break

     //case operation = '/':
     
       /*convert char to int(make sure to use seperate variables to prevent 
         errors for returning a char)
         function: charToInt*/
     
       //print digit

       //return char
     
     //break

     //default:

          /*submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
     printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
          */

     //}

   //stub
   return '-';
}

void calcAnsw (int firstNum, int firstDen, int secondNum, int secondDen, char operation)
{

  //initialize function/variables
    //variables = resultNum & resultDen
  
  //calculate the num and den using switch(operation)

  //{

    //case '+':
      //use firstNum, firstDen, secondNum, secondDen to calculate

      //assign resultNum & resultDen
    
    //break

    //case '-':
      //use firstNum, firstDen, secondNum, secondDen to calculate

      //assign resultNum & resultDen

    //break

    //case '/':
      //use firstNum, firstDen, secondNum, secondDen to calculate

      //assign resultNum & resultDen

    //break

    //case '*':
      //use firstNum, firstDen, secondNum, secondDen to calculate

      //assign resultNum & resultDen

    //break

    //default:
      // output error message for wrong parameters in the calcAnsw function

    //}

  //use printAnsw function to determine how to output it, and print it at once
    //function: printAnsw

}

bool checkForNegAnsw ( int value)
{
   //if value is less than zero
 
      //return true

   //else

      //return false
      return false;
}

bool checkForTwoDigits ( int value)
{
   //if value is less than 100 and greater than 9
 
      //return true

   //else

      //return false
      return false;
}

bool checkForThreeDigits ( int value)
{
   //if value is less than 1000 and greater than 99
 
      //return true

   //else

      //return false
      return false;
}

void printAnsw ( int finalNum, int finalDen)
{

  // initialize function/variables

  // set color for output

  /* if (numerator is positive and denominator is positive) or ( numerator and 
  denominator are both negative)*/

    //{
      //print numerator
        //if numerator is two digits

          //{
            
             //print first digit
             //function: printDigit & findFirstDigit

             //print second digit
             //function: printDigit & findSecondDigit

          //}

        //else if numerator is three digits

          //{

            //print first digit
             //function: printDigit & findFirstDigit

            //print second digit
             //function: printDigit & findSecondDigit

            //print third digit
             //function: printDigit & findThirdDigit

          //}

        //else (numerator is one digit)

          //{
            
            //print digit
             //function: printDigit

          //}
          
      //print denominator
        //if denominator is two digits

          //{
            
             //print first digit
             //function: printDigit & findFirstDigit

             //print second digit
             //function: printDigit & findSecondDigit

          //}

        //else if denominator is three digits

          //{

            //print first digit
             //function: printDigit & findFirstDigit

            //print second digit
             //function: printDigit & findSecondDigit

            //print third digit
             //function: printDigit & findThirdDigit

          //}

        //else (denominator is one digit)

          //{
            
            //print digit
             //function: printDigit

          //}

    //}

  /* else if(numerator is negative and denominator is positive) or (numerator is
  positive and denominator is negative) */

    //{

      //print negative sign
      //set color for negative sign
      //function: setColor

        //if numerator is three digits
        
          //{

            //print the negative sign by the denominator
              //convert char to int
              //function:charToInt

              //print operation sign
              //function printDigit

            //set color for numerator and denominator
            //function: setColor

            //print numerator
              //print first digit
               //function: printDigit & findFirstDigit

              //print second digit
               //function: printDigit & findSecondDigit

              //print third digit
               //function: printDigit & findThirdDigit

            //print denominator
              //if denominator is two digits

                //{
            
                   //print first digit
                   //function: printDigit & findFirstDigit

                   //print second digit
                   //function: printDigit & findSecondDigit

                //}

              //else (denominator is one digit)

                //{
            
                  //print digit
                   //function: printDigit

                //}

          //}

        //else

          //{

            //print negative sign by the numerator
              //convert char to int
              //function:charToInt

              //print operation sign
              //function printDigit

            //set color for numerator and denominator
            //function: setColor

            //print numerator
              //if numerator is two digits

                //{
            
                   //print first digit
                   //function: printDigit & findFirstDigit

                   //print second digit
                   //function: printDigit & findSecondDigit

                //}

              //else (numerator is one digit)

                //{
            
                  //print digit
                   //function: printDigit

                //}


            //print denominator
              //if denominator is two digits

                //{
            
                   //print first digit
                   //function: printDigit & findFirstDigit

                   //print second digit
                   //function: printDigit & findSecondDigit

                //}

              //else if denominator is three digits

                //{

                  //print first digit
                   //function: printDigit & findFirstDigit

                  //print second digit
                   //function: printDigit & findSecondDigit

                  //print third digit
                   //function: printDigit & findThirdDigit

                //}

              //else (denominator is one digit)

                //{
            
                  //print digit
                   //function: printDigit

                //}

          //}
    //}

  // else 

    //{

    //}

}
int findFirstDigit (int value)
{

  //initialize function/variables

  //divide value by 100 return the integer

  //stub
  return 0;
}

int findSecondDigit (int value)
{
  //initialize function/variables

  //if value is between or equal to 999 and 100

    //{
       
       //divide value by 10

      //use switch to return the tens place
       
        //switch(value)

        //{

          //case all values that have a 1 in the ones place AND return 1

          //break

          //case all values that have a 2 in the ones place AND return 2

          //break

          //case all values that have a 3 in the ones place AND return 3

          //break

          //case all values that have a 4 in the ones place AND return 4

          //break 
          
          //case all values that have a 5 in the ones place AND return 5

          //break
          
          //case all values that have a 6 in the ones place AND return 6

          //break

          //case all values that have a 7 in the ones place AND return 7

          //break

          //case all values that have a 8 in the ones place AND return 8

          //break

          //default:

          //return 9

        //}
    //}
  
  //else aka value is between or equal to 10 and 99

    //{
       
       //use math to find the value in the ones place
         //divide the value by 10

         //return the int

    //}

  //stub
  return 0;
}

int findThirdDigit ( int value)
{
  //initialize function/variables

  //if value is between or equal to 999 and 100

    //{
       
       //use math to find the value in the ones place
         //find the remainder aka % by dividing the value by 100

    //}
  
  //else aka value is between or equal to 10 and 99

    //{

       //use math to find the value in the ones place
         //find the remainder aka % by dividing the value by 10

    //}

  //stub
  return 0;
}
