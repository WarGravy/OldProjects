//Zachary Carlson Project 2 Monday
//include files
#include <iostream>
#include <fstream>
//these are needed for declaring srand
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//global const
const int MAX_COL = 52;
const int MAX_NAME = 25;

/*project2: structures
One structure for the deck of cards
Fields:
Char Array:Suit of card
Integer:1-13
Char Array:Color  
*/
struct cards{
char suit[MAX_NAME];
char color[6];
int value;
};


//function prototypes
/*
Project2: Write a string copy, and string compare function.
*/
/*
Name: displayScreen
This will display the menu out to the terminal, with the three options of quit, new game, and read a game
*/
void displayScreen();

/*
Name: shuffleDeck
project 2:generates two random numbers, which are used for the deck struct and swaps two cards in the deck.
*/
//project2: replace array with a struct array
void shuffleDeck(cards deck[52]);

/*
Name: writeFile
project2: writes out the name depending on the suit and value of the card. Separates names of cards by commas
*/
//project2: fix parameters
void writeFile(cards waste[24], char fileName[MAX_NAME],cards table[7][7]);

/*
Name: clearTable
loads the first 2 dimensions of an array with 0, and then the third dimension with the word empty.
*/
/*project2: this function may end up becoming useless after I start coding and //finishing the design*/
void clearTable( cards table[7][7]);


/*
Name: outputScreen

Reads both arrays, the waste pile first, then the table, and outputs the top cards
*/
//project 2: change arrays from char arrays to structure arrays
void outputScreen(cards waste[24], cards tab[7][7]);

/*
Name: readFile
project2: reads the file name and determines the cards value and suit, and color by the name in the file, and then sorts it into the tableau and waste pile
*/
void readFile( cards wastePile[24], char fileName[MAX_NAME], cards tab[7][7]);

/*
Name: iniDeck
initialized the deck of cards
*/
//project2: change array from char to structure array
void iniDeck(cards deckOfCards[52]);

/*
Name: compareStr
reads one character array, and a second character array, checks to see if they are both the same, and then returns either true or false
*/
bool compareStr(char firstStr[MAX_NAME], char secondStr[MAX_NAME]);

/*
Name: copyStr
Takes the copy array, and copies it over to the destination array. 
*/
void copyStr(char destination[MAX_NAME], char copy[MAX_NAME]);

//main program
int main()
  {
  //initialize variables
  bool quit = false;
  int indexTwo = 24;
  char response = 'z';
  int index = 0;
  //arrays
  cards deckOfCards[52];
  cards wastePile[24];
  cards table[7][7];
 
  //initialize text file name
	//project2: set variables for the filename
	char fileName[MAX_NAME] = "cardlist.txt";
	//newgame specific
	int count = 0;
	int col = 0;
	int row = 0;
 	//clear out table with empty
	  //function: clearTable
	  clearTable(table);
        //initialize deckOfCards
	 //function: iniDeck
	iniDeck(deckOfCards);

  //display screen
    //function: displayScreen()
    displayScreen();
  // run main menu
  while(quit != true)
  //start for loop
  {

   cin >> response;
    switch( response )
    //start for switch
    {
    //new game case
    case 'n':
    case 'N':
	//shuffle original card array(deck)
	  //function: shuffleDeck
	  shuffleDeck(deckOfCards);

	  //for loop
	   for( index = 0; index < 24; index++)
	     	{
		//load first 24 cards into 2D array(waste pile)
		wastePile[index] = deckOfCards[index];
		}

	//load last 28 cards into 3D array(tableau)
	  //for loop
	  for( row = 0; row < 7; row++)
	   {
	     for(col = 0; count+col < 7; col++)
		{
		//add card
		table[row][count+col] = deckOfCards[col+indexTwo];
		}
	    count++;
	    //set the correct col index
	    indexTwo = indexTwo +( 7 - count);
	   }
	   //write waste pile to file
	    //function: writeFile
	    writeFile(wastePile, fileName, table);
	//output to screen
	  //function: outputScreen
	    outputScreen(wastePile, table);
	//display screen/menu options

    break;
    //read a game case
    case 'R':
    case 'r':
	//project2: prompt user for file name
	cout << "Please type the name of the file you wish to load and it's file extension(25 characters max): ";
	cin >> fileName;
	//read waste pile to waste pile array
	  //function: readFile
 	   readFile( wastePile, fileName, table);
	//output to screen
	   outputScreen( wastePile, table);
	//display screen/menu options

    break;
    //quit
    case 'q':
    case 'Q':
    quit = true;
    break;
      //end for switch
      }
     //end for loop
    }

   //end program
  return 0;
  }
//function implementations

void displayScreen()
 {
 cout<<"Press N to start a New Game"<<endl;
 cout<<"Press R to read a Previous Game"<<endl;
 cout<<"Press Q at anytime to Quit"<<endl;
 }

