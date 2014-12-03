//NAME: Zachary Carlson
using namespace std;
class nodeList;
class arrayList;
class node{
  friend ostream& operator<< (ostream& out, const nodeList& rhs);
  friend ostream& operator<< (ostream& out, const arrayList& rhs);
  private:
  friend class nodeList;
  node();
  ~node();  
  int value;
  node* next;
  };
