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
void shuffleDeck(cards*deck);

/*
Name: writeFile
project2: writes out the name depending on the suit and value of the card. Separates names of cards by commas
*/
//project2: fix parameters
void writeFile(cards* wptr, char fileName[MAX_NAME],cards* tabptr);

/*
Name: clearTable
loads the first 2 dimensions of an array with 0, and then the third dimension with the word empty.
*/
/*project2: this function may end up becoming useless after I start coding and //finishing the design*/
void clearTable( cards* sptr);


/*
Name: outputScreen

Reads both arrays, the waste pile first, then the table, and outputs the top cards
*/
//project 4: add the paramater for the foundation arrays2D
void outputScreen(cards* wptr, cards* ptr);

/*
Name: readFile
project2: reads the file name and determines the cards value and suit, and color by the name in the file, and then sorts it into the tableau and waste pile
*/
void readFile( cards wastePile[24], char fileName[MAX_NAME], cards tab[49]);

/*
Name: iniDeck
initialized the deck of cards
*/
//project2: change array from char to structure array
void iniDeck(cards*ptr);

/*
Name: compareStr
reads one character array, and a second character array, checks to see if they are both the same, and then returns either true or false
*/
bool compareStr(char* firPtr, char* secPtr);

/*
Name: copyStr
Takes the copy array, and copies it over to the destination array. 
*/
void copyStr(char* ptr, char* copyptr, int size);

//Project 4 Prototypes
//Add a function that checks the tableau and loads any Ace Top cards into the correct foundation

//Add a function to initialize the foundation 2d array


//main program
int main()
  {
  //initialize variables
  bool quit = false;
  int indexTwo = 24;
  char response = 'z';
  int index = 0;
  //pointers
    //project4: declare the pointers for the foundation
  cards*wasteptr;
  cards*deckptr;
  cards*tabptr;
  cards*deckHome;
  cards*tabHome;
  cards*wasteHome;
  //arrays
    //project4: declare 2d foundation array
	//project 4: properly allocate space for the arrays
  deckptr = new cards[52];
  wasteptr = new cards[24];
  tabptr = new cards[49];
	//set home ptr
	deckHome = deckptr;
	wasteHome = wasteptr;
	tabHome = tabptr;
  //initialize text file name
	//project2: set variables for the filename
	char fileName[MAX_NAME] = "cardlist.txt";
//////////////////////////////////
	//newgame specific
	int count = 0;
	int col = 0;
	int row = 0;
 	//clear out table with empty
	  //function: clearTable
	  clearTable(tabptr);
        //initialize deckOfCards
	 //function: iniDeck
	iniDeck(deckptr);

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
     //this is not useless code, this is here to prevent a segfault for repeat cases
     wasteptr = wasteHome;
     deckptr = deckHome;
     tabptr = tabHome;
     // the above is not useless code, this is here to prevent a segfault
	//shuffle original card array(deck)
	  //function: shuffleDeck
	  shuffleDeck(deckptr);
	  //for loop
	   for( index = 0; index < 24; index++, wasteptr++, deckptr++)
	     	{
		//load first 24 cards into 2D array(waste pile)
		*wasteptr = *deckptr;
		}
	//load last 28 cards(tableau)
	  for(count = 0; count < 28; count++, tabptr++, deckptr++)
	   {
	   //add card
	   *tabptr = *deckptr;
	    /*move the pointer appropriately so that each repeating column has one more card than the previous column*/
	    if(count == 6)
	     tabptr++;
	    else if(count == 12)
             tabptr+=2;
	    else if(count == 17)
	     tabptr+=3;
	    else if(count == 21)
	     tabptr+= 4;
	    else if(count == 24)
	     tabptr+= 5;
	    else if(count == 26)
             tabptr += 6;
	     }
	     //set pointers back to home for functions
	     wasteptr = wasteHome;
             deckptr = deckHome;
             tabptr = tabHome;
	   //write waste pile to file
	    //function: writeFile
	    writeFile(wasteptr, fileName, tabptr);
	//output to screen
	  //function: outputScreen
	    //project4: Update the parameters
	    outputScreen(wasteptr, tabptr);
	//display screen/menu options
    	  //function: displayScreen()
    	   displayScreen();
    break;
    //read a game case
    case 'R':
    case 'r':
     //reinitialize
     wasteptr = wasteHome;
     deckptr = deckHome;
     tabptr = tabHome;
	//project2: prompt user for file name
	cout << "Please type the name of the file you wish to load and it's file extension(25 characters max): ";
	cin >> fileName;
	//read waste pile to waste pile array
	  //function: readFile
 	   readFile( wasteptr, fileName, tabptr);
	//output to screen
	    //project4: Update the parameters
	   outputScreen( wasteptr, tabptr);
	//display screen/menu options
    	  //function: displayScreen()
    	   displayScreen();

    break;
    //test cases
    case 't':
	int i;
    iniDeck(deckptr);

    for(i = 0; i < 52; i++, deckptr++)
    cout << (*deckptr).value << (*deckptr).suit << (*deckptr).color <<endl;

    break;
    //quit
    case 'q':
    case 'Q':
    quit = true;
     //reinitialize
     wasteptr = wasteHome;
     deckptr = deckHome;
     tabptr = tabHome;
	//project 4: properly deallocate space for the arrays
	delete[]deckptr;
	delete[]wasteptr;
	delete[]tabptr;
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

void shuffleDeck(cards*deck)
 {
/*project 4: this function already does the requirement of randomizing the cards*/
 //initialize variables
 int count=0;
 int randomNum;
 int randomNum2;
 cards temp1;
  //project3: initialize pointer
  cards* ptr;
  cards* ptr2;
  cards* home;
	home = deck;
	ptr = deck;
	ptr2 = deck;
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
	ptr += randomNum;
	//project 3: incremement the second point by the second randomNum2
	ptr2 += randomNum2;
	//project 3: store the first into temp using a pointer
	temp1 = *ptr;
	//project 3: trade cards
	*ptr = *ptr2;
	*ptr2 = temp1;
	//project 3: set pointers back to home	
	ptr = home;
	ptr2 = home;
	  }
	//increment loop
	count++;
	}
