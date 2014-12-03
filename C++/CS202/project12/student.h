//NAME: Zachary Carlson
#include "person.h"
using namespace std;

class student: public person{
  public:
  student();
  ~student();
  void printStudent();
  void setNSHE(int);
  int getNSHE();
  void setMajor(char*);
  char* getMajor();
  void setGPA(double);
  double getGPA();
  protected:
  private:
  int nsheNumber;
  char* major;
  double gpa;
};

