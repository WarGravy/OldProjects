#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <dirent.h>
#include <vector>
#include <unistd.h>
#include "zacks-standard.h"
using namespace std;
int COUNT =0;

/////////////////CLASS:FILE//////////////
file::file(){
bool found= false;
bool bad = false;
}
bool file::operator<( file& rhs ){
	if(name < rhs.name){
	return true;
	}
	else{
	return false;	
	}
}

////////////FUNCTIONS///////////////
void cleanFolder(string path){
	//variables
	int index2;
	int size =0;
	int index = 0;
		//count files
		countFiles(path, size);
		string names[size];
	//read all filenames in the folder
	readDocumentNames(path, names, size, index);
	//loops through and deletes all of them
	cout << "Deleting old files..."<<endl;
	for(index2=0; index2<index;index2++){
		unlink( names[index2].c_str() );
	}
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

bool searchForMatch(char key, const char* source){
  int sourceLen = cstringLength(source);
  int index = 0;
  
  while(index < sourceLen){
 	if(key == source[index]){
	return true;
	}
  index++;
  }
return false;
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

std::vector<std::string> read(std::string path = ".") {
    DIR*    dir;
    dirent* pdir;
    COUNT = 0;
    std::vector<std::string> files;

    dir = opendir(path.c_str());

    while (pdir = readdir(dir)) {
        files.push_back(pdir->d_name);
	COUNT ++;
	
    }
    closedir(dir);
    return files;
}
void countFiles(string path, int& start){
	//initialize variables
	std::vector<std::string> directoryTEMP;
	int j = 0;
	string temp;
	string temp2 = "/";
	
	//read directory
	  directoryTEMP = read(path);
	  while(j < COUNT){
	    //check and see if name is a folder or a file.
	    if(searchForMatch('.', directoryTEMP[j].c_str()) == false){
	    }
	    //count file
	    else if((cstringLength(directoryTEMP[j].c_str()) > 2) && (searchForMatch("DC_Store", directoryTEMP[j].c_str()) == false)){
		start++;
	  	}
	  //increment j index
	  j++;
	  }
	  directoryTEMP.erase(directoryTEMP.begin(), directoryTEMP.end());
}

bool check(const char* name){
  int size = cstringLength(name);
  int i;
	for(i = 0; i < size; i++){
	if((name[i] == '\0' || name[i] == '/') ||
	   (name[i] >= '0' && name[i] <= '9') ||
	   (name[i] >= 'A' && name[i] <= 'Z') ||
	   (name[i] >= 'a' && name[i] <= 'z') ||
	   (name[i] == '(' || name[i] == ')') ||
	   (name[i] == '-' || name[i] == '_')){
	   //do nothing
	   }
	else if(name[i] == '.'){
		if(i < size - 4){
			//checking for pptx jpeg docx xlsx mpeg sitx tar.gz
			if(((name[i+1] == 'j') && (name[i+2] == 'p') && (name[i+3] == 'e') && (name[i+4] == 'g')) ||
			   ((name[i+1] == 'p') && (name[i+2] == 'p') && (name[i+3] == 't') && (name[i+4] == 'x')) ||
			   ((name[i+1] == 'd') && (name[i+2] == 'o') && (name[i+3] == 'c') && (name[i+4] == 'x')) ||
		 	   ((name[i+1] == 'x') && (name[i+2] == 'l') && (name[i+3] == 's') && (name[i+4] == 'x')) ||
			   ((name[i+1] == 'm') && (name[i+2] == 'p') && (name[i+3] == 'e') && (name[i+4] == 'g')) ||
			   ((name[i+1] == 's') && (name[i+2] == 'i') && (name[i+3] == 't') && (name[i+4] == 'x')) ||
			   ((name[i+1] == 't') && (name[i+2] == 'a') && (name[i+3] == 'r') && (name[i+4] == '.')&&(name[i+5] == 'g') && (name[i+6] == 'z'))){
			//do nothing
			}
			else{
			return false;
			}
		}
		else{
		//do nothing
		}
	}
	else{
		return false;
	    }
	}
  return true;
}

bool readDocumentNames(string path, file docName[], int& stop, int& start){
	//initialize variables
	int numbFolds = 90;
	std::vector<std::string> directoryTEMP;
	int j = 0;
	int x;
	int numberOfPaths = 1;
	string folders[numbFolds];
	folders[0] = path;
	string temp;
	string temp2 = "/";
	//extensions
	//read directory
	  directoryTEMP = read(folders[0]);
	  while(j < COUNT && start < stop){
	   cout << directoryTEMP[j] <<endl;
	    //check and see if name is a folder or a file.
	    if(searchForMatch(".", directoryTEMP[j].c_str()) == false){
		//store folder name
		temp = directoryTEMP[j];
		temp = path + temp + temp2;
		folders[numberOfPaths] = temp;
		numberOfPaths++;
	    }
	    //load name into array with path added on
	    else if((cstringLength(directoryTEMP[j].c_str()) > 2) &&
		(searchForMatch("DS_Store", directoryTEMP[j].c_str()) == false)){
			if(searchForMatch("._", directoryTEMP[j].c_str()) == false){
				if(searchForMatch("..", directoryTEMP[j].c_str()) == false){
				docName[start].name = folders[0] + directoryTEMP[j];
				start++;
				}
			}
	  	}
	  //increment j index
	  j++;
	  }
	  for(x=1; x < numberOfPaths && x < numbFolds; x++){
	  readDocumentNames(folders[x], docName, stop, start);
	  }
	  directoryTEMP.erase(directoryTEMP.begin(), directoryTEMP.end());
  return true;
}

bool readDocumentNames(string path, string docName[], int& stop, int& start){
	//initialize variables
	std::vector<std::string> directoryTEMP;
	int j = 0;
	int x;
	int numberOfPaths = 1;
	string folders[100];
	string* folders2;
	string* folders3;
	folders[0] = path;
	string temp;
	string temp2 = "/";
	//extensions
	char period= '.';
	//read directory
	  directoryTEMP = read(folders[0]);
	  while(j < COUNT && start < stop){
	    //check and see if name is a folder or a file.
	    if(searchForMatch(period, directoryTEMP[j].c_str()) == false){
		//store folder name
		temp = directoryTEMP[j];
		temp = path + temp + temp2;
		if(numberOfPaths < 100){
		folders[numberOfPaths] = temp;
		}
		else if(numberOfPaths == 100){
		folders2 = new string[100];
		}
		else if(numberOfPaths >= 100 && numberOfPaths < 200){
		folders2[numberOfPaths-100] = temp;
		}
		else if(numberOfPaths == 200){
		folders3 = new string[100];
		}
		else if(numberOfPaths >= 200 && numberOfPaths < 300){
		folders3[numberOfPaths-200] = temp;
		}
		numberOfPaths++;
	    }
	    //load name into array with path added on
	    else if((cstringLength(directoryTEMP[j].c_str()) > 2) &&
		(searchForMatch("DS_Store", directoryTEMP[j].c_str()) == false)){
		if(searchForMatch("._", directoryTEMP[j].c_str()) == false){
		docName[start] = folders[0] + directoryTEMP[j];
		start++;
		}
	  	}
	  //increment j index
	  j++;
	  }
	  for(x=1; x < numberOfPaths && x < 30; x++){
	  	if(x<100){
	  	readDocumentNames(folders[x], docName, stop, start);
	  	}
	  	else if(x >= 100 && x < 200){
	  	readDocumentNames(folders2[x-100], docName, stop, start);
	  	}
	  	else if(x >= 200 && x < 300){
	  	readDocumentNames(folders3[x-200], docName, stop, start);
	  	}
	  }
	  directoryTEMP.erase(directoryTEMP.begin(), directoryTEMP.end());
  return true;
}
int readlevel1(const string path, string folder[], int stop){
	//initialize variables
	std::vector<std::string> directoryTEMP;
	int j = 0;
	int numb = 0;
	string temp;
	string temp2 = "/";
	//read directory
	  directoryTEMP = read(path);
	  while(j < COUNT){
	    //check and see if name is a folder or a file.
	    if((searchForMatch('.', directoryTEMP[j].c_str()) == false)
		&& (searchForMatch("DS_Store", directoryTEMP[j].c_str()) == false)){
		//store folder name
		temp = directoryTEMP[j];
		//load name into array with path added on
		temp = path + temp + temp2;
		folder[numb] = temp;
		numb++;
	    }
	  //increment j index
	  j++;
	  }
	  directoryTEMP.erase(directoryTEMP.begin(), directoryTEMP.end());
  return numb;
}


bool xmlSearchAdjust(const char* source, string& secondSource){
	bool flagX = false;
	char temp;
	int index;
	flagX = check(source);
	if(flagX == false){
		int len = cstringLength(source);
		secondSource.clear();
		QueType Q(len);
		//enqueue all characters into Q
		for(index = 0; index < len; index++){
			Q.Enqueue(source[index]);
		}
		//start dequeing operation
		for(index = 0; index < len; index++){
		Q.Dequeue(temp);
		//find and replace all ' ' with "%20"
			if(temp == ' '){
			secondSource = secondSource + "%20";
			}
		//find and replace all '&' with "amp;"
			else if(temp == '&'){
			secondSource = secondSource + "amp;";
			}
			else{
			secondSource = secondSource + temp;
			}
		}
		return true;
	}
	return false;
}
///////////////////////////////////////////

void InsertItem(string values[], int startIndex, int 
endIndex)
// Post: values[0]..values[endIndex] are now sorted.
{
  bool finished = false;
  int current = endIndex;
  string temp;
  bool moreToSearch = (current != startIndex);

  while (moreToSearch && !finished)
  {
    if (values[current] < values[current-1])
    {
      //Swap
      	temp = values[current];
	values[current] = values[current-1];
	values[current-1] = temp;
      current--;
      moreToSearch = (current != startIndex);
    }
    else
      finished = true;
  }
}


void InsertionSort(string values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
  for (int count = 0; count < numValues; count++)
    InsertItem(values, 0, count);
}

//files version
void InsertItem(file values[], int startIndex, int 
endIndex)
// Post: values[0]..values[endIndex] are now sorted.
{
  bool finished = false;
  int current = endIndex;
  file temp;
  bool moreToSearch = (current != startIndex);

  while (moreToSearch && !finished)
  {
    if (values[current] < values[current-1])
    {
      //Swap
      	temp.name = values[current].name;
	temp.found = values[current].found;
	temp.bad = values[current].bad;
	values[current].name = values[current-1].name;
	values[current].found = values[current-1].found;
	values[current].bad = values[current-1].bad;
	values[current-1].name = temp.name;
	values[current-1].bad = temp.bad;
	values[current-1].found = temp.found;
      current--;
      moreToSearch = (current != startIndex);
    }
    else
      finished = true;
  }
}


void InsertionSort(file values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
  for (int count = 0; count < numValues; count++)
    InsertItem(values, 0, count);
}

//////////////Case Insenstive Functions
void toLowerFile(string filename, string newloc, string& newfilename){
  //variables
  ifstream fin;
  ofstream fout;
  string temp = "/";
  newfilename = newloc + temp + newfilename;
  	//open file to read
  	fin.open(filename.c_str());
  	//open file to write
  	fout.open(newfilename.c_str());
	//loop through and read line, lower case, and write
    while (fin.good()){
      getline (fin,temp);
		//write lower case version
		toLowerString(temp);
		fout << temp << endl;
    }
	//close files
	fout.close();
	fin.close();
}
void toLowerString(string& data){
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
}
void toLowerXML(string xml[], int num){
  string dest = "resources/xml";
  string temp;
  int size, size2;
  int index = 0;
  while(index < num){
	cout << index << endl;
	cout << xml[index] <<endl;
	//get the name of the file excluding paths
			//if XML/
			size = cstringLength(xml[index].c_str());
			if(searchForMatch("XML/x", xml[index].c_str())){
				temp = xml[index].substr(4,size);
			}
			//if XML/Checked out
			else{
				//find xid
				size2 = xml[index].find("xml/x");
				temp = xml[index].substr(size2+3,size);
			}
	//write new lowercase version of the file
	toLowerFile(xml[index], dest, temp);
	//set new xml[index] name
	xml[index] = temp;
	index++;
	}
}
void toLowerStrings(string array[], int num){
int index=0;
	while(index < num){
	toLowerString(array[index]);
	index++;
	}
}
void toLowerFiles(file array[], int num){
int index=0;
	while(index < num){
	toLowerString(array[index].name);
	index++;
	}
}
