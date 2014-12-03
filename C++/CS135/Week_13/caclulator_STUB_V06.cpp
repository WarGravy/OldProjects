// Header files
#include "registers_v03.h"

using namespace std;

// Global Constants

   // color constants
   const short MENU_FG_COLOR = COLOR_YELLOW;
   const short MENU_BG_COLOR = COLOR_CYAN;
   const short PROMPT_FG_COLOR = COLOR_WHITE;
   const short PROMPT_BG_COLOR = COLOR_BLACK;

   // menu constants
   const int MENU_MIN_X = SCRN_MIN_X;
   const int MENU_MIN_Y = SCRN_MIN_Y;
   const int MENU_MAX_X = 17;
   const int MENU_MAX_Y = SCRN_MAX_Y;

// Function Prototypes

/*
name: displayMenu
process: displays base and register options, math menu options, 
         returns user selection
input: current base(int)
output/returned: user selection(int)
output/to screen: menu
output/via pointer: none
dependencies: formatted console I/O tools
*/
int displayMenu( int base );

/*
name: setBase
process: gets new base, returns new base, if within range, or old base
input: old base(int)
output/returned: correct base(int)
output/to screen: prompt for base
output/via pointer: none
dependencies: formatted console I/O tools
*/
int setBase( int oldBase );

/*
name: loadRegister
process: gets X or Y register choice, loads appropriate register
input: register X(int array), register Y(int array), current base(int)
output/returned: none
output/to screen: X or Y register prompt
output/via pointer: modified X or Y register
dependencies: formatted console I/O tools, register tools
*/
void loadRegister( int registerX[], int registerY[], int base );

/*
name: clearRegister
process: gets X or Y register choice, clears appropriate register, resets 
         Z register
input: register X(int array), register Y(int array), register Z(int array), 
       current base(int)
output/returned: none
output/to screen: X or Y register prompt, cleared register
output/via pointer: cleared X or Y register, reset Z register
dependencies: formatted console I/O tools, register tools
*/
void clearRegister( int registerX[], int registerY[], int registerZ[], int base );

/*
name: transferZRegister
process: gets X or Y register choice, transfers Z into appropriate register, 
         resets register Z
input: register X(int array), register Y(int array), register Z(int array)
output/returned: transfer success(bool)
output/to screen: X or Y register prompt
output/via pointer: modified X or Y register, reset Z register
dependencies: formatted console I/O tools, register tools
*/   
bool transferZRegister( int registerX[], int registerY[], int registerZ[] );
 
/*
name: addRegisters
process: adds values in register X and register Y, puts sum into register Z
input: register X(int array), register Y(int array), register Z(int array), 
       current base(int)
output/returned: false for overflow, true for no overflow(bool)
output/to screen: none
output/via pointer: Z register
dependencies: register tools
*/
bool addRegisters( int registerX[], int registerY[], int registerZ[], int base ); 

/*
name: subtractRegisters
process: subtracts values in register Y from register X, puts difference into 
         register Z
input: register X(int array), register Y(int array), register Z(int array), 
       current base(int)
output/returned: false for underflow, true for no underflow(bool)
output/to screen: none
output/via pointer: Z register
dependencies: register tools
*/
bool subtractRegisters( int registerX[], int registerY[], int registerZ[], int base ); 

/*
name: multiplyRegisters
process: adds values in register X register Y times, puts product into 
         register Z
input: register X(int array), register Y(int array), register Z(int array), 
       current base(int)
output/returned: false for overflow, true for no overflow(bool)
output/to screen: none
output/via pointer: Z register
dependencies: register tools
*/
bool multiplyRegisters( int registerX[], int registerY[], int registerZ[], int base ); 

/*
name: divideRegisters
process: counts subtraction of values in register Y from register X, puts that
         dividend into register Z
input: register X(int array), register Y(int array), register Z(int array), 
       current base(int)
output/returned: false for underflow, true for no underflow(bool)
output/to screen: none
output/via pointer: Z register
dependencies: register tools
*/   
bool divideRegisters( int registerX[], int registerY[], int registerZ[], int base ); 
 
