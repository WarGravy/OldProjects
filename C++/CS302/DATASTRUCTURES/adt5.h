//Class written by 
using namespace std;

class arrayListSorted{
  public:
  arrayListSorted(int);
  ~arrayListSorted();
  bool insert(int);
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
