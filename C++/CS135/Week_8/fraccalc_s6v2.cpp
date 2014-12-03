/*//////////////////////////////////////////////////////////////////////////
  
    Fraction Calculator

    Name: Zachary Carlson    
    Code Written:        03/7/2012
    Most Recent Update:  03/27/2012-2:06 a.m.
 

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
output/returned: char operation or '&' when failure
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
     int numOne = 1; 
     int denOne = 1;
     int numTwo = 1; 
     int denTwo = 1; 
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
       denOne = promptAndOutputInt(2);

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
     int titleX = MAX_X - 54; 
     int fracXone = MIN_X + 1; 
     int fracXtwo = MAX_X - 52; 
     int fracXthree = MAX_X - 25;
     int borderYone = 3;
     int borderYtwo = MAX_Y - 2;
     int titleYone = 0;
     int titleYtwo = 1;
     //set color and clear screen
       //function: setColor, clearScreen
       setColor( TITLE_COLOR , BACKGROUND_COLOR , true );
       clearScreen( MIN_X , MIN_Y , MAX_X , MAX_Y);

     //print title
       //function: printStringAt
       printStringAt( titleX, titleYone, "Fraction Calculation Program" , "LEFT");
     
     //print title underline
       //function: printStringAt
       printStringAt( titleX, titleYtwo, "============================" , "LEFT");

     //set color for borders
       //function: setcolor
       setColor( BORDER_COLOR , BACKGROUND_COLOR , true );
         //print horizontal borders
           //function: printStringAt
           printStringAt( fracXone, borderYone, "#############" , "LEFT");
           printStringAt( fracXtwo, borderYone, "#############" , "LEFT");
           printStringAt( fracXthree, borderYone, "########################" , "LEFT");
           printStringAt( fracXone, borderYtwo, "#############" , "LEFT");
           printStringAt( fracXtwo, borderYtwo, "#############" , "LEFT");
           printStringAt( fracXthree, borderYtwo, "########################" , "LEFT");
         //print vertical borders
           //function: printVerticalString
           printStringVertical( fracXone, borderYone, "####################","DOWN");
           printStringVertical( fracXone + 13, borderYone, "####################","DOWN");
           printStringVertical( fracXtwo, borderYone, "####################","DOWN");
           printStringVertical( fracXtwo + 13, borderYone, "####################","DOWN");
           printStringVertical( fracXthree, borderYone, "####################","DOWN");
           printStringVertical( fracXthree + 24, borderYone, "####################","DOWN");

}

int promptAndOutputInt( int locInt)
{
  //initialize function/variables
      //variables(note to self, make sure to assign x and y loc for prompt here
      int value;
      char valueB;
      
        // y location for denominator and numerator
        int yDen = 15;
        int yNum = 4;

        //Fraction one denominator/numerator X locations
        int xLocOne = 5;

        //Fraction two denominator/numerator X locations      
        int xLocTwo = MAX_X - 48;
      
      //setColor for prompt
        //function: setColor
        setColor( INPUT_TEXT_COLOR, BACKGROUND_COLOR , true );
/*//////////////////////////////////////////////////////////////////////////////

                             THIS CODE WAS TAKEN OUT

       I added this code into each individual case during step 6
--------------------------------------------------------------------------------        
      //promptForCharAt
        //function: promptForCharAt
        value = promptForCharAt( MIN_X + 5, MAX_Y, "Enter First Numerator:");

      //convert char to int
        //function:charToInt
        value = charToInt (value);
