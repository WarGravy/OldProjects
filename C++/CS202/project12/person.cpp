//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "person.h"
  using namespace std;
//IMPLEMENTATION
  person::person(){
  cout << "PERSON CONSTRUCTOR" << endl;
  age = 0;
  ssn = 0;
  firstName = new char[30];
  lastName = new char[30];
  }
  person::~person(){
  cout << "PERSON DESTRUCTOR" << endl;
  age = 0;
  ssn = 0;
  	if(firstName != NULL){
	delete[] firstName;
  	}
  	if(lastName != NULL){
	delete[] lastName;
  	}
  }
  void person::setAge(int i){
  age = i;
  }
  int person::getAge(){
  return age;
  }
  void person::setSsn(int z){
	ssn = z;
  }
  int person::getSsn(){
  return ssn;
  }
  void person::setName(char* fir, char* las){
	int x, y;
  	for(x = 0; fir != '\0' && x < 30 ; x++){
	firstName[x] = fir[x];
	//cout << firstName[x] << endl;
  	}
	firstName[x] = '\0';

  	for(y = 0; las != '\0' && y < 30 ; y++){
	lastName[y] = las[y];
	//cout << lastName[y] << endl;
  	}
	lastName[y] = '\0';
  }
  char* person::getFirstName(){
  return firstName;
  }
  char* person::getLastName(){
  return lastName;
  }
  void person::print(){
  cout << "First Name: "<< firstName << " Last Name: "<< lastName << " Age: "<< age <<" SSN: "<< ssn << endl;
  }