/*
name: moduloRegisters
process: subtracts values in register Y from register X, puts remainder into 
         register Z
input: register X(int array), register Y(int array), register Z(int array), 
       current base(int)
output/returned: false for underflow, true for no underflow(bool)
output/to screen: none
output/via pointer: Z register
dependencies: register tools
*/  
bool moduloRegisters( int registerX[], int registerY[], int registerZ[], int base ); 
  
/*
name: expPowerRegisters
process: multiplies values in register X register Y times, puts product into 
         register Z
input: register X(int array), register Y(int array), register Z(int array), 
       current base(int)
output/returned: false for overflow, true for no overflow(bool)
output/to screen: none
output/via pointer: Z register
dependencies: register tools
*/   
bool expPowerRegisters( int registerX[], int registerY[], int registerZ[], int base ); 
   
  
/*
name: copyRegister
process: copies source register into destination register element by element
input: destination register(int array), source register(int array)
output/returned: none
output/to screen: none
output/via pointer: new destination register
dependencies: none
*/
void copyRegister( int regDestination[], int regSource[] );
   
/*
name: getRegValLength
process: moves from last element of register until value greater than 0 is found
input: register to be counted(int array)
output/returned: number of digits in register(int)
output/to screen: none
output/via pointer: none
dependencies: none
*/   
int getRegValLength( int reg[] );
      
/*
name: isZero
process: checks that all values in register are set to 0
input: register to be checked(int array)
output/returned: true if all zeros, false otherwise(bool)
output/to screen: none
output/via pointer: none
dependencies: none
*/ 
bool isZero( int reg[] );