//////////////////////////////////////////////////////////////////////////////*/

  //assign x and y location for output & print digit (switch (locInt))
  switch(locInt)
  //{
  {
      //case locInt = 1:
      case 1:
        //promptForCharAt
          //function: promptForCharAt
        valueB = promptForCharAt( MIN_X + 5, MAX_Y, "Enter First Numerator: ");

        //convert char to int
          //function:charToInt
        //value = charToInt (valueB);

switch (valueB)
{
   case '0':
   value = 0;
   break;
   case '1':
   value = 1;
   break;
   case '2':
   value = 2;
   break;
   case '3':
   value = 3;
   break;
   case '4':
   value = 4;
   break;
   case '5':
   value = 5;
   break;
   case '6':
   value = 6;
   break;
   case '7':
   value = 7;
   break;
   case '8':
   value = 8;
   break;
   case '9':
   value = 9;
   break;
   default:
   value = -7;
}


        //if int returned from prompt is not less than 10 and greater than or equal to 0
        if( value >= 10 || value < 0)
        //{
          {
          //submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
          printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
        //}
          }        
        //else
          else
        //{
          {

        //printDigit
          //function: printDigit
          printDigit( xLocOne, yNum, value, OUTPUT_COLOR);

             //clear prompt added in step 6
     //function: clearScreen & setcolor
     setColor( OUTPUT_COLOR, BACKGROUND_COLOR, true );
     clearScreen( MIN_X, MAX_Y - 1, MIN_X + 36, MAX_Y);

        // set color for output 
          //function: setColor
          setColor ( FRACTION_COLOR, BACKGROUND_COLOR, true);

        //print Fraction sign in purple
        printStringAt(4, 12, "========", "LEFT");
        printStringAt(4, 13, "========", "LEFT");
        //}
        }  
      //break
      break;
      //case locInt = 2:
      case 2:
          //promptForCharAt
           //function: promptForCharAt
           valueB = promptForCharAt( MIN_X + 5, MAX_Y, "Enter First Denominator: ");

          //convert char to int
            //function:charToInt
            //value = charToInt (valueB); 

switch (valueB)
{
   case '0':
   value = 0;
   break;
   case '1':
   value = 1;
   break;
   case '2':
   value = 2;
   break;
   case '3':
   value = 3;
   break;
   case '4':
   value = 4;
   break;
   case '5':
   value = 5;
   break;
   case '6':
   value = 6;
   break;
   case '7':
   value = 7;
   break;
   case '8':
   value = 8;
   break;
   case '9':
   value = 9;
   break;
   default:
   value = -7;
}   
        //if int = 0
        if (value == 0)
           //{
           {
           //submit error message for dividing by zero
             //function: printStringAt & setColor
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
          printStringAt (MIN_X, MAX_Y, "  Error: Division by Zero - Program aborted", "LEFT");
           //}
           }
        //else if integer returned from prompt is not greater than 0, less than 10
        else if( value < 1 || value >= 10)
          //{
          {
          //submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
          printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
          //}
          }

        //else 
        else
        //{
        {
        
        //printDigit
          //function: printDigit
          printDigit( xLocOne, yDen, value, OUTPUT_COLOR);

             //clear prompt added in step 6
     //function: clearScreen & setcolor
     setColor( OUTPUT_COLOR, BACKGROUND_COLOR, true );
     clearScreen( MIN_X, MAX_Y - 1, MIN_X + 36, MAX_Y);

  
        //}
        }
  
      //break
      break;
      //case locInt = 3:
      case 3:
           //promptForCharAt
             //function: promptForCharAt
           valueB = promptForCharAt( MIN_X + 5, MAX_Y, "Enter Second Numerator: ");

          //convert char to int
            //function:charToInt
            //value = charToInt (valueB); 

switch (valueB)
{
   case '0':
   value = 0;
   break;
   case '1':
   value = 1;
   break;
   case '2':
   value = 2;
   break;
   case '3':
   value = 3;
   break;
   case '4':
   value = 4;
   break;
   case '5':
   value = 5;
   break;
   case '6':
   value = 6;
   break;
   case '7':
   value = 7;
   break;
   case '8':
   value = 8;
   break;
   case '9':
   value = 9;
   break;
   default:
   value = -7;
}
  

        //if int returned from prompt is not less than 10 and greater than or equal to 0
        if( value >= 10 || value < 0)
        //{
          {
          //submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
          printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
        //}
          }        
        //else
          else
        //{
          {

        //printDigit
          //function: printDigit
          printDigit( xLocTwo, yNum, value, OUTPUT_COLOR);
          
             //clear prompt added in step 6
     //function: clearScreen & setcolor
     setColor( OUTPUT_COLOR, BACKGROUND_COLOR, true );
     clearScreen( MIN_X, MAX_Y - 1, MIN_X + 36, MAX_Y);

        // set color for output 
          //function: setColor
          setColor ( FRACTION_COLOR, BACKGROUND_COLOR, true);

        //print Fraction sign in purple
        printStringAt(MAX_X - 49, 12, "========", "LEFT");
        printStringAt(MAX_X - 49, 13, "========", "LEFT");
        //}
        }  
      //break
      break;
      
      //case locInt = 4:
      case 4:
          //promptForCharAt
           //function: promptForCharAt
           valueB = promptForCharAt( MIN_X + 5, MAX_Y, "Enter Second Denominator: ");

          //convert char to int
            //function:charToInt
            //value = charToInt (valueB);    

switch (valueB)
{
   case '0':
   value = 0;
   break;
   case '1':
   value = 1;
   break;
   case '2':
   value = 2;
   break;
   case '3':
   value = 3;
   break;
   case '4':
   value = 4;
   break;
   case '5':
   value = 5;
   break;
   case '6':
   value = 6;
   break;
   case '7':
   value = 7;
   break;
   case '8':
   value = 8;
   break;
   case '9':
   value = 9;
   break;
   default:
   value = -7;
}



        //if int = 0
        if (value == 0)
           //{
           {
           //submit error message for dividing by zero
             //function: printStringAt & setColor
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
          printStringAt (MIN_X, MAX_Y, "  Error: Division by Zero - Program aborted", "LEFT");
           //}
           }
        //else if integer returned from prompt is not greater than 0, less than 10
        else if( value < 1 || value >= 10)
          //{
          {
          //submit error message
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
          printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");
          //}
          }

        //else 
        else
        //{
        {
        
        //printDigit
          //function: printDigit
          printDigit( xLocTwo, yDen, value, OUTPUT_COLOR);
          
             //clear prompt added in step 6
     //function: clearScreen & setcolor
     setColor( OUTPUT_COLOR, BACKGROUND_COLOR, true );
     clearScreen( MIN_X, MAX_Y - 1, MIN_X + 36, MAX_Y);

        //}
        }
  
      //break
      break;

      //default:
      default:

        //submit error message
          //function setColor, printStringAt
          setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
          printStringAt (MIN_X, MAX_Y, "  Error: Incorrect Location - Program aborted", "LEFT");
          

    //}
    }

  //return value
  return value;
}

