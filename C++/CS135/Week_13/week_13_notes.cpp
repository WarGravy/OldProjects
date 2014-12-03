
#include <iostream>
#include <fstream>
using namespace std;

const char NULL_CHAR = '\0';
const int MAX_ROWS = 100;
const int MAX_COLS = 80;
const int MAX_STR_LEN = 80;
/*
void showMatrix(double matrix[MAX_ROWS][MAX_COLS], int numRows, int numCols);
  void showRow( double row[MAX_COLS], int numCols );

int main()
  {
  double matrix[MAX_ROWS][MAX_COLS];
  int numRows = 3;
  int numCols = 5;
  
  showMatrix(matrix, numRows, numCols);
  cout << endl;
  showRow(matrix[0], numCols );

  cout<< endl;
  system("pause");
  return 0;
  }

void showMatrix(double matrix[MAX_ROWS][MAX_COLS], int numRows, int numCols)
  {
  int row, col; //index

  for( row = 0; row < numRows; row++)
    {
    for( col = 0; col < numCols; col++)
      {
      cout << matrix[row][col];
      }
    cout << endl;
    }
  }
void showRow( double row[MAX_COLS], int numCols )
  {
  int col;

      for( col = 0; col < numCols; col++)
      {
      cout << row[col] << ' ';
      }
    cout << endl;
  }
*/
//-------------------------------------------------------------
void setSentences( char sentence[MAX_ROWS][MAX_STR_LEN], char value[MAX_STR_LEN]);

int main()
  {
  char sentences[MAX_ROWS][MAX_STR_LEN+1];
  char value[MAX_STR_LEN] = "Hello, World" );
  int numSentences = 0;

  setSentences( sentences[0], value);
  numSentences = 1;

  cout<< endl;
  system("pause");
  return 0;
  }
void setSentences( char sentence[MAX_ROWS][MAX_STR_LEN], char value[MAX_STR_LEN])
{
int index;

for (index = 0; value[index] != NULL_CHAR ; index++)

    {
    sentence[index] = value[index];
    }
  sentence[index] = NULL_CHAR;
}
