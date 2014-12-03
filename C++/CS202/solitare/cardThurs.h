//NAME: Zachary Carlson
//class forward
class deck;
//class 
class card{
  public:
  card();
  card(const card&);
  ~card();
  //overloaded assignment operator
  //overloaded not equals operator(check notes)
  int getRank();
  bool setRank(int);
  char getColor();
  bool setColor(char);
  bool setSuit(char*);
  void print();
  //make into it's own file
  friend bool compareStr(char*, char*);
  friend int strlen(char*);
  friend void copystr(char*, char*);
  char* suit;
  int rank;
  char color;

};

class deck{
  public:
  deck();
  deck(const deck&);
  ~deck();
  void createDeck();
  void shuffle();
  void dealDeck(card*, card*);
  void printDeck();
  //overloaded equals operator
  //fix
  friend class card;
  friend bool compareStr(char*, char*);
  friend int strlen(char*);
  friend void copystr(char*, char*);
  private:

  card* dptr;  
};

//add pile class(no implmentation)
class pile{
  public:
  //parameterized constructor/destructor
  //flip
  //move
  //friend
  private:
  card* pileptr;
  int size;
  int position;
};
