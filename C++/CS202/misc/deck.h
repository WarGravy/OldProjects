//NAME: Zachary Carlson
//#include "card.h"
#include "tableau.h"
using namespace std;

class tableau;

class deck{
  public:
  deck();
  ~deck();
  //functions
  bool readDeck(char*);
  bool shuffleDeck();
  void loadTabAndWaste(tableau&);
  //overloaded operators
  deck operator=(const deck&);
  friend ostream& operator<< (ostream& out, const deck&);
  private:
  //variables
  card* head;
  card* cursor;
};

