#include <iostream>
#include "proj6.h"

using namespace std;

//prototypes
bool compareCstyle( char* key, char* source );

//class person
person::person( char* newName, char newGender, int newLevel )
   {
	int index;
	for(index =0; newName[index] != '\0'; index++){
    	name[index] = newName[index];
	}
	name[index] = '\0';
    gender = newGender;
    level = newLevel;
    numberOfChildren = 0;
    father = NULL;
    mother = NULL;
    spouse = NULL;
    next = NULL;
    bfsnext = NULL;
    marked = false;
   }


person::~person()
   {
	if(this != NULL && name != NULL){
    father = NULL;
    mother = NULL;
    spouse = NULL;
    next = NULL;
    gender = '\0';
    level = 0;
	}
   }


char person::getGender()
   {
    return gender;
   }


int person::getLevel()
   {
    return level;
   }


// overloaded operators
void person::operator=( person& rhs )
   {
    for( int i = 0; i < 10; i++ )
       {
        name[i] = rhs.name[i];
       }
    gender = rhs.gender;
    level = rhs.level;
    numberOfChildren = rhs.numberOfChildren;
    father = rhs.father;
    mother = rhs.mother;
    spouse = rhs.spouse;
    marked = rhs.marked;
    bfsnext = rhs.bfsnext;
    for( int i = 0; i < 20; i++ )
       {
        child[i] = rhs.child[i];
       }
    next = rhs.next;
   }

bool person::operator==( person& rhs )
   {
   int i;
   bool flag = true;
    for(i = 0; (i < 10) && (name[i] != '\0') && (rhs.name[i] == '\0'); i++ )
       {
        if(name[i] != rhs.name[i]){
        flag = false;
        }
       }
    if((name[i] == '\0' && rhs.name != '\0') || (name[i] != '\0' && rhs.name == '\0')){
    flag = false;
   }
  return flag;
}


ostream & operator<<( ostream& out, const person& rhs )
   {
    for( int i = 0; i < 10; i++ )
       {
        out << rhs.name[i] << endl;
       }

    return out;
   }


//class graph
graph::graph()
   {
    root = NULL; 
    cursor = NULL;
    //zack: I need this
    lowLevel = 0;
   }


graph::~graph()
   {
    //dynamically delete all nodes traversing through the next pointer
    person* temp = NULL;
    if( root != NULL )
       {
        temp = root;
        temp = root->next;
 	    delete root;
       }

    while(temp != NULL)
       {
	    root = temp;
	    temp = root -> next;
	    delete root;
       }
    lowLevel = 0;
   }


bool graph::addVert( char* newName, char newGender)
   {
    if( lowLevel == 0 )
       {
    	lowLevel = 1;
    	//create root
    	root = new person( newName, newGender, lowLevel );
       }
    else
       {
	    person* temp = new person( newName, newGender, lowLevel );
	    //search through next pointers until NULL
		//set last person's next pointer to temp
		//set temp to NULL
        cursor = root;
        while( cursor->next != NULL )
           {
            cursor = cursor->next;
           }
        cursor->next = temp;
        temp = NULL;
       }    
    return 0;
   }

void graph::clearMarks(){
  if(root!= NULL){
  cursor = root;
 	while(cursor!= NULL){
        cursor->marked = false;
        cursor = cursor-> next;
 	}
	
  }
}
bool graph::isMarked(person temp){
  if(temp.marked == true){
   return true;
  }
  return false;
}
void graph::bfs(char* name1, char* name2, int path[], int& pathIndex, char& gen )
   {
// Assumption: VertexType is a type for which the Ò==Ò and "<<" operators are defined.
  //find name 1, find name 2
   cursor = root;
    while( !compareCstyle( name1, cursor->name ) && cursor->next != NULL )
       {
        cursor = cursor->next;
       }
    person* cursor2 = root;
    while( !compareCstyle( name2, cursor2->name ) && cursor2->next != NULL )
       {
        cursor2 = cursor2->next;
       }
    gen = cursor2->gender;
    person startVertex = *cursor;
    person endVertex = *cursor2;
    queue q;
    queue vertexQ;
    path[0]=startVertex.level;
    bool found = false;
    person vertex((char*)"blank", 'm', 0);
    person item((char*)"blank", 'm', 0);
   
    clearMarks();
    q.Enqueue( startVertex );

    do
      {
       q.Dequeue( vertex );
       
       if( vertex == endVertex )
          {
	   pathIndex++;
           path[1]=vertex.level;
           found = true;
          }
       else
          {
           if( !isMarked( vertex ) )
              {
               vertex.marked = true;
	       pathIndex++;
               GetToVertices( vertex, vertexQ );

               while( !vertexQ.IsEmpty() )
                 {
                  vertexQ.Dequeue( item );
                  if( !isMarked( item ) )
                     {  
                      q.Enqueue( item );
                     }
                 }
              }
          }                
      }
    while ( !q.IsEmpty() && !found );
    if( !found )
       {
        cout << "Path not found." << endl;
       }

   } 
