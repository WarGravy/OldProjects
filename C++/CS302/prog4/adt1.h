//Class written by 
using namespace std;
class nodeSort
   {
    friend class linkedListSorted;
    public:
    nodeSort();
    ~nodeSort();
    private:
    int64_t value;
    nodeSort* next;
   };

class linkedListSorted{
   public:
  linkedListSorted();
  linkedListSorted(const linkedListSorted&);
  ~linkedListSorted();
  bool goToBeginning();
  bool goToEnd();
  bool find(int64_t&, int&, int& comparisons);
  bool goToPrior();
  bool insert(int64_t&, int&, int& comparisons);
  void remove(int64_t&, int&, int& comparisons);
  bool replace(int64_t&);
  int getCursor();
  bool empty();
  bool full();
  void clear();
  void print();
  private:
  bool insertAfter(int64_t&);
  bool insertBefore(int64_t&);
  nodeSort* head;
  nodeSort* cursor;
};
