//week 9 notes

//include files
#include <iostream>
#include <fstream>
using namespace std;

//program 1 ASCII value of an int
/*
int main()
    {
    int numb = 122;
    char somechar;
    
    cout<< char(numb) << endl;

    system("pause");
    return 0;

    }

*/

/*

function for returning two (pass by reference "&")

void promptForInts( int &firstInt, int & secondInt );

in main program code:
int alpha, beta;

promptForInts( alpha, beta );
cout << alpha << ' ' << beta << endl;

implementation:

void promptForInts( int &firstInt, int & secondInt )
{
 cout << "Enter first number";
 cin >> firstInt;
 cout << "Enter second number";
 cin >> secondInt; 
}


*/

/*

function for string(pass by reference "&")

void promptForName( string &name );

in main program code:
string name;

promptForName( name);
cout << name << endl;

implementation:

void promptForName( string &name )
{
 cout << "Enter first name";
 cin >> name;
}


*/

/*
proto:
void getNumbAndName(ifstream &theFile, int &numb, string &name);
main:
ifstream infile;
string filename = "myfile.txt";

infile.clear();
infile.open( filename.c_str() );
if ( infile.good())
   {
   getNumbAndName( infile, number, name );
   cout << number << ' ' << name;
   
   infile.close();
   }
else
    {

    cout << "could not open" << filename << endl;
    }

implementation:
void getNumbAndName(ifstream &theFile, int &numb, string &name)
{
  string garbage;
  theFile >> numb;
  theFile >> garbage;
  theFile >> name;

}
*/

/*
ARRAYS


*/
