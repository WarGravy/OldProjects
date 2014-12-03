//NAME: Zachary Carlson
#include "arrayList.h"
#include "node.h"
using namespace std;
//class
class nodeList{
  public:
  nodeList();
  ~nodeList();
  int removeInt();
  bool insert(int);
  bool empty()const;
  friend ostream& operator<< (ostream& out, const nodeList& rhs); 
  private:
  node* cursor;
  node* data;
  };



