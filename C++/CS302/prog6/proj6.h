#include <iostream>

class person;

using namespace std;

class graph
   {
    public:
    graph();
    ~graph();
    bool addVert( char*, char );
    void bfs();
    //the char* is the name of the person you wish to add a child or spouse to
    bool setChild( char*, char* );
    bool setSpouse( char*, char* );

    private:

    person* root; 
    person* cursor1;
    person* cursor2;
    //zack: I need this
    int lowLevel;
   };

class person
   {
    friend class graph;
    public:
    person( char*, char, int );

    ~person();
    char* getName();
    char getGender();
    int getLevel();
    private:
    char* name;
    char gender;
    //zack: I need the level
    int level;
    int numberOfChildren;
    person* father;
    person* mother;
    person* spouse;
    person* child[20];
    person* next;

   };
