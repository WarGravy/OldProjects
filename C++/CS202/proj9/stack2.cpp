//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include"stack2.h"
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
   int i;
   int* home = data;
   if(full())
     {
     return false;
     }
   else
     {
     actual++;
     top++;
     for(i = 0; i < top; i++){
	data++;
 	}
     *data = value;
     data = home;
     return true;
     }
  }
int stack::pop()
  {
    int value = -1;
    int i;
    int* home = data;
    //if empty
    if(empty()){
    return value;
 	}
    //else
    else{
	for(i = 0; i < top; i++){
	data++;
 	}
     	value = *data;
     	data = home;
	top--;
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
