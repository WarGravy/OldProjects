//Zachary Carlson
//INCLUDE FILES
#include <iostream>
#include <fstream>
//these are needed for declaring srand
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//GLOBAL CONSTANTS
const int MAX_NAME = 25;

//STRUCTURES
/*
Name: Cards
Char Array:Suit of the card
Integer value aka rank:1-13
Char Array:Color of the card  
*/
struct cards{
char suit[MAX_NAME];
char color[6];
int value;
};


//FUNCTION PROTOTYPES

/*
Name: displayScreen
This will display the menu out to the terminal, with the three options of quit, new game, and read a game.
*/
void displayScreen();

/*
Name: shuffleDeck
Generates two random numbers between 0 and 52, increments the two cards by these random numbers and swaps them.
*/
//project2: replace array with a struct array
void shuffleDeck(cards*deck);

/*
Name: writeFile
Writes the waste pile and tableau to the filename by writing the suit of the card, a comma, endline, card value, endline.(repeat)
Example:
Clubs,
1
Diamonds,
8
*/
void writeFile(cards* wptr, char fileName[MAX_NAME],cards* tabptr);

/*
Name: clearTable
loads the entire tableau with empty as the suit value, and 0 as the card value.
*/
void clearTable( cards* sptr);


/*
Name: outputScreen
Reads the waste pile, the foundation, the tableau, and then outputs every card to the screen.
*/
void outputScreen(cards* wptr, cards* ptr, cards* fndptr);

/*
Name: readFile
Reads in the suit and value of each card, wastepile first then the tableau. Then it determines the color of the card.
*/
void readFile( cards* wasteptr, char fileName[MAX_NAME], cards* tabptr);

/*
Name: iniDeck
initialized the deck of cards in order from 1-13, by each suit
*/
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

/*
Name: checkTab
This function checks the top cards of the rows for the tableau to see if there is an ace, if there is it will put the ace in the proper foundation pile.
*/
void checkTab(cards* foundptr, cards* tabptr);

/*
NAME: iniFoundation
This will set the foundation piles to empty and 0 for the value and suit. the layout of the foundation will be a 2d array with x = 13 and y = 4 (note, I am getting weird errors with a 2D array so I'm going to use a 1D array
*/
void iniFoundation(cards* foundptr);
/*
Name: readInSuits
loads the file zacksarrays.txt and reads in the arrays for the suit, that are then copied to the appropriate card arrays.
*/
void readInSuits(char* heart, char* spade, char* diamond, char* club);
/*
Name: assignColor
Initialized the two arrays each pointer points to with the corresponding colors red and black.
*/
void assignColor(char* red, char* black);

//MAIN PROGRAM
int main()
  {
  //PART1:initialize function 
    //initialize variables
    bool quit = false;
    char response = 'z';
    int index = 0;
    int count = 0;
    //initialize pointers and home pointers
    cards*wasteptr;
    cards*deckptr;
    cards*tabptr;
    cards*deckHome;
    cards*tabHome;
    cards*wasteHome;
    cards*found;
    cards*foundHome;
    //dynamically create the arrays
    deckptr = new cards[52];
    wasteptr = new cards[24];
    tabptr = new cards[49];
    found = new cards[52];
    //set home ptr
    deckHome = deckptr;
    wasteHome = wasteptr;
    tabHome = tabptr;
    foundHome = found;
    //initialize text file name
    char* fileName;
    char* fileNameHome;
    fileName = new char[MAX_NAME];
    fileNameHome = fileName;
    //clear out table with empty
      //function: clearTable
      clearTable(tabptr);
    //initialize deckOfCards
      //function: iniDeck
      iniDeck(deckptr);
    //display screen
      //function: displayScreen()
       displayScreen();

  //PART2:run main menu
  while(quit != true)
    //start for loop
    {
     //prompt for response
     cin >> response;
     //start switch
     switch(response)
     //switch open brace
     {
       //new game case
       case 'n':
       case 'N':
	//prompt for filename
	cout << "Please type the name of the file you wish to save your cards to and it's file extension(25 characters max): ";
	cin >> fileName;
        //initialize foundation
        iniFoundation(found);
        //reinitialize pointers for repeat use of the new game(Prevention of segfault)
        wasteptr = wasteHome;
        deckptr = deckHome;
        tabptr = tabHome;
        found = foundHome;
        fileName = fileNameHome;
	//shuffle original card array(deck)
	  //function: shuffleDeck
	  shuffleDeck(deckptr);
	  //load waste pile
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
	     outputScreen(wasteptr, tabptr, found);
	   //display screen/menu options
    	     //function: displayScreen()
    	     displayScreen();
       break;
       //read a game case
       case 'R':
       case 'r':
         //initialize foundation
         iniFoundation(found);
         //reinitialize pointers
         wasteptr = wasteHome;
         deckptr = deckHome;
         tabptr = tabHome;
         found = foundHome;
         fileName = fileNameHome;
	 //prompt user for file name
	 cout << "Please type the name of the file you wish to load and it's file extension(25 characters max): ";
	 cin >> fileName;
	 //read waste pile to waste pile array
	   //function: readFile
 	   readFile( wasteptr, fileName, tabptr);
	 //output to screen
	   //project4: Update the parameters
	   outputScreen(wasteptr, tabptr, found);
	 //display screen/menu options
    	   //function: displayScreen()
    	   displayScreen();
       break;
      //quit case
       case 'q':
       case 'Q':
	//set to true to end menu
        quit = true;
        //reinitialize
        wasteptr = wasteHome;
        deckptr = deckHome;
        tabptr = tabHome;
        found = foundHome;
        fileName = fileNameHome;
	//deallocate space for the arrays
	delete[]deckptr;
	delete[]wasteptr;
	delete[]tabptr;
	delete[]found;
	delete[]fileName;
       break;
      //end for switch
      }
     //end for loop
    }
   //end program
  return 0;
  }

