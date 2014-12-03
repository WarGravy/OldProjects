// Header Files
#include <iostream>
#include <fstream>
#include "formatted_console_io_v16.h"

using namespace std;

// Global Constants
const int MAX = 100;
const int SCROLL_START_X = 23;
const int SCROLL_START_Y = 1;
const int BOTTOM_SCROLL_START_Y = 25;
const int ONE_LINE = 1;
const int TWO_LINES = 2;
const int THREE_LINES = 3;
const int SCRN_X_MIN = 7;
const int SCRN_Y_MIN = 4;
const int SCRN_X_MAX = 72;
const int SCRN_Y_MAX = 18;
const int NO_WAIT = -1;
const char MARKER_CHAR = '>';
const char SPACE = ' ';
const int MAX_HEIGHT = 30;
const int MAX_WIDTH = 80;
const char NULL_CHAR = '\0';
const int MAX_ROWS = 21;
const int MAX_COLS = 59;
const int MAX_ASTEROIDS = 20;
const int END_POSITION = 13;

// Function Prototypes

/*
Name: displayTitle
Process: displays dynamic title screen
Input: none
Output: none
Dependencies: I/O tools
Developer: Jay Thom
*/
void displayTitle(); // complete

/*
Name: displayMenu
Process: displays screen with menu choices (switchcase)
Input: none
Output: none
Dependencies: I/O tools
Developer: Joseph Gast
*/
char displayMenu();  // complete

/*
Name: runGame
Process: runs main game
Input: int value for game difficulty
Output: int score value
Dependencies: gameDifficulty
Developer: Jay Thom
*/
int runGame( char gameArray[MAX_ROWS][MAX_COLS], int &difficultyLevel );

/*
Name: move
Process: moves game cursor up and down
Input: x position, y position, x vector, y vector
Output: bool value to show movement
Dependencies: runGame
Developer: Jay Thom
*/
bool move( int &xPos, int &yPos, int xVect, int yVect );

/*
Name: displayExitScreen
Process: displays exit screen
Input: none
Output: none
Dependencies: I/O tools
Developer: Joseph Gast
*/
void displayExitScreen();  // complete

/*
Name: getPlayerName
Process: gets player name for high scores
Input: char array player name
Output: none
Dependencies: none
Developer: Joseph Gast
*/
void getPlayerName(char playerName[]);  // complete

/*
name: topScores (16)
process: display the results of the score file
input: the name array (char [][]), the score array (int []), and the number of scores (int)
output/display: the top score display
dependencies: I/O tools
Developer: Joseph Gast
*/
void displayTopScores () ;  // complete

/*
Name: scoreSwap
Process: swaps old high scores with new high scores using bubble sort
Input: none
Output: none
Dependencies: none
Developer: Joseph Gast
*/
void scoreSwap();  // complete

/*
Name: displayRules
Process: displays rules menu
Input: none
Output: none
Dependencies: I/O tools
Developer: Jay Thom
*/
void displayRules();  // complete

/*
Name: displayDiffMenu
Process: displays menu to allow user to choose difficulty setting
Input: none
Output: integer difficulty level
Dependencies: none
Developer: Jay Thom
*/
void displayDiffMenu( int &difficultyLevel );  // complete

/*
Name: moveArr
Process: moves the game array over one, and fixes the xy locations to the new
     	locations of the asteroids
Input: game level array, x and y locations of asteroids array, x location, y location
Output: moves game level
Dependencies: none
Developers: Jay Thom and Joseph Gast
*/
bool moveArray( char gameArray[MAX_ROWS][MAX_COLS] );

/*
Name:checkForScore
Process: checks the array for an x location of 0, then checks to see if the y
     	location of the asteroid and cursor match, if this is true it returns
     	true.
Input: array with asteroid locations, y cursor location
Return: bool value
Dependencies: runGame
Developer: Jay Thom
*/
bool checkForScore( int xyArrLoc[MAX_HEIGHT][MAX_WIDTH],int yCursorLoc);

/*
Name: initializeArr
Process: initializes each asteroid field for the different difficulties
Input: none
Output: none
Dependencies: runGame
Developer: Jay Thom
 */
