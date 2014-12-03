//NAME: Zachary Carlson
//include files
 #include "cardMON.cpp"
//class 
class card{
  public:
  card();
  ~card();
  int getRank();
  bool setRank(int);
  char getColor();
  bool setColor(char);
  //noteToSelf think through suit functions 
  bool setSuit(char*);
  void print();
  private:
  char* suit;
  int rank;
  char color;
  bool compareStr(char*, char*);
  int strlen(char*);
  void copystr(char*, char*);
};
