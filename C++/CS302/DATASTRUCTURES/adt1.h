//Class written by 
using namespace std;
struct nodeSort
   {
    int value;
    nodeSort* next;
   };

class linkedListSorted{
   public:
  linkedListSorted();
  linkedListSorted(const linkedListSorted&);
  ~linkedListSorted();
  bool goToBeginning();
  bool goToEnd();
  bool find(int);
  bool goToPrior();
  bool insert(int);
  int remove();
  bool replace(int);
  int getCursor();
  bool empty();
  bool full();
  void clear();
  private:
  bool insertAfter(int);
  bool insertBefore(int);
  nodeSort* head;
  nodeSort* cursor;
};
