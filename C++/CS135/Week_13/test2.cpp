#include <iostream>
#include <fstream>
#include "formatted_console_io_v16.h"
using namespace std;

const char MARKER_CHAR = ' ';
const char NEW_CHAR = '*';


int main()
  {
  startCurses();
  setColor(COLOR_RED, COLOR_BLUE, true);

  printCharAt( -1, -10, 'A');
  cout<< endl<<endl;

  system("pause");
  endCurses;
  return 0;
  }
