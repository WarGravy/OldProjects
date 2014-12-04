////////////////////////////////////////////The Digital Intern/////////////////////
//INCLUDES///////////////////////////////Developer: Zachary Carlson////////////////
///////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <time.h>
#include "htmlzack.h"
#include "zacks-standard.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//GLOBAL VARIABLES/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int ACTUAL_NUM_OF_DOCS = 0;
int SEARCHED = 0;
int BAD =0;
int UNUSED=0;
//counter for the number of XML_FILES
int XML_FILES = 0;
int XML_FILES_TOT = 0;
//number of allowed level1 folders
const int LEVEL_ONE = 50;
//these are the initial paths, which are changed in the main program
string DOC_PATH ="documents/";
string DOC_REMOV ="documents/";
string RESOURCES ="resources/dlevelone.txt";
//path for the xml files 
const string PATH = "XML/";
//inputed by user
string DESCRIP;

///////////////////////////////////////////////////////////////////////////////////
//PROTOTYPES///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/*
Name: numOfBadNames
Description: Counts all the files with bad names.
Input: 
  Array of files(docName[])
Output: None
Return: Returns the number of bad files 
Dependencies: 
  zacks-standard.h: bool check(..);
  zacks-standard.h: struct file*/
int numOfBadNames(file docName[]);

/*
Name: cleanDocPath
Description: Removed the global string DOC_REMOV from the beginning of the all the file names.
Input:
  Array of files(docName[])
Output: None
Return: None
Dependencies: 
  zacks-standard.h: int cstringLength(..);
  zacks-standard.h: struct file
*/
void cleanDocPath(file docName[]);
void cleanDocPath();
/*
Name: outputHTML
Description: Writes an HTML page in the report/dpages folder or the report/ipages folder determined by the key (char def). The page contains the summary at the top, a link to index.html via the logo at the top, and a list of all the files not in use, with the files that are not in use with badnames highlighted in red, and a list of the files with bad names and a second list under each file of all the Xid that file was found on with active links.
Input: 
  Array of files(docName[])
  Number of files(docNum)
  Number of files with bad names(badNum)
  Number of files not found in search(notFoundNum)
  The name of the level one folder(level1name)
  Array of all the pages searched(xmlList[])
  Key determining what folder the level one folder is under(def)
Output: .html file in either the folder report/dpages/ or report/ipages/ the name being the level1name string
Return: None
Dependencies:
  prog.cpp: void xidList(..);
  htmlzack.h class->htmlzack
  zacks-standard.h: int cstringLength(..);
  zacks-standard.h: struct file */
void outputHTML(file docName[], int docNum, int badNum, int notFoundNum, string level1name, string xmlList[], char def);

/*
Name: outputIndex
Description: Writes the index.html page with a link to index2.html labeled "Document Report" and a second link to index3.html labeled "Image Report"
Input: None
Output: .html file report/index.html
Return: None
Dependencies:
  htmlzack.h class->htmlzack */
void outputIndex();

/*
Name: writeMainReport and writeMainReportImages
Description: Writes the index2.html or index3.html page with a linked list to all the reports for all the level1 folders indicated. The only difference between the two is the name of the page, and the links either link through the dpages folder, or the ipages folder
Input: 
  Array of folder names/html report names(level1names[])
  Number of folder names/html report pages(number)
  2D array with the first [] being the index corresponding to the array of folder names, and second [] being either the number of files not in use([0]), or files with bad names([1]).
Output: .html file report/index2.html
Return: None
Dependencies:
  htmlzack.h class->htmlzack
  zacks-standard.h: int cstringLength(..); */
void writeMainReport(const string level1names[], int number, int log[][2]);
void writeMainReportImages(const string level1names[], int number, int log[][2]);

/*
Name: xidList
Description: Writes a list with cms link("http://cms.unr.edu/client/default?ID=") attached at the front to all files term was found on, and skims file names down to x####. If file had a folder name in front of it, it assumes it was checked out. Takes in consideration ' ' and '&'.
Input: 
  search term(term)
  array of all the xml files to search(xmlList[])
  pointer of the hhtml file/ htmlzack class(outfile)
Output: list at the current position in the html file
Return: None
Dependencies:
  ifstream
  htmlzack.h class->htmlzack
  zacks-standard.h: int cstringLength(..);
  zacks-standard.h: bool xmlSearchAdjust(..); */
void xidList(string term, string xmlList[], htmlzack* outfile);

