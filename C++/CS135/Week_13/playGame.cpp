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
void startGame ( int difficultySet, int &score );

void startGame ( int difficultySet,  int &score )
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