//FUNCTION IMPLEMENTATION
void displayScreen()
 {
 cout<<"Press N to start a New Game"<<endl;
 cout<<"Press R to read a Previous Game"<<endl;
 cout<<"Press Q at anytime to Quit"<<endl;
 }

void shuffleDeck(cards*deck)
 {
  //initialize function
   //initialize variables
   int count=0;
   int randomNum;
   int randomNum2;
   cards temp1;
   //initialize pointer
   cards* ptr;
   cards* ptr2;
   cards* home;
     //assign home pointers
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
	 //incremement the first pointer by the first randomNum
	 ptr += randomNum;
	 //incremement the second point by the second randomNum2
	 ptr2 += randomNum2;
	 //store the first into temp using a pointer
	 temp1 = *ptr;
	 //trade cards
	 *ptr = *ptr2;
	 *ptr2 = temp1;
	 //set pointers back to home	
	 ptr = home;
	 ptr2 = home;
	  }
      //increment loop
      count++;
    }
  //output the function has finished shufflinf the deck
  cout<<"Finished"<<endl;
 }

void iniDeck(cards*ptr)
  {
  //initialize function
    //initialize variables
    int cardIndex;
    int number = 1;
    int counter = 0;
    //initialize pointer
    cards* home;
    home = ptr;
    char* heart;
    char* spade;
    char* diamond;
    char* club;
    char* red;
    char* black;
    //dynamically create space for the arrays
    heart = new char[7];
    spade = new char[7];
    diamond = new char[9];
    club = new char[6];
    red = new char[4];
    black = new char[6];
    //read in the suit names to arrays
      //function: readInSuits
      readInSuits(heart, spade, diamond, club);
    //initialize color arrays
      //function: assignColor
      assignColor(red, black);
  //create deck of cards
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
	}
      //set back to home
      ptr = home;
    //project 4: properly deallocate space for the arrays
    delete[]heart;
    delete[]spade;
    delete[]club;
    delete[]diamond;
    delete[]red;
    delete[]black;
  }

void writeFile(cards* wptr, char fileName[MAX_NAME],cards* tabptr)
  {
  //initialize function
    //initialize variables
    int index;
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
	    //Output the card value, card suit, and a comma to the file
	    fout << (*wptr).suit << ','<< endl << (*wptr).value << endl;
	  }
	//write each card in the table separated by commas on the file
	for(index=0; index < 49; index++, tabptr++)
	  {
	    //Output the card value, card suit, and a comma to the file
	    fout << (*tabptr).suit  << ','<< endl << (*tabptr).value << endl;
	  }
      }
  //close file
  fout.close();
  //set to home
  wptr =homewptr;
  tabptr = hometabptr;
  }