// Main function
int main()
   {
    // initialize function/program

       // initialize variables
       int regX[ NUM_REG_DIGITS ], regY[ NUM_REG_DIGITS ];
       int regZ[ NUM_REG_DIGITS ];
       int response, oldBase, base = 10;
       char regLetter;
       bool quit = false;

       // start curses
          // function: startCurses
       startCurses();

    // initialize registers

       // initialize X register
          // function: zeroRegister
       zeroRegister( regX );

       // initialize Y register
          // function: zeroRegister
       zeroRegister( regY );

       // initialize Z register
          // function: zeroRegister
       zeroRegister( regZ );

    // display initialized registers

       // set X register
       regLetter = 'x';

       // display X register
          // function: displayRegister
       displayRegister( regLetter, regX, base, DISPLAY_DIGITS );

       // set Y register
       regLetter = 'y';

       // display Y register
          // function: displayRegister
       displayRegister( regLetter, regY, base, DISPLAY_DIGITS );

       // set Z register
       regLetter = 'z';

       // display Z register
          // function: displayRegister
       displayRegister( regLetter, regZ, base, RESET_DIGITS );

    // run program
       do
         {
          // display options, get user input
          response = displayMenu( base );

          // choose from options
          switch( response )
             {
              // <E>nter base
              case 'e':
              case 'E':
                 // save current base
                 oldBase = base;

                 // get new base
                    // function: setBase
                 base = setBase( oldBase );

                 // check new base is not the same as the old base
                 if( base != oldBase )
                    {
                     // empty X register
                        // function: zeroRegister
                     zeroRegister( regX );

                     // set X register
                     regLetter = 'x';

                     // display X register
                        // function: displayRegister
                     displayRegister( regLetter, regX, base, DISPLAY_DIGITS );
 
                     // empty Y register
                        // function: zeroRegister
                     zeroRegister( regY );

                     // set Y register
                     regLetter = 'y';

                     // display Y register
                        // function: displayRegister
                     displayRegister( regLetter, regY, base, DISPLAY_DIGITS );

                     // set Z register
                     regLetter = 'z';

                     // display reset Z register
                        // function: displayRegister
                     displayRegister( regLetter, regX, base, RESET_DIGITS );
                     }
                 break;

                 // <L>oad register
                 case 'l':
                 case 'L':
                     // load a register
                        // function: loadRegister
                     loadRegister( regX, regY, base );

                     // set Z register
                     regLetter = 'z';

                     // display reset Z register
                        // function: displayRegister
                     displayRegister( regLetter, regZ, base, RESET_DIGITS ); 
                     break;

                 // <C>lear register
                 case 'c':
                 case 'C':
                     // clear a register
                        // function: clearRegister
                     clearRegister( regX, regY, regZ, base );
                     break;

                 // <A>dd registers
                 case 'a':
                 case 'A':
                     // add registers
                        // function: addRegisters
                     // check addition was a success
                     if( addRegisters( regX, regY, regZ, base ) )
                        {
                         // set Z register
                         regLetter = 'z';

                         // display sum in Z register
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, DISPLAY_DIGITS );
                        }
                     // otherwise
                     else
                        {
                         // indicate overflow
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, SHOW_OVERFLOW );
                        }
                     break; 
                     
                 // <S>ubtract registers
                 case 's':
                 case 'S':
                     // subtract registers
                        // function: subtractRegisters
                     // check subtraction was a success
                     if( subtractRegisters( regX, regY, regZ, base ) )
                        {
                         // set Z register
                         regLetter = 'z';

                         // display difference in Z register
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, DISPLAY_DIGITS );
                        }
                     // otherwise
                     else
                        {
                         // indicate underflow
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, SHOW_UNDERFLOW );
                        }
                     break; 
            
                 // <M>ultiply registers
                 case 'm':
                 case 'M':
                     // multiply registers
                        // function: multiplyRegisters
                     // check multiplication was a success
                     if( multiplyRegisters( regX, regY, regZ, base ) )
                        {
                         // set Z register
                         regLetter = 'z';

                         // display result in Z register
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, DISPLAY_DIGITS );
                        }
                     // otherwise
                     else
                        {
                         // indicate overflow
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, SHOW_OVERFLOW );
                        }
                     break; 
            
                 // <D>ivide registers
                 case 'd':
                 case 'D':
                     // divide registers
                        // function: divideRegisters
                     // check division was a success
                     if( divideRegisters( regX, regY, regZ, base ) )
                        {
                         // set Z register
                         regLetter = 'z';

                         // display result in Z register
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, DISPLAY_DIGITS );
                        }
                     // otherwise
                     else
                        {
                         // indicate underflow
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, SHOW_UNDERFLOW );
                        }
                     break; 

                 // m<O>dulo registers
                 case 'o':
                 case 'O':
                     // modulo registers
                        // function: moduloRegisters
                     // check modulo division was a success
                     if( moduloRegisters( regX, regY, regZ, base ) )
                        {
                         // set Z register
                         regLetter = 'z';

                         // display result in Z register
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, DISPLAY_DIGITS );
                        }
                     // otherwise
                     else
                        {
                         // indicate underflow
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, SHOW_UNDERFLOW );
                        }
                     break; 

                 // ex<P>onentiate registers
                 case 'p':
                 case 'P':
                     // raise register to exponent
                        // function: expPowerRegisters
                     // check exponential power was a success
                     if( expPowerRegisters( regX, regY, regZ, base ) )
                        {
                         // set Z register
                         regLetter = 'z';

                         // display result in Z register
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, DISPLAY_DIGITS );
                        }
                     // otherwise
                     else
                        {
                         // indicate overflow
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, SHOW_OVERFLOW );
                        }
                     break; 

                 // <T>ransfer z register
                 case 't':
                 case 'T':
                     // transfer z register
                        // function: transferZRegister
                     // check transfer was a success
                     if( transferZRegister( regX, regY, regZ ) )
                        {
                         // set X register
                         regLetter = 'x';

                         // display new X register
                            // function: displayRegister
                         displayRegister( regLetter, regX, base, DISPLAY_DIGITS );

                         // set Y register
                         regLetter = 'y';

                         // display new Y register
                            // function: displayRegister
                         displayRegister( regLetter, regY, base, DISPLAY_DIGITS );

                         // set Z register
                         regLetter = 'z';

                         // display cleared Z register
                            // function: displayRegister
                         displayRegister( regLetter, regZ, base, RESET_DIGITS ); 
                        }
              
                     break; 

                 // <Q>uit program
                 case 'q':
                 case 'Q':
                     // set quit flag to true
                     quit = true;
                     break; 
             }
         }
       // until user chooses quit
       while( !quit );

    // shut down program

       // shut down curses
          // function: endCurses
       endCurses();
  
       // return success
       return 0;

   }

