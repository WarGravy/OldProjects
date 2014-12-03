#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include "proj6.h"

using namespace std;

//prototypes
void command(graph&, char* str[], ofstream& fout);
void commandNoOutput(graph&, char* str[]);
bool compareStr(char* key, char* source);
bool searchForMatch(const char* key, const char* source);
void outputRelationLogic(int path[], int pathIndex, char gen);
//returns the length of a cstyle string
int cstringLength(const char*);
void lowercase(char& temp);

int main()
   {
	//initialize variables
	graph familyTree;
	bool runProgram = true;
	char** str;
	str = new char* [7];
	int z;
	ofstream fout;
	ifstream fin;
	for(z = 0; z< 6; z++){
	str[z] = new char[30];
	}
		//read Family.txt
		fin.clear();
		fin.open("Family.txt");
		fin.clear();
		fin>>str[0];
		fin>>str[1];
		fin>>str[2];
			if(compareStr(str[1], (char*)"AND")){
				fin>>str[3];
				fin>>str[4];
				fin>>str[5];
			}
			else{
			str[3][0] = '0';
			}
		cout << "Reading Family.txt"<<endl;
		cout << str[1]<<endl;
		while(fin.good()){
	
			commandNoOutput(familyTree, str);
			fin>>str[0];
			fin>>str[1];
			fin>>str[2];
			cout<<str[1]<<endl;
			cout << "HERE 1, 2 , 3"<<endl;
			if(compareStr(str[1], (char*)"AND")){
			cout << "HERE compare finished"<<endl;
				fin>>str[3];
			cout << "HERE 4th"<<endl;
				fin>>str[4];
			cout << "HERE 5th"<<endl;
				fin>>str[5];
			cout << "HERE 6th"<<endl;
			}
			else{
			str[3][0] = '\0';
			}
		}
		fin.close();
		cout << "Finished Reading Family.txt"<<endl;
	//open ofstream file Family.trn
	fout.clear();
	fout.open("Family.trn");
	fout.clear();
	//loop through commands (quit will end program)
	while(runProgram == true){	
		//enter command line
		str[0][0] ='\0';
		str[1][0] ='\0';
		str[2][0] ='\0';
		str[3][0] ='\0';
		str[4][0] ='\0';
		str[5][0] ='\0';
		cout << "Please enter the number of words your command line will contain. Example, 1, 3, 4, or 6"<<endl;
		cin >> z; 
		cin >> str[0];
		if(z >= 2){
		cin >> str[1];
		}
		if(z>= 3){
		cin >> str[2];
		}
		if(z >= 4){
		cin >> str[3];
		}
		if(z>= 5){
		cin >> str[4];
		}
		if(z>= 6){
		cin >> str[5];
		}
			//check for quit
			if(compareStr(str[0], (char*)"quit") || compareStr(str[0], (char*)"QUIT") || compareStr(str[0], (char*)"q") || compareStr(str[0], (char*)"Q")){
			runProgram = false;
			}
			//else run command
			else{
			command(familyTree, str, fout);
			}
    	}
    //familyTree.addVert( (char*)"john", 'm' );
    //familyTree.addVert( (char*)"martha", 'f' );
    return 0;
   }