void initializeArr (  char gameArray[MAX_ROWS][MAX_COLS], int &difficultyLevel );

void printArray( char gameArray[MAX_ROWS][MAX_COLS] );

// Main Program
int main()
   {
    // initialize variables
    bool continueProgram = false;
    char menuSelect;
    int difficultyLevel;
    char gameArray[MAX_ROWS][MAX_COLS];

    // start curses
       // function: startCurses
    startCurses();

    // display title screen
       // function: displayTitle
    displayTitle();

    // enter program switch loop
    do
       {
    // display menu screen
       // function: displayMenu
    displayMenu();
    menuSelect = waitForInput(0);
        switch( menuSelect )
          {
           // display game rules
              // switch case 1
           case '1':
           case 'R':
           case 'r':

              // function: displayRules
              displayRules();
              waitForInput( FIXED_WAIT );
              break;

           // display difficulty menu
              // switch case 2
           case '2':
           case 'D':
           case 'd':

             // function: gameDifficulty
              displayDiffMenu( difficultyLevel );
             // waitForInput( FIXED_WAIT );
              break;

           // start game
              // switch case 3
           case '3':
           case 'P':
           case 'p':

              // function: runGame
              runGame( gameArray, difficultyLevel );
              displayTopScores();
              break;

           // top scores
              // switch case 4
           case '4':
           case 'T':
           case 't':

              // function: displayTopScore
              displayTopScores();
              waitForInput( FIXED_WAIT );
              break;

           // exit program
              // switch case 5
           case '5':
           case 'Q':
           case 'q':

              // set bool variable to false
              continueProgram = true;
              break;

           default:
              break;
          }
       }
    // exit switchLoop
    while( !continueProgram );

    // display exit screen
       // function: displayExitScreen
    displayExitScreen();

    // end curses
      // function: endCurses
    endCurses();

    // end Program
       // return success
          // return 0
      return 0;
   }

// Function Implementations

void displayTitle()
   {
// initialize variables
   int xLoc = SCROLL_START_X, yLoc = SCROLL_START_Y, index = -1;
   bool continueProgram = true;
   char input, tempInput;

    // initialize arrIndex
    int arrIndex = 0;
    char letterArray[MAX][MAX];

    // initialize letterArray
    strcpy( letterArray[arrIndex], "    SSSS   TTTTTTTT    AA    RRRRR ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "   SSSSSS  TTTTTTTT   AAAA   RRRRRR");
    arrIndex++;
    strcpy( letterArray[arrIndex], "  SS    SS T  TT  T  AA  AA  RR  RR");
    arrIndex++;
    strcpy( letterArray[arrIndex], "  SS    SS    TT    AA   AA  RR  RR");
    arrIndex++;
    strcpy( letterArray[arrIndex], "  SS          TT    AA    AA RR  RR");
    arrIndex++;
    strcpy( letterArray[arrIndex], "   SSSS       TT    AA    AA RR  RR");
    arrIndex++;
    strcpy( letterArray[arrIndex], "    SSSS      TT    AA    AA RRRRR ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "       SS     TT    AAAAAAAA RRRR  ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "  SS    SS    TT    AAAAAAAA RRRRR ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "  SSSSSSS     TT    AA    AA RR  RR");
    arrIndex++;
    strcpy( letterArray[arrIndex], "   SSSSS      TT    AA    AA RR  RR");
    arrIndex++;
    strcpy( letterArray[arrIndex], "                                   ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "                                   ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "                                   ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM    AA    ZZZZZZZZ EEEEEEEE");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MMM   MMM   AAAA   ZZZZZZZZ EEEEEEEE");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MMMM MMMM  AA  AA        ZZ EE      ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM MMM MM AA    AA      ZZZ EE      ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM  M  MM AA    AA     ZZZ  EE      ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM AA    AA    ZZZ   EEEEE   ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM AA    AA   ZZZ    EEEEE   ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM AAAAAAAA  ZZZ     EE      ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM AAAAAAAA ZZZ      EE      ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM AA    AA ZZ       EE      ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM AA    AA ZZZZZZZZ EEEEEEEE");
    arrIndex++;
    strcpy( letterArray[arrIndex], "MM     MM AA    AA ZZZZZZZZ EEEEEEEE");
    arrIndex++;
    strcpy( letterArray[arrIndex], "                                    ");
    arrIndex++;
    strcpy( letterArray[arrIndex], "     Press Any Key To Continue      ");

   // set color and clear screen
     // function: setColor, clearScreen
   setColor( COLOR_YELLOW, COLOR_BLACK, true );
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

   // start the scrolling animation loop
     // function: waitForInput
     do
       {
        // initialize the loops
        index = 0;
        tempInput = waitForInput ( 0 );

        // start first half of loop (title to top of screen) 
        do
          {
           input = waitForInput( 0 );
           index++;
           clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y);
           xLoc = SCROLL_START_X;
           yLoc = (SCROLL_START_Y - index);

           for( arrIndex = 0; arrIndex < 28; arrIndex++ )
              {
               printStringAt( xLoc, yLoc, letterArray[arrIndex], "LEFT" );
               yLoc++;
              }
     
           // exit loop condition
           if (input != tempInput)
              {
               continueProgram = false;
              }
          }
        // end the loop
        while( index < 29 && continueProgram );

        // initialize index
        index = 0;

        // start second half of loop (title from bottom of screen to middle)
        do
          {
           input = waitForInput( 0 );
           index++;
           clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y);
           xLoc = SCROLL_START_X;
           yLoc = ( BOTTOM_SCROLL_START_Y - index);

           // print "STAR"
             // function: printStringAt

           for( arrIndex = 0; arrIndex < 28; arrIndex++ )
              {
               printStringAt( xLoc, yLoc, letterArray[arrIndex], "LEFT" );
               yLoc++;
              }
             
           // exit loop condition
           if (input != tempInput)
              {
               continueProgram = false;
              }
          }
        // end the loop
        while( index < 24 && continueProgram);

     // end the loop
    }
   while( continueProgram );
   }

