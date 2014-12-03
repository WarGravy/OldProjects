//Class written by 
using namespace std;

class arrayListUNSorted{
  public:
  arrayListUNSorted(int);
  ~arrayListUNSorted();
  bool insert(int64_t, int& swaps, int& comparisons);
  void clear();
  bool search(int64_t, int& swaps, int& comparisons);
  bool getint(int64_t&);
  void deleteInt(int64_t, int& swaps, int& comparisons);
  void print();
  private:
  int64_t* list;
  int cursor; 
  int rear;
  int size;
};
