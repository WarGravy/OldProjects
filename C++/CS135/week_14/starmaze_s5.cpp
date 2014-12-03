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
const char NULL_CHAR = '\0'; 



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
void initializeArr ( char gameArr[MAX_HEIGHT][MAX_WIDTH], int difficulty, int xyLocArr[MAX_HEIGHT][MAX_WIDTH]);

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
void moveArr( char gameArr[MAX_HEIGHT][MAX_WIDTH], int xyArrLoc[MAX_HEIGHT][MAX_WIDTH] ,
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

   // set color and clear screen
     // function: setColor, clearScreen

   // begin loop

    // set the temporary holder for the loop
      // function: waitForInput

      // begin secondary loop to flash title

         // set the hold time star display

         // set terminating condition


         // set x and y Locations

         
         // clear the screen 
           // function: clearScreen


         // set the color
           // function: setColor


           // print star text
             // function: printStringAt

           // print "press any key" line
             // function: printStringAt, setColor

           // print star field 1
              // function: setColor, printStringAt
              // set x and y Loc


           // set hold time for maze display

           // set terminating condition


           // clear screen for maze text
             // function: clearScreen
          
           // reset x and y locations

           // set color of maze text
             // function: setColor

           // print maze words
             // function: printStringAt

           // print "press any key" line
             // function: printStringAt, setColor


           // print star field 2
              // function: setColor, printStringAt
              
         // set x and y Loc


        // wait for input from user

        // set terminating condition

      // inner loop end condition



  //  }
   // outer loop end condition


}

char mainMenu()
{
    // initialize variables
    
    // set color of background
       // function: setColor

    // clear screen
      // funtion: clearScreen

    // set color of background
       // function: setColor

    // clear screen
      // funtion: clearScreen

    // print main menu options
      // printStringAt

    // prompt for user selection
      // function: promptForCharAt


    // return user selection
// stub
return 0;
}

void rulesMenu ()
  {
  //initialize function
	//initialize x and y locations
 
	//initialize c.style string arrays
	  //sentences 1-5, title, underline, press any key
	 
	//set color and clear screen
  	//function: setColor clearScreen

	//display title and underline
  	//title
    	//function: printStringAt

  	//underline
    	//function: printStringAt

  //output rules
   //sentence 1
 	//function: printStringAt

   //sentence 2
 	//function: printStringAt

   //sentence 3
 	//function: printStringAt

   //sentence 4
 	//function: printStringAt

   //sentence 5
 	//function: printStringAt

  //output "Press any key to continue. . ." array
	//function: printStringAt

}

void diffMenu( int &difficultySet  )
{
 // initialize variables   

    // clear screen

       // background color
          // function: setColor

       // clear screen
          // function: clearScreen

       // set menu color
          // function: setColor


       // clear menu
          // function: clearScreen


       // display difficulty options
          // function: printStringAt

          // prompt for selection
             // promptForIntAt  

          // switch for difficulty selections
             // {
               // case 1
        
               // case 2
        
               // case 3

            // }

}

