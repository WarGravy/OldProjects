#include <iostream>

class person;
class queue;
using namespace std;

class graph
   {
    public:
    graph();
    ~graph();
    bool addVert( char*, char );
    void bfs(char*, char*, int path[], int&, char&);
    //the char* is the name of the person you wish to add a child or spouse to
    bool setChild( char*, char* );
    bool setSpouse( char*, char* );
    void clearMarks();
    bool isMarked(person);
    void GetToVertices(person, queue&);
    private:
    person* root; 
    person* cursor;
    //zack: I need this
    int lowLevel;
   };

class person
   {
    friend class graph;
    friend class queue;
    public:
    
    person( char*, char, int );

    ~person();
    char getGender();
    int getLevel();

    void operator=( person& );
    bool operator==( person& );
    friend ostream& operator<<( ostream&, const person& );

    private:
    char name[10];
    char gender;
    //zack: I need the level
    bool marked;
    int level;
    int numberOfChildren;
    person* father;
    person* mother;
    person* spouse;
    person* child[20];
    person* next;
    person* bfsnext;

   };
using namespace std;

class queue
   {
    public: 
    queue();
    queue( int max );
    ~queue();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue( person newItem );
    void Dequeue( person& item );

    private:
    person* front;
    person* rear;
   };