/*
Name: xidMod
Description: Searches through all the xml files, and makes a new array with the file name list that contains only that term
Input: 
  array of all the xml files to search(xmlList[])
  the term to make the list based off of(string term)
  new array of all the xml files to search(xmlListNew[])
Output: None
Return: number of strings in the new list
Dependencies:
  fstream
  string
  iterator
  zacks-standard.h: toLowerString */
int xidMod(string xmlList[], string term, string xmlListNew[]);
///////////////////////////////////////////////////////////////////////////////////
//MAIN DRIVER//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main(){
    //initialize variables
	string temp;
	int maxtemp;
	int actualtemp;
	//index variables
	int z, max, divider;
	int counter;
	int bad;
	int xmlIndex=0;
	int level1;
	int index =0;
	//this is used in a function to determine if it needs to write the html files for documents or images
	char def = 'd';
	//other
	string level1Folders[LEVEL_ONE];
	int hours, minutes, seconds;
	clock_t start, end;
	double time;
	bool runProgram = false;
	//flag blue for documents
	bool flagGreen = false;
	bool flag = false;
	//fstream
	ifstream fin;
	fin.clear();
	ofstream fout;
	fout.clear();
	//testing new algorithm for searching
	istreambuf_iterator<char> eof;

	char deleteCharYN = 'z';
	while(deleteCharYN != 'y' && deleteCharYN != 'n'){
	cout << "Do you wish to read in new XML files? (y/n)"<<endl;
	cin >> deleteCharYN;
	}
	//INITIALIZE XML LIST
	countFiles(PATH, XML_FILES);
	z=XML_FILES;
	string xmlList[z+1];
	string xmlListNew[z+1];
	XML_FILES = 0;
