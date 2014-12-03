//////////////////////////include files////////////////////////////

#include <iostream>
#include <fstream>
#include "formatted_console_io_v16.h"
using namespace std;

//////////////////////////global constants////////////////////////////////////
const int MAX_HEIGHT = 100;
const int MAX_WIDTH = 100;
const char NEWLINE_CHAR = '\n';
const int NO_WAIT = -1;
const int MENU_MIN_X = 7;
const int MENU_MIN_Y = 4;
const int MENU_MAX_X = 72;
const int MENU_MAX_Y = 18;
const char NULL_CHAR = '\0';
const int CURSOR_X_LOC = MENU_MIN_X;
//stub constant, this will be implemented in the initialize array function
const int XY_LOC_ARR_MAX = 20;



/////////////////////function prototypes ///////////////////////////////

/*
written by: Chris Scott
Name: splashScreen
Process: clears screen, displays dynamic intro screen, then clears the screen
         to the main menu when a key is pressed
Output: dynamic splash screen to introduce game
Dependencies: none
*/
void splashScreen ();

/*
written by: Chris Scott
Name: mainMenu
Process: clears the screen then displays the switch options for gameplay
Output: main menu screen with switch options to navigate program
Dependencies: none
*/
char mainMenu();


/*
written by: Zachary Carlson
Name: rulesMenu
Process: clears screen, outputs rules, then clears screen when indicated
         waiting for input
Output: the rules on the screen.
Dependencies:clearScreen, setColor, waitForInput, printCharAt
*/
void rulesMenu ();

/*
written by: Chris Scott
Name: diffMenu
Process: clears the screen and gives three options to choose difficulty
Output: 3 options for different difficulties
Dependencies:clearScreen, setColor, waitForInput, printCharAt
*/
void diffMenu( int &difficultySet );

/*
written by: Chris Scott and Zachary Carlson
Name: startGame
Process: clears the screen, initializes array and begins the game at the selected
        difficulty. it then progresses through the game using a master loop.
        once that loop finished, it checks if the score is a high score, and
        kicks the user to the top score menu.
Output: asteroid array that moves across the screen while user determines cursor
Dependencies: clearScreen, setColor, waitForInput, initializeArray, moveToXY,
            moveCursor, checkForScore, moveArr, checkIfHighScore, promptForString,
            scoring, topScoreMenu
*/
void startGame ( int difficultySet );


/*
written by: Zachary Carlson
Name: topScoreMenu
Process: clears screen, opens and finds top 5 scores outputs the 5 top, closes
        file then clears screen when indicated by waiting for input in the
        main program
Output: the 5 top scores to screen.
Input: filename
Dependencies:clearScreen, setColor, printStringAt, readScoringAndOutput
*/
void topScoreMenu( char fileName[] );

/*
written by: Zachary Carlson
Name: readScoringAndOutput
Process: stores names of the top five scores and scores of each line into an array
then it outputs the arrays to the proper x and y locations.NOTE: one array for the top scores
and individual arrays for the names.
Output: the 5 top scores to screen.
Input: x start location, y start location, ifstream
Dependencies:printStringAt
*/
void readScoringAndOutput ( int xLoc, int yLoc, ifstream &fin);

/*
written by: Chris Scott
Name: quitScreen
Process: clears screen, displays large message telling user goodbye
Output: large text message to user
Dependencies:clearScreen, setColor, waitForInput, printCharAt
*/
void quitScreen( );


/*
written by: Zachary Carlson
Name: scoring
Process: accepts a highScore, accepts a filename, and loads the scores in the file
        into an array. Then if uses write highscore.
Output: rewrites the file with the correct top 5 scores
input: filename and highscore and username
Dependencies:writeHighScore
*/
void scoring(char fileName[] , int highscore, char username[]);

/*
written by: Zachary Carlson
Name: writeHighScore
Process: accepts new highScore, accepts a filename, accepts username, accepts
       an array with the top 5 scores then reorganizes the top five scores
Output: rewrites the file with the correct top 5 scores
input: filename and highscore and username
Dependencies:none
*/
void writeHighScore(char fileName[] , int highscore, char username[], int scores[]);

/*
Written by: Zachary Carlson
Name: checkIfHighScore
Process:Checks to see if the score is higher than one of the top five scores
Output/Returned: true or false
Input: the score from the latest game
Dependencies: This will be used in the playGame function.
*/
bool checkIfHighScore(char fileName[], int score);


/*
Written by: Chris Scott
Name: initializeArr
Process: initializes each asteroid field for the different difficulties
Output/Returned: none
Input: none
Dependencies: This will be used in the playGame function.
*/
void initializeArr ( char gameArr[MAX_HEIGHT][MAX_WIDTH], int difficulty, int xyArrLoc[MAX_HEIGHT][MAX_WIDTH]);


/*
Written by Zachary Carlson
Name:checkForScore
Process: checks the array for an x location of 0, then checks to see if the y
       location of the asteroid and cursor match, if this is true it returns
       true.
Input: array with asteroid locations, y cursor location
Return: true or false
Dependencies: used in startGame function
*/
bool checkForScore( int xyArrLoc[MAX_HEIGHT][MAX_WIDTH],int yCursorLoc);

/*
Written by Zachary Carlson and Chris Scott
Name: moveCursor
Process: covers the origial location, moves the cursor either up or down, and
       prints a new cursor
Input: pass by reference x and y locations of current cursor, and how much the
     y location needs to move by, aka -1 moves the cursor up, and 1 moves it
     down.
Output/Return: none
*/
void moveCursor( int &xPos, int &yPos, int yVect );

/*
Written by Zachary Carlson and Chris Scott
Name: moveArr
Process: moves the game array over one, and fixes the xy locations to the new
       locations of the asteroids
Input: game level array
Input: x and y locations of asteroids array
Input: x location
Input: y location
Output/Return: moves game level
*/
void moveArr( char gameArr[MAX_HEIGHT][MAX_WIDTH], int xyArrLoc[MAX_HEIGHT][MAX_WIDTH],
            int &xLoc, int &yLoc );



