#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*If initial string is index.html, index2.html, or index3.html it accessed the css sheet in same directory as well as images in the image folder, but if anything else is assumes the css is one folder up '../'
*/

//class
class htmlzack{
public:
htmlzack(string temp);
~htmlzack();
//TABLES
  /*<table border = "5" width = "800" align="center">
  <tr><th> string here </th></tr>*/
  void insertTableHead(std::string);
  //<tr><td> string here </td><tr>
  void insertRow(std::string);
  //<tr><td> string: int </td><tr>
  void insertRow(std::string, int);
  //<tr><td> string here: int(int%) </td><tr>
  void insertRow(std::string, int, int);
  //</table><p><br/></p>
  void endTable();
//LISTS
  //</ul>
  void insertListEndTag();
  //<ul>
  void insertListStartTag();
  //<p><b> string here </b><br />string here</p><ul>
  void insertListHead(std::string, std::string);
  //<li> string here </li>
  void insertList(std::string);
  //<li><a href="link"> string here (int/int)</a></li>
  void insertListLink(std::string temp, std::string link, int, int);
  //<li><a href="link"> string here</a></li>
  void insertListLink(std::string temp, std::string link);
  //<li><a href="link"> string here</a></li> (opens in new window)
  void insertListLinkW(std::string temp, std::string link);
  //<li style="color: #F00;"> string here </li>
  void insertListR(std::string);
  //<li> string here : int here </li>
  void insertList(std::string, int);
  //</ul><p><br/></p>
  void endList();
private:
void initialize();
void end();
std::ofstream hout;
};

