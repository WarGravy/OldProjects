//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "student.h"
  using namespace std;
//Implementation
  student::student(){
  cout << "STUDENT CONSTRUCTOR"<<endl;
  gpa = 0.0;
  major = new char[25];
  nsheNumber = 0;
  }
  student::~student(){
  cout << "STUDENT DESTRUCTOR"<<endl;
  gpa = 0.0;
  nsheNumber = 0;
  	if(major != NULL){
 	delete[] major;
  	}
  }
  void student::printStudent(){
  print();
  cout << " NSHE Number: " << nsheNumber << " Major: " << major << " GPA: " << gpa <<endl;
  }
  void student::setNSHE(int newNSHE){
  	nsheNumber = newNSHE;
  }
  int student::getNSHE(){
  return nsheNumber;
  }
  void student::setMajor(char* newMajor){
	int x;
  	for(x = 0; newMajor != '\0' && x < 25; x++){
	major[x] = newMajor[x];
  	}
	major[x] = '\0';
  }
  char* student::getMajor(){
  return major;
  }
  void student::setGPA(double num){
  gpa = num;
  }
  double student::getGPA(){
  return gpa;
  }
