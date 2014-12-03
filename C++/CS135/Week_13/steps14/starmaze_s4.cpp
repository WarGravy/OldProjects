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
const int SCRN_X_MIN = 7;
const int SCRN_Y_MIN = 4;
const int SCRN_X_MAX = 72;
const int SCRN_Y_MAX = 18;



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
  Process: clears the screen and begins the game at the selected difficulty
  Output: presents 
  Dependencies:clearScreen, setColor, waitForInput, printCharAt
*/
void startGame ( int difficultySet, int &score );


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
void readScoringAndOutput ( int xLoc, int yLoc, ifstream fin);

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
 Process: accepts a highScore, accepts a filename, and reorganizes the top 5
      	high scores in the file.
 Output: rewrites the file with the correct top 5 scores
 input: filename and highscore and username
 Dependencies:writeHighScore
*/
void scoring(char fileName[] , int highscore, char username[]);

/*
written by: Zachary Carlson
 Name: writeHighScore
 Process: accepts new highScore, accepts a filename, and accepts username, then
      	reorganizes the top five scores
 Output: rewrites the file with the correct top 5 scores
 input: filename and highscore and username
 Dependencies:none
*/
void writeHighScore(char fileName[] , int highscore, char username[], int scores[]);


/*
written by: Zachary Carlson and Chris Scott
 Name: movement
 Process: moves the spaceship based on user input
 Output: 
 input: 
 Dependencies:none
*/
void movement();



/*
Written by: Zachary Carlson
Name: checkIfHighScore
Process:Checks to see if the score is higher than one of the top five scores
Output/Returned: true or false
Input: the score from the latest game
Dependencies: This will be used in the playGame function. 
 */
bool checkIfHighScore(char fileName[], int score);


////////////////////////main program////////////////////////////////
int main()
  {
  //initialize function / variables
  bool quit = false;
  int response;
  int difficultySet;
  int score;
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
                    startGame(difficulty, score);
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
// stub
}

char mainMenu()
{
  // stub
 return 0;
}

void rulesMenu ()
{
  // stub
}

void diffMenu( int &difficultySet  )
{
  // stub
}

void startGame ( int difficultySet,  int &score )
{
  // stub
}

void topScoreMenu( char fileName[] )
{
  // stub
}

void readScoringAndOutput ( int xLoc, int yLoc, ifstream fin)
{
  // stub
}

void quitScreen ()
{
  // stub
}

void scoring(char fileName[] , int highscore, char username[])
{
 // stub
}

void writeHighScore(char fileName[] , int highscore, char username[], int scores[])
{
  // stub
}

void movement()
{
// stub
}


bool checkIfHighScore( char fileName[], int score)
{
// stub
  return true;
}


