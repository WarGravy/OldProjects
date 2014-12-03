//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "employee.h"
  using namespace std;
//IMPLEMENTATION
  employee::employee(){
  cout << "EMPLOYEE CONSTRUCTOR"<<endl;
  salary = 0.0;
  title = new char[25];
  employNum = 0;
  }

  employee::~employee(){
  cout << "EMPLOYEE DESTRUCTOR"<<endl;
  salary = 0.0;
  	if(title != NULL){
 	delete[] title;
  	}
  employNum = 0;
  }

  void employee::printEmployee(){
  print();
  cout << " EMPLOYEE Number: " << employNum << " Title: " << title << " Salary: " << salary <<endl;
  }

  void employee::setEmployNum(int emp){
  	employNum = emp;
  }

  int employee::getEmployNum(){
	return employNum;
  }

  void employee::setTitle(char* newTitle){
	int x;
  	for(x = 0; newTitle != '\0' && x < 25; x++){
	title[x] = newTitle[x];
  	}
	title[x] = '\0';
  }

  char* employee::getTitle(){
  	return title;
  }
  void employee::setSalary(double zack){
	salary = zack;
  }
  double employee::getSalary(){
	return salary;
  }
