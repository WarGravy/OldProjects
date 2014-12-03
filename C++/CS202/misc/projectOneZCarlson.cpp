//Zachary Carlson Project 1
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
 
//function prototypes
/*
Name: displayScreen
This will display the menu out to the terminal, with the three options of quit, new game, and read a game
*/
void displayScreen();

/*
Name: shuffleDeck
Uses pass by reference for a basic 2D array, clears the array, loads it with the basic 52 cards of the deck, and random/y shuffles the array
1st row consists of the characters 2-10, J, Q, K, A
2nd row consists of the characters S (spade), H(hearts), C(clubs), D(diamonds)
*/
void shuffleDeck(char cards[2][MAX_COL] );

/*
Name: writeFile
writes both arrays into the file, using periods to separate the waste from the tableau. commas separate each card
*/
void writeFile(char waste[2][24], char fileName[MAX_NAME],char table[7][7][MAX_NAME]);

/*
Name: clearTable
loads the first 2 dimensions of an array with 0, and then the third dimension with the word empty.
*/
void clearTable( char array[7][7][MAX_NAME]);


/*
Name: outputScreen

Reads both arrays, the waste pile first, then the table, and outputs the top cards
*/
void outputScreen(char waste[2][24], char tab[7][7][MAX_NAME]);

/*
Name: readFile
Reads a file and loads in the cards into two arrays, aka the waste pile and the tableau
*/
void readFile( char wastePile[2][24], char fileName[MAX_NAME], char tab[7][7][MAX_NAME]);