// Supporting function implementation

int displayMenu( int base )
   {
    // initialize function/variables
    int xPos, yPos;

    // set menu color
       // function: setColor 
    setColor( MENU_FG_COLOR, MENU_BG_COLOR, BRIGHT );

    // clear menu screen
       // function: clearScreen
    clearScreen( MENU_MIN_X, MENU_MIN_Y, MENU_MAX_X, MENU_MAX_Y );

    // print program title
       // set x position 
       xPos = 8; 

       // set y position
       yPos = 1;

       // print title
          // function: printStringAt
       printStringAt( xPos, yPos, "MULTI-BASE MATH", "CENTER" );

       // increase y position
       yPos++;
       
       // print underline
          // function: printStringAt
       printStringAt( xPos, yPos, "===============", "CENTER" );

       // set x position
       xPos = 1; 

       // increase y position
       yPos += 2;

       // print enter base option
          // function: printStringAt
          printStringAt( xPos, yPos, "<E>nter base", "LEFT" );

       // set x position
       xPos = 1; 

       // increase y position
       yPos += 2;

       // print load register option
          // function: printStringAt
       printStringAt( xPos, yPos, "<L>oad register", "LEFT" );

       // set x position
       xPos = 1; 

       // increase y position
       yPos += 2;

       // print clear register option
          // function: printStringAt
       printStringAt( xPos, yPos, "<C>lear register", "LEFT" );

       // set x position
       xPos = 1; 

       // increase y position
       yPos += 2;

       // print transfer z register option
          // function: printStringAt
       printStringAt( xPos, yPos, "<T>xfr Z register", "LEFT" );

    // specify math operations

       // set x position
       xPos = 1; 

       // increase y position
       yPos += 2;

       // print math operations
          // function: printStringAt
       printStringAt( xPos, yPos, "Math Operations", "LEFT" );

       // set x position
       xPos = 3; 

       // increase y position
       yPos += 2;

       // print add option
          // function: printStringAt
       printStringAt( xPos, yPos, "<A>dd: X + Y", "LEFT" );

       // set x position
       xPos = 3; 

       // increase y position
       yPos ++;

       // print subtract option
          // function: printStringAt
       printStringAt( xPos, yPos, "<S>ub: X - Y", "LEFT" );

       // set x position
       xPos = 3; 

       // increase y position
       yPos ++;

       // print multiply option
          // function: printStringAt
       printStringAt( xPos, yPos, "<M>ult: X * Y", "LEFT" );

       // set x position
       xPos = 3; 

       // increase y position
       yPos ++;

       // print divide option
          // function: printStringAt
       printStringAt( xPos, yPos, "<D>iv: X / Y", "LEFT" );

       // set x position
       xPos = 3; 

       // increase y position
       yPos ++;

       // print modulo option
          // function: printStringAt
       printStringAt( xPos, yPos, "M<O>D: X %m Y", "LEFT" );

       // set x position
       xPos = 3; 

       // increase y position
       yPos ++;

       // print exponent option
          // function: printStringAt
       printStringAt( xPos, yPos, "<P>ow: X ^ Y", "LEFT" );

       // set x position
       xPos = 1; 

       // increase y position
       yPos += 2;

       // print quit option
          // function: printStringAt
       printStringAt( xPos, yPos, "<Q>uit program", "LEFT" );

    // print status line

       // set x position
       xPos = 0; 

       // increase y position
       yPos += 2;

       // print underline
          // function: printStringAt
       printStringAt( xPos, yPos, "==================", "LEFT" );

       // set x position
       xPos = 1; 

       // increase y position
       yPos++;

       // print current base label
          // function: printStringAt
       printStringAt( xPos, yPos, "Current Base:", "LEFT" );

       // set x position
       xPos += 14;

       // print current base
          // function: printStringAt
       printIntAt( xPos, yPos, base, "LEFT" );

    // get user input
       // function: waitForInput
    return waitForInput( FIXED_WAIT );
   }