////////////////////////main program////////////////////////////////
int main()
{
//initialize function / variables
bool quit = false;
int response;
int difficultySet;
char topScoreFile[MAX_WIDTH] = "topscores.txt";
  

  //star curses
    //function: startCurses
    startCurses();
  
  //display splash intro
    //function: splashScreen
    splashScreen();

  // run program
     do
       {
  //display menu
  //function: mainMenu
        response = mainMenu( );
  
      //switch
        switch( response )
          {      
            //case R or r
            case 'r':
            case 'R':
            case '1':
                //rules
                  //function: rulesMenu
                  rulesMenu();
                  waitForInput( FIXED_WAIT );
     
            //break
            break;

      
            //case D or d
            case 'd':
            case 'D':
            case '2':
                //difficulty
                  //function: diffMenu
                  diffMenu( difficultySet );

            //break
            break;
      
            //case p or P
            case 'p':
            case 'P':
            case '3':
                //play game
                  //function: startGame
                  startGame(difficultySet);
                  waitForInput( FIXED_WAIT );
      
            //break
            break;
      
            //case t or T
            case 't':
            case 'T':
            case '4':
                //top scores
                  //function: topScoreMenu
                  topScoreMenu(topScoreFile);
                  waitForInput( FIXED_WAIT );
      
            //break
            break;
            
            //case q or Q
            case 'q':
            case 'Q':
            case '5':
                //quit screen
                  quit = true;
      
            //break
            break;
            

           }

      }
     // until user chooses quit
     while( !quit );

  // shut down program
      //function: quitScreen
      quitScreen();

  // wait for user input
    // function: waitForInput
    waitForInput( FIXED_WAIT );


     // shut down curses
        // function: endCurses
     endCurses();

     // return success
     return 0;
}

//////////// Function Implementation ////////////////////////

