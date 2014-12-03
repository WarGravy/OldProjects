// HEADER FILES

#include <iostream>
#include <fstream>
#include "adt1.h"
#include <string.h>


using namespace std;

// GLOBAL CONSTANTS

// FUNCTION PROTOTYPES

int displayMenu();

bool full(booking hol[], char* holiday, int magSize, int holSize);

void readInFiles(booking magicians[], booking holidays[], int&, int&);

void outputSchedule(char *, booking magicians[], int magSize);
//read in magSize, read in magicians
void readSchedule(char* filename, booking magicians[], int& magSize, booking holidays[], int& holiSize);

void stringcpy(char*, char*);

// MAIN PROGRAM

int main()
   {
    //variables
    int response;
    int check;
    bool runProgram = true;
    char magname[20];
    char custname[20];
    char holidayname[20];
    booking temp;
    item tempItem;
    char scheduleTXT[]="Schedule.txt";
    char trans[] ="Transaction.txt";
    booking magicians[10];
    int magicianSize = 0;
    booking holidays[10];
    int holidaySize = 0;
    	//read in Magician.txt and Holidays.txt
    	readInFiles(magicians, holidays, magicianSize, holidaySize);
    	//read in Schedule.txt
    	readSchedule(scheduleTXT, magicians, magicianSize, holidays, holidaySize);

	//transaction updating variables
	ofstream tout;
	tout.clear();
	tout.open(trans);
    //Main menu
    do
       {
        response = displayMenu();
        switch( response )
           {
            case 1: 
	    	cout << "Enter the name of the magician: " <<endl;
	    	cin >> magname;
		if(magicianSize + 1 <= 10){ 
		  // add a magician here
		  temp.setID(magname);
		  if(addBooking(magicians, temp, magicianSize)){
		  	magicianSize++;
		  	}
                         // update transactions.txt
			tout << magname << " added to magician booking." << endl;
		}
		else{
			cout << "Magician bookings full" << endl; 
		}

                break;
            case 2: // schedule holiday, customer
	    		cout << "Enter the name of the customer: " << endl;
	    		cin >> custname;
	    		cout << "Enter the name of the holiday: " << endl;
	    		cin >> holidayname;
		     //holiday isn't full
		  	if(!full(holidays, holidayname, magicianSize, holidaySize)){
			  //find available magician
				
			    //update transactions.txt
			}
		     //holiday is full
			else{
                      	  	// move customer to wait list if schedule full
			     	  // update transactions.txt
				  tout << custname << " was added to the back of the waiting list." << endl;
		   	}
                break;
            case 3: // print status of scheduled event
		  	cout << "Enter the name of the magician or holiday" << endl;
			cin >> magname;
			check = searchId(magname, magicians, magicianSize);
			if(check != -1){
			magicians[check].status();
			// update transactions.txt
			tout << "The status of " << magname << " was viewed." << endl;
			}
			else{
				check = searchId(magname, holidays, holidaySize);
				  	if(check != -1){
					holidays[check].status();
					// update transactions.txt
					tout << "The status of " << magname << " was viewed." << endl;
					}
					else{
					cout << "No magician or holiday with the name " << magname << " found." << endl;
					}
			}

                break;
            case 4: // cancel scheduled event
		  	cout << "Enter the name of the holiday" << endl;
			cin >> holidayname;
		  	cout << "Enter the name of the customer" << endl;
			cin >> custname;	
                      // move magician back to "available" status
			check = searchId(holidayname, holidays, holidaySize);
			if(check!= -1){
				//delete item from both bookings
			  	holidays[check].search(custname);
			  	holidays[check].getItem(tempItem);
			  	holidays[check].deleteItem();
			  	holidaySize--;
			  	check = searchId(tempItem.specialName, magicians, magicianSize);
			  	magicians[check].deleteItem();
			  	magicianSize--;
                        	// check wait list for customers
                          	  // set new scheduled event
                            	    // update transactions.txt
			}
			else{
				cout << "Event not found" << endl;
			}

                break;
            case 5: // remove magician from roster
			cout << "Enter the name of the magician: ";
			cin >> magname;
			check = searchId(magname, magicians, magicianSize);
			if(check != -1){
				temp = magicians[check];
				//shuffle down the rest of the magicians
				while(check < magicianSize - 1){
					magicians[check] = magicians[check+1];
					check++;
				}
				//decrement magicianSize
				magicianSize--;
				temp.resetCursor();
				while(temp.getLength() > 0){
					//grab item
					temp.getItem(tempItem);
					//check for possible replacement
					  //if not, add tempItem to front of the waiting list

					//delete item from temp
					temp.deleteItem();
				}
                        	  // reschedule customer or move to head of wait list
                          		// update transactions.txt
			}
			else{
				cout << magname << " not found." << endl;
			}

                break;
            case 6:
                if( response == 6 )
                   {
		    //UPDATE Schedule.txt(using outputToFile for bookings)
		    outputSchedule(scheduleTXT, magicians, magicianSize);
                    runProgram = false;
		    tout.close();
                   }
                break;

            default:
                cout << "incorrect entry, try again..............." << endl << endl;
           }

       }
    while( runProgram == true );

    return 0;
   }