void shuffleDeck(cards deck[52])
 {
 //initialize variables
 int count=0;
 int randomNum;
 int randomNum2;
 cards temp1;
  //project3: initialize pointer

  //initialize random
 srand( time(NULL));
 //output to user, telling them the game is shuffling the deck
 cout<< "Shuffling Cards Please wait..."<<endl;
 //shuffle the deck
 while(count < 160)
 	{
	//generate the two random cards that will be swapped
	randomNum = rand() % 100 + 1;
	randomNum = randomNum / 2;
	randomNum2 = rand() % 100 + 1;
	randomNum2 = randomNum2 / 2;
	//swap two cards in the deck
	if(randomNum < 52 && randomNum2 <52 && randomNum != randomNum2)
	  {
	//project 3: incremement the first pointer by the first randomNum

	//project 3: incremement the second point by the second randomNum2

	//project 3: store the first into temp using a pointer

	//project 3: trade cards

	//project 3: set pointers back to home	

	//store in temp for trade
	temp1 = deck[randomNum];
	//trade
	deck[randomNum] = deck[randomNum2];
	deck[randomNum2] = temp1;
	  }
	//increment loop
	count++;
	}
cout<<"Finished"<<endl;
 }

void writeFile(cards waste[24], char fileName[MAX_NAME],cards table[7][7])
  {
  //initialize function
  int index = 0;
	int rowIndex = 0;
	int colIndex = 0;
	int i;
  ofstream fout;
      //initialize pointers

  //create file
  fout.clear();
  fout.open(fileName);
	//check if created
	if(fout.good())
           {
	//write each card, with if statements for the possible names. separated by commas on the file
	while(index < 24)
	  {
	//project3: change to pointer += index
	  fout << waste[index].value;
	//project3: change to the pointer specific to the suit for waste
	//project3: also change from for loop to while loop and increment the pointer
	  for(i=0;waste[index].suit[i] != '\0';i++)
	    {	
	    fout << waste[index].suit[i];
	    }
	    //project2: fix the extra comma
		//add comma
		fout<<','<<endl;
	  //increment loop
	  index++;
	  }
	//after writing each card implement a period as a marker that the waste pile ends and everything after the period is the tableau
	  fout<<'.';
	//write each card/empty from table, with if statements for the possible names. separated by commas on the file
	//project3: swap to using one loop and a pointer for the whole array
	for(rowIndex = 0; rowIndex < 7; rowIndex++)
	  {
	    for(colIndex = 0; colIndex < 7; colIndex++)
		{
		//output value
		fout << table[rowIndex][colIndex].value;
		//output suit or empty
		for(i=0; table[rowIndex][colIndex].suit[i]!= '\0'; i++)
		 {
		   fout << table[rowIndex][colIndex].suit[i];
		 }
	 //insert a comma
	  fout<<','<<endl;
		}
	    }

	   }
  //close file with period marking terminator
  fout<<'.';
  fout.close();
  }
void clearTable( cards table[7][7])
  {
  //initialize variables
  int xIndex, yIndex;
  int i;
  char empty[] = "empty";
  //initialize pointers

  //project 3: change to one loop with one pointer going through the whole thing
  for(xIndex = 0; xIndex < 7; xIndex++)
     {
      for(yIndex = 0; yIndex < 7; yIndex++)
  	{
	//setting the cards in the table to 0s
	table[xIndex][yIndex].value = 0;
	//give the suit name empty	
	    copyStr(table[xIndex][yIndex].suit,empty);
	}
     }
   }
void outputScreen(cards waste[24], cards tab[7][7])
  {
  //initialize function
  int i;
  int index = 0;
  //project3: initialize pointers

  //output to console the first card in waste
	/*project3: use the pointer for the first card in the array and loop to output the whole waste pile*/
	cout<< "Top Card of the Waste Pile: ";
	cout<< waste[0].value;
	//output suit name
	for(i=0; waste[0].suit[i] != '\0';i++)
	   cout<< waste[0].suit[i];

	//output endline
	cout<<endl;

  //Find the top cards of each column for tab[][][]
	//NOTE: Thinking of checking each column individually with if statements and keeping track of which one using an index
	//output to console the top cards
	for(index = 0; index < 7; index++)
	  {
	    switch(index)
	      	{
		case 0:
		cout <<"First column top card: ";
		break;
		case 1:
		cout <<"Second column top card: ";
		break;
		case 2:
		cout <<"Third column top card: ";
		break;
		case 3:
		cout <<"Fourth column top card: ";
		break;
		case 4:
		cout <<"Fifth column top card: ";
		break;
		case 5:
		cout <<"Sixth column top card: ";
		break;
		case 6:
		cout <<"Seventh column top card: ";
		break;
		}
	  cout << tab[index][index].value;
	
	  for(i=0; tab[index][index].suit[i] != '\0';i++)
	  	cout <<tab[index][index].suit[i];

	cout<<endl;
	  }

  }
