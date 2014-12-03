//NAME: Zachary Carlson
//class forward
class deck;
//class 
class card{
  public:
  card();
  ~card();
  int getRank();
  bool setRank(int);
  char getColor();
  bool setColor(char);
  bool setSuit(char*);
  void print();
  char* suit;
  int rank;
  char color;
  //make into it's own file
  bool compareStr(char*, char*);
  int strlen(char*);
  void copystr(char*, char*);
};

class deck{
  public:
  deck();
  ~deck();
  void createDeck();
  void shuffle();
  //combine the dealTo into one function
  void dealToTableau(card*);
  void dealToWaste(card*);
  void printDeck();
  //fix
  friend bool card::compareStr(char*, char*);
  friend int card::strlen(char*);
  friend void card::copystr(char*, char*);
  private:
  card* dptr;  
};

//add pile class