void splashScreen()
{
// initialize variables
  int xLoc, yLoc;
  bool showSplash = true;
  char hold, inputHold;
  int letterIndex = 0;
  char starArr[MAX_HEIGHT][MAX_WIDTH];
  char mazeArr[MAX_HEIGHT][MAX_WIDTH];
  char bgArr[MAX_HEIGHT][MAX_WIDTH];

  // set color/clear screen
    // function: setColor, clearScreen
  setColor( COLOR_RED, COLOR_BLACK, SET_BRIGHT );
  clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );


   // initialize starArray
   strcpy( starArr[letterIndex], "  SSSS   TTTTTTTT    AA    RRRRR " );
   letterIndex++;
   strcpy( starArr[letterIndex], " SSSSSS  TTTTTTTT   AAAA   RRRRRR" );
   letterIndex++;
   strcpy( starArr[letterIndex], "SS    SS T  TT  T  AA  AA  RR  RR" );
   letterIndex++;
   strcpy( starArr[letterIndex], "SS    SS    TT    AA   AA  RR  RR" );
   letterIndex++;
   strcpy( starArr[letterIndex], "SS          TT    AA    AA RR  RR" );
   letterIndex++;
   strcpy( starArr[letterIndex], " SSSS       TT    AA    AA RR  RR" );
   letterIndex++;
   strcpy( starArr[letterIndex], "  SSSS      TT    AA    AA RRRRR " );
   letterIndex++;
   strcpy( starArr[letterIndex], "     SS     TT    AAAAAAAA RRRR  " );
   letterIndex++;
   strcpy( starArr[letterIndex], "      SS    TT    AAAAAAAA RRRRR  ");
   letterIndex++;
   strcpy( starArr[letterIndex], "SSSSSSS     TT    AA    AA RR  RR" );
   letterIndex++;
   strcpy( starArr[letterIndex], " SSSS       TT    AA    AA RR  RR");
   letterIndex++;
   strcpy( starArr[letterIndex], "  Press Any Key To Continue. . . " );

  // strcpy( wordArr[letterIndex], );
   //letterIndex++;
   
   letterIndex = 0;
   
   // initialize mazeArray
   strcpy( mazeArr[letterIndex], "MM     MM    AA    ZZZZZZZZ EEEEEEE" );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MMM   MMM   AAAA   ZZZZZZZZ EEEEEEE" );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MMMM MMMM  AA  AA        ZZ EE     " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM MMM MM AA    AA      ZZZ EE     " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM  M  MM AA    AA     ZZZ  EE     " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM     MM AA    AA    ZZZ   EEEEE  " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM     MM AA    AA   ZZZ    EEEEE  " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM     MM AAAAAAAA  ZZZ     EE     " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM     MM AAAAAAAA ZZZ      EE     " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM     MM AA    AA ZZ       EE     " );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "MM     MM AA    AA ZZZZZZZZ EEEEEEE" );
   letterIndex++;
   strcpy( mazeArr[letterIndex], "  Press Any Key To Continue. . . " );

   letterIndex = 0;

   // initialize bg array
   strcpy( bgArr[letterIndex],"*                                   *                    *                     " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"     *                 *                                            *          " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                             *                                                 " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                                           *                                  *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"        *                                         *            *               " );
   // left side stars
   letterIndex++;
   strcpy( bgArr[letterIndex],"             *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"   *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                      *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"         *");
   letterIndex++;
   strcpy( bgArr[letterIndex]," " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"  *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"  " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"             *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                     *" );
   letterIndex++;
   strcpy( bgArr[letterIndex]," *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"             *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"   *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                      *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"         *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"*                                   *                    *                     " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"        *                                         *            *               " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                                           *                                  *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                             *                                                 " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"     *                 *                                            *          " );
   // right side stars
   letterIndex++;
   strcpy( bgArr[letterIndex],"             *");
   letterIndex++;
   strcpy( bgArr[letterIndex],"   *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                      *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"         *" );
   letterIndex++;
   strcpy( bgArr[letterIndex]," " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"  *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"  " );
   letterIndex++;
   strcpy( bgArr[letterIndex],"             *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                     *" );
   letterIndex++;
   strcpy( bgArr[letterIndex]," *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"             *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"   *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"                      *" );
   letterIndex++;
   strcpy( bgArr[letterIndex],"         *" );
   letterIndex++;



  // begin loop

   // set the temporary holder for the loop
     // function: waitForInput
    hold = waitForInput( 0 );
     // begin secondary loop to flash title
      do
       {
        // set the hold time star display
        inputHold = waitForInput( 0 );
        // set terminating condition
        if ( inputHold != hold)
          {
           showSplash = false;
          }

        
        // clear the screen
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y);




          // print star field 1
             // function: setColor, printStringAt
             // set x and y Loc
          setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
          xLoc = 0;
          yLoc = 0;

          for(letterIndex = 0 ; letterIndex < 24 ; letterIndex++)
          {
            printStringAt(xLoc, yLoc, bgArr[letterIndex], "LEFT");
            yLoc++;
          }
          // right side stars
          xLoc = 58;
          yLoc = 5;
          for(letterIndex = 24 ; letterIndex < 38 ; letterIndex++)
          {
            printStringAt(xLoc, yLoc, bgArr[letterIndex], "LEFT");
            yLoc++;
          }



          // print "press any key" line
            // function: printStringAt, setColor
          letterIndex = 11;
          xLoc = 24;
          yLoc = 18;
          setColor( COLOR_BLUE, COLOR_BLACK, SET_BRIGHT );
          printStringAt( xLoc, yLoc, starArr[letterIndex], "LEFT");



        // set x and y Locations
        xLoc = 24;
        yLoc = 5;

        // set the color
          // function: setColor
          setColor( COLOR_YELLOW, COLOR_BLACK, SET_BRIGHT );

          // print star text
            // function: printStringAt
            for(letterIndex = 0 ; letterIndex < 11 ; letterIndex++)
              {
                printStringAt(xLoc, yLoc, starArr[letterIndex], "LEFT");
                yLoc++;
                hold = waitForInput( 0 );

             // set terminating condition
             if ( inputHold != hold)
                {
                 showSplash = false;
                }
              }







          // clear screen for maze text
            // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y);

          // print star field 2
             // function: setColor, printStringAt
             // set x and y Loc
          setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
          xLoc = 0;
          yLoc = 0;

          for(letterIndex = 0 ; letterIndex < 24 ; letterIndex++)
          {
            printStringAt(xLoc, yLoc, bgArr[letterIndex], "LEFT");
            yLoc++;
          }

          // right side stars
          xLoc = 58;
          yLoc = 5;
          for(letterIndex = 24 ; letterIndex < 38 ; letterIndex++)
          {
            printStringAt(xLoc, yLoc, bgArr[letterIndex], "LEFT");
            yLoc++;
          }



          // print "press any key" line
            // function: printStringAt, setColor
          letterIndex = 11;
          xLoc = 24;
          yLoc = 18;
          setColor( COLOR_BLUE, COLOR_BLACK, SET_BRIGHT );
          printStringAt( xLoc, yLoc, starArr[letterIndex], "LEFT");


         
          // reset x and y locations
          xLoc = 24;
          yLoc = 5;

          // set color of maze text
            // function: setColor
          setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

          // print maze words
            // function: printStringAt
            for(letterIndex = 0 ; letterIndex < 11 ; letterIndex++)
              {
                printStringAt(xLoc, yLoc, mazeArr[letterIndex], "LEFT");
                yLoc++;
                hold = waitForInput( 0 );

                   // set terminating condition
                   if ( inputHold != hold)
                     {
                      showSplash = false;
                     }
              }



       }
     //  loop end condition
     while( showSplash );


  

}


char mainMenu()
{
   // initialize variables
   //char selection;
   int xLoc = 32;
   int yLoc = 7;
   char menuTitle[] = "MENU SELECTIONS";
   char sep[] = "---------------";
   char lineA[] = "1. <R>ules";
   char lineB[] = "2. <D>ifficulty";
   char lineC[] = "3. <P>lay Game";
   char lineD[] = "4. <T>op Scores";
   char lineE[] = "5. <Q>uit Program";
   char prompt[] = "Enter Selection: ";  

   // set color of background
      // function: setColor
   setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
   // clear screen
     // funtion: clearScreen
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
   // set color of background
      // function: setColor
   setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
   // clear screen
     // funtion: clearScreen
   clearScreen( MENU_MIN_X, MENU_MIN_Y, MENU_MAX_X, MENU_MAX_Y );
   // print main menu options
     // printStringAt
   printStringAt( xLoc, yLoc, menuTitle, "LEFT" );
   yLoc++;
   printStringAt( xLoc, yLoc, sep, "LEFT" );
   yLoc += 2;
   printStringAt( xLoc, yLoc, lineA, "LEFT" );
   yLoc++;
   printStringAt( xLoc, yLoc, lineB, "LEFT" );
   yLoc++;
   printStringAt( xLoc, yLoc, lineC, "LEFT" );
   yLoc++;
   printStringAt( xLoc, yLoc, lineD, "LEFT" );
   yLoc++;
   printStringAt( xLoc, yLoc, lineE, "LEFT" );
   yLoc++;
   // prompt for user selection
     // function: promptForCharAt
     printStringAt( xLoc, yLoc, prompt, "LEFT" );

   // return user selection
   return waitForInput(FIXED_WAIT);


}

void rulesMenu ()
{
//initialize function
    //initialize x and y locations
    int xLeft = MENU_MIN_X;
    int yTop = MENU_MIN_Y;
    int xRight = MENU_MAX_X;
    int yBot = MENU_MAX_Y;
    int yTextStart = yTop + 3;
    int xText = xLeft + 10;
    //initialize c.style string arrays
    //sentences 1-5, title, underline, press any key
    char title[MAX_WIDTH] = "RULES";
    char underline[MAX_WIDTH] = "-----";
    char sentence1[MAX_WIDTH] = "Tap up and down arrow keys to move your Cruiser.";
    char sentence2[MAX_WIDTH] = "Holding keys down will distort space-time!";
    char sentence3[MAX_WIDTH] = "Collide with Asteroids to destroy them.";
    char sentence4[MAX_WIDTH] = "Press ESC to terminate mission.";
    char sentence5[MAX_WIDTH] = "Challenge yourself - increase the difficulty!";
    char anyKey[MAX_WIDTH] = "Press any key to continue . . .";
    //set color and clear screen
    //function: setColor clearScreen
    setColor(COLOR_WHITE, COLOR_BLUE, true);
    clearScreen( xLeft, yTop, xRight, yBot);
    //display title and underline
    //title
     //function: printStringAt
     printStringAt( xText, yTextStart, title,"LEFT");
    //underline
     //function: printStringAt
     printStringAt( xText, yTextStart+1, underline,"LEFT");
//output rules
//sentence 1
    //function: printStringAt
    printStringAt( xText, yTextStart+3, sentence1,"LEFT");
//sentence 2
    //function: printStringAt
    printStringAt( xText, yTextStart+4, sentence2,"LEFT");
//sentence 3
    //function: printStringAt
    printStringAt( xText, yTextStart+5, sentence3,"LEFT");
//sentence 4
    //function: printStringAt
    printStringAt( xText, yTextStart+6, sentence4,"LEFT");
//sentence 5
    //function: printStringAt
    printStringAt( xText, yTextStart+7, sentence5,"LEFT");
//output "Press any key to continue. . ." array
    //function: printStringAt
    printStringAt( xText, yTextStart+9, anyKey,"LEFT");
}

void diffMenu( int &difficultySet  )
{
// initialize variables
   int xLoc = 26;
   int yLoc = 7;
   char title[] = "DIFFICULTY RANK";
   char sep[] = "---------------";
   char optionA[] = "1. Master";
   char optionB[] = "2. Knight";
   char optionC[] = "3. Padawan";
   char prompt[] = "Enter Selection: ";
   int levelSelection;
   


   // clear screen

      // background color
         // function: setColor
         setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );

      // clear screen
         // function: clearScreen
         clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

      // set menu color
         // function: setColor
         setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );

      // clear menu
         // function: clearScreen
         clearScreen( MENU_MIN_X, MENU_MIN_Y, MENU_MAX_X, MENU_MAX_Y );

      // display difficulty options
         // function: printStringAt
         printStringAt( xLoc, yLoc, title, "LEFT" );
         yLoc++;
         printStringAt( xLoc, yLoc, sep, "LEFT" );
         yLoc+=2;
         printStringAt( xLoc, yLoc, optionA, "LEFT" );
         yLoc++;
         printStringAt( xLoc, yLoc, optionB, "LEFT" );
         yLoc++;
         printStringAt( xLoc, yLoc, optionC, "LEFT" );
         yLoc++;
         printStringAt( xLoc, yLoc, prompt, "LEFT" );
         // prompt for selection
            // promptForIntAt  
         xLoc = 43;
         levelSelection = waitForInput(FIXED_WAIT);

         // switch for difficulty selections
         switch( levelSelection )
           {
          // case 1
              case '1':
                 difficultySet = 3;
                 break;
       
          // case 2
              case '2':
                 difficultySet = 2;
                 break;
       
          // case 3
              case '3':
                 difficultySet = 1;
                 break;
          }

}

void startGame ( int difficultySet)
{
//initialize function/variables
    //variables
    int cycle;
    int newY = 0;
    int input;
    int cycleTime = 1;
    int scoreBoardY = SCRN_MAX_Y - 3;
    int centerX = SCRN_MAX_X / 2;
    int centerY = (SCRN_MAX_Y / 2) - 3;
    int scoreX = centerX + 9;
    int total = 0;
    int cursorX = CURSOR_X_LOC;
    int cursorY = centerY;
    char currentScore[] = "Current Score:";
    char line[] = 
    "================================================================================";
    char instruct[] = " Press Up or Down Arrow to Move";
    char instruct2[] = "Press ESC to Quit Game ";
    char level[MAX_WIDTH][MAX_HEIGHT];
    int xyLoc[MAX_WIDTH][MAX_HEIGHT];
    bool continueGame = true;
    //clear screen and set color
    //function: clearScreen and setColor
    setColor(COLOR_BLUE, COLOR_GREEN, true);
    clearScreen(SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y);
    setColor(COLOR_RED, COLOR_BLUE, true);
    clearScreen(MENU_MIN_X, SCRN_MIN_Y, MENU_MAX_X, SCRN_MAX_Y);
    clearScreen(SCRN_MIN_X, scoreBoardY, SCRN_MAX_X, SCRN_MAX_Y);

    printStringAt(SCRN_MIN_X, scoreBoardY, line, "LEFT");
    printStringAt(SCRN_MIN_X, scoreBoardY + 1, instruct, "LEFT"); 
    printStringAt(SCRN_MAX_X, scoreBoardY + 1, instruct2, "RIGHT");
    printStringAt(centerX, SCRN_MAX_Y, currentScore, "CENTER");
    printIntAt(scoreX, SCRN_MAX_Y, total, "LEFT");   
    //move cursor
    //function:moveToXY
    moveToXY(cursorX, cursorY);

    //load array
    //function: initializeArray()
    initializeArr( level, difficultySet, xyLoc);
//start level
//MASTER LOOP----------------------------------------------------------------
    //for(cycle = 0; continue; cycle++) cycle is a double, continue is bool
    for(cycle = 0; continueGame; cycle++)
     //MASTER START{
     {
      // get an input key, waiting for user input( cycleTime)
        //function: waitForInput
        input = waitForInput(cycleTime);
      //print score ** added in step 6
        printIntAt(scoreX, SCRN_MAX_Y, total, "LEFT");  
      // switch user input, set direction, otherwise ignore
       switch(input)
         //Switch start{
         {
          //case -1:
          case -1:
          //set y = 0
          newY = 0;
          //break;
          break;
          //case KB_UP_ARROW
          case KB_UP_ARROW:
          //set y = -1
          newY = -1;      
          //break;
          break;
          //case KB_DOWN_ARROW
          case KB_DOWN_ARROW:
          //y = 1
          newY = 1;
          //break;
          break;
          // set up a case for ending the program with the ESC key
          case KB_ESCAPE:
          //set continue to false
          continueGame = false;
          //break;
          break;
         //Switch end}
         }
      // move the character
        //function: moveCursor
        moveCursor( cursorX , cursorY , newY );
     //check if cursor is at the same location as an asteroid calculate score
       //function: bool checkForScore
       if(checkForScore(xyLoc,cursorY))
        //{
        {
        //score += 19/(difficulty * difficulty);
        total = total + ( 19/(difficultySet * difficultySet));
        //}
        }
     //move the level(switch for difficulty)
     switch(difficultySet)
         //START { for difficulty switch
         {
           //case hard move every 1 cycle aka case 1:
           case 3:
             //move level
               //function: move array
               
           //break;
           break;
           //case moderate move every 2 cycles aka case 2:
           case 2:
          
               //check if cycled twice( (cycle / 2.0) == 0.0 )
               
                 //{

                    //move level every 2 cycles
                      //function: move array
                 //}

           //break;
           break;
           //case easy move every three cycles aka case 3:
           case 1:
              //check if cycled thrice( (cycle / 3.0) == 0.0)
              
                //{

                  //move level every 3 cycles
                    //function: move array
                //}

           //break;
           break;
         //END } for difficulty switch
         }
        //check if last array x location is 0
        
          //{

             //set continue program to false
             
          //}

     //MASTER END }
     }
//END OF MASTER LOOP----------------------------------------------------------      

//end of level

 // check if score is a high score
    //function: checkIfHighScore

    //if true

      //{

        //prompt for username
          //function: void promptForStringAt( int xPos, int yPos,
                   //const string &promptString, char resultString[] );

        //set new score
         //function: scoring

      //}

 //jump to top score menu
    //function: topScoreMenu

}


void topScoreMenu( char fileName[] )
{
//initialize function and variables
//variables: x & y locations, ifstream
    int xLeft = MENU_MIN_X;
    int yTop = MENU_MIN_Y;
    int xRight = MENU_MAX_X;
    int yBot = MENU_MAX_Y;
    int titleY = yTop + 2;
    int titleX = xLeft + 18;
    ifstream fin;
//c.style string arrays
    char topScore[MAX_WIDTH] = "TOP SCORES";
    char topScoreLine[MAX_WIDTH] = "----------";
    char name[MAX_WIDTH] = "NAME";
    char nameLine[MAX_WIDTH] = "----";
    char score[MAX_WIDTH] = "SCORE";
    char scoreLine[MAX_WIDTH] = "-----";
    //error
    char error[MAX_WIDTH] = "There are no high scores";
//set color and clear screen
    //function: setColor  and clearScreen
    setColor(COLOR_WHITE, COLOR_BLUE, true);
    clearScreen( xLeft, yTop, xRight, yBot);
//output titles
printStringAt( titleX + 11, titleY, topScore,"LEFT");
printStringAt( titleX + 11, titleY + 1, topScoreLine,"LEFT");

printStringAt( titleX, titleY + 2, name,"LEFT");
printStringAt( titleX, titleY + 3, nameLine,"LEFT");

printStringAt( titleX + 25, titleY + 2, score,"LEFT");
printStringAt( titleX + 25, titleY + 3, scoreLine,"LEFT");
//open file
//clear ifstream
fin.clear();
//open
fin.open(fileName);
//test if good
if ( fin.good() )
//{
 {
    //use readScoringAndOutput
    //function: readScoringAndOutput
    readScoringAndOutput( titleX, titleY + 5, fin);
//}
 }
//else if not good
else
//{
 {
    //display error array to screen
    //output error
      //function: printStringAt
      printStringAt( titleX - 5, MENU_MAX_Y - 3, error,"LEFT");          
//}
}
//close file
fin.close();
}

void readScoringAndOutput ( int xLoc, int yLoc, ifstream &fin)
{
//initialize function and variables
//variables
int xScore = xLoc + 25;
int score = 0;
char letter = 'x';
int size = 5;
int index;
//arrays 1 integer array, and  5 names array
int scores[size];
char place1[MAX_WIDTH];
char place2[MAX_WIDTH];
char place3[MAX_WIDTH];
char place4[MAX_WIDTH];
char place5[MAX_WIDTH];
//read scores
//for loop
for(index = 0; index < size; index ++)
//{
 {
    //read dummy name
    fin >> letter;
    while(letter != NEWLINE_CHAR)
      {
      fin >> letter;
      }
    //read score
    fin >> score;
    //assign integer array[index] to score
    scores[index] = score;
//}
 }
//clear ifstream
fin.clear();
//read names

    //for( index = 0; letter != new line; index ++)
    for (index = 0; letter != NEWLINE_CHAR ; index ++)
    //{
    {
    //read letter
    fin >> letter;
    //assign the letter to names array1[index]
    place1[index] = letter;
    //}
    }
    place1[index + 1] = NULL_CHAR;
    //read dummy score
    fin >> score;

    //for( index = 0; letter != new line; index ++)
    for (index = 0; letter != NEWLINE_CHAR ; index ++)
    //{
    {
    //read letter
    fin >> letter;
    //assign the letter to names array2[index]
    place2[index] = letter;
    //}
    }
    place2[index + 1] = NULL_CHAR;
    //read dummy score
    fin >> score;

    //for( index = 0; letter != new line; index ++)
    for (index = 0; letter != NEWLINE_CHAR ; index ++)
    //{
    {
    //read letter
    fin >> letter;
    //assign the letter to names array3[index]
    place3[index] = letter;
    //}
    }
    place3[index + 1] = NULL_CHAR;
    //read dummy score
    fin >> score;

    //for( index = 0; letter != new line; index ++)
    for (index = 0; letter != NEWLINE_CHAR ; index ++)
    //{
    {
    //read letter
    fin >> letter;
    //assign the letter to names array4[index]
    place4[index] = letter;
    //}
    }
    place4[index + 1] = NULL_CHAR;
    //read dummy score
    fin >> score;

    //for( index = 0; letter != new line; index ++)
    for (index = 0; letter != NEWLINE_CHAR ; index ++)
    //{
    {
    //read letter
    fin >> letter;
    //assign the letter to names array5[index]
    place5[index] = letter;
    //}
    }
    place5[index + 1] = NULL_CHAR;

//output scores to screen
//for(index = 0; index<5; index ++)
for(index = 0; index < 5 ; index++)
//{
{
    //output integer to screen
    //function: printIntAt( xLoc, index + yLoc, number[index], "left")
    printIntAt(xScore, index + yLoc, scores[index], "CENTER");
//}
}
//output names to screen

//output first name
    //function: printStringAt
    printStringAt( xLoc, yLoc, place1, "LEFT");
//output second name
    //function: printStringAt
    printStringAt( xLoc, yLoc+1, place2, "LEFT");
//output third name
    //function: printStringAt
    printStringAt( xLoc, yLoc+2, place3, "LEFT");
//output fourth name
    //function: printStringAt
    printStringAt( xLoc, yLoc+3, place4, "LEFT");
//output fifth name
    //function: printStringAt
    printStringAt( xLoc, yLoc+4, place5, "LEFT");
}


void quitScreen ()
{
// initialize variables
  int xLoc, yLoc;
  int Y_TOP_MAX = 9;
  char messageArr[MAX_HEIGHT][MAX_WIDTH];
  int messageIndex = 0;
  

  // initialize array
   strcpy( messageArr[messageIndex], " TTTTT  HH  HH    AA   NN   NN  KK   KK       YY   YY    OO   UU  UU" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   T    HH  HH   AAAA  NNN  NN  KK KK           Y Y     OOOO  UU  UU" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   T    HHHHHH  AA  AA NN N NN  KKKK             Y     OO  OO UU  UU" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   T    HH  HH  AAAAAA NN  NNN  KK KK            Y      OOOO  UU  UU" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   T    HH  HH  AA  AA NN   NN  KK   KK          Y       OO   UUUUUU" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "For Playing This Amazing Game" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "You can give us money for playing on PayPal!" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "         _____ " );
   messageIndex++;
   strcpy( messageArr[messageIndex], "       .'/L|__`. " );
   messageIndex++;
   strcpy( messageArr[messageIndex], "      / =[_]O|` |   . . . BYE!!");
   messageIndex++;
   strcpy( messageArr[messageIndex], "      | +_____ :| " );
   messageIndex++;
   strcpy( messageArr[messageIndex], "    __:='|____`-:__" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   ||[] ||====| []||" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   ||[] | |=| | []||" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   |:||_|=|U| |_||:|" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   |:|||]_=_ =[_||:| " );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   | |||] [_][]C|| |" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   | ||-      `-|| |" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   | ||-      `-|| |" );
   messageIndex++;
   strcpy( messageArr[messageIndex], "   /|||_|_|_|_/_//|| " );
   messageIndex++;
   strcpy( messageArr[messageIndex], "  |___|  | | |  |___| " );
   messageIndex++;
   strcpy( messageArr[messageIndex], "  `---'  |___|  `---' " );
   messageIndex++;
   strcpy( messageArr[messageIndex], "         `---' " );
   messageIndex++;
   strcpy( messageArr[messageIndex], " Press any key to exit game . . .");




  // set color and clear screen
    // function: setColor, clearScreen
  setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
  clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, Y_TOP_MAX );
  
  // set x and y location
  xLoc = 5;
  yLoc = 1;
  // print final message (BIG LETTERS)
    // function: printStringAt

    for(messageIndex = 0 ; messageIndex < 5 ; messageIndex++)
      {
        printStringAt(xLoc, yLoc, messageArr[messageIndex], "LEFT");
        yLoc++;
      }

 // set new color
  setColor( COLOR_CYAN, COLOR_BLACK, SET_BRIGHT );
  // print first message
  xLoc = 25;
  yLoc++;
  messageIndex = 5;
  printStringAt( xLoc, yLoc, messageArr[messageIndex], "LEFT");

  // set new color
  setColor( COLOR_MAGENTA, COLOR_BLACK, SET_BRIGHT );
  // print second message
  yLoc ++;
  xLoc = 17;
  messageIndex = 6;
  printStringAt( xLoc, yLoc, messageArr[messageIndex], "LEFT");


  // set color and clear screen
    // function: setColor, clearScreen
  setColor( COLOR_BLACK, COLOR_RED, SET_BRIGHT );
  clearScreen( SCRN_MIN_X, Y_TOP_MAX, SCRN_MAX_X, SCRN_MAX_Y );
  
  // set new x and y loc
  yLoc ++;
  xLoc = 0;
 // set new color
  setColor( COLOR_BLACK, COLOR_RED, SET_BRIGHT );
  // print picture
    // function: printStringAt
    for(messageIndex = 7 ; messageIndex < 23 ; messageIndex++ )
      {
      printStringAt( xLoc, yLoc, messageArr[messageIndex], "LEFT");
      yLoc++;
      }

 // set new x loc
   // print exit message
   xLoc = 45;
   yLoc --;
   messageIndex = 23;
   printStringAt( xLoc, yLoc, messageArr[messageIndex], "LEFT");
    


}

