//NAME: Zachary Carlson
//INCLUDE FILES
  #include <iostream>
  #include "tableau.h"
  using namespace std;
//IMPLEMENTATION
tableau::tableau(){
    	col1Top = NULL;
	col2Top = NULL;
	col3Top = NULL;
	col4Top = NULL;
	col5Top = NULL;
	col6Top = NULL;
	col7Top = NULL;
 	cursor = NULL;
}
tableau::~tableau(){
  //delete column 1
  if(checkEmptyCol(1)){
  cursor = NULL;
  }
  else if(col1Top -> next == NULL){
  delete col1Top;
  }
  else{
  cursor = col1Top->next;
  	while(cursor != NULL){
  	delete col1Top;
  	col1Top = cursor;
  	cursor = col1Top->next;
	}
  }
  //delete column 2
  if(checkEmptyCol(2)){
  cursor = NULL;
  }
  else if(col2Top -> next == NULL){
  delete col2Top;
  }
  else{
  cursor = col2Top->next;
  	while(cursor != NULL){
  	delete col2Top;
  	col2Top = cursor;
  	cursor = col2Top->next;
	}
  }
  //delete column 3
  if(checkEmptyCol(3)){
  cursor = NULL;
  }
  else if(col3Top -> next == NULL){
  delete col3Top;
  }
  else{
  cursor = col3Top->next;
  	while(cursor != NULL){
  	delete col3Top;
  	col3Top = cursor;
  	cursor = col3Top->next;
  	}
  }
  //delete column 4
  if(checkEmptyCol(4)){
  cursor = NULL;
  }
  else if(col4Top -> next == NULL){
  delete col4Top;
  }
  else{
  cursor = col4Top->next;
  	while(cursor != NULL){
  	delete col4Top;
  	col4Top = cursor;
  	cursor = col4Top->next;
  	}
  }
  //delete column 5
  if(checkEmptyCol(5)){
  cursor = NULL;
  }
  else if(col5Top -> next == NULL){
  delete col5Top;
  }
  else{
  cursor = col5Top->next;
  	while(cursor != NULL){
  	delete col5Top;
  	col5Top = cursor;
  	cursor = col5Top->next;
 	}
  }
  //delete column 6
  if(checkEmptyCol(6)){
  cursor = NULL;
  }
  else if(col6Top -> next == NULL){
  delete col6Top;
  }
  else{
  cursor = col6Top->next;
  	while(cursor != NULL){
  	delete col6Top;
  	col6Top = cursor;
  	cursor = col6Top->next;
  	}
  }
  //delete column 7
  if(checkEmptyCol(7)){
  cursor = NULL;
  }
  else if(col7Top -> next == NULL){
  delete col7Top;
  }
  else{
  cursor = col7Top->next;
  	while(cursor != NULL){
  	delete col7Top;
  	col7Top = cursor;
  	cursor = col7Top->next;
  	}
  }

}

bool tableau::checkEmptyCol(int id){
  switch(id){
  case 1:
   	if(col1Top == NULL){
	return true;
	}
  break;
  case 2:
   	if(col2Top == NULL){
	return true;
	}
  break;
  case 3:
   	if(col3Top == NULL){
	return true;
	}
  break;
  case 4:
   	if(col4Top == NULL){
	return true;
	}
  break;
  case 5:
   	if(col5Top == NULL){
	return true;
	}
  break;
  case 6:
   	if(col6Top == NULL){
	return true;
	}
  break;
  case 7:
   	if(col7Top == NULL){
	return true;
	}
  break;
  default:
  cout << "Incorrect Column Choice" << endl;
  return true;
  }
  return false;

}

//moveCursorToBottom
bool tableau::moveCursorToBottom(int colID){
  bool test = false;
  if(checkEmptyCol(colID)){
  return false;
  }
  else{
	test = goToTop(colID);
   	if(test == false){
 	return false;
	}
 	//move cursor down
  	while(cursor -> next != NULL){
  	cursor = cursor -> next;
  	}
	return true;
  }
}
//returnCursor
card tableau::returnCursor(){
   return (*cursor);
}
//go to next
bool tableau::goToNext(){
  if(cursor->next == NULL){
  return false;
  }
  else{
  cursor = cursor -> next;
  return true;
  }
}
bool tableau::goToTop(int col){
   if(checkEmptyCol(col)){
	return false;
   }
    	switch(col){
  	case 1:
   	cursor = col1Top;
  	return true;
  	break;
  	case 2:
   	cursor = col2Top;
  	return true;
  	break;
  	case 3:
   	cursor = col3Top;
  	return true;
  	break;
  	case 4:
   	cursor = col4Top;
  	return true;
  	break;
  	case 5:
   	cursor = col5Top;
  	return true;
  	break;
  	case 6:
   	cursor = col6Top;
  	return true;
 	break;
  	case 7:
   	cursor = col7Top;
  	return true;
  	break;
  	default:
  	return false;
  	}
}