void graph::GetToVertices(person vertex, queue& adjVertices){
  int toIndex;
  person temp((char*)"blank", 'm', 0);
  person* temp2;
  int childIndex = vertex.numberOfChildren;
  if(vertex.mother != NULL){
  temp2 = vertex.mother;
  temp = (*temp2);
  adjVertices.Enqueue(temp);
  }
  if(vertex.father != NULL){
  temp2 = vertex.father;
  temp = (*temp2);
  adjVertices.Enqueue(temp);
  }
  if(vertex.spouse != NULL){
  temp2 = vertex.spouse;
  temp = (*temp2);
  adjVertices.Enqueue(temp);
  }
  for(toIndex = 0; toIndex < childIndex; toIndex++){
  temp2 = vertex.child[toIndex];
  temp = (*temp2);
  adjVertices.Enqueue(temp);
  }
}

bool graph::setChild( char* _name, char* _child )
   {
	int level2;
    //search for the person node using name
    cursor = root;
    while( !compareCstyle( _name, cursor->name ) && cursor->next != NULL )
       {
        cursor = cursor->next;
       }
    person* cursor2 = root;
    while( !compareCstyle( _child, cursor2->name ) && cursor2->next != NULL )
       {
        cursor2 = cursor2->next;
       }
	//if found 
    if( compareCstyle( _child, cursor2->name ) && compareCstyle( _name, cursor->name ))
       {
		//increment the parent's number of children
        cursor->numberOfChildren++;
        	level2 = cursor -> level;
		//set child -> level = parent's -> level+1
		cursor2 -> level = level2 + 1;
			//if parent is male
			if(cursor->gender == 'm' || cursor->gender =='M'){
				//set child's father
				cursor2 -> father = cursor;
				//set child's mother through the father's spouse pointer
				cursor2 -> mother = cursor -> spouse;
				//set parents child
				cursor->child[cursor->numberOfChildren-1] = cursor2;
				cursor->spouse->child[cursor->numberOfChildren-1] = cursor2;
				cursor2 = NULL;
				return true;
			}
			//if parent is female
				if(cursor->gender == 'f' || cursor->gender =='F'){
				//set child's mother
				cursor2 -> mother = cursor;
				//set child's father through the mother's spouse pointer
				cursor2 -> father = cursor -> spouse;
				//set parents child
				cursor->child[cursor->numberOfChildren-1] = cursor2;
				cursor->spouse->child[cursor->numberOfChildren-1] = cursor2;
				cursor2 = NULL;
				return true;
			}
	//else the person is not found 
       }
    	return false;
   }


bool graph::setSpouse( char* _name, char* _spouse)
   {
    //search for the person node using name
    cursor = root;
    while( !compareCstyle( _name, cursor->name ) && cursor->next != NULL )
       {
        cursor = cursor->next;
       }

     //search for the person node using name
    person* cursor2 = root;
    while( !compareCstyle( _spouse, cursor2->name ) && cursor2->next != NULL )
       {
        cursor2 = cursor2->next;
       }
	//if the person's spouse node is NULL
    if( cursor->spouse == NULL && cursor2->spouse == NULL)
       {
		//set spouse for name node = to spouse node
        cursor->spouse = cursor2;
		cursor2->spouse = cursor;
		//set spouse's spouse pointer to name node
        cursor = root;
        cursor2 = NULL;
            return true;
       
       }
	//else if person's spouse node is NOT NULL aka already married 
	return false;
   }


bool compareCstyle( char* key, char* source )
   {
    int index = 0;
	while( ( key[index] != '\0' ) && ( source[index] != '\0' ) && ( key[index] == source[index] ) )
       	  { 
	    index++;
	   }
	if( index > 0 && ( key[index] == source[index] ) )
       {
	    return true;
	   }
	return false;
   }
////////////////QUEUE//////////////////////



///////////////////////////////////////////




///////////////////////////////////////////


queue::queue()
{
  front = NULL;
  rear = NULL;
}


void queue::MakeEmpty()
   {

    /*while (front != NULL)
       {
        tempPtr = front;
        front = front->bfsnext;
        delete tempPtr;
       }*/
    front = NULL;
    rear = NULL;
   }


queue::~queue()
   {
    MakeEmpty();
   }


bool queue::IsFull() const
   {
    person* location;
    try
       {
        location = new person( (char*)"jim", 'm', 0 );
        delete location;
        return false;
       }
    catch(bad_alloc exception)
       {
        return true;
       }
   }


bool queue::IsEmpty() const
   {
    return (front == NULL);
   }


void queue::Enqueue( person newItem ) 
   {
   int index = 0;
    person* newNode = new person(newItem.name, newItem.gender, newItem.level);
    newNode -> mother = newItem.mother;
    newNode -> father = newItem.father;
    newNode -> spouse = newItem.spouse;
    newNode -> next = newItem.next;
    newNode -> numberOfChildren = newItem.numberOfChildren;
    //loop through children
    for(index =0; index < newNode->numberOfChildren; index++){
	newNode->child[index] = newItem.child[index];
    }
    newNode->bfsnext = NULL;
    if (rear == NULL){
      front = newNode;
      rear = front;
	}
    else
      rear->next = newNode;
    rear->bfsnext = newNode;
   }


void queue::Dequeue( person& newNode )
   {
    newNode = (*front);
    front = front->bfsnext;
    newNode.bfsnext = NULL;
    if (front == NULL)
      rear = NULL;
   }