void scoring(char fileName[] , int highscore, char username[])
{
//initialize function and variables
    //variables
    char dummy;
    int score;
    int size = 5;
    int scores[size];
    ifstream fin;
    int index;
    //clear ifstream, open file
    fin.clear();
    fin.open( fileName);
//read numbers into an array

//for loop
for(index = 0; index < size; index ++)
  //{
  {
    //read dummy name
    fin >> dummy;
     while(dummy != NEWLINE_CHAR)
       {
       fin >> dummy;
       }
    //read score
    fin >> score;
    //assign integer array[index] to score
    scores[index] = score;
  //}
  }

 /*<step 6> removed useless comments which indicated that this function would
 check if the highscore is a highscore, but this function is only used in
 start game which already checks if the score is a highscore before it calls
 this function. */

 //re organize
    //close file
    fin.close();
    //Write the new highscore to the file and organize
      //function: writeHighScore
      writeHighScore( fileName, highscore, username, scores);

}

void writeHighScore(char fileName[] , int highscore, char username[], int scores[])
{
//initialize function
    //variables
    int index, dummy, count;
    char letter;
    ifstream fin;
    ofstream fout;
    char array1[MAX_WIDTH];
    char array2[MAX_WIDTH];
    char array3[MAX_WIDTH];
    char array4[MAX_WIDTH];
    char array5[MAX_WIDTH];   
    //clear ifstream and open file
    fin.clear();
    fin.open(fileName);
//read names

    //for( index = 0; letter != new line; index ++)
    for( index = 0; letter != NEWLINE_CHAR; index++)
    //{
     {
    //read letter
    fin >> letter;
    //assign the letter to names array1[index]
    array1[index] = letter;
    //}
    }
    array1[index+1] = NULL_CHAR;
    //read dummy score
    fin >> dummy;
    //for( index = 0; letter != new line; index ++)
    for( index = 0; letter != NEWLINE_CHAR; index++)
    //{
     {
    //read letter
    fin >> letter;
    //assign the letter to names array2[index]
    array2[index] = letter;
    //}
    }
    array2[index+1] = NULL_CHAR;
    //read dummy score
    fin >> dummy;

    //for( index = 0; letter != new line; index ++)
    for( index = 0; letter != NEWLINE_CHAR; index++)
    //{
     {
    //read letter
    fin >> letter;
    //assign the letter to names array3[index]
    array3[index] = letter;
    //}
    }
    array3[index+1] = NULL_CHAR;
    //read dummy score
    fin >> dummy;

    //for( index = 0; letter != new line; index ++)
    for( index = 0; letter != NEWLINE_CHAR; index++)
    //{
     {
    //read letter
    fin >> letter;
    //assign the letter to names array4[index]
    array4[index] = letter;
    //}
    }
    array4[index+1] = NULL_CHAR;
    //read dummy score
    fin >> dummy;

    //for( index = 0; letter != new line; index ++)
    for( index = 0; letter != NEWLINE_CHAR; index++)
    //{
     {
    //read letter
    fin >> letter;
    //assign the letter to names array5[index]
    array5[index] = letter;
    //}
    }
    array5[index+1] = NULL_CHAR;

//close file
fin.close();
//open file with ofstream
fout.clear();
fout.open(fileName);
fout.clear();
//sort high scores
   
    //for index = 0; scores[index] > highscore; index ++)
    for(index = 0; scores[index] > highscore; index++)   
    //{
    {
       //count + 1 and it will be initialized at 0
       count++;
    //}
    }
    //switch count
    switch(count)
    //{
    {
    //case 0
    case 0:
    //stream ofstream with numbers in correct order including endlines
      fout << username << endl;
      fout << highscore << endl;
       // write first place to second
          fout << array1 <<endl;
          fout << scores[0]<<endl;
       //write second place to third
          fout << array2 << endl;
          fout << scores[1] << endl;
       //write third place to forth
          fout << array3 << endl;
          fout << scores[2] << endl;
       //write forth place to fifth
          fout << array4 << endl;
          fout << scores[3] << endl;
    //break
    break;
    //case 1
    case 1:
    //stream ofstream with numbers in correct order including endlines
      //keep first place
          fout << array1 <<endl;
          fout << scores[0]<<endl;
      //write in new second place
      fout << username << endl;
      fout << highscore << endl;
      //write second place to third
          fout << array2 << endl;
          fout << scores[1] << endl;
       //write third place to forth
          fout << array3 << endl;
          fout << scores[2] << endl;
       //write forth place to fifth
          fout << array4 << endl;
          fout << scores[3] << endl;

    //break
    break;
    //case 2
    case 2:
    //stream ofstream with numbers in correct order including endlines
     //keep first
          fout << array1 <<endl;
          fout << scores[0]<<endl;
     //keep second
          fout << array2 << endl;
          fout << scores[1] << endl;
     //write new third
      fout << username << endl;
      fout << highscore << endl;
       //write third place to forth
          fout << array3 << endl;
          fout << scores[2] << endl;
       //write forth place to fifth
          fout << array4 << endl;
          fout << scores[3] << endl;
    //break
    break;
    //case 3
    case 3:
    //stream ofstream with numbers in correct order including endlines
     //keep first
          fout << array1 <<endl;
          fout << scores[0]<<endl;
     //keep second
          fout << array2 << endl;
          fout << scores[1] << endl;
     //keep third
          fout << array3 << endl;
          fout << scores[2] << endl;
     //write new forth
      fout << username << endl;
      fout << highscore << endl;
     //write forth place to fifth
          fout << array4 << endl;
          fout << scores[3] << endl;      

    //break
    break;
    //case 4
    case 4:
    //stream ofstream with numbers in correct order including endlines
     //keep first
          fout << array1 <<endl;
          fout << scores[0]<<endl;
     //keep second
          fout << array2 << endl;
          fout << scores[1] << endl;
     //keep third
          fout << array3 << endl;
          fout << scores[2] << endl;
     //keep forth
          fout << array4 << endl;
          fout << scores[3] << endl;
     //write new fifth
      fout << username << endl;
      fout << highscore << endl;
    //break
    break;
    //}
    }
//close file
fout.close();
}