char displayMenu()
   {
   // initiate variables
    char menuSelection;
    int xPosA = 27;
    int yPosA = 7;
    int yPosB = 10;

    // create background

       // set background color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLACK, true );

       // create outer boarder
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // create foreground color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, true );

       // create inner boarder
          // function: clearScreen
          clearScreen( SCRN_X_MIN, SCRN_Y_MIN, SCRN_X_MAX, SCRN_Y_MAX );

       // create menu selections 
          // function: printStringAt
          printStringAt( xPosA, yPosA, "MENU SELECTIONS", "LEFT" );
          yPosA++;
          printStringAt( xPosA, yPosA, "---------------", "LEFT" );
          printStringAt( xPosA, yPosB, "1. <R>ules", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "2. <D>ifficulty", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "3. <P>lay Game", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "4. <T>op Scores", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "5. <Q>uit Program", "LEFT" );
          yPosB++;

 //   return menuSelection;

    return menuSelection;
   }

void displayRules()
   {
    // initiate variable
    int xPosA = 22;
    int yPosA = 7;
    int yPosB = 10;

    // create background

       // set background color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLACK, true );

       // create outer boarder
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // create foreground color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, true );

       // create inner boarder
          // function: clearScreen
          clearScreen( SCRN_X_MIN, SCRN_Y_MIN, SCRN_X_MAX, SCRN_Y_MAX );

       // print rules on screen
          // printStringAt
          printStringAt( xPosA, yPosA, "RULES", "LEFT" );
          yPosA++;
          printStringAt( xPosA, yPosA, "-----", "LEFT" );
          printStringAt( xPosA, yPosB, "Tap up and down arrow keys to move your Cruiser.", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "Holding keys down will distort space/time!", "LEFT" );
          yPosB++;
          printStringAt(xPosA, yPosB, "Collide with asteroids to destroy them.", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "{Press ESC to terminate mission. ", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "Challenge yourself-increase the difficulty.", "LEFT" );
   }

