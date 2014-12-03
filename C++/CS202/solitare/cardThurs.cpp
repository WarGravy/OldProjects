//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include"cardThurs.h"
  #include <time.h>
  #include <stdio.h>
  #include <stdlib.h>
  using namespace std;

//ADD THESE TO THEIR OWN FILE
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
       //check if they are both nulls
       if(*firPtr == null && *secPtr == null)
	 {
	   result = true;
	   stop = true;
	 }
      //else check if the characters are the same and not the null char
      else if( *firPtr == *secPtr && *firPtr != null)
         {
           index++;
	   firPtr += index;
	   secPtr += index;
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

int strlen(char* c)
  {
  int ctr = 0;
  while(*c != '\0')
    {
    c++;
    ctr++;
    }
  return ctr;
  }

void copystr(char* dest, char* cpy)
  {
  while(*cpy != '\0')
   {
   *dest = *cpy;
    dest++;
    cpy++;
   }
  }
///////////////////////////
//CARD CLASS IMPLEMENTATION
///////////////////////////
  card::card()
     {
     suit = NULL;
     rank = 0;
     color = 'o';
     }
  card::card(const card& rhs)
  {
  int i;
  rank = rhs.rank;
  color = rhs.color;
  i = strlen(rhs.suit);
  suit = new char[i];
  copystr(suit, rhs.suit);
  }
  card::~card()
     {
     if(suit != NULL)
       delete []suit;
       
     rank = 0;
     color = 'o';
     }

  int card::getRank()
     {
     return rank;
     }

  bool card::setRank(int i)
     {
      if(i >= 1 && i <= 13)
	{
   	rank = i;
        return true;
	}
      else
	return false;
     }

  char card::getColor()
     {
     return color;
     }

  bool card::setColor(char c)
     {
     if( c == 'r' || c == 'b')
     	{
	color = c;
	return true;
	}
     else
        return false;
     }

  bool card::setSuit(char* temp)
     {
     int i;
     if(temp != NULL || suit != NULL)
       {
       i = strlen(temp);
       suit = new char[i];
       copystr(suit, temp);
       return true;
       }
     else
      return false;
     }

void card::print()
  {
  if( suit != NULL)
  cout << rank << suit << ": ";
  
  if(color == 'r')
  cout << "Red";

  if(color == 'b')
  cout << "Black";

  if( suit == NULL)
  cout << "Can't print, suit is NULL!";
  }



///////////////////////////
//DECK CLASS IMPLEMENTATION
///////////////////////////
  deck::deck()
  {
  dptr = new card[52];
  }
  deck::deck(const deck& rhs)
  {
  	int i;
	dptr = new card[52];
	card* home;
 	home = dptr;
  	for(i = 0; i < 52; i++){
	dptr[i].setRank(rhs.dptr[i].rank);
  	dptr[i].setColor(rhs.dptr[i].color);
  	dptr[i].setSuit(rhs.dptr[i].suit);
  	}
	dptr = home;
  }
  deck::~deck()
  {
  delete []dptr;
  }
  void deck::createDeck()
  {
  //initialize suits
  char diamond[] = "Diamond";
  char spade[] = "Spade";
  char heart[] = "Heart";
  char club[] = "Club";
  card* homeptr;
  homeptr = dptr;
  int i = 1;
  int ctr;
  //loop and set cards
   for(ctr = 0; ctr < 52; ctr++){
   (*dptr).rank = i;
   //hearts
   if(ctr < 13){
   (*dptr).setSuit(heart);
   (*dptr).setColor('r');
      }
   //spades
   else if(ctr >= 13 && ctr <26){
   (*dptr).setSuit(spade);
   (*dptr).setColor('b');
      }
   //diamonds
   else if(ctr >= 26 && ctr < 39){
   (*dptr).setSuit(diamond);
   (*dptr).setColor('r');
      }
   //clubs
   else{
   (*dptr).setSuit(club);
   (*dptr).setColor('b');
      }
    i++;
    dptr++;
   if( i == 14){
   i = 1;
   }
   }
  dptr = homeptr;
  }
  void deck::shuffle()
  {
   {
  //initialize function
   //initialize variables
   int count=0;
   int randomNum;
   int randomNum2;
   card temp1;
   //initialize pointer
   card* ptr;
   card* ptr2;
   card* home;
     //assign home pointers
     home = dptr;
     ptr = home;
     ptr2 = home;
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
	 //temp1 = ptr
         temp1.setSuit((*ptr).suit);
         temp1.rank = (*ptr).rank;
         temp1.color = (*ptr).color;
	 //trade cards
         //ptr = ptr2
	 (*ptr).setSuit((*ptr2).suit);
         (*ptr).rank = (*ptr2).rank;
         (*ptr).color = (*ptr2).color;
         //ptr2 = temp
	 (*ptr2).setSuit(temp1.suit);
         (*ptr2).rank = temp1.rank;
         (*ptr2).color = temp1.color;
	 //set pointers back to home	
	 ptr = home;
	 ptr2 = home;
	  }
      //increment loop
      count++;
    }
    //output the function has finished shufflinf the deck
    cout<<"Finished"<<endl<<endl;
    }
  }


  void deck::dealDeck(card* waste, card* tab){
    //initialize variables
    card* home;
    home = dptr;
    int i, j;
    //declare empty
    char empty[] = "Empty";
    	
	//deal to waste
    	for(j=0; j < 24; j++){
    	(*waste).setSuit((*dptr).suit);
    	(*waste).rank = (*dptr).rank;
    	(*waste).color = (*dptr).color;
    	waste++;
    	dptr++;
    	}

   //load Tableau with emptys in appropriate locations
  	for(i = 0; i < 49; i ++, tab++){
	//place empty cards in correct spots
        if( i == 7 || i == 14 || i == 15){
  	(*tab).setSuit(empty);
	}
	else if( i >= 21 && i <= 23){
	(*tab).setSuit(empty);
	}
	else if( i >= 28 && i <= 31){
	(*tab).setSuit(empty);
	}
	else if( i >= 35 && i <= 39){
	(*tab).setSuit(empty);
	}
	else if( i >= 42 && i <= 47){
	(*tab).setSuit(empty);
	}
	//else place deal the card to the tableau
	else{
	(*tab).setSuit((*dptr).suit);
	(*tab).setRank((*dptr).rank);
	(*tab).setColor((*dptr).color);
	dptr++;
	}
        
  //end of loop
  }
  //set deck point back
  dptr=home;
  }

  void deck::printDeck()
  {
  //initialize variables
  card* homeptr;
  homeptr = dptr;
  int i;
  
  	for(i = 0; i < 52; i++){
        (*dptr).print();
        cout << endl;
        dptr++;
  	}
   dptr = homeptr;
  }

///////////////////////////
//PILE CLASS IMPLEMENTATION
///////////////////////////
