//NAME: Zachary Carlson
using namespace std;
//class
class person{
  public:
  person();
  ~person();
  void setAge(int);
  int getAge();
  void setSsn(int);
  int getSsn();
  void setName(char*, char*);
  char* getFirstName();
  char* getLastName();
  void print();
  protected:
  char* firstName;
  char* lastName;
  int age;
  int ssn;
  private:
  };



