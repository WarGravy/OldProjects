//NAME: Zachary Carlson
#include "card.h"
using namespace std;

class tableau{
  public:
  friend class deck;
  tableau();
  ~tableau();
  //overloaded operator >>
  friend ostream& operator<< (ostream& out, const tableau&);
  //remove and return
  private:
  bool insertAfter(card,int);
  card returnCursor();
  bool goToTop(int);
  bool checkEmptyCol(int);
  bool goToNext();
  bool moveCursorToBottom(int);
  card* cursor;
  card* col1Top;
  card* col2Top;
  card* col3Top;
  card* col4Top;
  card* col5Top;
  card* col6Top;
  card* col7Top;
};
