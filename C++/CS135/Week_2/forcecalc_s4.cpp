/*//////////////////////////////////////////////////////////////////////////
  
    Program:             forcecalc.cpp
    Author:              <Zachary Carlson>
    Update By:           n/a
    Description:         Program calculates and displays some masses

    Program Written:     02/05/2012
    Most Recent Update:  02/06/2012 - 1:51 p.m.
    Date Due for Review: 02/07/2012

/////////////////////////////////////////////////////////////////////////*/

// Header Files

   #include "formatted_cmdline_io_v06.h"	// for console I/O
   #include <iostream>
   using namespace std;

// Global Constant Definitions

   // none

// Global Function Prototypes

    // none

// Main Program Definition
int main()
   {
    // initialize program

        // initialize variables
        int testNumOne, testNumTwo;
        string forceNameOne; 
        string forceNameTwo;
        double firForcVal, secForcVal, firAcc, secAcc;
        double massOne, massTwo;
        char pipe = '|';

        // show title, with underline
           // function: iostream <<
           cout<< "Mass Calculation Program"<<endl
               << "========================"<<endl
               <<endl;

    // input Data

        // get test numbers from user

           // acquire first experimental test number
              // function: iostream >>, <<
              cout << "Enter first experimental test number     :";
              cin >> testNumOne ;
           // acquire second experimental test number
              // function: promptForInt
              testNumTwo = promptForInt ( "Enter second experimental test number    :");

        // output a divider space
           // function: iostream <<
           cout << " "<<endl;
        // get force name from user

           // acquire first force name
              // function: iostream >>, <<
              cout << "Enter first force name <cause of force>  :";
              cin >> forceNameOne;
           // acquire second force name
              // function: promptForString
              forceNameTwo = promptForString ( "Enter second force name <cause of force> :");

        // output a divider space
           // function: printEndLines
           printEndLines(1);
        // get force from user

           // acquire first force value
              // function: iostream >>, <<
              cout << "Enter first force (Newtons)              :";
              cin >> firForcVal;
           // acquire second force value
              // function: promptForDouble
              secForcVal = promptForDouble ( "Enter second force <Newtons>             :");

        // output a divider space
           // function: printEndLines
           printEndLines(1);
        // get acceleration from user

           // acquire first acceleration value
              // function: iostream >>, <<
              cout << "Enter first acceleration <m/s/s>         :";
              cin >> firAcc;
           // acquire second acceleration value
              // function: promptForDouble
              secAcc = promptForDouble ("Enter second acceleration <m/s/s>        :");

    // calculate masses

       // calculate mass one
          // operation: math
          massOne = firForcVal / firAcc;
       // calculate mass two
          // operation: math
          massTwo = secForcVal / secAcc;
    // output Data

        // make vertical space
           // function: printEndLines
           printEndLines(1);
        // print top line
           // function: printString, printEndLines
           printString ("|---------------------------------------------------------------|", 65, "CENTER");
           printEndLines(1);
        // print main title
           // function: printChar, printString, printEndLines
           printString ("|                       DATA PRESENTATION                       |", 65, "CENTER");
           printEndLines(1);
        // print sub titles

           // print top line
              // function: printString, printEndLines
              printString ("|--------|----------------|---------|----------------|----------|", 65, "CENTER");
              printEndLines(1);
           // print main subtitle line
              // function: printString, printEndLines
              printString ("|  TEST  |   Force Name   |  Force  |  Acceleration  |   Mass   |", 65, "CENTER");
              printEndLines(1);
           // print subtitle units line
              // function: printString, printEndLines
              printString ("|   Num  |     <cause>    |<Newtons>|    <m/s/s>     |   <Kg>   |", 65, "CENTER");
              printEndLines(1);
           // print bottom line
              // function: printString, printEndLines
              printString ("|--------|----------------|---------|----------------|----------|", 65, "CENTER");
              printEndLines(1);
        // print first data set

           // print left line edge (Pipe)
              // function: printChar
              printChar (pipe);

           // print test number
              // function: printInt 
              printInt (testNumOne, 8, "CENTER");

           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);           
           // print force name
              // function: printString
              printString (forceNameOne, 16, "CENTER");
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print force
              // function: printDouble
               printDouble (firForcVal, 2, 9, "RIGHT");            
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print acceleration
              // function: printDouble
              printDouble (firAcc, 2, 16, "RIGHT");
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print mass
              // function: printDouble
              printDouble (massOne, 2, 10, "RIGHT");
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print end of line
              // function: printEndLines
              printEndLines(1);
        // print second data set

           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print test number
              // function: printInt
              printInt (testNumTwo, 8, "CENTER");
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print force name
              // function: printString
              printString (forceNameTwo, 16, "CENTER");
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print force
              // function: printDouble
              printDouble (secForcVal, 2, 9, "RIGHT"); 
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print acceleration
              // function: printDouble
              printDouble (secAcc, 2, 16, "RIGHT");
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
           // print mass
              // function: printDouble
               printDouble (massTwo, 2, 10, "RIGHT");
           // print divider char (Pipe)
              // function: printChar
              printChar (pipe);
        // make end of line
           // function: printEndLines
           printEndLines(1);
        // print bottom line
           // function: printString, printEndLines
            printString ("|--------|----------------|---------|----------------|----------|", 65, "CENTER");
            printEndLines(1);
    // end program

       // print vertical space
          // function: printEndLines
          printEndLines(1);
       // hold screen for user
          // function: system/pause
          system( "PAUSE" );
       // return zero
       return 0;
   }

// Supporting function implementations

    // none