void readFile( cards wastePile[24], char fileName[MAX_NAME], cards tab[7][7])
  {
  //initialize function
  	int index = 0;
  	int row, col;
	int i;
  	ifstream fin;
      	//value of the card
  	int dummy;
    	//suit of the card
  	char dummy2 = 'z';
    	//checkpoints
  	char com = ',';
  	char term = '.';
	//initialize pointers

  //read and load the names to determine what to load into waste until period
  fin.clear();
  fin.open(fileName);
 
    if (fin.good())
	{
	  //loads in the waste pile	
	  while (dummy2!= term)
	    {
		//read in the value
		fin >> dummy;
		wastePile[index].value = dummy;
		fin>> dummy2;
		//project 3: fix for loop so it stops
		//project 3: also use pointers and not arrays
		for(i=0; dummy2 != com || dummy2 != term; i++)
		   {
		   wastePile[index].suit[i] = dummy2;
		   fin >> dummy2;
		   }
		   //add the null terminator
		    wastePile[index].suit[i] = '\0';
		//increment
		index++;	
	    }
  //read and load the names under case statements to determine what to load into table until period using row outside loop and col inside loop

	for(row = 0; row < 7; row ++)
	  {
	   for(col = 0; col < 7; col++)
		{
	  //loads in the waste pile	
	  while (dummy2!= term)
	    {
		//project 3: fix for loop so it stops for suit
		//project 3: also use pointers and not arrays
		//read in the value
		fin >> dummy;
		tab[row][col].value = dummy;
		fin>> dummy2;
		for(i=0; dummy2 != com || dummy2 != term; i++)
		   {
		   tab[row][col].suit[i] = dummy2;
		   fin >> dummy2;
		   }
		   //add the null terminator
		    tab[row][col].suit[i] = '\0';
		//increment
		index++;	
	    }
		//end of col for loop
		}
	  //end of first for row
	  }
	//end of if.good
  	}
   fin.close();
  //funct end
  }
void iniDeck(cards deckOfCards[52])
  {
	//initialize variables
	int cardIndex;
	int number = 1;
	int counter = 0;
	int i;
	char heart[] = "Hearts";
	char spade[] = "Spades";
	char diamond[] = "Diamonds";
	char club[] = "Clubs";
	char red[] = "Red";
	char black[] = "Black";
	//initialize pointers

	//project3: set to pointers
	for(cardIndex = 0; cardIndex < 52; cardIndex++, number++)
 	  {
	   //make sure the value is between 1-13
	   if(number == 14)
		{
		number = 1;
		//the counter is used for changing suits
		counter++;
		}
	  //set the value of the card
	  deckOfCards[cardIndex].value = number;
	  //set the suit of the card
	  if(counter == 0)
	     {
		copyStr(deckOfCards[cardIndex].suit, heart);
	     }
	  else if(counter == 1)
	     {
	    	copyStr(deckOfCards[cardIndex].suit, spade);
	     }
	  else if(counter == 2)
	     {
		copyStr(deckOfCards[cardIndex].suit, diamond);
	     }
	  else
	     {
		copyStr(deckOfCards[cardIndex].suit, club);
	     }
	//compare strings to set color
	  if(compareStr(deckOfCards[cardIndex].color, heart))
		{
		copyStr(deckOfCards[cardIndex].color, red);
		}
	  else if( compareStr(deckOfCards[cardIndex].suit, diamond))
		{
		copyStr(deckOfCards[cardIndex].color, red);
		}
	  else
		{
		copyStr(deckOfCards[cardIndex].color, black);
		}
	  }
  }

//project 2: Implement the string copy and string compare functions
bool compareStr(char firstStr[MAX_NAME], char secondStr[MAX_NAME])
  {
  //initialize function
  int index = 0;
  char null = '\0';
  bool result = false;
  bool stop = false;
 	//initialize pointers

  //loop project3: fix
	while(stop != false)
	  {
	  //check if the characters are the same and not the null char
	  if( firstStr[index] == secondStr[index] && firstStr[index] != null)
		{
		index++;
		}
	  //else check if they are both nulls
	  else if( firstStr[index] == null && secondStr[index] == null)
		{
		result = true;
		stop = true;
		}
	  //last else, they aren't the same
	  else
		{
		stop = true;
		}
	  }
  return result;
  }
void copyStr(char destination[MAX_NAME], char copy[MAX_NAME])
  {
   //initialize function
   int i;
   //initialize pointer

   //run the loop copying each char over one by one 
	for(i=0; copy[i] != '\0'; i++)
     	  {
	  destination[i] = copy[i];
	  }
	  //assign the null char
	destination[i] = copy[i];
  }