char promptAndOutputChar()
{
   //initialize function/variables
     //variables
     int xLocation = 17;
     int yLocation = 13;
     char operation;
     
     //setColor for prompt
     setColor( INPUT_TEXT_COLOR, BACKGROUND_COLOR , true );
     
   //promptForCharAt
   operation = promptForCharAt( MIN_X + 5, MAX_Y, "Enter math operator: ");
   setColor( OUTPUT_COLOR, BACKGROUND_COLOR, true );
   clearScreen( MIN_X, MAX_Y - 1, MIN_X + 36, MAX_Y);
   //switch (operation)
   switch (operation)
   //{
   {
     //case operation = '+':
     case '+':     
     
       //print digit
       setColor( OPERATION_COLOR, BACKGROUND_COLOR, true);
       printStringAt(xLocation, yLocation, "########", "LEFT");
       printStringVertical(xLocation + 3, yLocation - 3, "#######", "DOWN");
       printStringVertical(xLocation + 4, yLocation - 3, "#######", "DOWN");

       //return char
       return operation;
     
     //break
     break;
     //case operation = '*':
     case '*':
       //print digit
       setColor( OPERATION_COLOR, BACKGROUND_COLOR, true);
       printStringAt(xLocation, yLocation - 3, "#  #  #", "LEFT");
       printStringAt(xLocation, yLocation - 2, " # # # ", "LEFT");
       printStringAt(xLocation, yLocation - 1, "  ###  ", "LEFT");
       printStringAt(xLocation, yLocation,"#######", "LEFT");
       printStringAt(xLocation, yLocation + 1, "  ###  ", "LEFT");
       printStringAt(xLocation, yLocation + 2, " # # # ", "LEFT");
       printStringAt(xLocation, yLocation + 3, "#  #  #", "LEFT");

       //return char
       return operation;     
     //break
     break;     

     //case operation = '-':
     case '-':
       //print digit
       setColor( OPERATION_COLOR, BACKGROUND_COLOR, true);
       printStringAt(xLocation, yLocation, "########", "LEFT");

       //return char
       return operation;
     
     //break
     break;

     //case operation = '/':
     case '/':
     
       //print digit
              setColor( OPERATION_COLOR, BACKGROUND_COLOR, true);
       printStringAt(xLocation, yLocation - 3, "   ##", "LEFT");
       printStringAt(xLocation, yLocation - 2, "   ##", "LEFT");
 
       printStringAt(xLocation, yLocation,     "########", "LEFT");

       printStringAt(xLocation, yLocation + 2, "   ##", "LEFT");
       printStringAt(xLocation, yLocation + 3, "   ##", "LEFT");

       //return char
       return operation;
     
     //break
     break;

     //default:
     default:

       //submit error message
       setColor( ERROR_COLOR, BACKGROUND_COLOR, true );
       printStringAt (MIN_X, MAX_Y, "  Error: Incorrect input - Program aborted", "LEFT");

       return '&';
    //}
     }
}

