//Class written by Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "adt3.h"

stack::stack(int max){

	top = -1;
	if (max>0){
	size = max;
	}
	else{
	size = 1;
	}
	array = new int[size];

}
stack::~stack(){
delete[] array;
}
int stack::pop(){
	top--;
	return array[top+1];

}
void stack::push(int numb){
	top++;
	array[top] = numb;

}
