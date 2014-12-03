//Class written by 
using namespace std;

class arrayListUNSorted{
  public:
  arrayListUNSorted(int);
  ~arrayListUNSorted();
  bool insertAtEnd(int);
  void clear();
  bool search(int);
  bool getint(int&);
  void deleteInt(int);
  void print();
  private:
  int* list;
  int cursor; 
  int rear;
  int size;
};