//////////
	if(deleteCharYN == 'y'){	
	//CLEAN FOLDERS
	cleanFolder("resources/xml/");
	cleanFolder("report/dpages/");
	cleanFolder("report/ipages/");

	
	readDocumentNames("XML/",xmlList,z, XML_FILES);
		cout <<"Please enter the string you wish to set for the Summary description."<<endl;
		cin >> DESCRIP;
		//Check for XML readability
			fout.open("resources/xmllist.txt");
			fout.clear();
			cout << "Checking XML Files."<< endl;
			for(z=0;z<XML_FILES;z++){
			cout << "Checking XML File: "<< xmlList[z]<<endl;
			fin.open(xmlList[z].c_str());
				if(fin.good()){
					while(fin.good()){
					fin >> temp;
					}
				}
				else{
				cout << "Bad file found and removed from search list: " << xmlList[z] << endl;
				flagGreen = true;
				}
				//output XML files to .txt
				fout << xmlList[z] << endl;
				fin.close();
			}
			//output no errors if there were no errors
			if(flagGreen == false){
				cout << "There were no errors checking the XML Files." << endl;
			}
			//empty xmlList and read list from xmllist.txt
			fout.close();
////////////
	   }
	
			fin.clear();
			fin.open("resources/xmllist.txt");
			
			for(XML_FILES = 0; fin.good();XML_FILES++){
				fin >> xmlList[XML_FILES];
			}
			//XML_FILES--;
			//output new list to xmlcheck.txt
			fin.close();
			fout.open("resources/xmlcheck.txt");
			fout.clear();
			for(z=0;z<XML_FILES;z++){
				fout << xmlList[z]<<endl;
			}
			fout.close();
			//fix list
			XML_FILES--;
			toLowerXML(xmlList, XML_FILES);
			XML_FILES_TOT = XML_FILES;
		//prompt user for maximum number of files possible
		cout << "Please Type in the maximum number of documents you will be searching for in each level one folder and its sub folders within the documents folder, this number can exceede the actual number of documents. Reccomended: Greater than 4 and Less than 4000" <<endl << endl;
		cin >> max;
		if(max <= 4 && max >=0){
		max = 4;
		}
		while(max < 0){
		cout << "Invalid number, please try again."<<endl;
		cin >> max;
		}
		file docName[max];
		//Version 0.6 writes a blank.txt file to both folders so there is no crashes when the folders are empty.
		fout.clear();
		fout.open("documents/blank.txt");
		fout.close();
		fout.open("images/blank.txt");
		fout.close();
		fout.clear();
		//end
 //document/image divider
 for(divider = 0; divider < 2; divider++){
  //set for images
  if(divider == 1){
	//fin.close();
	DOC_PATH = "images/";
	DOC_REMOV = "images/";
	RESOURCES ="resources/ilevelone.txt";
	UNUSED = 0;
	BAD = 0;
	SEARCHED = 0;
	ACTUAL_NUM_OF_DOCS=0;
	def = 'i';
	xmlIndex=0;
  }
	//READ IN FILE NAMES
		//Read Level 1 folders-output names to levelone.txt
	        level1 = readlevel1(DOC_PATH, level1Folders, LEVEL_ONE);
		InsertionSort(level1Folders, level1);
		fout.clear();
		fout.open(RESOURCES.c_str());
		for(z=0; z<level1;z++){
			fout<<level1Folders[z]<<endl;
		}
		fout.close();
		//Check for first folder that contains bad documents
		maxtemp = max;
		actualtemp = ACTUAL_NUM_OF_DOCS;
		for(z=0; z<level1;z++){
		cout << "Checking if all files are readable under the " << level1Folders[z] << " folder."<<endl;
		readDocumentNames(level1Folders[z], docName, maxtemp, actualtemp);
		}

  	//start of the loop
	//start time tracking
	start = clock();
        //0=unused 1=bad
	int log[level1][2];
	for(z=0; z < level1; z++){
		counter = 0;
		bad = 0;
		DOC_PATH = level1Folders[z];
			//fix the xml list
				//function: xidMod
			cleanDocPath();
			XML_FILES = xidMod(xmlList, DOC_PATH, xmlListNew);
			//read in document names recursively
			ACTUAL_NUM_OF_DOCS = 0;
			readDocumentNames(level1Folders[z], docName, max, ACTUAL_NUM_OF_DOCS);
			//make all lower case
			toLowerFiles(docName, ACTUAL_NUM_OF_DOCS);
			cout << "FINISHED Reading File names." << endl;
			InsertionSort(docName, ACTUAL_NUM_OF_DOCS);
			cout << "FINISHED Sorting File names." << endl;
			//eliminate DOC_PATH from search
			cleanDocPath(docName);
				
			//SAFETY NET
			runProgram = false;
			xmlIndex = 0;
			//open xml file
			fin.open(xmlListNew[xmlIndex].c_str());
			if(fin.good()){
				runProgram = true;
			}
			else{
				//if there are 0 files all documents are considered not found.
			cout << DOC_PATH << endl;
			cout << XML_FILES << endl;
			runProgram = false;
			counter = ACTUAL_NUM_OF_DOCS;
			}

	if(runProgram){
	//search for match for names
	index = 0;
	xmlIndex =0;
	//outfile.insertListHead("Files that were not found within the XML folder:", level1Folders[z]);
	
	while(index < ACTUAL_NUM_OF_DOCS){
		fin.close();
		fin.open(xmlListNew[xmlIndex].c_str());

    		if(eof == search(istreambuf_iterator<char>(fin), eof, docName[index].name.begin(),docName[index].name.end())){
			cout << "string: " << docName[index].name <<endl<< " SEARCHING" << endl;
			cout << "XID: " << xmlListNew[xmlIndex] <<endl;
		xmlIndex++;
		}
		else{
			//was found
			docName[index].found=true;
			xmlIndex = 0;
			index++;
		}
		if( xmlIndex > XML_FILES -1){
		//not found in search
			//check if name needs to be adjusted, if no
			if(!(xmlSearchAdjust(docName[index].name.c_str(), temp))){
				//was not found
				docName[index].found=false;
				index++;
				counter++;
				//possibly set xml1 here
				xmlIndex = 0;
			}
			//check if name needs to be adjusted, if yes redo search
			else{
				flag = false;
			for(xmlIndex=0; xmlIndex < XML_FILES && flag == false; xmlIndex++){
				fin.close();
				fin.open(xmlListNew[xmlIndex].c_str());
				//searching
    				if(eof == search(istreambuf_iterator<char>(fin), eof, temp.begin(),temp.end())){
					cout << "string: " << temp <<endl<< " SEARCHING" << endl;
					cout << "XID: " << xmlListNew[xmlIndex] <<endl;
					xmlIndex++;
				}
				else{
				//was found
					docName[index].found=true;
					xmlIndex = 0;
					index++;
					flag = true;
				}
			}
				//if not found
				if( xmlIndex >= XML_FILES && flag == false){
					docName[index].found=false;
					index++;
					counter++;
					//possibly set xml1 here
					xmlIndex = 0;
				}
			}
		}
	///////WHILE}///////
	  }
	///IF runProgram}////
	}

	//BADNAMES OUTPUT
	bad = numOfBadNames(docName);
        log[z][0]= counter;
        log[z][1]=bad;
	outputHTML(docName, ACTUAL_NUM_OF_DOCS, bad, counter, level1Folders[z], xmlListNew, def);
	UNUSED = UNUSED + counter;
	BAD = BAD + bad;
	SEARCHED = SEARCHED + ACTUAL_NUM_OF_DOCS;
	
	//close file
	fin.close();
	fin.clear();
	/////FOR z<level1}//////
	}
	//OUTPUT REPORT MAIN
	if(divider == 0){
        	writeMainReport(level1Folders, level1, log);
	}
	if(divider == 1){
		writeMainReportImages(level1Folders, level1, log);
	}
	end = clock();
	time = ((end-start)/(double)(CLOCKS_PER_SEC));
		//time calculations*/
		hours = (time / 3600);
		time = time - hours * 3600;
		minutes = (time / 60);
		time = time - minutes * 60;
		seconds = time;
		
  //end loop for document/image divider
  }
  //output main index
  outputIndex();
  //end
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//IMPLEMENTATION - read prototype definitions at top of page///////////////////////
///////////////////////////////////////////////////////////////////////////////////
void cleanDocPath(file docName[]){
  int index;
  string temp;
  int size;
  int size2 = cstringLength(DOC_REMOV.c_str());
	//shuffles down
	for(index = 0; index < ACTUAL_NUM_OF_DOCS; index++){
		size = cstringLength(docName[index].name.c_str());
		temp = docName[index].name.substr(size2,size-size2);
	 	docName[index].name = temp;
	}
}
void cleanDocPath(){
  int size;
  int size2 = cstringLength(DOC_REMOV.c_str());
		//adjust
		size = cstringLength(DOC_PATH.c_str());
		DOC_PATH = DOC_PATH.substr(size2, size-size2);
}

