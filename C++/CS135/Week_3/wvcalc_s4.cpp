/*//////////////////////////////////////////////////////////////////////////
  
    Program:             wvcalc.cpp
    Author:              <Zachary Carlson>
    Update By:           n/a
    Description:         Program calculates Y position in a Wave.

    Program Written:     02/12/2012
    Most Recent Update:  02/14/2012 - 12:14 p.m.
    Date Due for Review: 02/14/2012

/////////////////////////////////////////////////////////////////////////*/

// Header Files

   #include "formatted_cmdline_io_v06.h"	// for console I/O
   #include <cmath>
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
       int testNum;
       char pipe = '|';
       string media;
       double amplitude, time, wavePeriod, xLocation, waveLength, yPosition;
       double pi = 3.14159265;
         //Variables added for calculating yPosition
         double partOne, partTwo;

       //title and underline and vertical space
         //function:printString, printEndLines
         printEndLines(1);
         printString("   Y Position in Wave Calculator", 31, "CENTER");
         printEndLines(1);
         printString("   =============================", 31, "CENTER");
         printEndLines(2);

    // input Data
       //prompt experimental test number
         //function:promptForInt
         testNum = promptForInt("   Enter experiment test number   : ");

       //prompt wave media
         //function:promptForString
         media = promptForString("   Enter wave media     <material>: ");

       //prompt amplitude
         ///function:promptForDouble
         amplitude = promptForDouble("   Enter Amplitude             <m>: ");

       //prompt time
         ////function:promptForDouble
         time = promptForDouble("   Enter time                <sec>: ");

       //prompt wave period
         //function:promptForDouble
         wavePeriod = promptForDouble("   Enter wave period         <sec>: ");

       //prompt x location
         //function:promptForDouble
         xLocation = promptForDouble("   Enter x location          <sec>: ");

       //prompt wavelength
         //function:promptForDouble
         waveLength = promptForDouble("   Enter wavelength            <m>: ");
    // calculate Y position
       /*/calculate Y1
       amplitude * sin [ 2pi * (( time/period) - (xlocation/waveLength)]
       (time/period) - (xlocation/wavelength) = partOne 
       2pi * partOne = partTwo
       amplitude * (sin partTwo) = yPosition
       
       added local variables: all doubles
       partOne, partTwo

       /*/

          //part 1
          partOne = (time / wavePeriod) - (xLocation / waveLength);
          //part 2
          partTwo = 2 * pi * partOne;
          //part 3
          yPosition = amplitude * sin( partTwo );
    // output Data
       //print vertical space
         //function:printEndLines
         printEndLines(2);

       //print top line aka table starts
         //function:printString,printEndLines
         printString ("   |=====================================================|", 58, "CENTER"); 
         printEndLines(1);
       //print main title
         //function:printString,printEndLines, printChar
         printString ("   ",3,"CENTER");
         printChar (pipe);
         printString ("   EXPERIMENTAL RESULTS", 53, "CENTER");
         printChar (pipe);
         printEndLines(1);
       //print line under title
         //function:printString,printEndLines
         printString ("   |============================|==========|=============|", 58, "CENTER"); 
         printEndLines(1);
       //print sub titles
           //print column title 1 RESULT NAME
             //function:printString
         printString ("   |         RESULT NAME        |", 33, "CENTER"); 

           //print column title 2 VALUE
             //function:printString, printChar
         printString ("VALUE", 10, "CENTER"); 
         printChar (pipe);

           //print column title 3 Units
             //function:printString, printEndLines, printChar
         printString ("UNITS", 13, "CENTER"); 
         printChar (pipe);
         printEndLines(1);

             //underline title
               //function:printString, printEndLines
         printString ("   |============================|==========|=============|", 58, "CENTER"); 
         printEndLines(1);
       //data set 1 Experimental Test Number
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print experimental test number
             //function:printString
             printString (" Experimental Test Number", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printInt, printString
             printInt (testNum, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("n/a", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //data set 2 Media Material
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print media material
             //function:printString
             printString (" Media Material", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printString, printString
             printString (media, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("n/a", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //data set 3 Amplitude
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print amplitude
             //function:printString
             printString (" Amplitude", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printDouble, printString
             printDouble (amplitude, 2, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("meters", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //data set 4 Time
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print time
             //function:printString
             printString (" Time", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printDouble, printString
             printDouble (time, 2, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("seconds", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //data set 5 Wave Period
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print wave period
             //function:printString
             printString (" Wave Period", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printDouble, printString
             printDouble (wavePeriod, 2, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("seconds", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //data set 6 Wave Length
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print wave length
             //function:printString
             printString (" Wave Length", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printDouble, printString
             printDouble (waveLength, 2, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("meters", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //data set 7 X Location
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print x location
             //function:printString
             printString (" X Location", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printDouble, printString
             printDouble (xLocation, 2, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("meters", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //line divider, same as line under title
         //function:printString,printEndLines     
         printString ("   |============================|==========|=============|", 58, "CENTER"); 
         printEndLines(1);
       //Y position
           //print pipe
             //function:printChar, printString
             printString ("   ", 3, "CENTER");
             printChar (pipe);
           //print y position
             //function:printString
             printString (" Y Position", 28, "LEFT");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print value
             //function:printDouble, printString
             printDouble (yPosition, 2, 9, "RIGHT");
             printString (" ", 1, "CENTER");
           //print pipe
             //function:printChar
             printChar (pipe);
           //print units
             //function:printString
             printString ("meters", 13, "CENTER");
           //print pipe
             //function:printChar, printEndlines
             printChar (pipe);
             printEndLines(1);
       //bottom line of table aka table ends
         //function: printString, printEndLines
         printString ("   |============================|==========|=============|", 58, "CENTER"); 
         printEndLines(1);
    // end program
       //print vertical space
         //function:printEndLines
         printEndLines(2);
       //hold screen
         //function:system/pause
         system("pause");
       // return zero
       return 0;
   }

// Supporting function implementations

    // none