bool checkIfHighScore( char fileName[], int score)
{
//initialize function
    //variables
    ifstream read;
    ofstream fout;
    char dummy;
    int number, index;
    char blankName[MAX_WIDTH] = "No Name";
    int blankScore = 0;
//clear fstream
read.clear();
//open file
read.open(fileName);
    //test if good
    if(read.good())
    //{
    {
    //while .good
    while(read.good())
    //{   
     {
     //read dummy name
     read >> dummy;
     while(dummy != NEWLINE_CHAR)
       {
       read >> dummy;
       }
     //read number
      read >> number;      
       //if number < score
       if(number < score)
       //{
       {
       //close file
        read.close();    
         //return true
         return true;
       //}
       }
    //close file
    read.close();
    //}
     }
    //return false
    return false;
    //}
    }
//if file did not open, create a file
//clear ofstream
fout.clear();
//create file
fout.open(fileName);
//output blank scores and names
    //for( index = 0; index <5; index ++)
    for(index = 0; index < 5; index ++)
    //{
    {
    //stream name array , a new line, and then a blank number 0
    fout << blankName << endl << blankScore << endl;
    //}
    }
//close file
fout.close();
//return true
return true;
}

void initializeArr ( char gameArr[MAX_HEIGHT][MAX_WIDTH], int difficulty, int xyLocArr[MAX_HEIGHT][MAX_WIDTH] )
{
// intialize variables


// initialze array with null characters in for loop

//switch(difficulty)

//easy
      // set first row of asteroids  
         //row++
  
         // set x and y locations for array

      // set second row of asteroids  
         //row++
  
         // set x and y locations for array

     // set third row of asteroids
         //row++
  
         // set x and y locations for array

      // set fourth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fifth row of asteroids
         //row++
  
         // set x and y locations for array

      // set sixth row of asteroids
         //row++
  
         // set x and y locations for array

      // set seventh row of asteroids
         //row++
  
         // set x and y locations for array

      // set eight row of asteroids
         //row++
  
         // set x and y locations for array

      // set ninth row of asteroids
         //row++
  
         // set x and y locations for array

      // set tenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set eleventh row of asteroids
         //row++
  
         // set x and y locations for array

      // set twelth row of asteroids
         //row++
  
         // set x and y locations for array

      // set thirteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fourteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fifth row of asteroids
         //row++
  
         // set x and y locations for array

      // set sixthteen row of asteroids
         //row++
  
         // set x and y locations for array

      // set seventeenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set eighteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set nineteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set twentheth row of asteroids
         //row++
  
         // set x and y locations for array

//moderate
      // set first row of asteroids  
         //row++
  
         // set x and y locations for array

      // set second row of asteroids  
         //row++
  
         // set x and y locations for array

     // set third row of asteroids
         //row++
  
         // set x and y locations for array

      // set fourth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fifth row of asteroids
         //row++
  
         // set x and y locations for array

      // set sixth row of asteroids
         //row++
  
         // set x and y locations for array

      // set seventh row of asteroids
         //row++
  
         // set x and y locations for array

      // set eight row of asteroids
         //row++
  
         // set x and y locations for array

      // set ninth row of asteroids
         //row++
  
         // set x and y locations for array

      // set tenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set eleventh row of asteroids
         //row++
  
         // set x and y locations for array

      // set twelth row of asteroids
         //row++
  
         // set x and y locations for array

      // set thirteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fourteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fifth row of asteroids
         //row++
  
         // set x and y locations for array

      // set sixthteen row of asteroids
         //row++
  
         // set x and y locations for array

      // set seventeenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set eighteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set nineteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set twentheth row of asteroids
         //row++
  
         // set x and y locations for array

//hard
      // set first row of asteroids  
         //row++
  
         // set x and y locations for array

      // set second row of asteroids  
         //row++
  
         // set x and y locations for array

     // set third row of asteroids
         //row++
  
         // set x and y locations for array

      // set fourth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fifth row of asteroids
         //row++
  
         // set x and y locations for array

      // set sixth row of asteroids
         //row++
  
         // set x and y locations for array

      // set seventh row of asteroids
         //row++
  
         // set x and y locations for array

      // set eight row of asteroids
         //row++
  
         // set x and y locations for array

      // set ninth row of asteroids
         //row++
  
         // set x and y locations for array

      // set tenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set eleventh row of asteroids
         //row++
  
         // set x and y locations for array

      // set twelth row of asteroids
         //row++
  
         // set x and y locations for array

      // set thirteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fourteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set fifth row of asteroids
         //row++
  
         // set x and y locations for array

      // set sixthteen row of asteroids
         //row++
  
         // set x and y locations for array

      // set seventeenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set eighteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set nineteenth row of asteroids
         //row++
  
         // set x and y locations for array

      // set twentheth row of asteroids
         //row++
  
         // set x and y locations for array



}
bool checkForScore( int xyArrLoc[MAX_HEIGHT][MAX_WIDTH],int yCursorLoc)
{
//initialize variables
int col;
bool highScore = false;

//for loop( col aka width = 0; width < size; col++)
for(col = 0; col < XY_LOC_ARR_MAX; col++)//stub: XY_LOC_ARR_MAX
    //{
    {  
    //check if the xyArrLoc[0][col] is equal to x loc of cursor
    if(xyArrLoc[0][col] == CURSOR_X_LOC)
     //{
       {
        //check if xyArrLoc[1][col] is equal to the cursor y location
        if(xyArrLoc[1][col] == yCursorLoc)
          //{   
            {    
             //return true
             highScore = true;
             return highScore;
          //}
          }
     //}
     }
    //}
    }
    //If the loop gets to this point, the cursor is not equal to an asteroid loc
    //return false
    return highScore;
}

