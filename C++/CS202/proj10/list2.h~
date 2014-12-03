//NAME: Zachary Carlson
using namespace std;
//node
class node{
public:
node();
char value;
node* next;
};
//array based list 
class list{
  public:
  list();
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
  char getCursor();
  bool empty();
  bool full();
  void clear();
  //overloaded operators
  //operator =
  //list operator=(const list& rhs);
  //operator <<
  //friend ostream& operator<< (ostream& out, const node& rhs);
  //operator ==
  //bool operator==(const list&);
  private:
  node* head;
  node* cursor;
};