/*
Name: iniDeck
initialized the deck of cards
*/
void iniDeck(char deckOfCards[2][MAX_COL]);
//main program
int main()
  {
  //initialize variables
  bool quit = false;
  int indexTwo = 24;
  char response = 'z';
  char deckOfCards[2][MAX_COL];
  char wastePile[2][24];
  char table[7][7][MAX_NAME];
  int index = 0;

  
  //initialize text file name
	char fileName[] = "cardlist.txt";
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
	//load first 24 cards into 2D array(waste pile)
	  //for loop
	   for( index = 0; index < 23; index++)
	     	{
		wastePile[0][index] = deckOfCards[0][index];
		wastePile[1][index] = deckOfCards[1][index];
		}

	//load last 28 cards into 3D array(tableau)
	  //for loop
	  for( row = 0; row < 7; row++)
	   {
	     for(col = 0; count+col < 7; col++)
		{
		//add card
		table[row][count+col][0] = deckOfCards[0][col+indexTwo];
		//add card name abbrev.
		table[row][count+col][1] = deckOfCards[1][col+indexTwo];
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
    break;
    //read a game case
    case 'R':
    case 'r':	
	//read waste pile to waste pile array
	  //function: readFile
 	   readFile( wastePile, fileName, table);
	//output to screen
	   outputScreen( wastePile, table);
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

void shuffleDeck(char cards[2][MAX_COL])
 {
 //initialize variables
 int count=0;
 int randomNum;
 int randomNum2;
 char temp1;
 char temp2;

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
	//store in temp for trade
	temp1 = cards[0][randomNum];
	temp2 = cards[1][randomNum];
	//trade
	cards[0][randomNum] = cards[0][randomNum2];
	cards[1][randomNum] = cards[1][randomNum2];
	cards[0][randomNum2] = temp1;
	cards[1][randomNum2] = temp2;
	  }
	//increment loop
	count++;
	}
cout<<"Finished"<<endl;
 }

void writeFile(char waste[2][24], char fileName[MAX_NAME],char table[7][7][MAX_NAME])
  {
  //initialize function
  int index = 0;
	int rowIndex = 0;
	int colIndex = 0;
  char dummy1;
  char dummy2;
  ofstream fout;
  //create file
  fout.clear();
  fout.open(fileName);
	//check if created
	if(fout.good())
           {
	//write each card, with if statements for the possible names. separated by commas on the file
	while(index < 24)
	  {
	  dummy1 = waste[0][index];
	  dummy2 = waste[1][index];
		//switch statements for names
		switch(dummy1)
		{
		case 'A':
		fout << "Ace";
		break;
		case '2':
		fout << "Two";
		break;
		case '3':
		fout << "Three";
		break;
		case '4':
		fout << "Four";
		break;
		case '5':
		fout << "Five";
		break;
		case '6':
		fout << "Six";
		break;
		case '7':
		fout << "Seven";
		break;
		case '8':
		fout << "Eight";
		break;
		case '9':
		fout << "Nine";
		break;
		case 'T':
		fout << "Ten";
		break;
		case 'J':
		fout << "Jack";
		break;
		case 'Q':
		fout << "Queen";
		break;
		case 'K':	
		fout << "King";
		break;
		}
		//switch statements for names
		switch(dummy2)
		  {
		  case 'S':
		  fout <<"Spade";
		  break;
		  case 'H':
		  fout <<"Heart";
		  break;
		  case 'C':
		  fout <<"Clubs";
		  break;
		  case 'D':
		  fout<<"Diamonds";
		  break;
		  }
		//add comma
		fout<<','<<endl;
	  //increment loop
	  index++;
	  }
	//after writing each card implement a period as a marker that the waste pile ends and everything after the period is the tableau
	  fout<<'.';
	//write each card/empty from table, with if statements for the possible names. separated by commas on the file
	for(rowIndex = 0; rowIndex < 7; rowIndex++)
	  {
	    for(colIndex = 0; colIndex < 7; colIndex++)
		{
		//assign dummys
		dummy1 = table[rowIndex][colIndex][0];
		dummy2 = table[rowIndex][colIndex][1];
		//switch statements for names
		switch(dummy1)
		{
		case '0':
		fout << "Empty";
		break;
		case 'A':
		fout << "Ace";
		break;
		case '2':
		fout << "Two";
		break;
		case '3':
		fout << "Three";
		break;
		case '4':
		fout << "Four";
		break;
		case '5':
		fout << "Five";
		break;
		case '6':
		fout << "Six";
		break;
		case '7':
		fout << "Seven";
		break;
		case '8':
		fout << "Eight";
		break;
		case '9':
		fout << "Nine";
		break;
		case 'T':
		fout << "Ten";
		break;
		case 'J':
		fout << "Jack";
		break;
		case 'Q':
		fout << "Queen";
		break;
		case 'K':	
		fout << "King";
		break;
		}
		//switch statements for names
		switch(dummy2)
		  {
		  case 'S':
		  fout <<"Spade";
		  break;
		  case 'H':
		  fout <<"Heart";
		  break;
		  case 'C':
		  fout <<"Clubs";
		  break;
		  case 'D':
		  fout<<"Diamonds";
		  break;
		  }
	 //insert a second period for an ending terminator
	  fout<<','<<endl;
		}
	    }

	   }
  //close file
  fout<<'.';
  fout.close();
  }
void clearTable( char array[7][7][MAX_NAME])
  {
  int xIndex, yIndex, zIndex = 0;

  for(xIndex = 0; xIndex < 7; xIndex++)
     {
      for(yIndex = 0; yIndex < 7; yIndex++)
  	{
	array[xIndex][yIndex][zIndex] = '0';
	array[xIndex][yIndex][zIndex + 1] = 'E';
	}
     }
   }

void outputScreen(char waste[2][24], char tab[7][7][MAX_NAME])
  {
  //initialize function
  char dummyWaste1;
	char dummyWaste2;
  char dummyTab1;
  	char dummyTab2;
  int index = 0;
  //output to console the first card in waste
	dummyWaste1 = waste[0][0];
	dummyWaste2 = waste[1][0];
	cout<< "Top Card of the Waste Pile: ";
	  //switch
	  	switch(dummyWaste1)
		{

		case 'A':
		cout << "Ace";
		break;
		case '2':
		cout << "Two";
		break;
		case '3':
		cout << "Three";
		break;
		case '4':
		cout << "Four";
		break;
		case '5':
		cout << "Five";
		break;
		case '6':
		cout << "Six";
		break;
		case '7':
		cout << "Seven";
		break;
		case '8':
		cout << "Eight";
		break;
		case '9':
		cout << "Nine";
		break;
		case 'T':
		cout << "Ten";
		break;
		case 'J':
		cout << "Jack";
		break;
		case 'Q':
		cout << "Queen";
		break;
		case 'K':	
		cout << "King";
		break;
		}
		//switch statements for names
		switch(dummyWaste2)
		  {
		  case 'S':
		  cout <<"Spade";
		  break;
		  case 'H':
		  cout <<"Heart";
		  break;
		  case 'C':
		  cout <<"Clubs";
		  break;
		  case 'D':
		  cout<<"Diamonds";
		  break;
		  }
	cout<<endl;
  //Find the top cards of each column for tab[][][]
	//NOTE: Thinking of checking each column individually with if statements and keeping track of which one using an index
	//output to console the top cards
	for(index = 0; index < 7; index++)
	  {
	  dummyTab1 = tab[index][index][0];
	  dummyTab2 = tab[index][index][1];
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
	  	switch(dummyTab1)
		{

		case 'A':
		cout << "Ace";
		break;
		case '2':
		cout << "Two";
		break;
		case '3':
		cout << "Three";
		break;
		case '4':
		cout << "Four";
		break;
		case '5':
		cout << "Five";
		break;
		case '6':
		cout << "Six";
		break;
		case '7':
		cout << "Seven";
		break;
		case '8':
		cout << "Eight";
		break;
		case '9':
		cout << "Nine";
		break;
		case 'T':
		cout << "Ten";
		break;
		case 'J':
		cout << "Jack";
		break;
		case 'Q':
		cout << "Queen";
		break;
		case 'K':	
		cout << "King";
		break;
		}
		//switch statements for names
		switch(dummyTab2)
		  {
		  case 'S':
		  cout <<"Spade";
		  break;
		  case 'H':
		  cout <<"Heart";
		  break;
		  case 'C':
		  cout <<"Clubs";
		  break;
		  case 'D':
		  cout<<"Diamonds";
		  break;
		  }
	cout<<endl;
	  }

  }
void readFile( char wastePile[2][24], char fileName[MAX_NAME], char tab[7][7][MAX_NAME])
  {
  //initialize function
  int index = 0;
  int row, col;
  char dummy;
  char dummy2;
  char com = ',';
  char term = '.';
  ifstream fin;
  //read and load the names under case statements to determine what to load into waste until period
  fin.clear();
  fin.open(fileName);
    if (fin.good())
	{
	
	  while (dummy!= term)
	    {
		fin >> dummy;
		wastePile[0][index] = dummy;
		fin>>dummy;
		while(dummy != 'D' || 
		dummy != 'C' || 
		dummy != 'H' || 
		dummy != 'S' || 
		dummy != term || 
		dummy != com)
		  {
			if (dummy == 'D')
			   {
			   wastePile[1][index] = dummy;
			   }
			else if(dummy == 'C')
			   {
			   fin >> dummy2;
				if(dummy2 == 'l')
				  {
				  wastePile[1][index] = dummy;
				  }
			    //continue loop
				else
				{
			    	  dummy = 'z';
				}
			   }
			else if(dummy == 'H')
			  {
				fin >> dummy2;
				if(dummy2 == 'e')
				  {
				  wastePile[1][index] = dummy;
				  }
				//continue loop
				else
				  {
				  dummy = 'z';
				  }
				  
			  }
			else if(dummy == 'S')
			   {
			     fin >> dummy2;
				if(dummy2 == 'p')
				  {
				  wastePile[1][index] = dummy;
				  }
			    //continue loop
				else
				{
			    	  dummy = 'z';
				}
			   }
			fin>>dummy;
			}
		//increment
		index++;	
	    }
  //read and load the names under case statements to determine what to load into table until period using row outside loop and col inside loop

	for(row = 0; row < 7; row ++)
	  {
	   for(col = 0; col < 7; col++)
		{
	 	 while (dummy!= term)
	    	{
		fin >> dummy;
		tab[row][col][0] = dummy;
		fin>>dummy;
		while(dummy != 'D' || 
		dummy != 'C' || 
		dummy != 'H' || 
		dummy != 'S' ||
		dummy != 'E' || 
		dummy != term || 
		dummy != com)
			{
			if (dummy == 'D')
			   {
			   tab[row][col][1] = dummy;
			   }
			else if(dummy == 'C')
			   {
			   fin >> dummy2;
				if(dummy2 == 'l')
				  {
				  tab[row][col][1] = dummy;
				  }
			    //continue loop
				else
				{
			    	  dummy = 'z';
				}
			   }
			else if(dummy == 'H')
			  {
				fin >> dummy2;
				if(dummy2 == 'e')
				  {
				  tab[row][col][1] = dummy;
				  }
				//continue loop
				else
				  {
				  dummy = 'z';
				  }
				  
			  }
			else if(dummy == 'S')
			   {
			   fin >> dummy2;
				if(dummy2 == 'p')
				  {
				  tab[row][col][1] = dummy;
				  }
			    //continue loop
				else
				{
			    	  dummy = 'z';
				}
			   }
			else if( dummy == 'E')
			  {
			   tab[row][col][1] = dummy;
			  }
			fin>>dummy;
			}
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
void iniDeck(char deckOfCards[2][MAX_COL])
  {
	int cardIndex;
	int hearts = 0;
	int spades = 13;
	int diamonds = 26;
	int clubs = 39;

	for(cardIndex = 0; cardIndex < 50; cardIndex++)
	  {
	deckOfCards[0][cardIndex] = 'A';
	deckOfCards[0][cardIndex+1] = '2';
	deckOfCards[0][cardIndex+2] = '3';
	deckOfCards[0][cardIndex+3] = '4';
	deckOfCards[0][cardIndex+4] = '5';
	deckOfCards[0][cardIndex+5] = '6';
	deckOfCards[0][cardIndex+6] = '7';
	deckOfCards[0][cardIndex+7] = '8';
	deckOfCards[0][cardIndex+8] = '9';
	deckOfCards[0][cardIndex+9] = 'T';
	deckOfCards[0][cardIndex+10] = 'J';
	deckOfCards[0][cardIndex+11] = 'Q';
	deckOfCards[0][cardIndex+12] = 'K';

	cardIndex+= 12;
	  }

	while(hearts < 13)
  	  {
	   deckOfCards[1][hearts] = 'H';
	   hearts++;
	  }
	while(spades < 26)
  	  {
	   deckOfCards[1][spades] = 'S';
	   spades++;
	  }
	while(diamonds < 39)
  	  {
	   deckOfCards[1][diamonds] = 'D';
	   diamonds++;
	  }
	while(clubs < 52)
  	  {
	   deckOfCards[1][clubs] = 'C';
	   clubs++;
	  }
  }
