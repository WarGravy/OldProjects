//Class written by 
using namespace std;

#include <iostream>

using namespace std;


class rbnode
   {
    friend class rbtree;

    rbnode( long int );
    ~rbnode();

    char getColor();
    long int getElement();

    long int element;
    char color;
    rbnode *left;
    rbnode *right;
    rbnode *parent;
   };

class rbtree
   {
    friend class rbnode;

    public:

    rbtree( int = 0 );
    ~rbtree();

    void rbDelete( long , int& swaps, int& comparisons );
    void deleteFixup( rbnode *, int&, int& );

    void rbInsert( long, int& swaps ,int& comparisons );
    void insertFixup( rbnode * , int&, int&);

    void leftRotate( rbnode * );
    void rightRotate( rbnode * );

    void setparent( rbnode *, rbnode * );
    long int find( long , int& swaps, int& comparisons );

    rbnode * successor( rbnode * );
    rbnode * predecessor( rbnode * );

    rbnode * maximum( rbnode * );
    rbnode * minimum( rbnode * );

    private:

    rbnode *root;
    rbnode *w;
    rbnode *x;
    rbnode *y;
    rbnode *z;
   };

