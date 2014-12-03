
//INCLUDE FILES
  #include <iostream>
  #include <fstream>
  #include "intervalTree.h"
  using namespace std;

using namespace std;

/************************* rbnode *************************/

// RBNODE CONSTRUCTOR
rbnode::rbnode( long newElement, long newHigh )
   {
    element = newElement;
    high = newHigh;
    max = newHigh;
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

/************************* intervalTree *************************/

// intervalTree CONSTRUCTOR
intervalTree::intervalTree( int ignore )
   {
    root = NULL;
    w = NULL;
    x = NULL;
    y = NULL;
    z = NULL;
   }

// intervalTree DESTRUCTOR
intervalTree::~intervalTree()
   {
    root = NULL;
    w = NULL;
    x = NULL;
    y = NULL;
    z = NULL;
   }

// INSERT
void intervalTree::rbInsert( long value, long high, std::ofstream& outFile  )
   {
    z = new rbnode( value, high );
    y = NULL;
    x = root;
    while ( x != NULL )
      {
   	   y = x;
      //comparisons++;
       if( (z->element == x->element)&&(z->high == x->high) )
          {
           cout << "Duplicate Value, no insert" << endl << endl;
           outFile << "Duplicate Value, no insert" << endl << endl;
           delete z;
           return;
          }
       else if( z->element <= x->element )
          {
	  //comparisons++;
                   if(z->max < x->max){
		   z->max = x->max;	
 		   }
   		   else{
 		   x->max = z->max;
  		   }
		   x = x->left;
   		   
          }
       else
          {
	   //comparisons++;
		  if(z->max < x->max){
		   z->max = x->max;	
 		   }
   		   else{
 		   x->max = z->max;
  		   }

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
            if(z->max < y->max){
		   z->max = y->max;	
 		   }
   	    else{
 		   y->max = z->max;
  		   }
	    if( z->element <= y->element )
           {
		    y->left = z;
           }
	    else
           {
        	y->right = z;
           }
	   }
    //fix with max
    insertFixup( z );
   }

// INSERT FIX-UP
void intervalTree::insertFixup( rbnode * z )
    {
	while( z->parent != NULL && z->parent->color == 'R' )
	   {
		//comparisons++;
		//swaps++;
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
			   //comparisons++;
				z = z->parent;
				leftRotate( z );
			   }

				//Case 3: y is black and z is left child
			else 
			   {
			   //comparisons++;
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				rightRotate( z->parent->parent );
			   }
		   }
		else
		   {
			y = z->parent->parent->left;

            //Case 1
			//comparisons++;
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
		//comparisons++;
                z = z->parent;
                rightRotate( z );
               }

                //Case 3
            else
			   {
			  //comparisons++;
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
                leftRotate( z->parent->parent );
			   }
		   }
	   }
	root->color = 'B';

   }

// DELETE
void intervalTree::rbDelete( )
   {
	y = z;

	if( z == NULL)
       {
        return;
       }
	else
	   {
		//comparisons++;
		if( z->left == NULL || z->right == NULL )
           {
			y = z;
           }
		else
           {
			y = successor( z );
           }
		//comparisons++;
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
			//comparisons++;
			y->parent->left = x;
           }
		else
           {
			//comparisons++;
			y->parent->right = x;
           }
		if( y != z )
           {
			z->element = y->element;
           }
		if( y->color == 'B' )
           {
			deleteFixup( x );
           }
	   }
   }

// DELETE FIX-UP
void intervalTree::deleteFixup( rbnode * x )
   {
	while( x != NULL && x->color == 'B' )
	  {
		//comparisons++;
		if( x == x->parent->left )
		   {
			//comparisons++;
			w = x->parent->right;
			if( w != NULL )
			   {
			    if( w->color == 'R' )
				   {
				    //swaps++;
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
					//swaps++;
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
		//comparisons++;
                if( w->color == 'R' )
				   {
		    //swaps++;
                    w->color = 'B';
                    x->parent->color = 'R';
                    leftRotate( ( x->parent ) );
                    w = x->parent->left;
		//comparisons++;
		   }
                if( w->right->color == 'B' && w->left->color == 'B' )
				   {		    
                    w->color = 'R';
                    x = x->parent;
				   }
                else if( w->left->color == 'B' )
				   {
		    //comparisons++;
                    w->right->color = 'B';
                    w->color = 'R';
		    //swaps++;
                    rightRotate( w );
                    w = x->parent->left;
				   }
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
		       }
		//comparisons++;
	    //swaps++;
            leftRotate( x->parent );
            x = root;
           }
	   x->color = 'B';
	  }
   }

// LEFT ROTATE
void intervalTree::leftRotate( rbnode * x )
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
void intervalTree::rightRotate( rbnode * x )
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
void intervalTree::setparent( rbnode *r, rbnode *r1)
   {
	if( r != NULL )
       {
        r->parent = r1;
       }
   }

//SUCCESSOR OF A NODE
rbnode * intervalTree::successor( rbnode *r )
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
rbnode * intervalTree::predecessor( rbnode *r )
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
rbnode * intervalTree::minimum( rbnode *r )
   {
	while( r->left != NULL )
		r = r->left;
	return r;
   }

//MAXIMUM NODE OF A TREE
rbnode * intervalTree::maximum( rbnode * r )
   {
	while( r->right != NULL )
       {
		r = r->right;
       }
	return r;
   }

long intervalTree::find( long value, long high, std::ofstream& outFile )
   {
    long found;
    z = root;

    while( 1 )
       {
        if( z != NULL )
           {
	    //comparisons++;
            if( (value < z->element) ||(z->element == value && high != z->high) )
               {
                z = z->left;
               }
            else if( value > z->element )
               {
		//comparisons++;
                z = z->right;
               }
            else if( z->element == value && high == z->high )
               {
		//comparisons++;

                found = z->element;
                return found;
               }
           }
        else
           {
            cout << "value not found in tree" << endl;
            outFile << "value not found in tree" << endl;
            return -1;
           }
       }
   }
long intervalTree::search( long value,long high,  std::ofstream& outFile )
   {
    z = root;

    while( 1 )
       {
        if( z != NULL )
           {
            //check to see if there is an overlap
	    //comparisons++;
            if( high >= z->element && value <= z->high )
               {
                outFile << "Found an overlap: " << endl;
                outFile << value << '\t' << high << endl;
                outFile << z-> element << '\t' << z-> high << endl;
                cout << "Found an overlap: " << endl;
                cout << value << '\t' << high << endl;
                cout << z-> element << '\t' << z-> high << endl;
                 
                return 1;
               }
            else if( value > z->max )
               {
		//comparisons++;
                z = z->right;
               }
            else
               {
		//comparisons++;
		z = z->left;
               }
           }
        else
           {
            cout << "value not found in tree" << endl;
            outFile << "value not found in tree" << endl;
            return -1;
           }
       }
   }
void intervalTree::print(std::ofstream& outFile){
     rbnode* temp = root;
     cout << "Printing Interval Tree..."<<endl;
     outFile << "Printing Interval Tree..."<<endl;
     PrintTree(temp, outFile);
}
//MODIFIED FROM THE BINARY SEARCH TREE FROM THE BOOK
void intervalTree::PrintTree(rbnode* tree, std::ofstream& outFile) 
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);   // Print left subtree.
    outFile << "Interval:" << tree->element << '\t' << tree-> high << endl;
    cout << "Interval:" << tree->element << '\t' << tree-> high << endl;
    PrintTree(tree->right, outFile);  // Print right subtree.
  }
}