int numOfBadNames(file docName[]){
  int index;
  int counter = 0;
  bool good;
	for(index = 0; index < ACTUAL_NUM_OF_DOCS; index++){
	cout << "checking for bad names" << endl;
	good = check(docName[index].name.c_str());
		docName[index].bad=false;
		if(good == false){
		docName[index].bad=true;
		counter ++;
		}
	}
  return counter;
}
void outputHTML(file docName[], int docNum, int badNum, int notFoundNum, string level1name, string xmlList[], char define){
  //initialize variables
  int index2;
  double tempP;
  bool flagBAD = false;
  int tempP2;
  string name;
  string temp;
  string temp2;
  htmlzack* file;
	int size;
  	int size2 = cstringLength(DOC_REMOV.c_str());

	//initialize new html page
	size = cstringLength(level1name.c_str());
	//cout << "Writing the HTML page for " << level1name <<"..." <<endl;
		temp = level1name.substr(size2,size-size2);
	 	level1name = temp;
		//pop last off
		size = cstringLength(level1name.c_str());
		temp = level1name.substr(0,size-1);
		temp2 = temp;
		temp.append(".html");
		level1name = temp;
		if(define == 'd'){
		temp = "report/dpages/";
		}
		if(define == 'i'){
		temp = "report/ipages/";
		}
		level1name = temp + level1name;
	file = new htmlzack(level1name.c_str());
	//output summary
	file->insertTableHead(temp2);
	file->insertRow("Number of files searched for", docNum);
	tempP = (double)notFoundNum/(double)docNum;
	tempP = tempP * 100;
	tempP2 = tempP/1;	
	file->insertRow("Number of files not in use", notFoundNum, tempP2);
	tempP = (double)badNum/(double)docNum;
	tempP = tempP * 100;
	tempP2 = tempP/1;
	file->insertRow("Number of bad files", badNum, tempP2);
	file->endTable();
	//output files not in use
	file->insertListHead(temp2, "Files not in use (files in red also have bad names):" );
	if(notFoundNum == 0){
	file->insertListR("No files found");
	}
	for(index2 =0; index2 < docNum; index2++){
		if(docName[index2].found == false){
			if(docName[index2].bad == true){
			file->insertListR(docName[index2].name);
			}
			else{
			file->insertList(docName[index2].name);
			}
		}
	}
	file->endList();
	//output files with badnames
	file->insertListHead(temp2, "Files in use with bad names:");
	if(badNum == 0){
	file->insertListR("No files found");
	}
	else{
	  for(index2 =0; index2 < docNum; index2++){
		if(docName[index2].bad == true){
		//if not in use and have a bad name mark in red
			if(docName[index2].found == false){
			//file->insertListR(docName[index2].name);
			}
			else{
			file->insertList(docName[index2].name);
			//function call to search through the xml files and output what XID pages it was found on.
			xidList(docName[index2].name, xmlList, file);
			flagBAD = true;
			}
		}
	  }
	}
	if(badNum > 0 && flagBAD == false){
	file->insertListR("No files found");
	}
	file->endList();
	//end html page
	delete file;
}

