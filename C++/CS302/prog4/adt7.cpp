//Class written by 
//INCLUDE FILES
  #include <iostream>
  #include "adt7.h"
  using namespace std;

using namespace std;

/************************* rbnode *************************/

// RBNODE CONSTRUCTOR
rbnode::rbnode( long newElement )
   {
    element = newElement;
    right = NULL;
    left = NULL;
    parent = NULL;
    color = 'R';
   }

// RBNODE DESTRUCTOR
rbnode::~rbnode()
   {
    right = NULL;
    left = NULL;
    parent = NULL;
   }

// GET COLOR
char rbnode::getColor()
   {
    return color;
   }

// GET ELEMENT
long rbnode::getElement()
   {
    return element;
   }

/************************* rbtree *************************/

// RBTREE CONSTRUCTOR
rbtree::rbtree( int ignore )
   {
    root = NULL;
    w = NULL;
    x = NULL;
    y = NULL;
    z = NULL;
   }

// RBTREE DESTRUCTOR
rbtree::~rbtree()
   {
    root = NULL;
    w = NULL;
    x = NULL;
    y = NULL;
    z = NULL;
   }

// INSERT
void rbtree::rbInsert( long value , int& swaps, int& comparisons)
   {
    z = new rbnode( value );
    y = NULL;
    x = root;
    while ( x != NULL )
      {
   	   y = x;
      comparisons++;
       if( z->element == x->element )
          {
           cout << "Duplicate Value, no insert" << endl << endl;
           delete z;
           return;
          }
       else if( z->element < x->element )
          {
	  comparisons++;
		   x = x->left;
          }
	   else
          {
	   comparisons++;
		   x = x->right;
          }
      }

	z->parent = y;

    if( y == NULL )
       {
        root = z;
       }
    else
	   {
	    z->parent = y;
	    if( z->element < y->element )
           {
		    y->left = z;
           }
	    else
           {
        	y->right = z;
           }
	   }
    insertFixup( z , swaps, comparisons);
   }

// INSERT FIX-UP
void rbtree::insertFixup( rbnode * z, int& swaps, int& comparisons )
    {
	while( z->parent != NULL && z->parent->color == 'R' )
	   {
		comparisons++;
		swaps++;
		if( z->parent == z->parent->parent->left)
		   {
			y = z->parent->parent->right; //uncle

			//Case 1 when y is red
			if( y != NULL && y->color == 'R'  )
			   {
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
               }

			//Case 2: y is black and z is right child
			else if( z == z->parent->right )
			   {
			   comparisons++;
				z = z->parent;
				leftRotate( z );
			   }

				//Case 3: y is black and z is left child
			else 
			   {
			   comparisons++;
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				rightRotate( z->parent->parent );
			   }
		   }
		else
		   {
			y = z->parent->parent->left;

            //Case 1
			comparisons++;
			if( y != NULL && y->color == 'R'  )
			   {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
               }

            //Case 2
            else if( z == z->parent->left )
               {
		comparisons++;
                z = z->parent;
                rightRotate( z );
               }

                //Case 3
            else
			   {
			  comparisons++;
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
                leftRotate( z->parent->parent );
			   }
		   }
	   }
	root->color = 'B';

   }

// DELETE
void rbtree::rbDelete( long value, int& swaps, int& comparisons )
   {
	y = z;

	if( z == NULL)
       {
        return;
       }
	else
	   {
		comparisons++;
		if( z->left == NULL || z->right == NULL )
           {
			y = z;
           }
		else
           {
			y = successor( z );
           }
		comparisons++;
		if( y->left == NULL )
           {
			x = y->left;
           }
		else
           {
			x = y->right;
           }

		setparent( x, y->parent );
		if( y->parent == NULL )
           {
			root = x;
           }
		else if( y == y->parent->left )
           {
			comparisons++;
			y->parent->left = x;
           }
		else
           {
			comparisons++;
			y->parent->right = x;
           }
		if( y != z )
           {
			z->element = y->element;
           }
		if( y->color == 'B' )
           {
			deleteFixup( x, swaps, comparisons );
           }
	   }
   }

