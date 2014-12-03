//Class written by Zachary Carlson
using namespace std;
// NODE CLASS
struct node
   {
    int value;
    node* next;
   };

class linkedListUNSorted{
   public:
  linkedListUNSorted();
  linkedListUNSorted(const linkedListUNSorted&);
  ~linkedListUNSorted();
  bool goToBeginning();
  bool goToEnd();
  bool goToPrior();
  bool find(int);
  bool insert(int);
  int remove();
  bool replace(int);
  int getCursor();
  bool empty();
  bool full();
  void clear();
  private:
  node* head;
  node* cursor;
};
