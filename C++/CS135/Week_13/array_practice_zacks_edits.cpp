// HEADER FILES
#include <iostream>
using namespace std;

// GLOBAL CONSTANTS
const int MAX_ROWS = 21;
const int MAX_COLS = 60;
const int MAX_ASTEROIDS = 20;
const char SPACE = ' ';

// FUNCTION PROTOTYPES
   // none

// MAIN PROGRAM
int main()
   {
    // initialize variables
    int randomX, randomY;
    char array[MAX_ROWS][MAX_COLS];//note: if we use my method for difficulty,
                                         //our array can go over the capacity
                                         //so we would need to do this:
                                         //char array[MAX_ROWS + 1][MAX_COLS + 1];

    int rowIndex, colIndex, index, xPos=0, yPos=0;
 
     //added by zack-------------------------
      int xyAsteroidLoc[MAX_ROWS][MAX_ASTEROIDS];
      int count = 0, hard = 1, medium = 2, difficulty = 1;
      //---------------------------------------

    // initialize random number generator
    srand ( time(NULL) );

    // initialize array to all 'space'
    for( rowIndex = 0; rowIndex < MAX_ROWS; rowIndex++ )
       {
        for( colIndex = 0; colIndex < MAX_COLS; colIndex++ )
           {
            array[rowIndex][colIndex] = ' ';
           }
       }

    // randomly insert '#' characters into array
    for( index = 0; index < MAX_ASTEROIDS; index++ )
       {
        randomX = rand() % MAX_COLS;
        randomY = rand() % MAX_ROWS;
        //original: array[randomY][randomX] = '#';
        //added by zack:
//-----------------------------------------------
        if(difficulty == hard)
          {
          array[randomY][randomX] = '#';
          //set array x and y locations
          xyAsteroidLoc[0][index] = randomX;
          xyAsteroidLoc[1][index] = randomY;
          }
        else if(difficulty == medium)
          {
          array[randomY][randomX] = '#';
          array[randomY][randomX + 1] = '#';
          //set array x and y locations
          xyAsteroidLoc[0][count] = randomX;
          xyAsteroidLoc[1][count] = randomY;
          xyAsteroidLoc[0][count+1] = randomX + 1;
          xyAsteroidLoc[1][count+1] = randomY;
          count = count + 2;
          }
         else
         {
          array[randomY][randomX] = '#';
          array[randomY][randomX + 1] = '#';
          array[randomY + 1][randomX + 1] = '#';
          array[randomY + 1][randomX] = '#';
          //set array x and y locations
          xyAsteroidLoc[0][count] = randomX;
          xyAsteroidLoc[1][count] = randomY;

          xyAsteroidLoc[0][count+1] = randomX + 1;
          xyAsteroidLoc[1][count+1] = randomY;

          xyAsteroidLoc[0][count+2] = randomX + 1;
          xyAsteroidLoc[1][count+2] = randomY + 1;
          
          xyAsteroidLoc[0][count+3] = randomX;
          xyAsteroidLoc[1][count+3] = randomY+1;
          count = count + 4;
         }
//-------------------------------------------------------------
       }
 
    // print array
    for( rowIndex = 0; rowIndex < MAX_ROWS; rowIndex++ )
       {
        for( colIndex = 0; colIndex < MAX_COLS; colIndex++ )
           {
            xPos = colIndex ;
            yPos = rowIndex ;
            cout << array[ yPos][xPos];
           }
        cout << endl;
       }

    system ("pause");
    return 0;
   }

// FUNCTION IMPLEMENTATION
