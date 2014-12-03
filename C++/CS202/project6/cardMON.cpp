//NAME: Zachary Carlson
//INCLUDE FILES
  #include<iostream>

//IMPLEMENTATION
  card::card()
     {
     suit = NULL;
     rank = 0;
     color = o;
     }
  card::~card()
     {
     if(suit != NULL)
       delete []suit;
       
     rank = 0;
     color = o;
     }
  int card::getRank()
     {
     return rank;
     }
  bool card::setRank(int i)
     {
      if(i >= 1 && i <= 13)
	{
   	age = i;
        return true;
	}
      else
	return false;
     }
  char card::getColor();
     {
     return color;
     }
  bool card::setColor(char c);
     {
     if( c == 'r' || c == 'b')
     	{
	color = c;
	return true;
	}
     else
        return false;
     }
  bool card::setsuit(char* temp)
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
  cout << rank << ' ' << suit << ' ' << color;
  else
  cout << "Can't print, suit is NULL!";
  }
bool card::compareStr(char* firPtr, char* secPtr)
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
int card::strlen(char* c)
  {
  int ctr = 0;
  
  while(*c != '\0')
    {
    c++;
    ctr++;
    }
  return ctr;
  }
void card::copystr(char* dest, char* cpy)
  {
  while(*cpy != '\0')
   {
   *dest = *cpy;
    dest++;
    cpy++;
   }
  }
