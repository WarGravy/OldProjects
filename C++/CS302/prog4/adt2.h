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
  bool goToPrior(int&);
  bool find(int64_t, int& swaps, int& comparisons);
  bool insert(int64_t, int& swaps, int& comparisons);
  int64_t remove(int& swaps, int& comparisons);
  bool replace(int64_t);
  int getCursor();
  bool empty();
  bool full();
  void clear();
  private:
  node* head;
  node* cursor;
};