void startGame ( int difficultySet )
  {
  //initialize function/variables
	//variables

	//clear screen and set color
  	//function: clearScreen and setColor

	//move cursor
  	//function:moveToXY

	//load array
  	//function: initializeArray( int difficultySet, level[][MAX_HEIGHT] )

  //start level
  //MASTER LOOP----------------------------------------------------------------
	//for(cycle = 0; continue; cycle++) cycle is a double, continue is bool

   	//MASTER START{
  	 
    	// get an input key, waiting for user input( cycleTime)
      	//function: waitForInput
   	 
    	// switch user input, set direction, otherwise ignore
   	 
       	//Switch start{

        	//case -1:

        	//set y = 0

        	//break;

        	//case KB_UP_ARROW

        	//set y = -1
       	 
        	//break;

        	//case KB_DOWN_ARROW

        	//y = 1
       	 
        	//break;

        	// set up a case for ending the program with the ESC key
       	 
        	//set continue to false

        	//break;

       	//Switch end}

    	// move the character
      	//function: moveCursor

   	//check if cursor is at the same location as an asteroid calculate score
     	//function: bool checkForScore

      	//{

      	//score += 19/(difficulty * difficulty);

      	//}

   	//move the level(switch for difficulty)

       	//START { for difficulty switch
      	 
         	//case hard move every 1 cycle aka case 1:

           	//move level
             	//function: move array

         	//break;

         	//case moderate move every 2 cycles aka case 2:
     	 
       	 
             	//check if cycled twice( (cycle / 2.0) == 0.0 )
            	 
               	//{

                  	//move level every 2 cycles
                    	//function: move array
               	//}

         	//break;

         	//case easy move every three cycles aka case 3:
     	 
            	//check if cycled thrice( (cycle / 3.0) == 0.0)
         	 
              	//{

                	//move level every 3 cycles
                  	//function: move array
              	//}

         	//break;

       	//END } for difficulty switch

      	//check if last array x location is 0
     	 
        	//{

           	//set continue program to false
          	 
        	//}

   	//MASTER END }
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

   //c.style string arrays
 	//error

   //set color and clear screen
 	//function: setColor  and clearScreen

   //output titles

 //open file
   //clear ifstream

   //open

   //test if good

   //{

 	//use readScoringAndOutput
   	//function: readScoringAndOutput

   //}

   //else if not good

   //{
   
 	//display error array to screen
 	//for loop

 	//{

    	//output error
      	//function: printCharAt
	 
 	//}

   //}

   //close file
 }

void readScoringAndOutput ( int xLoc, int yLoc, ifstream fin)
 {
 //initialize function and variables
   //variables

   //arrays 1 integer array, and  5 names array

 //read scores
   //for loop
   
   //{
 
 	//read dummy name

 	//read score

 	//assign integer array[index] to score
 
   //}

  //clear ifstream

 //read names
   
 	//for( index = 0; letter != new line; index ++)

 	//{

    	//read letter

    	//assign the letter to names array1[index]

 	//}

 	//read dummy score

 	//for( index = 0; letter != new line; index ++)

 	//{

    	//read letter

    	//assign the letter to names array2[index]

 	//}

 	//read dummy score

 	//for( index = 0; letter != new line; index ++)

 	//{

    	//read letter

    	//assign the letter to names array3[index]

 	//}

 	//read dummy score

 	//for( index = 0; letter != new line; index ++)

 	//{

    	//read letter

    	//assign the letter to names array4[index]

 	//}

 	//read dummy score

 	//for( index = 0; letter != new line; index ++)

 	//{

    	//read letter

    	//assign the letter to names array5[index]

 	//}

 //output scores to screen
   //for(index = 0; index<5; index ++)

   //{

 	//output integer to screen
 	//function: printIntAt( xLoc, index + yLoc, number[index], "left")

   //}

 //output names to screen

   //output first name
 	//function: printStringAt

   //output second name
 	//function: printStringAt

   //output third name
 	//function: printStringAt

   //output fourth name
 	//function: printStringAt

   //output fifth name
 	//function: printStringAt

 }

void quitScreen ()
{
 // initialize variables

   // set color and clear screen
     // function: setColor, clearScreen

   // set x and y location

   // print final message (BIG LETTERS)
     // function: printStringAt
   
   // set new x and y loc

   // set new color

   // print second message
  
  // set new color

   // print funny message and character

        // set new color

        // print picture
            // function: printStringAt

// print exit command



}

void scoring(char fileName[] , int highscore, char username[])
 {
  //initialize function and variables
	//variables
    
	//clear ifstream, open file

  //read numbers into an array

	//for(index = 0; index < 5; index ++)
 
	//{

  	//read dummy name

  	//read score

  	//assign score to number array[index]

	//}

  //check to see if any of the numbers in the array are smaller than the highscore
	//for (index = 0; index < 5; index ++)

	//{
    
  	//if highscore is > number array[index]
 	 
  	//{
 	 
      	//set a bool to true

  	//}

	//}

  //if the bool is false
    
	//{

	//close file ifstream
	//}

  //else re organize
 
	//{
 
 	//close file

  	//Write the new highscore to the file and organize
    	//function: writeHighScore

	//}

 }

