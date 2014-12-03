// HEADER FILES
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// NODE CLASS
class node
   {

    friend class linkedList;

    private:

	node();
	node(const node&);
	~node();

    char* data1;
    char* data2;
    node* next;
   };

// LINKEDLIST CLASS
class linkedList
   {
    public:

    linkedList();
    ~linkedList();

    void addFront( char*, char* );
    void addRear( char*, char* );
    void getFront( char*, char* );
    void getRear( char*, char* );
    void displayList();

    private:

    node* cursor;
    node* head;
    };
