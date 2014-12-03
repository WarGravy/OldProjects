//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #ifdef TYPE
    #if TYPE==1
         #include "list1.h"
    #elif TYPE==2
         #include "list2.h"
    #endif
  #endif
 using namespace std;

//MAIM
int main()
  {
  bool check = false;
  char testchar;
  list test;
  //type 1
  	check = test.insertAfter('z');
  	check = test.insertAfter('a');
  	check = test.insertAfter('c');
  	check = test.insertAfter('k');
	cout << "create array based list with my name: "<< test << endl;

  	check = test.insertBefore('t');
  	check = test.insertBefore('e');
  	check = test.insertBefore('s');
  	check = test.insertBefore('t');	
  	cout << "insert the word test before the k in my name" << test << endl;

  	//remove cases
  	testchar = test.remove();
  	cout << "testing first remove:" << test << endl;
  	testchar = test.remove();
  	cout << "testing second remove:" << test << endl;
  	testchar = test.remove();
  	cout << "testing third remove:" << test << endl;
  	list test2(test);
	//copy constructor
  	if( test == test2){
  	cout << "The Copy Constructor Works!"<<endl;
  	}
  	//function tests
  	check = test.goToBeginning();
  	cout << "Test 'goToBeginning' case: " << test << endl;

  	check = test.goToEnd();
  	cout << "Test 'goToEnd' case: " << test << endl;

    	check = test.goToPrior();
  	cout << "Test 'goToPrior' case: " << test << endl;

  	check = test.goToNext();
  	cout << "Test 'goToNext' case: " << test << endl;

  	check = test.replace('X');
  	cout << "Test 'replace' case with an X: " << test << endl;

  return 0;
  }