void writeMainReport(const string level1names[], int number, int log[][2]){
    htmlzack outfile("report/index2.html");
    string newnames[number+1];
    string links[number+1];
    string page = "dpages/";
    double tempP;
    int index, tempP2;
    string temp;
    //copy level1names to an array
    	for(index=0; index < number; index++){
	newnames[index] = level1names[index];
	}
    //change the names appropriately
	int size;
  	int size2 = cstringLength(DOC_REMOV.c_str());

	for(index=0; index < number; index++){
	size = cstringLength(newnames[index].c_str());
		//removes documents/
		temp = newnames[index].substr(size2,size-size2);
	 	newnames[index] = temp;
		//pop last off
		size = cstringLength(newnames[index].c_str());
		temp = newnames[index].substr(0,size-1);
		newnames[index] = temp;
		temp.append(".html");
		temp = page + temp;
		links[index] = temp;
		
	}
    //output summary
    outfile.insertTableHead("Document Summary: " + DESCRIP);	
    outfile.insertRow("Numbers of files searched for: ", SEARCHED);
    tempP = (double)UNUSED/(double)SEARCHED;
    tempP = tempP * 100;
    tempP2 = tempP/1;
    outfile.insertRow("Numbers of files not in use: ", UNUSED, tempP2);
    tempP = (double)BAD/(double)SEARCHED;
    tempP = tempP * 100;
    tempP2 = tempP/1;
    outfile.insertRow("Numbers of files with bad names: ", BAD, tempP2);
    outfile.endTable();
    //output links to individual pages
    outfile.insertListHead("Summary Pages", "Linked List of Level One Folders");
    for(index=0; index < number; index++){
    outfile.insertListLink(newnames[index], links[index], log[index][0], log[index][1]);
    }
    outfile.endList();
}

void writeMainReportImages(const string level1names[], int number, int log[][2]){
    htmlzack outfile("report/index3.html");
    string newnames[number+1];
    string links[number+1];
    string page = "ipages/";
    double tempP;
    int index, tempP2;
    string temp;
    //copy level1names to an array
    	for(index=0; index < number; index++){
	newnames[index] = level1names[index];
	}
    //change the names appropriately
	int size;
  	int size2 = cstringLength(DOC_REMOV.c_str());

	for(index=0; index < number; index++){
	size = cstringLength(newnames[index].c_str());
		//removes documents/
		temp = newnames[index].substr(size2,size-size2);
	 	newnames[index] = temp;
		//pop last off
		size = cstringLength(newnames[index].c_str());
		temp = newnames[index].substr(0,size-1);
		newnames[index] = temp;
		temp.append(".html");
		temp = page + temp;
		links[index] = temp;
		
	}
    //output summary
    outfile.insertTableHead("Image Summary: " + DESCRIP);	
    outfile.insertRow("Numbers of files searched for: ", SEARCHED);
    tempP = (double)UNUSED/(double)SEARCHED;
    tempP = tempP * 100;
    tempP2 = tempP/1;
    outfile.insertRow("Numbers of files not in use: ", UNUSED, tempP2);
    tempP = (double)BAD/(double)SEARCHED;
    tempP = tempP * 100;
    tempP2 = tempP/1;
    outfile.insertRow("Numbers of files with bad names: ", BAD, tempP2);
    outfile.endTable();
    //output links to individual pages
    outfile.insertListHead("Summary Pages", "Linked List of Level One Folders");
    for(index=0; index < number; index++){
    outfile.insertListLink(newnames[index], links[index], log[index][0], log[index][1]);
    }
    outfile.endList();
}