void displayDiffMenu( int &difficultyLevel )
   {
    int xPosA = 27;
    int yPosA = 7;
    int yPosB = 10;
    char diffSelect;
    

    // create background

       // set background color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLACK, true );

       // create outer boarder
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // create foreground color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, true );

       // create inner boarder
          // function: clearScreen
          clearScreen( SCRN_X_MIN, SCRN_Y_MIN, SCRN_X_MAX, SCRN_Y_MAX );

       // display difficulty rank on screen
          // function print string at
          printStringAt( xPosA, yPosA, "DIFFICULTY RANK", "LEFT" );
          yPosA++;
          printStringAt( xPosA, yPosA, "---------------", "LEFT" );
          printStringAt( xPosA, yPosB, "1. Master", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "2. Knight", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "3. Padawan", "LEFT" );
          yPosB++;
          printStringAt( xPosA, yPosB, "Enter Selection: ","LEFT" );
           diffSelect = waitForInput( NO_WAIT);

    switch( diffSelect )
      {

       case '1':
          difficultyLevel = 1;
          break;


       case '2':
          difficultyLevel = 2;
          break;


       case '3':
          difficultyLevel = 3;
          break;
      }
   }

int runGame( char gameArray[MAX_ROWS][MAX_COLS], int &difficultyLevel )
   {
    // initialize program / function
    
       // initialize variables
       int userInput, xLoc, yLoc, xVector, yVector;
       bool continueProgram = true;
  //     char gameArr[MAX_ROWS][MAX_COLS];

       // initialize locations and movement vectors
       xLoc = 24;
       yLoc = SCRN_MAX_Y / 2;
       xVector = 0; yVector = 0;
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
       clearScreen( 0, 0, 79, 21 );
       setColor( COLOR_RED, COLOR_BLUE, SET_BRIGHT );
       printStringAt( 0, 22, "========================================", "LEFT" );
       printStringAt( 40, 22,"========================================", "LEFT" );
       printStringAt( 0, 23, " Press Up or Down Arrow to Move", "LEFT" );
       printStringAt( 79, 23, "Press ESC to Quit Game ", "RIGHT" );
       printStringAt( 33, 24, "Current Score: ", "LEFT" );
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
       clearScreen( 10, 0, 69, 21 );
       initializeArr ( gameArray, difficultyLevel );
   // start loop
    do
       {
        printArray( gameArray );

        moveArray( gameArray );

        printCharAt( xLoc, yLoc, MARKER_CHAR );

        // get an input key, waiting for user input
        userInput = waitForInput( 0 );

        // if user input, set direction, otherwise ignore
        switch( userInput )
           {
            // set up a case for moving up with the up arrow key
            case KB_UP_ARROW:
               xVector = 0;
               yVector = -1;
               break;

            // set up a case for moving down with the down arrow key
            case KB_DOWN_ARROW:
               xVector = 0;
               yVector = 1;
               break;
            // set up a case for ending the program with the ESC key
            case KB_ESCAPE:
               continueProgram = false;
               break;

            case KB_RIGHT_ARROW:
               xVector = 0;
               yVector = 0;
               break;

            case KB_LEFT_ARROW:
               xVector = 0;
               yVector = 0;
               break;

            default:
               xVector = 0;
               yVector = 0;
               break;
             
           }

        // move the character
        move( xLoc, yLoc, xVector, yVector );

       }
    while( continueProgram );

    // shut down program
       // return success
       return 0;
   }

bool move( int &xPos, int &yPos, int xVect, int yVect )
   {
    // initialize function/variables
    bool moved = false;
    int oldY = yPos;

    // test for out of bounds
    if( ( yVect != 0 )
               && ( yPos + yVect >= SCRN_MIN_Y )
                    && ( yPos + yVect <= 21 ) )
       {
        // cover up the old marker
        printCharAt( xPos, oldY, SPACE );

        // reset the y position
        yPos = yPos + yVect;

        // set the moved flag to indicate success
        moved = true;
       }

    // print the marker at the specified location
    printCharAt( xPos, yPos, MARKER_CHAR );

    // return successful move
    return moved;
   }

void displayExitScreen()
   {
    // apply background

       // set background color
         // function: setColor
         setColor( COLOR_WHITE, COLOR_BLACK, true );

       // create outer boarder
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // create foreground color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, true );

       // create inner boarder
          // function: clearScreen
          clearScreen( SCRN_X_MIN, SCRN_Y_MIN, SCRN_X_MAX, SCRN_Y_MAX );

    // print exit message
       // function: printStringAt
       printStringAt(25, 10, "Thank you for playing!", "LEFT");

    // pause screen
       // function: waitForInput
       waitForInput(FIXED_WAIT);
   }