void clearTable( cards* sptr)
  {
  //initialize function
    //initialize variables
    int i;
    //initialize pointers
    char* empty;
    char* emptyHome;
    cards* home;
    //dynamically create array
    empty = new char[7];
    //set home pointers
    emptyHome = empty;
    home = sptr;
      //assign empty
      *empty = 'E';
      empty++;
      *empty = 'm';
      empty++;
      *empty = 'p';
      empty++;
      *empty = 't';
      empty++;
      *empty = 'y';
      empty++;
      *empty = '\0';
      //set back to home
      empty = emptyHome;
  //loop through tableau
  for(i = 0; i < 49; i++)
    {
      //setting the cards in the table to 0s
      (*sptr).value = 0;
      //give the suit name empty
      copyStr((*sptr).suit, empty, 5);
      //increment pointer
      sptr++;
    }
   //set to home and delete empty
   sptr = home;
   delete[]empty;
  }

void outputScreen(cards* wptr, cards* ptr, cards* fndptr)
  {
  //initialize function
    //initialize variables
    int j;
    int index;
    //initialize pointers
    cards*homew;
    cards*homet;
    cards*homef;
      //set home pointers
      homef = fndptr;
      homew = wptr;
      homet = ptr;
  //output to console the first card in waste
  cout<< "Top Card of the Waste Pile: "<<endl;
  cout<< (*wptr).value << (*wptr).suit<<endl;
  cout<< "The Rest of the Waste Pile: "<<endl;
  //output the rest of the wastepile
  wptr++;
  for(j = 0; j < 23; j++, wptr++)
    {
      //output card value and suit
      cout<< (*wptr).value << (*wptr).suit<<endl;
    }
  //check tableau for aces on top
  checkTab(fndptr,ptr);
  //output the foundations
  cout << "Diamond Foundation Pile:"<< (*fndptr).value<<(*fndptr).suit<<endl;
  fndptr += 13;
  cout << "Hearts Foundation Pile:"<< (*fndptr).value<<(*fndptr).suit<<endl;
  fndptr += 13;
  cout << "Spades Foundation Pile:"<< (*fndptr).value<<(*fndptr).suit<<endl;
  fndptr += 13;
  cout << "Clubs Foundation Pile:"<<(*fndptr).value<<(*fndptr).suit<<endl<<endl;
  //output to console the tableau
  for(index = 0; index < 49; index++, ptr ++)
    {
      //table outline	  
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
  //set to home and add space for readability
  cout<<endl<<endl;
  wptr = homew;
  ptr = homet;
  fndptr = homef;
  }

void readFile( cards* wasteptr, char fileName[MAX_NAME], cards* tabptr)
  {
  //initialize function
    //initialize variables
    int index;
    int i, j;
    ifstream fin;
    //value of the card
    int value;
    //suit of the card
    char dummy;
    //initialize pointers
    cards*wasteptrHOME;
    wasteptrHOME = wasteptr;
    cards*tabptrHOME;
    tabptrHOME = tabptr;
  //read and load the names to determine what to load into waste until period
  fin.clear();
  fin.open(fileName);
    if (fin.good())
      {
        //for loop for reading through the file
	for(index = 0; index < 52; index++)
  	  {
	   //load waste pile
	   if(index < 24)
	     {
	      //read in first suit
	      fin >> dummy;
	      i = 0;
	      while(dummy != ',')
	        {
		  (*wasteptr).suit[i] = dummy;
		  fin >> dummy;	
		  i++;
		}
	      //add null char
	      (*wasteptr).suit[i] = '\0';
	      //read in value
	      fin >> value;
	      (*wasteptr).value = value;
	      //incremement the waste pile
	      wasteptr++;
	     }
	   //load tableau
	   else
	     {
	       //read in the first suit
	       fin >> dummy;
	       j = 0;
	       while(dummy != ',')
		  {
		  (*tabptr).suit[j] = dummy;
		  fin >> dummy;
		  j++;
		  }
	       //add null char
	       (*tabptr).suit[j] = '\0';
	       //read in value
	       fin >> value;
	       (*tabptr).value = value;
	       //increment the tableau pointer
	       tabptr++;
	      }
	  }
	//end of if.good
  	}
   fin.close();
  //funct end
    //set to home
    wasteptr = wasteptrHOME;
    tabptr = tabptrHOME;
  }

bool compareStr(char* firPtr, char* secPtr)
  {
  //initialize function
  int index = 0;
  char null = '\0';
  bool result = false;
  bool stop = false;
  //loop through the pointers
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
  //end program
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

void checkTab(cards* foundptr, cards* tabptr)
  {
  //initialize variables
  int i;
  char* empty;
  char* emptyHome;
  empty = new char[7];
  emptyHome = empty;
  cards temp;
  cards* foundHome;
  cards* tabHome;
  foundHome = foundptr;
  tabHome = tabptr;
  //assign empty
   *empty = 'E';
   empty++;
   *empty = 'm';
   empty++;
   *empty = 'p';
   empty++;
   *empty = 't';
   empty++;
   *empty = 'y';
   empty++;
   *empty = '\0';
  //set back to home
  empty = emptyHome;
  //check if card is ace and swap it to the right foundation pile
  for(i = 0; i < 7; i ++)
    {
    //check if ace
    if((*tabptr).value == 1)
      {
   	temp = *tabptr;
	//copy empty into the tab spot
	copyStr((*tabptr).suit, empty, 5);
	(*tabptr).value = 0;
	//check to see what the suit is and insert in appropriate foundation
	if(temp.suit[0] == 'H')
	   foundptr += 13;
	if(temp.suit[0] == 'S')
	   foundptr += 26;
	if(temp.suit[0] == 'C')
	   foundptr += 39;
	//insert
	*foundptr = temp;
	  //after inserting set found back to home
	  foundptr = foundHome;
      }
	//move tabptr
	tabptr += 7 + i;
    }
  //set back to home
  foundptr = foundHome;
  tabptr = tabHome;
  delete[]empty;
  }

//Add a function to initialize the foundation 2d array
void iniFoundation(cards* foundptr)
  {
  //initialize variables
  int i;
  char* empty;
  char* emptyHome;
  empty = new char[7];
  emptyHome = empty;
  cards* home;
  home = foundptr;
  //assign empty
   *empty = 'E';
   empty++;
   *empty = 'm';
   empty++;
   *empty = 'p';
   empty++;
   *empty = 't';
   empty++;
   *empty = 'y';
   empty++;
   *empty = '\0';
  //set back to home
  empty = emptyHome;
  //project 3: change to one loop with one pointer going through the whole thing
  for(i = 0; i < 52; i++)
    {
      //setting the cards in the table to 0s
      (*foundptr).value = 0;
      //give the suit name empty
      copyStr((*foundptr).suit, empty, 5);
      foundptr++;
     }
  foundptr = home;
  delete[]empty;
  }
void readInSuits(char* heart, char* spade, char* diamond, char* club)
  {
  //initialize variables
  ifstream fin;
  char dummy;
  int index;
  char* homeH;
  char* homeS;
  char* homeD;
  char* homeC;
  //set homes
  homeH = heart;
  homeS = spade;
  homeD = diamond;
  homeC = club;
  //open zacksarray.txt
  fin.clear();
  fin.open("zacksarrays.txt");
  if ( fin.good() )
    {
    //read in each array
    //loop 1 for the hearts
    fin>> dummy;
    for(index = 0; index < 6; index++)
  	{
   	  *heart = dummy;
	  heart++;
	  fin>> dummy;
	}
	*heart = '\0';
    //loop 2 for the spades
    for(index = 0; index < 6; index++)
  	{
   	  *spade = dummy;
	  spade++;
	  fin>> dummy;
	}
	*spade = '\0';
    //loop 3 for the diamond
    for(index = 0; index < 8; index++)
  	{
   	  *diamond = dummy;
	  diamond++;
	  fin>> dummy;
	}
	*diamond = '\0';
    //loop 4 for the clubs
    for(index = 0; index < 5; index++)
  	{
   	  *club = dummy;
	  club++;
	  fin>> dummy;
	}
	*club = '\0';
    }
  //set homes
  heart = homeH;
  spade = homeS;
  diamond = homeD;
  club = homeC;
  //close zacksarray.txt
  fin.close();
  }

void assignColor(char* red, char* black)
  {
  //assign red
   *red = 'r';
   red++;
   *red = 'e';
   red++;
   *red = 'd';
   red++;
   *red = '\0';

  //assign black
   *black = 'b';
   black++;
   *black = 'l';
   black++;
   *black = 'a';
   black++;
   *black = 'c';
   black++;
   *black = 'k';
   black++;
   *black = '\0';
  }
