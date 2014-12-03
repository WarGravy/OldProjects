/*//////////////////////////////////////////////////////////////////////////
  
    Program:             wvcalc.cpp
    Author:              <Zachary Carlson>
    Update By:           n/a
    Description:         Program calculates Y position in a Wave.

    Program Written:     02/12/2012
    Most Recent Update:  02/14/2012 - 11:45 p.m.
    Date Due for Review: 02/14/2012

/////////////////////////////////////////////////////////////////////////*/

// Header Files

   #include "formatted_cmdline_io_v06.h"	// for console I/O

   using namespace std;

// Global Constant Definitions

   // none

// Global Function Prototypes

    // none

// Main Program Definition
int main()
   {
    // initialize program
       //initialize variables
         //Variables added for calculating yPosition

       //title and underline and vertical space
         //function:printString, printEndLines
    // input Data
       //prompt experimental test number
         //function:promptForInt

       //prompt wave media
         //function:promptForString

       //prompt amplitude
         ///function:promptForDouble

       //prompt time
         ////function:promptForDouble

       //prompt wave period
         //function:promptForDouble

       //prompt x location
         //function:promptForDouble

       //prompt wavelength
         //function:promptForDouble

    // calculate Y position
       //calculate Y1
              /*/calculate Y1
       amplitude * sin [ 2pi * (( time/period) - (xlocation/waveLength)]
       (time/period) - (xlocation/wavelength) = partOne 
       2pi * partOne = partTwo
       amplitude * (sin partTwo) = yPosition
       
       added local variables: all doubles
       partOne, partTwo

       /*/

          //part 1
          //part 2
          //part 3

    // output Data
       //print vertical space
         //function:printEndLines

       //print top line aka table starts
         //function:printString,printEndLines

       //print main title
         //function:printString,printEndLines, printChar

       //print line under title
         //function:printString,printEndLines

       //print sub titles
           //print column title 1 RESULT NAME
             //function:printString

           //print column title 2 VALUE
             //function:printString, printChar

           //print column title 3 Units
             //function:printString, printEndLines, printChar

             //underline title
               //function:printString, printEndLines
       //data set 1 Experimental Test Number
           //print pipe
             //function:printChar, printString

           //print experimental test number
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printInt, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //data set 2 Media Material
           //print pipe
             //function:printChar, printString

           //print media material
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printString, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //data set 3 Amplitude
           //print pipe
             //function:printChar, printString

           //print amplitude
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printDouble, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //data set 4 Time
           //print pipe
             //function:printChar, printString

           //print time
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printDouble, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //data set 5 Wave Period
           //print pipe
             //function:printChar, printString

           //print wave period
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printDouble, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //data set 6 Wave Length
           //print pipe
             //function:printChar, printString

           //print wave length
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printDouble, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //data set 7 X Location
           //print pipe
             //function:printChar, printString

           //print x location
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printDouble, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //line divider, same as line under title
         //function:printString,printEndLines     

       //Y position
           //print pipe
             //function:printChar, printString

           //print y position
             //function:printString

           //print pipe
             //function:printChar

           //print value
             //function:printDouble, printString

           //print pipe
             //function:printChar

           //print units
             //function:printString

           //print pipe
             //function:printChar, printEndlines

       //bottom line of table aka table ends
         //function: printString, printEndLines

    // end program
       //print vertical space
         //function:printEndLines

       //hold screen
         //function:system/pause

       // return zero
       return 0;
   }

// Supporting function implementations

    // none