bool tableau::insertAfter(card newCard, int col){
  card* temp;

  if(checkEmptyCol(col)){
    	switch(col){
  	case 1:
   	col1Top = new card;
  	cursor = col1Top;
	(*col1Top) = newCard;
  	break;
  	case 2:
   	col2Top = new card;
  	cursor = col2Top;
	(*col2Top) = newCard;
  	break;
  	case 3:
   	col3Top = new card;
  	cursor = col3Top;
	(*col3Top) = newCard;
  	break;
  	case 4:
   	col4Top = new card;
  	cursor = col4Top;
	(*col4Top) = newCard;
  	break;
  	case 5:
   	col5Top = new card;
  	cursor = col5Top;
	(*col5Top) = newCard;
  	break;
  	case 6:
   	col6Top = new card;
  	cursor = col6Top;
	(*col6Top) = newCard;
 	break;
  	case 7:
   	col7Top = new card;
  	cursor = col7Top;
	(*col7Top) = newCard;
  	break;
 	}
  	return true;
  }
  else{
  	temp = cursor;
  	cursor = new card;
 	(*cursor) = newCard;
  	(*cursor).next = (*temp).next;
 	(*temp).next = cursor;
 	return true;
  }
}

//OVERLOADED OPERATOR <<
ostream& operator<< (ostream& out, const tableau& rhs){
   card* temp;
   cout << "Tableau: " << endl;
   //output each column of the tableau
   cout << "COLUMN 1 of the Tableau: " << endl; 
      //initial value
  	if(rhs.col1Top != NULL){
     	temp = rhs.col1Top;
   	cout << "  " <<(*temp) << endl;
	temp = rhs.col1Top->next;
		//loop through the column
		while(temp != NULL){
		cout << "  " <<(*temp) << endl;
		temp = temp->next;
		}
        }
   cout << endl <<"COLUMN 2 of the Tableau: " << endl;
      //initial value
  	if(rhs.col2Top != NULL){
     	temp = rhs.col2Top;
   	cout << "  " <<(*temp) << endl;
	temp = rhs.col2Top->next;
		//loop through the column
		while(temp != NULL){
		cout << "  " <<(*temp) << endl;
		temp = temp->next;
		}
        } 
   cout << endl << "COLUMN 3 of the Tableau: " << endl;
      //initial value
  	if(rhs.col3Top != NULL){
     	temp = rhs.col3Top;
   	cout << "  " <<(*temp) << endl;
	temp = rhs.col3Top->next;
		//loop through the column
		while(temp != NULL){
		cout << "  " <<(*temp) << endl;
		temp = temp->next;
		}
        } 
   cout << endl << "COLUMN 4 of the Tableau: " << endl;
      //initial value
  	if(rhs.col4Top != NULL){
     	temp = rhs.col4Top;
   	cout << "  " <<(*temp) << endl;
	temp = rhs.col4Top->next;
		//loop through the column
		while(temp != NULL){
		cout << "  " <<(*temp) << endl;
		temp = temp->next;
		}
        } 
   cout << endl << "COLUMN 5 of the Tableau: " << endl; 
      //initial value
  	if(rhs.col5Top != NULL){
     	temp = rhs.col5Top;
   	cout << "  " <<(*temp) << endl;
	temp = rhs.col5Top->next;
		//loop through the column
		while(temp != NULL){
		cout << "  " <<(*temp) << endl;
		temp = temp->next;
		}
        }
   cout << endl << "COLUMN 6 of the Tableau: " << endl; 
      //initial value
  	if(rhs.col6Top != NULL){
     	temp = rhs.col6Top;
   	cout << "  " <<(*temp) << endl;
	temp = rhs.col6Top->next;
		//loop through the column
		while(temp != NULL){
		cout << "  " <<(*temp) << endl;
		temp = temp->next;
		}
        }
   cout << endl << "COLUMN 7 of the Tableau: " << endl;
      //initial value
  	if(rhs.col7Top != NULL){
     	temp = rhs.col7Top;
   	cout << "  " <<(*temp) << endl;
	temp = rhs.col7Top->next;
		//loop through the column
		while(temp != NULL){
		cout << "  " <<(*temp) << endl;
		temp = temp->next;
		}
        }
   //end
   return out;
}

//REMOVE AND RETURN
card tableau::removeAndReturn(int col, int row){
  //initialize temp card
  card tempCard;
  card* previous;
  int i = 1;
  bool check;
  //check if column is not empty
  if(!checkEmptyCol(col)){
  //set cursor to top of column
  check = goToTop(col);
  previous = cursor;
  	//move cursor down
	if(check == true){
        	while(i < row){
 	 	previous = cursor;
		cursor = cursor->next;
		i++;
		}
		if( row == 1){
			switch(col){
			case '1':
			col1Top = NULL;
			break;
			case '2':
			col2Top = NULL;
			break;
			case '3':
			col3Top = NULL;
			break;
			case '4':
			col4Top = NULL;
			break;
			case '5':
			col5Top = NULL;
			break;
			case '6':
			col6Top = NULL;
			break;
			case '7':
			col7Top = NULL;
			break;
			}
		}	
  		//check if cursor is not null
		if(cursor != NULL){
	   	//set temp card to cursor
		tempCard = (*cursor);
		//remove card and set previous next to null
		previous->next = NULL;
	        cout << "test" << endl;
		delete cursor;
		cursor = previous;
		}
 	   
  	}
  }
  //end
  cout << tempCard << endl;
  return tempCard; 
}
