
using namespace std;

#include <iostream>

using namespace std;


class rbnode
   {
    friend class intervalTree;

    rbnode( long int, long int );
    ~rbnode();

    char getColor();
    long int getElement();
    //element is low, aka key
    long int element;
    long int high;
    //max is the max interval following down the right path of the node.
    long int max;
    char color;
    rbnode *left;
    rbnode *right;
    rbnode *parent;
   };

class intervalTree
   {
    friend class rbnode;

    public:

    intervalTree( int = 0 );
    ~intervalTree();

    void rbDelete(  );
    void deleteFixup( rbnode*);

    void rbInsert( long , long, std::ofstream& outFile  );
    void insertFixup( rbnode* );

    void leftRotate( rbnode* );
    void rightRotate( rbnode* );

    void setparent( rbnode *, rbnode * );
    long int find( long, long, std::ofstream& outFile );
    long int search( long, long, std::ofstream& outFile );

    void print(std::ofstream& outFile);

    rbnode * successor( rbnode * );
    rbnode * predecessor( rbnode * );

    rbnode * maximum( rbnode * );
    rbnode * minimum( rbnode * );

    private:
    void PrintTree(rbnode* tree, std::ofstream& outFile); 

    rbnode *root;
    rbnode *w;
    rbnode *x;
    rbnode *y;
    rbnode *z;
   };