void calcAnsw (int firstNum, int firstDen, int secondNum, int secondDen, char operation)
{

  //initialize function/variables
    //variables = resultNum & resultDen
    int resultNum; 
    int resultDen;

  //calculate the num and den using switch(operation)
  switch(operation)
  //{
  {
    //case '+':
    case '+':
      //use firstNum, firstDen, secondNum, secondDen to calculate
      if ( firstDen == secondDen )
        {
      //assign resultNum & resultDen
      resultNum = firstNum + secondNum;
      resultDen = secondDen;
        }
      else
        {
        resultNum = ((firstNum * secondDen ) + (secondNum * firstDen));
        resultDen = (firstDen * secondDen);
        }
    //break
    break;

    //case '-':
    case '-':
      //use firstNum, firstDen, secondNum, secondDen to calculate
      if ( firstDen == secondDen )
        {
      //assign resultNum & resultDen
      resultNum = firstNum - secondNum;
      resultDen = secondDen;
        }
      else
        {
        resultNum = ((firstNum * secondDen ) - (secondNum * firstDen));
        resultDen = (firstDen * secondDen);
        }
    //break
    break;
    //case '/':
    case '/':
      //use firstNum, firstDen, secondNum, secondDen to calculate
      //assign resultNum & resultDen
      resultNum = firstNum * secondDen;
      resultDen = firstDen * secondNum;
    //break
    break;

    //case '*':
    case '*':
      //use firstNum, firstDen, secondNum, secondDen to calculate
      //assign resultNum & resultDen
      resultNum = firstNum * secondNum;
      resultDen = firstDen * secondDen;
    //break
    break;

    //default:
      // output error message for wrong parameters in the calcAnsw function


    //}
    }

  //use printAnsw function to determine how to output it, and print it at once
    //function: printAnsw
    printAnsw( resultNum, resultDen);

}

bool checkForNegAnsw ( int value)
{
   //if value is less than zero
   if ( value < 0)
   {
      //return true
      return true;
   }
   //else
   else

      //return false
      return false;
}

bool checkForTwoDigits ( int value)
{
   //if value is less than 100 and greater than 9
   if ( value < 100 && 9 < value)
   { 
      //return true
      return true;
   }
   //else
   else
      //return false
      return false;
}

bool checkForThreeDigits ( int value)
{
   //if value is less than 1000 and greater than 99
   if ( value < 1000 && 99 < value )
   {
      //return true
      return true;
   }
   //else
   else
      //return false
      return false;
}