// DELETE FIX-UP
void rbtree::deleteFixup( rbnode * x, int& swaps, int& comparisons )
   {
	while( x != NULL && x->color == 'B' )
	  {
		comparisons++;
		if( x == x->parent->left )
		   {
			comparisons++;
			w = x->parent->right;
			if( w != NULL )
			   {
			    if( w->color == 'R' )
				   {
				    swaps++;
				    w->color = 'B';
				    x->parent->color = 'R';
				    leftRotate( x->parent);
				    w = x->parent->right;
				   }
			    if( w->left->color == 'B' && w->right->color == 'B' )
				   {
				    w->color = 'R';
				    x = x->parent;
				   }
			    else if( w->right->color == 'B' )
				   {
					swaps++;
				    w->left->color = 'B';
				    w->color = 'R';
				    rightRotate( w );
				    w = x->parent->right;
				   }
			    w->color = x->parent->color;
			    x->parent->color = 'B';
			    w->right->color = 'B';
			   }
			leftRotate( x->parent );
			x = root;
		   }
		else// Everything same as above with left and right interchanged. Accounting when color of w is red.
		   {
			w = x->parent->left;
			if( w != NULL )
			   {
		comparisons++;
                if( w->color == 'R' )
				   {
		    swaps++;
                    w->color = 'B';
                    x->parent->color = 'R';
                    leftRotate( ( x->parent ) );
                    w = x->parent->left;
		comparisons++;
		   }
                if( w->right->color == 'B' && w->left->color == 'B' )
				   {		    
                    w->color = 'R';
                    x = x->parent;
				   }
                else if( w->left->color == 'B' )
				   {
		    comparisons++;
                    w->right->color = 'B';
                    w->color = 'R';
		    swaps++;
                    rightRotate( w );
                    w = x->parent->left;
				   }
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
		       }
		comparisons++;
	    swaps++;
            leftRotate( x->parent );
            x = root;
           }
	   x->color = 'B';
	  }
   }

// LEFT ROTATE
void rbtree::leftRotate( rbnode * x )
   {
	y = x->right;
	x->right = y->left;
	setparent( y->left, x );
	setparent( y, x->parent );
	if( x->parent == NULL )
       {
		root = y;
       }
	else if( x == x->parent->left )
       {
		x->parent->left = y;
       }
	else
       {
		x->parent->right = y;
       }
	y->left = x;
	setparent( x, y );
   }

// RIGHT ROTATE
void rbtree::rightRotate( rbnode * x )
   {
	y = x->left;
	x->left = y->right;
	setparent( y->right, x );
	setparent( y, x->parent );
	
	if( x->parent == NULL )
       {
		root = y;

       }
	else if( x == x->parent->right )
       {
		x->parent->right = y;
       }
	else
       {
		x->parent->left = y;
       }
	y->right = x;
	setparent( x, y );
   }

// SET PARENT
void rbtree::setparent( rbnode *r, rbnode *r1)
   {
	if( r != NULL )
       {
        r->parent = r1;
       }
   }

//SUCCESSOR OF A NODE
rbnode * rbtree::successor( rbnode *r )
   {

	if( r->right != NULL )
       {
		return( minimum( r->right ) );
       }
	y = r->parent;
	while( y != NULL && r == y->right )
	   {
		r = y;
		y = y->parent;
	   }
	if( y == NULL )
       {
		return r;
       }
	else
       {
		return y;
       }
   }

//PREDECESSOR OF A NODE
rbnode * rbtree::predecessor( rbnode *r )
   {
	if( r->parent != NULL )
       {
		if( r->parent->right == r )
		return r->parent;
       }
	if( r->left != NULL )
       {
		return maximum( r->left );
       }
	return r;
   }

//MINIMUM NODE OF A TREE
rbnode * rbtree::minimum( rbnode *r )
   {
	while( r->left != NULL )
		r = r->left;
	return r;
   }

//MAXIMUM NODE OF A TREE
rbnode * rbtree::maximum( rbnode * r )
   {
	while( r->right != NULL )
       {
		r = r->right;
       }
	return r;
   }

long rbtree::find( long value, int& swaps, int& comparisons )
   {
    long found;
    z = root;

    while( 1 )
       {
        if( z != NULL )
           {
	    comparisons++;
            if( value < z->element )
               {
                z = z->left;
               }
            else if( value > z->element )
               {
		comparisons++;
                z = z->right;
               }
            else if( z->element == value )
               {
		comparisons++;

                found = z->element;
                return found;
               }
           }
        else
           {
            cout << "value not found in tree" << endl;
            return -1;
           }
       }
   }
