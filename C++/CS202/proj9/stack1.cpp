//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include"stack1.h"
//IMPLEMENTATION
stack::stack(int newMax)
  {
  max = newMax;
  actual = 0;
  top = -1;
  data = new int[max];
  }
stack::stack(const stack& rhs)
  {
  int* rhsarray = rhs.data;
  int i;
  max = rhs.max;
  actual = rhs.actual;
  top = rhs.top;
  data = new int[max];
  int* home = data;
  //loop to add all values of stack
    for(i = 0; i < actual; i++, data++, rhsarray++)
   {
   *data = *rhsarray;
   }
  data = home;
  }
stack::~stack()
  {
  delete[] data;
  }
bool stack::push(int value)
  {
  //initialize variables for the last else situation
  int* temp1 = data;
  int* temp2 = data;
  int i, j, k;
  //check if empty
  if(empty())
    {
    actual = 1;
    top = 0;
    *data = value;
    return true;
    }
  //check if not full
  else if(full())
    {
    return false;
    }
  //else
  else
     {
     actual++;
     //far right destination
     for(j=0;j<actual;j++)
        temp1++;
     //over left one from destination
     for(k=0;k<actual-1;k++)
        temp2++;

     //shuffle values down working from back to front with loop
     	for(i = 0; i < actual; i++){
        *temp1 = *temp2;
        temp1 --;
        temp2 --;
     	}
     *data = value;
     return true;
     }
  }
int stack::pop()
  {
    //initialize variables
    //right
    int* temp1 = data;
    temp1++;
    //left
    int* temp2 = data;
    int i;
    int value = -1;
    //check if empty
    if(empty()){
    return value;
    }
    //else if not empty
    else{
     	//take value out
        value = *data;
     	//shuffle down
        for(i = 0; i < actual; i++){
        *temp2 = *temp1;
        temp1 ++;
        temp2 ++;
     	}
    actual--;
    return value;
    }
  }
bool stack::empty()
  {
  if(actual == 0)
    return true;
  else
    return false;
  }
bool stack::full()
  {
  if( actual == (max))
    return true;
  else
    return false;
  }
bool stack::clear()
  {
  actual = 0;
  top = -1;
  return false;
  }
