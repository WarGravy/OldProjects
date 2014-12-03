//NAME: Zachary Carlson
using namespace std;
#include "foundation.h"

class card;
//queue based and node based
class waste{
  public:
  waste();
  ~waste();
  //functions
  bool endQueue(card);
  card deQueue();
  bool isEmpty();
  void empty();
  //overloaded operators
  void operator=(const waste&);
  friend ostream& operator<< (ostream& out, const waste&);
  private:
  card* front;
  card* rear;
  int size;
};