//IMPLEMENTATION
void command(graph& familyTree, char* str[], ofstream& fout){
	int i=0;
	int j;
	int path[40];
	int pathIndex = 0;
	char gen;
	//drop down to all lowercases
	cout << "Forcing Lower Cases."<<endl;
	for(j=0; j < 6; j++){
    		for(i=0; str[j][i]!= '\0';i++){
       			lowercase(str[j][i]);
      		}
	}
		cout << endl;
			//IF STATEMENTS ACT AS CASES
				//CASE 1: FEMALE EXISTS
				if(searchForMatch("female", str[0]) && searchForMatch("exists",str[2])){
 					familyTree.addVert(str[1], 'f');
				}
				//CASE 2: MALE EXISTS
				else if(searchForMatch("male", str[0]) && searchForMatch("exists",str[2])){
                                       familyTree.addVert(str[1], 'm');
				}
				//CASE 3: AND BEGET SON
				else if(searchForMatch("and", str[1]) && searchForMatch("beget",str[3]) && searchForMatch("son",str[4])){
					familyTree.addVert(str[5],'m');
					familyTree.setChild(str[0], str[5]);
				}
				//CASE 4: AND BEGET DAUGHTER
				else if(searchForMatch("and", str[1]) && searchForMatch("beget",str[3]) && searchForMatch("daughter",str[4])){
					familyTree.addVert(str[5],'f');
					familyTree.setChild(str[0], str[5]);
				}
				//CASE 5: MARRIES
				else if(searchForMatch("marries", str[1])){
					familyTree.setSpouse(str[0], str[2]);
				}
				//CASE 6: PRINT 'S NOT IN TEXT FILE
				else if(searchForMatch("print", str[0])){
					//remove 's
				}
				//CASE 7: RELATION AND
				else if(searchForMatch("relation", str[0]) && searchForMatch("and",str[2])){
					//find relation
					familyTree.bfs(str[1], str[3], path, pathIndex, gen);
					outputRelationLogic(path, pathIndex, gen);
				}
				//CASE 8: not valid command
				else{
				cout << "Invalid Command from the input text file." << endl;
				}

}
void commandNoOutput(graph& familyTree, char* str[]){
	int i=0;
	int j;
	//drop down to all lowercases
	for(j=0; j < 6; j++){
    	for(i=0;str[j][i]!= '\0';i++){
       		lowercase(str[j][i]);
      		}
		}
			//IF STATEMENTS ACT AS CASES
				//CASE 1: FEMALE EXISTS
				if(searchForMatch((char*)"female", str[0]) && searchForMatch((char*)"exists",str[2])){
 					familyTree.addVert(str[1], 'f');
				}
				//CASE 2: MALE EXISTS
				else if(searchForMatch((char*)"male", str[0]) && searchForMatch((char*)"exists",str[2])){
                                       familyTree.addVert(str[1], 'm');
				}
				
				//CASE 3: AND BEGET SON
				else if(searchForMatch((char*)"and", str[1]) && searchForMatch((char*)"beget",str[3]) && searchForMatch((char*)"son",str[4])){
					familyTree.addVert(str[5],'m');
					familyTree.setChild(str[0], str[5]);
				}
				//CASE 4: AND BEGET DAUGHTER
				else if(searchForMatch((char*)"and", str[1]) && searchForMatch((char*)"beget",str[3]) && searchForMatch((char*)"daughter",str[4])){
					familyTree.addVert(str[5],'f');
					familyTree.setChild(str[0], str[5]);
				}
				//CASE 5: MARRIES
				else if(searchForMatch((char*)"marries", str[1])){
					familyTree.setSpouse(str[0], str[2]);
				}
				//CASE 6: PRINT 'S NOT IN TEXT FILE
				//CASE 7: RELATION AND NOT IN TEXT FILE
				//CASE 8: not valid command
				else{
				cout << "Invalid Command from the input text file." << endl;
				}

}
bool compareStr(char* key, char* source){
	int index;
	for(index=0; (key[index]!='\0' && source[index]!='\0') && (key[index] == source[index]) && (index < 20);index++){
	}
	if(key[index] == '\0' && source[index] =='\0'){
	return true;
	}
	return false;
}
int cstringLength(const char* key){
  int index=0;
  if(key != NULL){
	while(key[index] != '\0'){
		index++;
	}
  }
  return index;
}
bool searchForMatch(const char* key, const char* source){
  int index = 0;
  int cycle = 0;
  int sourceLen = cstringLength(source);
  int keyLen = cstringLength(key);
  //check if possible(lengths)
  if(keyLen > sourceLen){
	//if not possible return false
	return false;
	}
  while(source[cycle] != '\0' && keyLen <= sourceLen){	
  	//look for first occurence of the first letter of key
  	while(key[index] != source[cycle] && keyLen <= sourceLen){
		cycle++;
		sourceLen--;
	}

   	if(keyLen > sourceLen){
		return false;
	}
	//loop to see if match
	while(key[index] == source[cycle + index]){
	index++;
		//if match return true
		if(index == keyLen){
			return true;
		}
	}
  //loop up to second occurence of the first letter
  cycle++;
  index = 0;
  }
  return false;
}
void outputRelationLogic(int path[], int pathIndex, char gen){
	bool flag = false;
	cout << pathIndex << endl;
	if(pathIndex == 1){
		//check for spouse
		if(path[0] == path[1]){
			if(gen == 'm'){
			cout << "Husband" << endl;
			flag = true;
			}
			else{
			cout << "Wife"<<endl;
			flag = true;
			}
		}
		//check for children
		else if(path[0] < path[1]){
			if(gen == 'm'){
			cout << "Son" << endl;
			flag = true;
			}
			else{
			cout << "Daughter"<<endl;
			flag = true;
			}
		}
		
		//check for parents
		else if(path[0] > path[1]){
			if(gen == 'm'){
			cout << "Father" << endl;
			flag = true;
			}
			else{
			cout << "Mother"<<endl;
			flag = true;
			}
		}
	}
	else if(pathIndex == 2){
		//check for siblings
		if(path[0] == path[1]){
			if(gen == 'm'){
			cout << "Brother" << endl;
			flag = true;
			}
			else{
			cout << "Sister"<<endl;
			flag = true;
			}
		}
		//check for grandparents
		else if(path[0] > path[1]){
			if(gen == 'm'){
			cout << "Grandfather" << endl;
			flag = true;
			}
			else{
			cout << "Grandmother"<<endl;
			flag = true;
			}
		}
	}
	else if(pathIndex == 3){
		//check for uncles/aunts
		if(path[0] + 1 == path[1]){
			if(gen == 'm'){
			cout << "Uncle" << endl;
			flag = true;
			}
			else{
			cout << "Aunt"<<endl;
			flag = true;
			}
		}
	}
	else if(pathIndex == 4){
	//check for cousins
	 	if(path[0] == path[1]){
		cout << "Cousin"<<endl;
		flag = true;
		}
	}
	if(flag == false){
	cout << "Too Distant."<<endl;
	}
}

