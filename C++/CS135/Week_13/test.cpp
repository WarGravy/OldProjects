//test for playgame function
//possible dependencies: functions: move, moveArray, checkForScore

#include <iostream>
#include <fstream>
#include "formatted_console_io_v16.h"
using namespace std;

const char MARKER_CHAR = ' ';
const char NEW_CHAR = '*';

bool move( int &xPos, int &yPos, int xVect, int yVect );

int main()
  {
// initialize variables///////////////////////////////
       int userInput, xLoc, yLoc, xVector, yVector;
       bool continueProgram = true;
       int cycleTime = 1;
       int difficulty = 3;
       double cycle;
       double endGame = 50.0;

       // initialize locations and movement vectors
       xLoc = SCRN_MAX_X / 2;
       yLoc = SCRN_MAX_Y / 2;
       xVector = 0; yVector = 0;
       userInput = -1;

       // initialize curses
       startCurses();
       setColor( COLOR_RED, COLOR_BLACK, SET_BRIGHT );

//MASTER LOOP//////////////////////////////////////
    for(cycle = 0; continueProgram; cycle++)
       {
       
        // get an input key, waiting for user input
        userInput = waitForInput( cycleTime );
        
        // if user input, set direction, otherwise ignore
        switch( userInput )
           {
            case -1:
            xVector = 0;
            break;
           // set up a case for moving up with the up arrow key
            case KB_UP_ARROW:
              yVector = -1;
              break;

            // set up a case for moving down with the down arrow key
            case KB_DOWN_ARROW:
              yVector = 1;
              break;

            // set up a case for ending the program with the ESC key
            case KB_ESCAPE:
            endCurses();
            return 1;
            break;
           }
        // move the character
        move( xLoc, yLoc, xVector, yVector );
//-------------------------------------------------------------------------
/*
NOTE: thinking of using a loop that checks an array that holds all the current 
locations of the asteroids. The array will change with the move array function.
One 2d array will be preferrable, where this loop checks if the colIndex is = 
the x location of the cursor, if this is true then it will check if the y location 
is equal to the second row, same colIndex aka y locations of the asteroid, if both
are true it changes a bool variable for the loop to false so it ends the loop.
The loop will end if the bool variable is false or if the colIndex is < the size
of the array width wise.

It is possible that if this code gets to large, we can simply have a separate 
bool function that does all of this and returns either true or false if the cursor
is at the x and y location.

For all of this to work, our x and y location of the cursor would need to be 
pass by reference via the move function.
*/
        //if cursor is at the same location as an asteroid calculate score
          //{
          //score += 19/(difficulty * difficulty);
          //}
//---------------------------------------------------------------------------

        //move the level(switch for difficulty)
        switch(difficulty)
           //START } for difficulty switch
           {
          //case hard move every 1 cycle
          case 1:
            //move level
              //function: move array
          break;
          //case moderate move every 2 cycles
          case 2:
            
              if( (cycle / 2.0) == 0.0 )
                {
             //move level every 2 cycles
              //function: move array
                }
              else
                {
                // do nothing
                }
           break;
          //case easy move every three cycles
          case 3:
            if( (cycle / 3.0) == 0.0)
              {
            //move level every 3 cycles
              //function: move array
              }
            else
              {
              //do nothing   
              }
           break;
           //END } for difficulty switch
           }
          //check if array has passed and game is finished.
          if( cycle == endGame)
           {
           //set continue program to false
           continueProgram = false;
           }
       }
//END OF MASTER LOOP

//end of level////////////////////////////////////////////

 // check if score is a high score
    //function: checkIfHighScore

    //if true

    //{

      //clear screen and set color
       
      //prompt for username
        //function: void promptForStringAt( int xPos, int yPos,
                  //const string &promptString, char resultString[] );


      //set new score
        //function: scoring

    //}

    //jump to top score menu
      //function: topScoreMenu

// stub////////////////////////////////////////////
       endCurses(); 
       return 0;
}

bool move( int &xPos, int &yPos, int xVect, int yVect )
   {
    // initialize function/variables
    bool moved = false;
    int oldX = xPos, oldY = yPos;

    // if x vector is live, test for acceptable movement limits
    if( ( xVect != 0 ) // is meant to move
          && ( xPos + xVect >= SCRN_MIN_X ) // won't go off left side of screen 
               && ( xPos + xVect <= SCRN_MAX_X )  ) // won't go off right side of screen
       {
        // cover up the old marker
        printCharAt( oldX, oldY, MARKER_CHAR );

        // reset the x position
        xPos = xPos + xVect;

        // set moved flag to indicate success
        moved = true;
       }

    // if y vector is live, test for acceptable movement limits
    else if( ( yVect != 0 ) // is meant to move
               && ( yPos + yVect >= SCRN_MIN_Y ) // won't go off top of screen
                    && ( yPos + yVect <= SCRN_MAX_Y ) ) // won't go off bottom of screen
       {
        // cover up the old marker
        printCharAt( oldX, oldY, MARKER_CHAR );

        // reset the y position
        yPos = yPos + yVect;

        // set the moved flag to indicate success
        moved = true;
       }

    // print the marker at the specified location
    printCharAt( xPos, yPos, NEW_CHAR );

    // return successful move
    return moved;
   }