void xidList(string term, string xmlList[], htmlzack* outfile){
	//initialize
	int index=0;
	string CMSlink = "http://cms.unr.edu/client/default?ID=";
	string temp;
	string temp2;
	string adjust;
	bool flag = false;
	int size;
	int size2;
	ifstream fin;
	fin.clear();
	istreambuf_iterator<char> eof;
	outfile->insertListStartTag();
	//loop through, if found output as <li>
	while(index < XML_FILES){
	cout << "Finding all XML files that that "<< term<<" is located on and outputing to html."<<endl;
		if(fin.is_open()){
			fin.close();
			fin.clear();
		}
		fin.open(xmlList[index].c_str());
    		if(eof == search(istreambuf_iterator<char>(fin), eof, term.begin(), term.end())){
		}
		else{
			//was found
			//the linked version will be <a href="http://cms.unr.edu/client/default?ID=x31128">x31128</a>
			//need to add the xid and remove XML/ to the end of CMSlink
			//removes documents/
			size = cstringLength(xmlList[index].c_str());
			//if XML/
			if(searchForMatch("XML/x", xmlList[index].c_str())){
			temp = xmlList[index].substr(4,size);
			size = cstringLength(xmlList[index].c_str());
			temp2 = temp;
			}
			//if XML/Checked out
			else{
			//find xid
			size2 = xmlList[index].find("xml/x");
			temp = xmlList[index].substr(size2+4,size);
			//change temp2
			temp2 = temp;
			}
			temp = CMSlink + temp;
			//remove .xml at end
			size = cstringLength(temp.c_str());
			temp = temp.substr(0, size-4);
			outfile->insertListLinkW(temp2, temp);
		}
		index++;
	}
	flag = xmlSearchAdjust(term.c_str(), adjust);
	cout << "FLAG"<<flag<<endl;
	index =0;
	fin.close();
	fin.clear();
	while(flag && index < XML_FILES){
	cout << "Finding all XML files that that "<< adjust<<" is located on and outputing to html."<<endl;
		if(fin.is_open()){
			fin.close();
			fin.clear();
		}
		fin.open(xmlList[index].c_str());
    		if(eof == search(istreambuf_iterator<char>(fin), eof, adjust.begin(), adjust.end())){
		//not found
		}
		else{
			//was found
			//the linked version will be <a href="http://cms.unr.edu/client/default?ID=x31128">x31128</a>
			//need to add the xid and remove XML/ to the end of CMSlink
			//removes documents/ or images/
			cout << "adjust: " << adjust.c_str() << "XML" << xmlList[index]<<endl;
			size = cstringLength(xmlList[index].c_str());
			//if XML/
			if(searchForMatch("XML/x", xmlList[index].c_str())){
				temp = xmlList[index].substr(4,size);
				size = cstringLength(xmlList[index].c_str());
				temp2 = temp;
			}
			//if XML/Checked out
			else{
				//find xid
				size2 = xmlList[index].find("xml/x");
				temp = xmlList[index].substr(size2+4,size);
				//change temp2
				temp2 = temp;
			}
			temp = CMSlink + temp;
			//remove .xml at end
			size = cstringLength(temp.c_str());
			temp = temp.substr(0, size-4);
			outfile->insertListLinkW(temp2, temp);	
		}
	index++;
	}
	if(fin.is_open()){
	fin.close();
	fin.clear();
	}
	//end
	outfile->insertListEndTag();
}
void outputIndex(){
  htmlzack outfile("report/index.html");
  outfile.insertListStartTag();
  outfile.insertListLink("Document Report", "index2.html");
  outfile.insertListLink("Image Report", "index3.html");
  outfile.insertListEndTag();
}
int xidMod(string xmlList[], string term, string xmlListNew[]){
	//variables
	toLowerString(term);
	int index =0;
	int inew=0;
    bool flag;
	string adjust;
	ifstream fin;
	fin.clear();
	istreambuf_iterator<char> eof;
	ofstream fout;
	//terms
	while(index < XML_FILES_TOT -1){
		//open file
		fin.open(xmlList[index].c_str());
		//search for img, image, doc
		if(eof == search(istreambuf_iterator<char>(fin), eof, term.begin(),term.end())){
		}
		//else was found
		else{
		xmlListNew[inew] = xmlList[index];
		inew++;
		}
	index++;
	fin.close();
	fin.clear();
	}
	flag = xmlSearchAdjust(term.c_str(), adjust);
	//terms with space and & fixes
	if(flag == true){
	index = 0;
		while(index < XML_FILES_TOT -1){
		//open file
		fin.open(xmlList[index].c_str());
			//search for img, image, doc
			if(eof == search(istreambuf_iterator<char>(fin), eof, adjust.begin(),adjust.end())){
			}
			//else was found
			else{
			xmlListNew[inew] = xmlList[index];
			inew++;
			}
		index++;
		fin.close();
		fin.clear();
		}
	}
	return inew;
}
