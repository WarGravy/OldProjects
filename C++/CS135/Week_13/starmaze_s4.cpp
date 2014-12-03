//include files
#include <iostream>
#include <fstream>
#include "formatted_console_io_v16.h"
using namespace std;

//global constants
  const char NULL_CHAR = '\0';
  const char NEWLINE_CHAR = '\n';
  const int MAX_STR_LEN = 120;
  const int MAX_ROWS = 80;

//function prototypes
  //splash screen:chris

  //mainmenu: chris

/*written by: Zachary Carlson
  Name: rulesMenu
  Process: clears screen, outputs rules, then clears screen when indicated 
           waiting for input
  Output: the rules on the screen.
  Dependencies:clearScreen, setColor, waitForInput, printCharAt
*/
void rulesMenu ();

  //difficulty: chris

  //playGame: both

/*written by: Zachary Carlson
  Name: topScoreMenu
  Process: clears screen, opens and finds top 5 scores and stores them in 5 arrays, 
           outputs the 5 top, closes file then clears screen when indicated 
           by waiting for input
  Output: the 5 top scores to screen.
  Input: filename
  Dependencies:clearScreen, setColor, waitForInput, printCharAt
*/
void topScoreMenu( char fileName[] );

  //quitprogram: chris

/*written by: Zachary Carlson
  Name: scoring
  Process: accepts a highScore, accepts a filename, and reorganizes the top 5 
           high scores in the file.
  Output: rewrites the file with the correct top 5 scores
  input: filename and highscore
  Dependencies:none
*/
void scoring(char fileName[] , int highscore);
  //movement: both

  //copy array: chris

  //checkIfHighScore: Zack
/*
Written by: Zachary Carlson
Name: checkIfHighScore
Process:Checks to see if the score is higher than one of the top five scores
Output/Returned: true or false
Input: the score from the latest game
Dependencies: This will be used in the playGame function. 
 */
bool checkIfHighScore(char fileName[], int score);

//main
int main()
  {
  //initialize function
    //variable
    char menuCase = 'z';
    int promptXloc = 10;
    int promptYloc = 10;
    
    //star curses
      //function: startCurses
      startCurses();
    
    //display splash intro
      //function: splashScreen
      splashScreen();

  //Menu
    //loop while case!= q or Q
    while((menuCase != q) || (menuCase != Q))    
    //{
    {
    //display menu
    //function: mainMenu
    mainMenu();
    //prompt for case here
      //function: promptForCharAt
      promptForCharAt( promptXloc, 
    //switch

      //{      
      
      //case R or r

      //rules
        //function: rulesMenu

      //break

      //case D or d
      
      //difficulty
        //function: diffMenu

      //break

      //case p or P
      
      //play game
        //function: playGame

        //break

      //case t or T

      //top scores
        //function: topScoreMenu

      //break
      
      //case q or Q

      //quit screen
        //function: quitProgram
        
      //break

        //}

     //}

  //end program
    
  //end curses
  system ("pause");
  return 0; 
  }

//implementation

  //splash screen:chris

  //mainmenu: chris

void rulesMenu ()
  {
  }

  //difficulty: chris

  //playGame: both

void topScoreMenu( char fileName[] )
  {
  }

  //quitprogram: chris

void scoring(char fileName[] , int highscore)
  {
  }
  //movement: both

  //copy array: chris

bool checkIfHighScore( char fileName[], int score)
 {
 //stub
 return false;
 }
