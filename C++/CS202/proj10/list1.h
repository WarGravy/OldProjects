//NAME: Zachary Carlson
using namespace std;
//array based list 
class list{
  public:
  list(int = 10);
  list(const list&);
  ~list();
  bool goToBeginning();
  bool goToEnd();
  bool goToNext();
  bool goToPrior();
  bool insertAfter(char);
  bool insertBefore(char);
  char remove();
  bool replace(char);
  int getCursor();
  bool empty();
  bool full();
  void clear();
  //overloaded operators
  //operator =
  list operator=(const list& rhs);
  //operator <<
  friend ostream& operator<< (ostream& out, const list& rhs);
  //operator ==
  bool operator==(const list&);
  private:
  int max;
  int actual;
  int cursor;
  char* data;
};

