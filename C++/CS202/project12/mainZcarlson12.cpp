//NAME: Zachary Carlson
//INCLUDE FILES
#include<iostream>
#include<fstream>
#include "employee.h"
using namespace std;
//GLOBAL

//PROTOTYPES

//MAIN PROGRAM
int main()
  {
  //initialize variables 
  student s1;
  employee e1;
  char filename[] = "datafile.txt";
  fstream fin;
	//dummy variables
	char dummy, *name1, *name2;
	double dubDummy;
	name1 = new char[30];
	name2 = new char[30];
	int index, z, y, c, num;
  //open file
  fin.clear();
  fin.open(filename);
  if(fin.good()){
 	//run through the file and read out the values
   	for(index = 0; index < 15; index++){
	//read in e or s
	fin >> dummy;
		//EMPLOYEE CASE
	  	if(dummy == 'e'){
		//read in dummy colon
		fin >> dummy;
		fin >> dummy;
			//read in first name
			for(z = 0; dummy != ':'; z++){
			name1[z] = dummy;
			fin >> dummy;
			}
			name1[z] = '\0';
			fin >> dummy;
			//read in last name
			for(c = 0; dummy != ':'; c++){
			name2[c] = dummy;
			fin >> dummy;
			}
			name2[c] = '\0'; 
			//assign name
			e1.setName(name1, name2);
  		//read in age and set it
		fin >> num;
		e1.setAge(num);
		//read in dummy colon
		fin >> dummy;
			//read in SSN
			//read in SSN
			fin >> num;
			//set SSN
			e1.setSsn(num);
		//READ IN Employee Number
			//read colon
			fin >> dummy;
			//read in eNum
			fin >> num;
			//set employee number
			e1.setEmployNum(num);
		//READ IN Title
			//read in colon
			fin >> dummy;
			fin >> dummy;
			//loop through and get title
			for(c = 0; dummy != ':'; c++){
			name1[c] = dummy;
			fin >> dummy;
			}
			name1[c] = '\0';
			e1.setTitle(name1); 
		//READ IN Salary
		fin >> dubDummy;
		e1.setSalary(dubDummy);
		//PRINT EMPLOYEE
		cout << "Employee: " << endl;
		e1.printEmployee();
		cout << endl;
		}

		//STUDENT CASE
		if(dummy == 's'){
		//read in dummy colon
		fin >> dummy;
			fin >> dummy;
			//read in first name
			for(z = 0; dummy != ':'; z++){
			name1[z] = dummy;
			fin >> dummy;
			}
			name1[z] = '\0';
			//read in last name
			fin >> dummy;
			for(c = 0; dummy != ':'; c++){
			name2[c] = dummy;
			fin >> dummy;
			}
			name2[c] = '\0'; 
			//assign name
			s1.setName(name1, name2);
  		//read in age and set it
		fin >> num;
		s1.setAge(num);
		//read in dummy colon
		fin >> dummy;
			//read in SSN
			fin >> num;
			//ssnDummy[0] = num;
			//set SSN
			s1.setSsn(num);
		//READ IN NSHE
			//read colon
			fin >> dummy;
			//read in NSHE
			fin >> num;
			//set employee number
			s1.setNSHE(num);
		//READ IN MAJOR
			//read in colon
			fin >> dummy;
			fin >> dummy;
			//loop through and major
			for(c = 0; dummy != ':'; c++){
			name1[c] = dummy;
			fin >> dummy;
			}
			name1[c] = '\0';
			s1.setMajor(name1); 
		//READ IN GPA
		fin >> dubDummy;
		s1.setGPA(dubDummy);
		//PRINT STUDENT
		cout << "Student: " << endl;
		s1.printStudent();
		cout << endl;
		}
	}
  }
  else{
  cout << "No file named datafile.txt" << endl;
  }
  fin.close();
  //DELETE ARRAYS
	delete[] name1;
	delete[] name2;
  return 0;
  }