void lowercase(char& temp){
/*ALL BECAUSE tolower() is being an oppositional defiant teenager of a function!*/
	if(temp == 'A'){
	temp = 'a';
		}
	else if(temp == 'B'){
	temp = 'b';
		}
	else if(temp == 'C'){
	temp = 'c';
		}
	else if(temp == 'D'){
	temp = 'd';
		}
	else if(temp == 'E'){
	temp = 'e';
		}
	else if(temp == 'F'){
	temp = 'f';
		}
	else if(temp == 'G'){
	temp = 'g';
		}
	else if(temp == 'H'){
	temp = 'h';
		}
	else if(temp == 'I'){
	temp = 'i';
		}
	else if(temp == 'J'){
	temp = 'j';
		}
	else if(temp == 'K'){
	temp = 'k';
		}
	else if(temp == 'L'){
	temp = 'l';
		}
	else if(temp == 'M'){
	temp = 'm';
		}
	else if(temp == 'N'){
	temp = 'n';
		}
	else if(temp == 'O'){
	temp = 'o';
		}
	else if(temp == 'P'){
	temp = 'p';
		}
	else if(temp == 'Q'){
	temp = 'q';
		}
	else if(temp == 'R'){
	temp = 'r';
		}
	else if(temp == 'S'){
	temp = 's';
		}
	else if(temp == 'T'){
	temp = 't';
		}
	else if(temp == 'U'){
	temp = 'u';
		}
	else if(temp == 'V'){
	temp = 'v';
		}
	else if(temp == 'W'){
	temp = 'w';
		}
	else if(temp == 'X'){
	temp = 'x';
		}
	else if(temp == 'Y'){
	temp = 'y';
		}
	else if(temp == 'Z'){
	temp = 'z';
		}
}
