///////////////////////////////////////////////////////////////////////////
/*
    Program:             digits_v01.h
    Author:              Michael Leverington
    Update By:           n/a
    Description:         digit I/O printing resource
  
    Program Written:     03/18/2009
    Most Recent Update:  02/31/2010 - 3:30 p.m.
*/
///////////////////////////////////////////////////////////////////////////
/*
   INSTRUCTIONS:
    
   Function operations are specified below.

   END OF INSTRUCTIONS
*/

// Header files
#include "formatted_console_io_V16.h" // for advanced console functions

using namespace std;

// Global Constants
//
   const int MAX_SEGMENT_COORDS = 80;
   const int BAD_CHAR_INPUT = -1;

   const char SPACE = ' ';
//
// Global Function Prototypes
//
    // Name: printDigit
    // Input: x and y location, upper left (int), digit value (int)
    // Output (to screen): prints digit at x, y location
    // Dependencies: I/O operations, printSegments
    // Process: prints digit at X, Y location;
    void printDigit( int xLoc, int yLoc, int digit, short digitColor );

    // Name: printSegments
    // Input: x and y location (int), specified segments (char array)
    // Output (to screen): prints segments at x, y location (upper left)
    // Dependencies: I/O operations, charToInt
    // Process: prints segments at x, y location
    void printSegments( int xLoc, int yLoc, char segmentList[], short digitColor );

    // Name: charToInt (utility)
    // Input: digit character (char)
    // Output: integer value
    // Dependencies: none
    // Process: evaluates character for value (0-9),
    //          returns decimal value
    int charToInt( char val );
//
// Supporting function implementation

void printDigit( int xLoc, int yLoc, int digit, short digitColor )
   {
    // initialize function/variables
    char segList[ MAX_SEGMENT_COORDS ];

    // set segments for each digit/letter
    switch( digit )
       {
        case 0:
           strcpy( segList, 
                   "1,0;2,0;0,1;3,1;0,2;3,2;0,3;3,3;0,4;3,4;0,5;3,5;1,6;2,6;" );
           break;

        case 1:
           strcpy( segList, "2,0;1,1;2,1;2,2;2,3;2,4;2,5;1,6;2,6;3,6;" );
           break;

        case 2:
           strcpy( segList, 
                           "1,0;2,0;0,1;3,1;3,2;2,3;1,4;0,5;0,6;1,6;2,6;3,6;" );
           break;

        case 3:
           strcpy( segList, 
                           "1,0;2,0;0,1;3,1;3,2;1,3;2,3;3,4;0,5;3,5;1,6;2,6;" );
           break;

        case 4:
           strcpy( segList, 
                       "0,0;3,0;0,1;3,1;0,2;3,2;0,3;1,3;2,3;3,3;3,4;3,5;3,6;" );
           break;
        case 5:
           strcpy( segList, 
                           "1,0;2,0;3,0;0,1;0,2;1,3;2,3;3,4;0,5;3,5;1,6;2,6;" );
           break;

        case 6:
           strcpy( segList, 
                           "1,0;2,0;0,1;3,1;0,2;1,3;2,3;0,4;3,4;0,5;3,5;1,6;2,6;" );
           break;

        case 7:
           strcpy( segList, "0,0;1,0;2,0;3,0;3,1;3,2;2,3;1,4;0,5;0,6;" );
           break;

        case 8:
           strcpy( segList, 
                   "1,0;2,0;0,1;3,1;0,2;3,2;1,3;2,3;0,4;3,4;0,5;3,5;1,6;2,6;" );
           break;

        case 9:
           strcpy( segList, 
                   "1,0,2,0;0,1;3,1;0,2;3,2;1,3;2,3;3,3;3,4;0,5;3,5;1,6;2,6;" );
           break;

        default:  // if no numbers, print dash
           strcpy( segList, "2,2;1,3;0,4;" );
           break;
       }

    // print the digit/letter segments
    printSegments( xLoc, yLoc, segList, digitColor );
   }


void printSegments( int xLoc, int yLoc, char segmentList[], short digitColor )
   {
    // initialize function/variables
    int xPos, yPos, stringLength, index = 0;

    // get length of string
    stringLength = strlen( segmentList );

    // set digit color
    setColor( COLOR_WHITE, digitColor, SET_BRIGHT );

    // loop through string of x,y pairs, painting segments
    while( index < stringLength )
       {
        // calculate x position with offset
        xPos = xLoc + charToInt( segmentList[ index ] );

        index += 2; // skip comma

        // calculate y position with offset
        yPos = yLoc + charToInt( segmentList[ index ] );

        // paint the segment
        printCharAt( xPos, yPos, SPACE );

        index += 2; // skip semicolon
       }
   }

int charToInt( char val )
   {
    // if character values are between 0-9, set to number
    if( ( val >= '0' ) && ( val <= '9' ) )
       {
        return int( val - '0' );
       }

    // in case of bad input, return informational constant
    return BAD_CHAR_INPUT;
   }


/*
int main()
   {
    startCurses();

    setColor( COLOR_GREEN, COLOR_WHITE, SET_BRIGHT );

    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    printDigit( 5, 5, '3', COLOR_CYAN );

    waitForInput( FIXED_WAIT );

    endCurses();    
    return 0;
   }
*/