void printAnsw ( int finalNum, int finalDen)
{

  // initialize function/variables
  int yLocN = 4;
  int yLocD = 15;
  int digitA, digitB, digitC;
  int digitD, digitE, digitF;

      // x location for numerator and denominator if 1 digits
      int xOneDigit = MAX_X - 16;
      // x location for numerator and denominator if 2 digits
      int xTwoDigitA = MAX_X - 18; 
      int xTwoDigitB = MAX_X - 13;
      // x location for numerator and denominator if 3 digits
      int xThreeDigitA = MAX_X - 19; 
      int xThreeDigitB = MAX_X - 14; 
      int xThreeDigitC = MAX_X - 9;
      //x & y location for negative sign
      int xNegLocNumOne = xOneDigit - 5;
      int xNegLocNumTwo = xTwoDigitA - 5;
      int yNegLocNum = 8; 
      int yNegLocDen = 19;

  //print equal sign
  setColor ( OPERATION_COLOR, BACKGROUND_COLOR, true);
  printStringAt(MAX_X - 29, 12, "########", "RIGHT");
  printStringAt(MAX_X - 29, 14, "########", "RIGHT");

  // print fraction border
  setColor ( FRACTION_COLOR, BACKGROUND_COLOR, true);
   printStringAt(MAX_X - 3, 12, "====================", "RIGHT");
   printStringAt(MAX_X - 3, 13, "====================", "RIGHT");
  
  

  /* if (numerator is positive and denominator is positive) or ( numerator and 
  denominator are both negative)*/
  if((finalNum >= 0 && finalDen > 0) 
     || (finalNum < 0 && finalDen < 0))

    //{
    {
/*/////////////////////////////////////////////////////////////////////////////
MAKE THE FINALNUM and FINALDEN POSITIVE ADDED IN STEP 6*****
*/
        finalNum = abs(finalNum);
        finalDen = abs(finalDen);

/*/////////////////////////////////////////////////////////////////////////////
*/
      //print numerator
        //if numerator is two digits
        if(checkForTwoDigits ( finalNum) == true)
          //{
          {
             //print first digit
             //function: printDigit & findFirstDigit
             digitA = findFirstDigit( finalNum);
             printDigit(xTwoDigitA, yLocN, digitA, OUTPUT_COLOR);

             //print second digit
             //function: printDigit & findSecondDigit
             digitB = findSecondDigit( finalNum);
             printDigit(xTwoDigitB, yLocN, digitB, OUTPUT_COLOR);

          //}
          }
        //else if numerator is three digits
        else if(checkForThreeDigits(finalNum) == true)
          //{
          {
            //print first digit
             //function: printDigit & findFirstDigit
             digitA = findFirstDigit( finalNum);
             printDigit(xThreeDigitA, yLocN, digitA, OUTPUT_COLOR);

            //print second digit
             //function: printDigit & findSecondDigit
             digitB = findSecondDigit( finalNum);
             printDigit(xThreeDigitB, yLocN, digitB, OUTPUT_COLOR);

            //print third digit
             //function: printDigit & findThirdDigit
             digitC = findThirdDigit( finalNum);
             printDigit(xThreeDigitC, yLocN, digitC, OUTPUT_COLOR);

          //}
          }

        //else (numerator is one digit)
        else
          //{
          {            
            //print digit
             //function: printDigit
             printDigit(xOneDigit, yLocN, finalNum, OUTPUT_COLOR);
          //}
          }         
      //print denominator
        //if denominator is two digits
        if(checkForTwoDigits ( finalDen) == true)

          //{
             {
             //print first digit
             //function: printDigit & findFirstDigit
             digitD = findFirstDigit( finalDen);
             printDigit(xTwoDigitA, yLocD, digitD, OUTPUT_COLOR);             

             //print second digit
             //function: printDigit & findSecondDigit
             digitE = findSecondDigit( finalDen);
             printDigit(xTwoDigitB, yLocD, digitE, OUTPUT_COLOR); 

          //}
            }
        //else if denominator is three digits
        else if(checkForThreeDigits(finalDen) == true)
          //{
          {

            //print first digit
             //function: printDigit & findFirstDigit
             digitD = findFirstDigit( finalDen);
             printDigit(xThreeDigitA, yLocD, digitD, OUTPUT_COLOR);
            //print second digit
             //function: printDigit & findSecondDigit
             digitE = findSecondDigit( finalDen);
             printDigit(xThreeDigitB, yLocD, digitE, OUTPUT_COLOR);

            //print third digit
             //function: printDigit & findThirdDigit
             digitF = findThirdDigit (finalDen);
             printDigit(xThreeDigitC, yLocD, digitF, OUTPUT_COLOR);

          //}
          }

        //else (denominator is one digit)
        else
          //{
            {
            //print digit
             //function: printDigit
             printDigit(xOneDigit, yLocD, finalDen, OUTPUT_COLOR);
          //}
          }
    //}
    }
  /* else if(numerator is negative and denominator is positive) or (numerator is
  positive and denominator is negative) */
  else if( (finalNum < 0 && finalDen >= 0) || (finalDen < 0 && finalNum >= 0))
    //{
    {

/*/////////////////////////////////////////////////////////////////////////////
MAKE THE FINALNUM and FINALDEN POSITIVE ADDED IN STEP 6*****
*/
        finalNum = abs(finalNum);
        finalDen = abs(finalDen);

/*/////////////////////////////////////////////////////////////////////////////
*/
        //if numerator is three digits
        if(checkForThreeDigits(finalNum) == true)
        
          //{
          {

            //print numerator
            //print first digit
             //function: printDigit & findFirstDigit
             digitA = findFirstDigit( finalNum);
             printDigit(xThreeDigitA, yLocN, digitA, OUTPUT_COLOR);

            //print second digit
             //function: printDigit & findSecondDigit
             digitB = findSecondDigit( finalNum);
             printDigit(xThreeDigitB, yLocN, digitB, OUTPUT_COLOR);

            //print third digit
             //function: printDigit & findThirdDigit
             digitC = findThirdDigit( finalNum);
             printDigit(xThreeDigitC, yLocN, digitC, OUTPUT_COLOR);

            //print denominator
              //if denominator is two digits
              if(checkForTwoDigits(finalDen) == true)

                //{
                {
            //print the negative sign by the denominator
            setColor(OPERATION_COLOR, BACKGROUND_COLOR, true);
            printStringAt(xNegLocNumTwo, yNegLocDen, "#####", "LEFT");
            
              //print first digit
             //function: printDigit & findFirstDigit
             digitD = findFirstDigit( finalDen);
             printDigit(xTwoDigitA, yLocD, digitD, OUTPUT_COLOR);             

             //print second digit
             //function: printDigit & findSecondDigit
             digitE = findSecondDigit( finalDen);
             printDigit(xTwoDigitB, yLocD, digitE, OUTPUT_COLOR); 

                //}
                }

              //else (denominator is one digit)
              else
                //{
                {
             //print the negative sign by the denominator
            setColor(OPERATION_COLOR, BACKGROUND_COLOR, true);
            printStringAt(xNegLocNumOne, yNegLocDen, "#####", "LEFT");
                  //print digit
                   //function: printDigit
                   printDigit(xOneDigit, yLocD, finalDen, OUTPUT_COLOR);

                //}
                }
          //}
          }
        //else
        else

          //{
          {

            //print numerator
              //if numerator is two digits
              if(checkForTwoDigits(finalNum) == true)

                //{
                {
                   //print negative sign
                   setColor(OPERATION_COLOR, BACKGROUND_COLOR, true);
                   printStringAt(xNegLocNumTwo, yNegLocNum, "#####", "LEFT");
            
                  //print first digit
                  //function: printDigit & findFirstDigit
                  digitA = findFirstDigit( finalNum);
                  printDigit(xTwoDigitA, yLocN, digitA, OUTPUT_COLOR);

                   //print second digit
                    //function: printDigit & findSecondDigit
                     digitB = findSecondDigit( finalNum);
                     printDigit(xTwoDigitB, yLocN, digitB, OUTPUT_COLOR);

                //}
                }
              //else (numerator is one digit)
              else
                //{
                {
                   //print negative sign
                   setColor(OPERATION_COLOR, BACKGROUND_COLOR, true);
                   printStringAt(xNegLocNumOne, yNegLocNum, "#####", "LEFT");
            
                  //print digit
                   //function: printDigit
                   printDigit(xOneDigit, yLocN, finalNum, OUTPUT_COLOR);

                //}
                }

            //print denominator
              //if denominator is two digits
              if(checkForTwoDigits(finalDen) == true)
                //{
                {            
                //print first digit
                //function: printDigit & findFirstDigit
                digitD = findFirstDigit( finalDen);
                printDigit(xTwoDigitA, yLocD, digitD, OUTPUT_COLOR);             

                //print second digit
                //function: printDigit & findSecondDigit
                digitE = findSecondDigit( finalDen);
                printDigit(xTwoDigitB, yLocD, digitE, OUTPUT_COLOR); 

                //}
                }
              //else if denominator is three digits
              else if(checkForThreeDigits(finalDen) == true)
                //{
                {

            //print first digit
             //function: printDigit & findFirstDigit
             digitD = findFirstDigit( finalDen);
             printDigit(xThreeDigitA, yLocD, digitD, OUTPUT_COLOR);
            //print second digit
             //function: printDigit & findSecondDigit
             digitE = findSecondDigit( finalDen);
             printDigit(xThreeDigitB, yLocD, digitE, OUTPUT_COLOR);

            //print third digit
             //function: printDigit & findThirdDigit
             digitF = findThirdDigit (finalDen);
             printDigit(xThreeDigitC, yLocD, digitF, OUTPUT_COLOR);

                //}
                }

              //else (denominator is one digit)
              else

                //{
                {
                  //print digit
                   //function: printDigit
                   printDigit(xOneDigit, yLocD, finalDen, OUTPUT_COLOR);
                   
                //}
                }

          //}
          }
    //}
    }
  // else 
  else
    //{
    {
    //}
    }

}
int findFirstDigit (int value)
{

  //initialize function/variables
  int result;
  //divide value by 100 return the integer
  if (value > 99 && value < 1000)
  {
  result = value / 100;
  }
  else
  {
  result = value / 10;
  }
  //stub
  return result;
}