void writeHighScore(char fileName[] , int highscore, char username[], int scores[])
 {
  //initialize function
	//variables

	//clear ifstream and open file

  //read names
 
	//for( index = 0; letter != new line; index ++)

	//{

   	//read letter

   	//assign the letter to names array1[index]

	//}

	//read dummy score

	//for( index = 0; letter != new line; index ++)

	//{

   	//read letter

   	//assign the letter to names array2[index]

	//}

	//read dummy score

	//for( index = 0; letter != new line; index ++)

	//{

   	//read letter

   	//assign the letter to names array3[index]

	//}

	//read dummy score

	//for( index = 0; letter != new line; index ++)

	//{

   	//read letter

   	//assign the letter to names array4[index]

	//}

	//read dummy score

	//for( index = 0; letter != new line; index ++)

	//{

   	//read letter

   	//assign the letter to names array5[index]

	//}

  //close file

  //open file with ofstream

  //sort high scores
	 
 	//for index = 0; scores[index] > highscore; index ++)
      	 
   	//{
  	 
      	//count + 1 and it will be initialized at 0

   	//}

	//switch count

	//{
    
  	//case 0
 	 
  	//stream ofstream with numbers in correct order including endlines

  	//break

  	//case 1
 	 
  	//stream ofstream with numbers in correct order including endlines

  	//break

  	//case 2
 	 
  	//stream ofstream with numbers in correct order including endlines

  	//break

  	//case 3
 	 
  	//stream ofstream with numbers in correct order including endlines

  	//break

  	//case 4
 	 
  	//stream ofstream with numbers in correct order including endlines

  	//break

	//}

  //close file
 }



bool checkIfHighScore( char fileName[], int score)
{
  //initialize function
	//variables

  //clear fstream

  //open file

	//test if good
    
	//{
 	 
  	//while .good
 	 
  	//{   
 	 
    	//read dummy name

    	//read number
    	 
      	//if number < score

      	//{

	//close file
   	 
        	//return true

      	//}
 	 
	//close file

  	//}

  	//return false

	//}

  //if file did not open, create a file

  //clear ofstream
 
  //create file

  //output blank scores and names

	//for( index = 0; index <5; index ++)

	//{
    
  	//stream name array , a new line, and then a blank number 0

	//}

  //close file

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

  //for loop( col aka width = 0; width < size; col++)

	//{
    
  	//check if the xyArrLoc[0][col] is equal to x loc of cursor
 	 
    	//{

       	//check if xyArrLoc[1][col] is equal to the cursor y location
      	 
         	//{   
        	 
            	//return true

         	//}
    	//}

	//}

	//If the loop gets to this point, the cursor is not equal to an asteroid loc
  	//return false
  	return false;
  }

void moveCursor( int &xPos, int &yPos, int yVect )
   {
	// initialize function/variables

	// if y vector is not zero, and yPos + yVect are less than screen limits

   	//{

    	// cover up the old marker
      	//function: printCharAt

    	// set yPos to new yPos

   	//}

	// print the marker at the specified location
  	//function: printCharAt

   }

void moveArr( char gameArr[MAX_HEIGHT][MAX_WIDTH], int xyArrLoc[MAX_HEIGHT][MAX_WIDTH] , int &xLoc, int &yLoc )
  {
//initialize variables
  //xLoc = xLoc - 1

//outer loop for row aka height for(row = 0 ; row < maxHeight ; row++ )
  //{
          //inner loop for col aka width for( col = 0; col < maxWidth; col++)
  	//{

	//printCharAt( xloc, yloc, gameArr[row][height] );
	  //function: printCharAt

	 //xloc ++

                //}

//yLoc++

  //}

// for( col = 0; col < maxWidth; col++)

  //{

      //xyArrLoc[0][col] -= 1

   //}	

  }
