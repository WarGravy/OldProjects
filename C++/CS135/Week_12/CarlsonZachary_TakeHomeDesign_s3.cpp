/*
Name: Zachary Carlson
Date: April 17, 2012
TA: Faezeh T.
Section: 1202
Assignment: CS 135 Take Home Component Mid Term 2 - Spring 2012
*/

//include files
#include<iostream>
#include<fstream>
using namespace std;

//global constants
  //none

//function prototypes

/*
Name:readFile
Description: reads a file and uploads each integer into an array
Input: array and ifstream
Output: none
Return: the number of integers in an array
*/
int readFile( int arr[], ifstream &fin);

/*
Name:dataAverage
Description: averages the numbers in an array
Input: the array and the count of how many integers is in the array
Output: none
Return: the average of all the integers in the array
*/
int dataAverage( int arr[], int count );

/*
Name:highestValue
Description: finds the highest value in an array
Input: the array and the count of how many integers is in the array
Output: none
Return: returns the highest value in the array
*/
int highestValue( int arr[], int count );

/*
Name:lowestValue
Description: finds the lowest value in an array
Input: the array and the count of how many integers is in the array
Output: none
Return: returns the lowest value in the array
*/
int lowestValue( int arr[], int count );


//main program
int main()
  {
  //initialize main function
    //variables

    //display title

    //clear fstream
    
  //prompt for filename and test if opened correctly
    //prompt

    //if not good

      //{
      
      //display error

      //end program

      //}

  //display data analysis and upload data to an array
    //display data analysis title

    //read the file and upload to an array
    //function: int readFile( int arr[], ifstream &fin);

  //find a item count, data average, highest value, lowest value

    //find data average
    //function: int dataAverage( int arr[], int count );

    //find highest value
    //function: int highestValue( int arr[], int count );

    //find lowestvalue
    //function: int lowestValue( int arr[], int count );

  //display results

  //end program and pause screen
  
  //pause
  system("pause");
  //end
  return 0;
  }

//function implementations

int readFile( int arr[], ifstream &fin)
  {
  //stub
  return 1;
  }

int dataAverage( int arr[], int count )
  {

  //stub
  return 0;
  }

int highestValue( int arr[], int count )
  {

  //stub
  return 0;
  }

int lowestValue( int arr[], int count )
  {

  //stub
  return 0;
  }
