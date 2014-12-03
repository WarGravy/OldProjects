//NAME: Zachary Carlson
using namespace std;
class tableau;
class waste;
//class 
class card{
  public:
  friend class deck;
  friend class tableau;
  friend class waste;
  friend class foundation;
  card();
  ~card();
  void operator=(const card& rhs);
  private:
  //functions
  bool setSuit(char*);
  //overloaded operators
  bool operator==(const card&);
  friend ostream& operator<< (ostream& out, const card&);
  //these are required so that when printing cards that are linked, the variable 
      //next no longer is private.
      friend ostream& operator<< (ostream& out, const tableau&);
      friend ostream& operator<< (ostream& out, const waste&);
  //variables
  card* next;
  int rank;
  char* suit;
  char color;
  };