cout<<"Finished"<<endl;
 }
void iniDeck(cards*ptr)
  {
/*project 4: this function already does the requirement of setting the cards in order*/
  //initialize variables
  int cardIndex;
  int number = 1;
  int counter = 0;
  int i;
  //initialize pointer
  cards* home;
  home = ptr;
  char* heart;
  char* spade;
  char* diamond;
  char* club;
  char* red;
  char* black;
  //project 4: properly allocate space for the arrays
  char heart1[] = "Hearts";
  char spade1[] = "Spades";
  char diamond1[] = "Diamonds";
  char club1[] = "Clubs";
  char red1[] = "Red";
  char black1[] = "Black";
  heart = heart1;
  spade = spade1;
  diamond = diamond1;
  club = club1;
  red = red1;
  black = black1;

	//project3: set to pointers
	for(cardIndex = 0; cardIndex < 52; cardIndex ++, ptr ++, number++)
 	  {
	   //make sure the value is between 1-13
	   if(number == 14)
		{
		number = 1;
		//the counter is used for changing suits
		counter++;
		}
	  //set the value of the card
	  (*ptr).value = number;
	  //set the suit of the card
	  if(counter == 0)
	     {
		copyStr((*ptr).suit, heart, 6);
	     }
	  else if(counter == 1)
	     {
	    	copyStr((*ptr).suit, spade, 6);
	     }
	  else if(counter == 2)
	     {
		copyStr((*ptr).suit, diamond, 8);
	     }
	  else
	     {
		copyStr((*ptr).suit, club, 5);
	     }
	//compare strings to set color(project4: fix)
	  if(compareStr((*ptr).suit, club))
		{
		copyStr((*ptr).color, black, 5);
		}

	  else if(compareStr((*ptr).suit, spade))
		{
		copyStr((*ptr).color, black, 5);
		}

	  else
		{
		copyStr((*ptr).color, red, 3);
		}
	  //TEST for the suits, the values, and colors of the entire deck
	  //cout << "TEST" << (*ptr).suit << (*ptr).value << (*ptr).color<<endl;
	  }
	//set back to home
	ptr = home;
//project 4: properly deallocate space for the arrays
  }

void writeFile(cards* wptr, char fileName[MAX_NAME],cards* tabptr)
  {
  //initialize function
  int index;
	int rowIndex = 0;
	int colIndex = 0;
	int i;
  ofstream fout;
      //initialize pointers
	cards*homewptr;
        homewptr = wptr;
	cards*hometabptr;
	hometabptr = tabptr;

  //create file
  fout.clear();
  fout.open(fileName);
	//check if created
	if(fout.good())
           {
	//write each card in waste separated by commas on the file
	for(index=0; index < 24; index++, wptr++)
	  {
	//project3: Output the card value, card suit, and a comma to the file
	  fout << (*wptr).suit << ','<< endl << (*wptr).value << endl;
	  }
	//write each card in the table separated by commas on the file
	for(index=0; index < 49; index++, tabptr++)
	  {
	//project3: Output the card value, card suit, and a comma to the file
	  fout << (*tabptr).suit  << ','<< endl << (*tabptr).value << endl;
	  }

	   }
  fout.close();
	//set to home
        wptr =homewptr;
	tabptr = hometabptr;
  }
void clearTable( cards* sptr)
  {
  //initialize variables
  int i;
  char empty[] = "empty";
  cards* home;
  home = sptr;
  //project 3: change to one loop with one pointer going through the whole thing
   for(i = 0; i < 49; i++)
	{
	//setting the cards in the table to 0s
	(*sptr).value = 0;
	//give the suit name empty
	copyStr((*sptr).suit, empty, 5);
	sptr++;
	}
sptr = home;

   }
