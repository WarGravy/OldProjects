//NAME: Zachary Carlson
#include "waste.h"
using namespace std;

class tableau{
  public:
  friend class deck;
  tableau();
  ~tableau();
  //overloaded operator >>
  friend ostream& operator<< (ostream& out, const tableau&);
  //remove and return
  card removeAndReturn(int, int);
  bool insertAfter(card,int);
  bool goToTop(int);
  private:
  card returnCursor();
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