int setBase( int oldBase )
   {
    // initialize function/variables
    int xPos, yPos, base;

    // set color for base prompt
       // function: setColor
    setColor( PROMPT_FG_COLOR, PROMPT_BG_COLOR, BRIGHT );

    // clear box for base input

       // set x position
       xPos = 15; 

       // set y position
       yPos = 24;

       // print two spaces
          // function: printStringAt
       printStringAt( xPos, yPos, "  ", "LEFT" );

    // get base input
       // function: promptForIntAt
    base = promptForIntAt( xPos, yPos, "" );

    // check base input is greater than the minimum
    if( ( base >= MIN_BASE ) 
          // less than the maximum
          && ( base <= MAX_BASE ) 
               // and not equal to previous base
               && ( base != oldBase ) )
       {
        // return new base
        return base;
       }

    // otherwise return the old base
    return oldBase;
   }

void loadRegister( int rX[], int rY[], int base )
   {
   //initialize funtction and variables

   //prompt for x or y
     //move cursor

   // switch

     //case x

     //enter to register x

     //break
     
     //case y

     //enter to register y

     //break

   //default
   
     //print "cannot load" case

    // stub function
   }

void clearRegister( int rX[], int rY[], int rZ[], int base )
   {
   //initialize function

   //prompt for case

   //switch

     //case x

       //zeroRegister

       //output array

       //break

     //case y

       //zeroRegister

       //output array

       //break

     //default

       //print "cannot load" case

    // stub function
   }

bool transferZRegister( int registerX[], int registerY[], int registerZ[] )
   {
    // initialize function / variables
    int xPos = 2, yPos = 11;
    char regLtr;

    // get X or Y register

       // set color for register prompt
          // function: setColor
       setColor( PROMPT_FG_COLOR, PROMPT_BG_COLOR, BRIGHT );

       // prompt for register
          // function: printStringAt
       printStringAt( xPos, yPos, "To Register?:  ", "LEFT" );

       // set x position
       xPos += 14;

       // get register letter
          // function: promptForCharAt
       regLtr = promptForCharAt( xPos, yPos, "" );

    // load appropriate register
       // set x position
       xPos = 14;

       // print loading message
          // function: printStringAt
       printStringAt( xPos, yPos, "Loading Reg:", "RIGHT" );

       // set x position
       xPos += 2;

       // check register selection for X
       if( ( regLtr == 'x' ) || ( regLtr == 'X' ) )
          {
           // transfer register Z to register X
              // function: copyRegister
           copyRegister( registerX, registerZ );

           // clear register Z
              // function: zeroRegister
           zeroRegister( registerZ );
          }

       // otherwise check register selection for Y
       else if( ( regLtr == 'y' ) || ( regLtr == 'Y' ) )
          {
           // transfer register Z to register Y
              // function: copyRegister
           copyRegister( registerY, registerZ );

           // clear register Z
              // function: zeroRegister
           zeroRegister( registerZ );
          }

       // otherwise print error message
       else
          {
           // set x position
           xPos = 15;

           // display error
              // function: printStringAt
           printStringAt( xPos, yPos, "Cannot txfer: ", "RIGHT" );

           // hold screen to continue
              // function: waitForInput
           waitForInput( FIXED_WAIT );
          
           // return no success
           return false;
          }
    // return success
    return true;
   }

bool addRegisters( int registerX[], int registerY[], int registerZ[], int base )
   {
    // stub function
       // stub return
    return true;
   }