void moveCursor( int &xPos, int &yPos, int yVect )
{
    // initialize function/variables
    int yOld = yPos;
    char marker = ' ';
    char cursor = '>';
    // if y vector is not zero, and yPos + yVect are less than screen limits
    if ((yVect != 0) &&
      ((yVect + yPos) >= SCRN_MIN_Y )
      && ((yVect + yPos) < (SCRN_MAX_Y - 3)))
    //{
    {
     // cover up the old marker
       //function: printCharAt
       printCharAt( xPos, yOld, marker);
     // set yPos to new yPos
     yPos = yPos + yVect;
    //}
    }
    // print the marker at the specified location
    //function: printCharAt
    printCharAt(xPos, yPos, cursor);
}
void moveArr( char gameArr[MAX_HEIGHT][MAX_WIDTH], int xyArrLoc[MAX_HEIGHT][MAX_WIDTH] , int &xLoc, int &yLoc )
{
//initialize variables
   int row, col;
   int xOld = xLoc;
   char cover = ' ';
  //xLoc = xLoc - 1
  xLoc = xLoc - 1;

//outer loop for row aka height for(row = 0 ; row < maxHeight ; row++ )
for(row = 0; row < 21; row++)
//{
   {
   //inner loop for col aka width for( col = 0; col < maxWidth; col++)
    for(col = 0; col < 60; col++)
    //{
      {
      //cover the track
      printCharAt( xOld + col, yLoc + row, cover);
      //printCharAt( xloc, yloc, gameArr[row][height] );
       //function: printCharAt
       printCharAt( xLoc + col, yLoc + row, gameArr[row][col] );
    //}
    }
//}
}
// for( col = 0; col < maxWidth; col++)
for(col = 0; col < XY_LOC_ARR_MAX; col++)
//{
  {
    //xyArrLoc[0][col] -= 1
    xyArrLoc[0][col] -= 1;
 //}   
  }
}

