//Coded and Implemented by Zachary Carlson
using namespace std;

//structs
struct item{
  char customerName[20];
  char specialName[20];
  };
//classes
class booking{
  public:
  booking();
  ~booking();
  //inserts the item into booking alphabetically by customer name
  bool insert(item);
  //gets item at cursor
  bool getItem(item&);
  //clears the booking list setting rear and cursor to 0
  void clear();
  /*sets the cursor to the item with the matching customer name, if not sets cursor back to original location*/
  bool search(char array[20]);
/*sets the cursor to the item with the matching special name, if not sets cursor back to original location*/
  bool searchSpecial(char array[20]);
  //checks if full
  bool isFull();
  //returns the amount of items in archive(rear+1)
  int getLength();
  //deletes item at cursor and shuffles everything appropriately
  bool deleteItem();
  //outputs archive to screen
  void status();
  //writes to filename the entire archive
  bool outputToFile(ofstream&);
  //overloaded operator =
  void operator=(const booking&);
  //Sets the id(used when dealing with arrays of bookings)
  void setID(char* id);
  //this variable is only used when calling an array of bookings
  char* id;
  void resetCursor();
  bool moveNext();
  private:
  //copies item to cursor
  void copyItem(item);
  item* archive;
  int cursor; 
  int rear;
  };
//Protoypes for arrays of bookings
/*This is serves the purpose of adding a booking into an array of bookings and inserts it in
the correctly sorted position by alphabetical IDs. Size represents the current amount of bookings in the booking array*/
bool addBooking(booking array[], booking newList, int size);
/*This functions searches for matching c style strings and returns the integer of where 
in the array the booking is.Returns -1 if not found. Size represents the current amount of bookings in the booking array* */
int searchId(char*, booking array[], int size);
/*checks to see if the newString is suppose to be sorted before the original string (alphabetically)*/
bool sortStringBefore(char* original, char* newString);
//Checks to make sure strings are identical
bool compareString(char* original, char* rhs);
