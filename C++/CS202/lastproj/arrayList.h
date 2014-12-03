//NAME: Zachary Carlson
using namespace std;
//class
class arrayList{
  public:
  arrayList(int = 10);
  arrayList(const arrayList&);
  ~arrayList();
  bool goToBeginning();
  bool goToEnd();
  bool goToNext();
  bool goToPrior();
  bool insertAfter(int);
  bool insertBefore(int);
  int remove();
  bool replace(int);
  int getCursor();
  bool empty();
  bool full();
  void clear();
  int setPivot();
  int binarySearch(int, int);
  friend ostream& operator<< (ostream& out, const arrayList& rhs);
  private:
  int max;
  int actual;
  int cursor;
  int* data;
  int pivot;
  };



