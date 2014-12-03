//NAME: Zachary Carlson
using namespace std;
struct item{
  int id;
  char description[13];
  double price;
  char tax;
  };

class inventory{
  public:
  inventory();
  ~inventory();
  bool insertAtEnd(item);
  void clear();
  bool search(int);
  bool getItem(item&);
  void print();
  private:
  item* archive;
  int cursor; 
  int rear;
  };
