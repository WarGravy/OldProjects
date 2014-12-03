//Class written by 
#include <string>
#include <fstream>
typedef char ItemType;
//struct TreeNode; included with adt4
#include "adt4.h"
//enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER}; included with adt4
class iTreeType
{
public:
  iTreeType();                     // constructor
 ~iTreeType();                    // destructor
  iTreeType(const iTreeType& originalTree); 
  void operator=(const iTreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const; 
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void iDeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem (OrderType order, bool& finished);
  void Print(std::ofstream& outFile) const;
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

