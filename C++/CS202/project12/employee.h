//NAME: Zachary Carlson
#include "student.h"
using namespace std;

class employee: public person{
  public:
  employee();
  ~employee();
  void printEmployee();
  void setEmployNum(int);
  int getEmployNum();
  void setTitle(char*);
  char* getTitle();
  void setSalary(double);
  double getSalary();
  protected:
  private:
  int employNum;
  char* title;
  double salary;
};