bool subtractRegisters( int registerX[], int registerY[], int registerZ[], int base )
   {
    // initialize function / variables
    int index, tempIndex, minuendLength, subtrahendLength;
    int minuend[ NUM_REG_DIGITS ];
    int difference[ NUM_REG_DIGITS ];
    bool borrowSuccess = true;

    // minuend will be modified by operation, make copy
       // function: copyRegister
    copyRegister( minuend, registerX );

    // clear difference register
       // function: zeroRegister
    zeroRegister( difference );

    // find length of X register
       // function: getRegValLength
    minuendLength = getRegValLength( minuend );

    // find length of Y register
       // function: getRegValLength
    subtrahendLength = getRegValLength( registerY );

    // check for subtrahend larger than minuend
    if( subtrahendLength > minuendLength )
       {
        // return false for underflow
        return false;
       }

    // subtract elements in registers
       // for each element in minuend register
       for( index = 0; index < minuendLength && borrowSuccess; index++ )
          {
           // check for need to borrow
           if( registerY[ index ] > minuend[ index ] ) 
              {
               // set borrow success to false
               borrowSuccess = false;

               // start temporary index at current index
               tempIndex = index;

               // increase current element by base amount
               minuend[ tempIndex ] += base;

               // move to next element
               tempIndex++;

               // as long as next element is 0
               while( ( tempIndex < minuendLength ) 
                      && ( minuend[ tempIndex ] == 0 ) )
                  {
                   // borrow from 0
                   minuend[ tempIndex ] = base - 1;

                   // go to next element
                   tempIndex++;
                  }

           // check there is a digit to borrow from
           if( tempIndex < minuendLength )
              {
               // borrow 1
               minuend[ tempIndex ] -= 1;

               // set borrow success to true
               borrowSuccess = true;
              }
          }

       // check for borrow success
       if( borrowSuccess )
          {
           // subtract elements
           difference[ index ] = minuend[ index ] - registerY[ index ];
          }
       }

    // save difference in register Z
       // function: copyRegister
    copyRegister( registerZ, difference );

    // return borrow success to indicate no underflow
    return borrowSuccess;
   }

bool multiplyRegisters( int registerX[], int registerY[], int registerZ[], int base )
   {
    // initialize function / variables
    int subtractOne[ NUM_REG_DIGITS ], tempMultiplier[ NUM_REG_DIGITS ];
    int product[ NUM_REG_DIGITS ];
    bool noOverflow = true;

    // create decrement register

       // clear subtract one register
          // function: zeroRegister
       zeroRegister( subtractOne );
       
       // set LSD to 1
       subtractOne[ 0 ] = 1;

    // clear product register
       // function: zeroRegister
    zeroRegister( product );

    // multiplier will be modified by operation, make copy
       // function: copyRegister
    copyRegister( tempMultiplier, registerY );
    
    // for register Y number of times
       // function: subtractRegisters
    while( subtractRegisters( tempMultiplier, subtractOne, tempMultiplier, base ) 
             && noOverflow )
       {
        // add register X to product register
           // function: addRegisters
        noOverflow = addRegisters( product, registerX, product, base );
       }

    // save product in register Z
       // function: copyRegister
    copyRegister( registerZ, product );

    // return add success to indicate overflow
    return noOverflow;
   }

bool divideRegisters( int registerX[], int registerY[], int registerZ[], int base )
   {
    // stub function
       // stub return
    return true;
   }

bool moduloRegisters( int registerX[], int registerY[], int registerZ[], int base )
   {
    // stub function
       // stub return
    return true;
   }

bool expPowerRegisters( int registerX[], int registerY[], int registerZ[], int base )
   {
    // stub function
       // stub return
    return true;
   }

void copyRegister( int regDestination[], int regSource[] )
   {
    // initialize function / variables
    int index;

    // for every element in the registers
    for( index = 0; index < NUM_REG_DIGITS; index++ )
       {
        // copy source element to destination element
        regDestination[ index ] = regSource[ index ];
       }
   }

int getRegValLength( int reg[] )
   {
    // initialize function / variables
    int index = NUM_REG_DIGITS - 1;

    // while there are digits and the current digit is clear
    while( ( index > 0 ) && ( reg[ index ] == 0 ) )
       {
        // move to previous index
        index--;
       }

    // return current index + 1
    return ( index + 1 );
   }

bool isZero( int reg[] )
   {
    // initialize function / variables
    int index = 0;

    // while there are digits
    while( index < NUM_REG_DIGITS )
       {
        // check if that digit is not zero
        if( reg[ index ] != 0 )
           {
            // return false for nonzero
            return false;
           }

        // move to next digit
        index++;
       }

    // return zero register
    return true;
   }


