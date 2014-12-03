// HEADER FILES

#include <iostream>
#include <fstream>
#include <string.h>
#include "linkedList.h"


using namespace std;

// GLOBAL CONSTANTS

// FUNCTION PROTOTYPES

int displayMenu();

// MAIN PROGRAM

int main()
   {
    // initialize variables
    int response;
    bool runProgram = true;
    char* name = new char[25];
    char* holiday = new char[25];

    // initialize objects
    linkedList list1;

    // do-loop for menu
    do
       {
        // set flag
        response = displayMenu();

        // switch case
        switch( response )
           {
            // case 1-enter name at front of list
            case 1: 
                cout << "enter a name" << endl << endl;
                cin >> name;
                cout << "enter a holiday" << endl << endl;
                cin >> holiday;
                list1.addFront( name, holiday );

                break;

            // case 2-enter name at rear of list
            case 2:
                cout << "enter a name" << endl << endl;
                cin >> name;
                cout << "enter a holiday" << endl << endl;
                cin >> holiday;
                list1.addRear( name, holiday );

                break;;

            // case 4-get name at front of list and remove
            case 3:
                list1.getFront( name, holiday );
                cout << name << " " << holiday << endl << endl;

                break;

            // case 5-get name at rear of list and remove
            case 4:
                list1.getRear( name, holiday );
                cout << name << " " << holiday << endl << endl;

                break;

            // case 6-display current list
            case 5:
                list1.displayList();

                break;

            // case 7-quit menu
            case 6:
                if( response == 6 )
                   {
                    runProgram = false;
                   }

                break;

            // default-display error message
            default:
                cout << "incorrect entry, try again..............." << endl << endl;
                runProgram = true;
           }

       }
    while( runProgram == true );

//    delete[]name;
//    delete[]holiday;

    // end program
    return 0;
   }

// FUNCTION IMPLEMENTATION

int displayMenu()
   {
    // initialize variables
    int num;

    // output menu options
    cout << endl << endl << endl;
    cout << "            Node Based List Class" << endl << endl << endl;
    cout << "1.  Add a name and holiday to the front of the list" << endl << endl;
    cout << "2.  Add a name and holiday to the rear of the list" << endl << endl;
    cout << "3.  Get the name and holiday at the front of the list" << endl << endl;
    cout << "4.  Get the name and holiday at the rear of the list" << endl << endl;
    cout << "5.  Display the list" << endl << endl;
    cout << "6.  Quit" << endl << endl;
    cout << endl << endl << endl;
    cin >> num;


    // return selection
    return num;
   }