int findSecondDigit (int value)
{
  //initialize function/variables
  int result;

  //if value is between or equal to 999 and 100
  if ( value > 99 && value < 1000 )
    //{
       {
       //divide value by 10
       value = value / 10;
      //use switch to return the tens place
       //switch(value)
       switch (value)
        //{
        {
        
        case 10:
        case 20:
        case 30:
        case 40:
        case 50:
        case 60:
        case 70:
        case 80:
        case 90:
        result = 0;
        return result;
          //case all values that have a 1 in the ones place AND return 1
          case 11:
          case 21:
          case 31:
          case 41:
          case 51:
          case 61:
          case 71:
          case 81:
          case 91:
          result = 1;
          return result;
          //break
          break;
          //case all values that have a 2 in the ones place AND return 2
          case 12:
          case 22:
          case 32:
          case 42:
          case 52:
          case 62:
          case 72:
          case 82:
          case 92:
          result = 2;
          return result;
          //break
          break;

          //case all values that have a 3 in the ones place AND return 3
          case 13:
          case 23:
          case 33:
          case 43:
          case 53:
          case 63:
          case 73:
          case 83:
          case 93:
          result = 3;
          return result;
          //break
          break;

          //case all values that have a 4 in the ones place AND return 4
          case 14:
          case 24:
          case 34:
          case 44:
          case 54:
          case 64:
          case 74:
          case 84:
          case 94:
          result = 4;
          return result;
          //break
          break; 
          
          //case all values that have a 5 in the ones place AND return 5
          case 15:
          case 25:
          case 35:
          case 45:
          case 55:
          case 65:
          case 75:
          case 85:
          case 95:
          result = 5;
          return result;
          //break
          break;
          
          //case all values that have a 6 in the ones place AND return 6
          case 16:
          case 26:
          case 36:
          case 46:
          case 56:
          case 66:
          case 76:
          case 86:
          case 96:
          result = 6;
          return result;
          //break
          break;

          //case all values that have a 7 in the ones place AND return 7
          case 17:
          case 27:
          case 37:
          case 47:
          case 57:
          case 67:
          case 77:
          case 87:
          case 97:
          result = 7;
          return result;
          //break
          break;

          //case all values that have a 8 in the ones place AND return 8
          case 18:
          case 28:
          case 38:
          case 48:
          case 58:
          case 68:
          case 78:
          case 88:
          case 98:
          result = 8;
          return result;
          //break
          break;

          //default:
          default:

          //return 9
          return 9;
        //}
        }
    //}
    }
  
  //else aka value is between or equal to 10 and 99
  else
    //{
      { 
       //use math to find the value in the ones place
         //divide the value by 10
         result = value % 10;
         //return the int
         return result;
    //}
    }
}

int findThirdDigit ( int value)
{
  //initialize function/variables
  int result;
  //if value is between or equal to 999 and 100
  if ( value > 99 && value < 1000 )
    //{
    {       
       //use math to find the value in the ones place
         //find the remainder aka % by dividing the value by 10
         result = value % 10;
    //}
    }
  //else aka value is between or equal to 10 and 99
  else
    //{
    {
       //use math to find the value in the ones place
         //find the remainder aka % by dividing the value by 10
         result = value % 10;
    //}
    }
  //returned result
  return result;
}