void getPlayerName(char playerName[])
   {
    // create background

       // set background color
         // function: setColor
         setColor( COLOR_WHITE, COLOR_BLACK, true );

       // create outer boarder
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // create foreground color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, true );

       // create inner boarder
          // function: clearScreen
          clearScreen( SCRN_X_MIN, SCRN_Y_MIN, SCRN_X_MAX, SCRN_Y_MAX );

    // print prompt for name
       // function: printStringAt
    printStringAt( 37, 7, "ENTER YOUR NAME", "LEFT" );
    printStringAt( 37, 8, "---------------", "LEFT" );

    // get name from user
       // function: promlptForStringAt
    promptForStringAt( 37, 9, "",  playerName);

   }

void displayTopScores()
   {
    // initiate variables
    ifstream fin;
    int score, xLocLeft, xLocRight, yLoc;
    char dummy;
    char name[100];
    fin.clear();

    // open file
       //function: fin
    fin.open("Scores.txt");

    // create background

       // set background color
         // function: setColor
         setColor( COLOR_WHITE, COLOR_BLACK, true );

       // create outer boarder
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // create foreground color
          // function: setColor
          setColor( COLOR_WHITE, COLOR_BLUE, true );

       // create inner boarder
          // function: clearScreen
          clearScreen( SCRN_X_MIN, SCRN_Y_MIN, SCRN_X_MAX, SCRN_Y_MAX );

    // define location variable values
    xLocLeft = 25;
    xLocRight = 45;
    yLoc = 5;

    // print menu titles
       // printStringAt
    printStringAt( xLocLeft, yLoc, "Name", "LEFT" );
    printStringAt( xLocRight, yLoc, "Score", "LEFT" );
    yLoc++;
    printStringAt( xLocLeft, yLoc, "----", "LEFT" );
    printStringAt( xLocRight, yLoc, "-----", "LEFT" );

    // start name printing loop
    while(fin.good())
       {

       // increase y index
       yLoc++;

       // intake score integer
          // function: fin
          fin >> score;

       // intake dummy character
          // function: fin
       fin >> dummy;

       // intake player name string
          // function: fin
       fin >> name;

       // print current player score
          // function: printIntAt
          printIntAt(xLocRight, yLoc, score, "LEFT");

       // print current player score
          // function: printStringAt
       printStringAt(xLocLeft, yLoc, name, "LEFT:");
       }

   }

void scoreSwap()
   {


    // initiate variables
       int scores[100];
       int tempInt, length, tempIndex;
       char names[100][100];
       char tempChar[100];
       char dummy;
       bool swapped;
       ifstream fin;
       ofstream fout;

       fin.clear();
       fin.open("Scores.txt");

      length = 0;
      while(fin.good())
         {
            // intake score integer
          // function: fin
          fin >> scores[length];

       // intake dummy character
          // function: fin
       fin >> dummy;

       // intake player name string
          // function: fin
       fin >> names[length];    

       // adjust variables
       length++;
         }

    // close fule
       // function: fin
       fin.close();

      swapped = true;
      // initiate outer bubble sort loop
      while (swapped) 
         {
          // adjust booleon variable
          swapped = false;

          // initiate inner bubble sort loop
          for (int index = 0; index < (length - 1); index++)
              {
               // determine if a swap must occur
               if (scores[index] < scores[index + 1])
                  {

                  // store first value in temperary variable
                  tempIndex = 0;
               
                  // while loop: run until null character
                  while( names[index][tempIndex] != NULL_CHAR)
                     {
                        // copy the temperary character to the current array character
                        tempChar[tempIndex] = names[index][tempIndex];
                        // increment index 1
                        tempIndex++;
                     }
                     // end loop

                     // add null char to current array position
                     tempChar[tempIndex] = NULL_CHAR;
                     // set tomperary integer to first score value
                     tempInt = scores[index];
                      


                  // store second value in first value location

                  // zero index 1
                  tempIndex = 0;

                  // while loop: run until null character
                  while( names[index + 1][tempIndex] != NULL_CHAR)
                     {
                     // save position 1 character in position 2
                     names[index][tempIndex] = names[index + 1][tempIndex];
                     // increment index1
                     tempIndex++;
                     }
                     // end loop

                     names[index][tempIndex] = NULL_CHAR;
                     // add null char to last value

                  scores[index] = scores[index + 1];
                  // set score 1 equal to score 2


                  //store temp value in second value location
                  tempIndex = 0;

                  // while loop: run until null character
                  while( tempChar[tempIndex] != NULL_CHAR)
                     {
                     // set array 1 character equal to temp character
                     names[index + 1][tempIndex] = tempChar[tempIndex];
 
                     // increment index 1
                     tempIndex++;
                     }
                  // end loop
       
                  // add null character at the end of array possition
                   names[index + 1][tempIndex] = NULL_CHAR;

                  // set score value 2 equal to temperary character
                  scores[index + 1] = tempInt;


                  // aknowledge that a swap has occured
                  swapped = true;

                  }

            }

      }

   // clear file
      // function : fout
      fout.clear();

   // open score file
      // function fout
      fout.open("Scores.txt");

   // reset length and index1 variables
      length = 10;
      tempIndex = 0;

   // while loop: count down length of array
      while (length > 0)
         {
      // output info to file
         // function: fout
          fout << scores[tempIndex] << ';' << names[tempIndex]<< endl;
      // indcrement temperary index
          tempIndex++;
 
      // increment length - 1
          length--;
          }
      // close file
         // function fout
      fout.close();
   }