//project 4: add the paramater for the foundation arrays2D
void outputScreen(cards* wptr, cards* ptr)
  {
  //initialize function
  int i = 0;
  int j;
  int index;
  //project3: initialize pointers
  cards*homew;
  cards*homet;
  //output to console the first card in waste
	/*project3:Output the entire wastepile*/
	cout<< "Top Card of the Waste Pile: "<<endl;
	cout<< (*wptr).value << (*wptr).suit<<endl;
	cout<< "The Rest of the Waste Pile: "<<endl;
	//output the rest of the wastepile
	wptr++;
	for(j = 0; j < 23; j++, wptr++)
     	  {
	  cout<< (*wptr).value << (*wptr).suit<<endl;
	  }
	//Project 4 
/*Call the function to check the table and output any Ace Cards on the top of a column to the proper foundation*/

	//project 4: output the foundations

	//output to console the tableau
	for(index = 0; index < 49; index++, ptr ++)
	  {	  
		if( 0 == index) 
		cout<<endl<<endl<<"COL 1 | COL 2 | COL 3 | COL 4 | COL 5 | COL 6 | COL 7"<<endl;

		else if( 7 == index) 
		cout<<endl<<endl;
		
		else if( 14 == index) 
		cout<<endl<<endl;
		
		else if( 21 == index) 
		cout<<endl<<endl;
		
		else if( 28 == index) 
		cout<<endl<<endl;
		
		else if( 35 == index) 
		cout<<endl<<endl;
		
		else if( 42 == index) 
		cout<<endl<<endl;
		
	  //output each of the cards for the column
	    cout << (*ptr).value << (*ptr).suit << " | ";

	  }
	cout<<endl<<endl;
  wptr = homew;
  ptr = homet;
  }
void readFile( cards wastePile[24], char fileName[MAX_NAME], cards tab[49])
  {
  //initialize function
  	int index;
	int i;
	bool wasteLoop = true;
  	ifstream fin;
      	//value of the card
  	int dummy;
    	//suit of the card
  	char dummy2;
    	//checkpoints
  	char com = ',';
	//initialize pointers
	cards*wasteptr;
  	wasteptr = &wastePile[0];
	cards*tabptr;
	tabptr = &tab[0];
  //read and load the names to determine what to load into waste until period
  fin.clear();
  fin.open(fileName);
    if (fin.good())
	{
	//Project4: Figure out why it is skipping a card and not reading correctly
	//read in the first waste pile value
	fin >> dummy;
	(*wasteptr).value = dummy;

	/*start loop to read the name of the suit, increment the card, read in comma/term,  then read in the value*/
	for(i = 0; wasteLoop == true; i++ )
	  {
	  //read in suit name with inner loop
	    fin >> dummy2;
	    for(index = 0; dummy2 != ','; index++)
   	      {
	       (*wasteptr).suit[index] = dummy2;
	 	fin >> dummy2;
	      }
	     (*wasteptr).suit[index] = '\0';
	    wasteptr++;
	    if(i == 24)
		wasteLoop = false;
	    else
	   	{
		fin >> dummy;
		(*wasteptr).value = dummy;
		}
	    
	   }
	//Project4: Figure out why it is skipping a card and not reading correctly
/* It most likely skips a card before this comment in the previous loop*/

       //read in tablaeu
	//read in the first tab value
	fin >> dummy;
	(*tabptr).value = dummy;

	/*start loop to read the name of the suit, increment the card, read in comma/term,  then read in the value*/
	for(i = 0; i < 49; i++ )
	  {
	  //read in suit name with inner loop
	    fin >> dummy2;
	    for(index = 0; dummy2 != ','; index++)
   	      {
	       (*tabptr).suit[index] = dummy2;
	 	fin >> dummy2;
	      }
	     (*tabptr).suit[index] = '\0';
	    tabptr++;

	    if( i <= 47 )
	   	{
		fin >> dummy;
		(*tabptr).value = dummy;
		}
	    
	  }  

	//end of if.good
  	}
   fin.close();
  //funct end
  }


//project 2: Implement the string copy and string compare functions
bool compareStr(char* firPtr, char* secPtr)
  {
  //initialize function
  int index = 0;
  char null = '\0';
  bool result = false;
  bool stop = false;
 
  //loop project3: fix
	while(stop != true)
	  {
	  //check if the characters are the same and not the null char
	  if( *firPtr == *secPtr && *firPtr != null)
		{
		index++;
		firPtr += index;
		secPtr += index;
		}
	  //else check if they are both nulls
	  else if( *firPtr == null && *secPtr == null)
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
void copyStr(char* ptr, char* copyptr, int size)
  {
   //initialize function
   int i;
   //run the loop copying each char over one by one 
	for(i=0; i < size ; i++)
	  {
	  *ptr = *copyptr;
	  ptr++;
	  copyptr++;
	  }
	*ptr = '\0';	
  }

//Project 4 Implementations
//Add a function that checks the tableau and loads any Ace Top cards into the correct foundation

//Add a function to initialize the foundation 2d array
