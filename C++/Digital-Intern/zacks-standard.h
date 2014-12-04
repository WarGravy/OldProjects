#include <iostream>
#include <string>
#include <algorithm>
#include <dirent.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "adt2.h"
using namespace std;
//GLOBALS

//STRUCTURES
class file{
public:
file();
bool operator<( file& );
std::string name;
bool found;
bool bad;
};

//PROTOTYPES
//removes all files in a folder while keeping the folder intact (NOT MEANT TO BE USED ON FOLDERS CONTAINING FOLDERS
void cleanFolder(string path);
//checks if badname, if bad name return true and modifies the second c style string to an appropriate search term
bool xmlSearchAdjust(const char* source, string& secondSource);

//reads all the file names and loads them into the docName array
bool readDocumentNames(string path, file docName[], int& stop, int& start);
bool readDocumentNames(string path, string docName[], int& stop, int& start);

//reads only the first level of a directory and returns the folder names in that directory in the folder array
int readlevel1(const string path, string folder[], int stop);

//reads all file names within a folder designated by the string path
std::vector<std::string> read(std::string path);

//counts all the files in a folder
void countFiles(string path, int& start);

//false means the name is a bad name
bool check(const char* name);

//returns the length of a cstyle string
int cstringLength(const char*);

//searches for a match of a cstyle string
bool searchForMatch(const char* key, const char* source);

//searches for a char key
bool searchForMatch(char key, const char* source);

//basic sorting of strings in an array
void InsertionSort(string values[], int numValues);
void InsertionSort(file values[], int numValues);

//Case Insensitive Functions
//reads a file, and outputs the identical version of the file in a folder determined by the parameter newLoc, except this version is all lower case, and passes by the new name of the file including the path
void toLowerFile(string filename, string newloc, string& newfilename);

//makes a string lowercase
void toLowerString(string& data);

//writes an array of filenames as all lowercase in the resource/xml folder and transforms the array to the proper name of the new filename
void toLowerXML(string xml[], int num);

//makes all strings lowercase
void toLowerStrings(string array[], int num);
void toLowerFiles(file array[], int num);