void initializeArr (  char gameArr[MAX_ROWS][MAX_COLS], int &difficultyLevel )
   {
    // intialize variables
    int randomX = 0, randomY = 0;
    int rowIndex, colIndex, index;

    // initialize random number generator
       // function: srand
    srand ( time(NULL) );

    // initialize array to all 'space'
    for( rowIndex = 0; rowIndex < MAX_ROWS; rowIndex++ )
       {
        for( colIndex = 0; colIndex < MAX_COLS; colIndex++ )
           {
            gameArr[rowIndex][colIndex] = SPACE;
           }
       }

    for( index = 0; index < MAX_ASTEROIDS; index++ )
       {
        randomX = rand() % 30 + 29;
        randomY = rand() % MAX_ROWS;
        gameArr[randomY][randomX] = '#';
       }

   }

bool checkForScore( int xyArrLoc[MAX_HEIGHT][MAX_WIDTH],int yCursorLoc)
   {
    //initialize variables

    //for loop( col aka width = 0; width < size; col++)

    //check if the xyArrLoc[0][col] is equal to x loc of cursor
 	 
    //check if xyArrLoc[1][col] is equal to the cursor y location

  	//return false
  	return 0; // teporary return value
   }

bool moveArray( char gameArray[MAX_ROWS][MAX_COLS] )
   {
   int rowIndex;
   int colIndex;
   rowIndex = 0;
   colIndex = 10;

         while( rowIndex < MAX_ROWS)
            {
             while (colIndex < 70)
                {
                gameArray[rowIndex][colIndex] = gameArray[rowIndex][colIndex + 1];
                colIndex++;
                }
             rowIndex++;
             colIndex = 10;
            }
    rowIndex = 0;

    while( rowIndex < MAX_ROWS)
       {
        gameArray[rowIndex][colIndex] = SPACE;
        rowIndex++;
       }



return 0;
   }

void printArray( char gameArray[MAX_ROWS][MAX_COLS] )
   {
   int index;
   int rowIndex;
   int colIndex;
   int xPrint = 11;
   int yPrint = 0;
   rowIndex = 0;
   colIndex = 0;

             while( rowIndex < MAX_ROWS)
            {
             while (colIndex < 70)
                {
                if( gameArray[rowIndex][colIndex] == '#')
                    {
                    printCharAt(colIndex, rowIndex, gameArray[rowIndex][colIndex]);
                    printCharAt(colIndex + 1, rowIndex, gameArray[rowIndex][colIndex + 1]);
                    for( index = 0; index < 21; index++ )
                       {
                        printCharAt( xPrint, yPrint, SPACE );
                        yPrint++;
                       }
                    }

                colIndex++;
                }
             rowIndex++;
             colIndex = 0;
            }

   }