// FUNCTION IMPLEMENTATION

int displayMenu()
   {
    int num;
    cout << endl << endl << endl;
    cout << "            Welcome to the MAGICIAN SCHEDULER" << endl << endl << endl;
    cout << "1.  SIGN UP..........sign up here if you are a magician" << endl << endl;
    cout << "2.  SCHEDULE.........schedule a magician for your holiday event" << endl << endl;
    cout << "3.  STATUS...........check the status of your booking" << endl << endl;
    cout << "4.  CANCEL...........cancel a previoiusly booked event" << endl << endl;
    cout << "5.  DROP OUT.........drop out here if you are a magician quitting the service" << endl << endl;
    cout << "6.  QUIT.............exit the magician scheduler" << endl << endl;
    cout << endl << endl << endl;
    cin >> num;
    return num;
   }
bool full(booking hol[], char* holiday, int magSize, int holSize)
  {
	int hID = searchId(holiday, hol, holSize);
	int i = hol[hID].getLength();
	if(i > magSize){
	return false;
	}
	else
	return true;
  }
void readInFiles(booking magicians[], booking holidays[], int& magSize, int& holiSize){
  //variables
  char magFile[] = "Magician.txt";
  char holidayFile[] = "Holidays.txt";
  char name[20];
  ifstream fin;
  fin.clear();
  fin.open(magFile);
  if(fin.good()){
	fin >> name;
	while(fin.good() && magSize <= 10){
		cout << name << endl;
		magicians[magSize].setID(name);
		magSize++;
		fin >> name;
	}
   fin.close();
  }
  fin.clear();
  fin.open(holidayFile);
  if(fin.good()){
	fin >> name;
	while(fin.good() && holiSize <= 10){
		holidays[holiSize].setID(name);
		holiSize++;
		fin >> name;
	}
  fin.close();
  }
}
void readSchedule(char* filename, booking magicians[], int& magSize, booking holidays[], int& holiSize){
  //initialize variables
  int index = 0;
  int place, size, i, size2;
  int holidayPlace;
  item temp;
  char id[20];
  bool continueAdd = true;
  ifstream fin;
  fin.clear();
  fin.open(filename);
  if(fin.good()){
  	//read in mag size
  	fin >> size;
	while(index < size && size != 0){
  		//read in initial magician id
  		fin >> id;
  		//search for magician id in array
		place = searchId(id, magicians, magSize);
		if(place == -1){
		//check if enough space to add magician
			if(magSize+1 > 10){
			cout << "TOO MANY MAGICIANS, Schedule.txt and Magician.txt excede limit" << endl;
			continueAdd = false;
			}
			else{
			place = magSize;
			magSize++;
			}
		}
		//ADDING THE MAGICIAN ITEMS
		if(continueAdd){
			//read in amount of items under magician
			fin >> size2;
			for(i = 0; i < size2; i++){
			fin >> temp.specialName >> temp.customerName;
			magicians[place].insert(temp);
			//find holiday in holiday list
			holidayPlace = searchId(temp.specialName, holidays, holiSize);
				//check if found
				if(holidayPlace == -1){
					if(holiSize+1 > 10){
					cout << "TOO MANY Holidays, Schedule.txt and Holiday.txt excede limit" << endl;
					}
					else{
					holidayPlace = holiSize;
					holiSize++;
					}
				}
				//add info to holiday list
				stringcpy(temp.specialName, id);
				holidays[holidayPlace].insert(temp);
			}
		}
		else{
			//set continue to true for next iteration of loop
			cout << "Reading in starter files aborted" << endl;
			size = 0;
		}
	//increment loop
	index++;
	}
   fin.close();
  }
}
void outputSchedule(char* filename, booking magicians[], int magSize){
  int i;
  ofstream fout;
  fout.clear();
  fout.open(filename);
  fout.clear();
  	if(fout.good()){
	//output number of magicians
	fout << magSize << endl;
		//output each magician
		for(i = 0; i < magSize; i++){
		magicians[i].outputToFile(fout);
		}
  	//close file
	fout.close();
	}
}
void stringcpy(char* name, char* newname){
  int i;
  for (i = 0; newname[i] !='\0';i++){
  name[i] = newname[i];
  }
  name[i] = '\0'; 
}

/*bool schedule(booking mag[], booking hol[], char* holiday, int magSize, int holSize)
  {
	int hID = searchId(holiday, hol, holSize);
	int j = 0;
	int i;
	item temp;
	bool found;
	hol[hID].getItem(temp);
	for(i = 0; i < magSize; i++, j++){
		if(compareString(mag[j].id, temp.specialName){
		i = 0;
		}
	return true;
	}
  }*/
