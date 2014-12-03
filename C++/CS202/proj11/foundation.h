//NAME: Zachary Carlson
#include "card.h"
using namespace std;

//stack array based
/*
These piles are really basic array based stacks. There are three implementations of array based stacks and I chose the varient where my stack grows and moves the top toward the end of the array. There is no need for an actual variable in this design. When top = -1 I know the array is empty.
*/
class foundation{
  public:
  foundation();
  ~foundation();
  card pop();
  bool push(card&);
  //overloaded operators
  //>>
  friend ostream& operator<< (ostream& out, const foundation&);
  private:
  int top;
  int actual;
  card* pile;
};
