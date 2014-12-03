//NAME: Zachary Carlson
using namespace std;
//class 
class card{
  private:
  friend class deck;
  friend class tableau;
  card();
  ~card();
  //functions
  bool setSuit(char*);
  //overloaded operators
  card operator=(const card& rhs);
  bool operator==(const card&);
  friend ostream& operator<< (ostream& out, const card& rhs);
  //variables
  card* next;
  int rank;
  char* suit;
  char color;
  };



