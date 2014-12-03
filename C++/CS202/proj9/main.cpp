//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #ifdef TYPE
    #if TYPE==1
         #include "stack1.h"
    #elif TYPE==2
         #include "stack2.h"
    #elif TYPE==3
         #include "stack3.h"
    #endif
  #endif
 using namespace std;

//MAIM
int main()
  {
  bool test;
  int i;
  int get;
  stack s1;
	//insert values to s1
  	for (i = 0; i < 9; i++){
  	test = s1.push(i);
        }
	//copy constructor test
  	cout << "copy constructor is used to create stack 2 from stack 1" << endl;
	stack s2(s1);
        //print s1
  	cout << "printing stack 1: "<<endl;
  	for (i = 0; i < 10; i++){
  	get = s1.pop();
  	cout << get << endl;
        }
   	//print s2
  	cout << "printing stack 2: "<<endl;
  	for (i = 0; i < 10; i++){
  	get = s2.pop();
  	cout << get << endl;
        }
  	//clear s1
  	cout << "clearing stack 1 and printing: "<<endl;
  	s1.clear();
        //print s1
  	for (i = 0; i < 10; i++){
  	get = s1.pop();
  	cout << get << endl;
        }

  return 0;
  }
