//Program written and designed by Zachary Carlson and Jay Thom
// HEADER FILES
#include <iostream>
#include <fstream>
#include <stdint.h>
#include "adt1.h"
#include "adt2.h"
#include "adt3.h"
//#include "adt4.h" linking it via adt4
#include "adt5.h"
#include "adt6.h"
#include "adt7.h"
#include "rbtree.h"
//included for random number generating
#include <cstdlib>
//include for time 
#include <time.h>
using namespace std;

/*GLOBAL VARIABLES<these are all that need to be changed to determine how the program runs*/
/*used for generating numbers for input, search, and delete list(1,000 / 10,000 / 100,000 / 1,000,000)*/
const int MAX_INTEGERS = 1000000;
//2^32 this is used for generating numbers between 1 and bounds
const int64_t BOUNDS = 4294967296 + 1;
/*how many ADTs NOTE: if you add an adt, make sure to add their own if statement for insertion, search, and deletion phases with the correct output to file and screen, and the index for the adt is n-1 so ADT8 index is 7*/
const int NUM_ADTS = 8;
//filename for summary of all tests(comparisons, swaps, times, test cases)
const char filename[] = "output.txt";
/*filenames for the insertion, deletion, and search lists. If you change the name make sure to change the indexFilenameStart to match that of '1' and make sure to keep the number pattern of 01*/ 
char filename2[] = "insertList01.txt";
char filename3[] = "searchList01.txt";
char filename4[] = "deleteList01.txt";
int indexFilenameStart = 11;
/*TEST_CASES is how many times the program tests all the ADTs do not excede 99 for filename reasons*/
const int TEST_CASES = 10;

//MAIN PROGRAM
int main(){
  //initialize variables
     int tempNum;
     bool found;
     srand( time(NULL));
     long int randomNumb;
     int64_t* input;
     int64_t* search;
     int64_t* deleteList;
     char fileChar = '1';
     char fileChar2 = '1';
     char fileChar3 = '1';
     char tempChar = '1';
     //time/////////////////////////
     clock_t start, end;
     //index variables
     int gen, i, j, k, x, y, index, caseIndex;
     int swaps=0;
     int comparisons=0;
     //initialize ADTs
     linkedListSorted* adt1;
     linkedListUNSorted* adt2;
     iTreeType* adt3;
     TreeType* adt4;
     arrayListSorted* adt5;
     arrayListUNSorted* adt6;
     rbtree* adt7;
     RBTree* adt8;
     RBTreeNode *node;
     //fstream related
     ofstream fout;
     fout.clear();
     fout.open(filename);
     ofstream fout2;
     fout2.clear();
  //LOOP START, TEST_CASE DETERMINES HOW MANY TIMES THE PROGRAM TESTS ALL ADTs
  for(caseIndex = 0; caseIndex < TEST_CASES; caseIndex++){
     fout << "TEST CASE #" << caseIndex << endl;
     fout << "---------------------------------"<<endl<<endl;
     //initialize lists;
     input = new int64_t[MAX_INTEGERS];
     search = new int64_t[MAX_INTEGERS];
     deleteList = new int64_t[MAX_INTEGERS];
    /*generate  2^32 random numbers between 1  and 1,000,000 loaded into an array(INPUT LIST)*/
     //output insert list
     fout2.open(filename2);
     
     for(gen=0;gen < MAX_INTEGERS; gen++){
     cout << "Calculating Input Index Number :" << gen <<endl;
     randomNumb = rand() % BOUNDS;
     input[gen] = randomNumb;
     //output to insert list
     fout2 << input[gen] << endl;
     }
     //close file and append name
     fout2.close();
     if(fileChar == '9'){
     	fileChar = '0';
     	tempChar = filename2[indexFilenameStart-1];
     	tempChar++;
     	filename2[indexFilenameStart-1] = tempChar;
     	filename2[indexFilenameStart] = fileChar;
     }
     else{
	fileChar++;
	filename2[indexFilenameStart] = fileChar;
	}
    /*generate  2^32 random numbers between 1  and 1,000,000 loaded into an array(SEARCH LIST)*/
     fout2.open(filename3);
     gen=0;
     while( gen < MAX_INTEGERS){
     cout << "Calculating Search Index Number :" << gen <<endl;
     randomNumb = rand() % BOUNDS;
 	//for(y=0;y < gen && search[gen] != randomNumb; y++){
        //}
	//if(y == gen){
     	search[gen] = randomNumb;
	//output to insert list
        fout2 << search[gen] << endl;
        gen++;
	//}
     }
     //close file and append name
     fout2.close();
     if(fileChar2 == '9'){
     	fileChar2 = '0';
     	tempChar = filename3[indexFilenameStart-1];
     	tempChar++;
     	filename3[indexFilenameStart-1] = tempChar;
     	filename3[indexFilenameStart] = fileChar2;
     }
     else{
	fileChar2++;
	filename3[indexFilenameStart] = fileChar2;
	}
    /*generate array(DELETE LIST)*/
    i=j=k=0;
    fout2.open(filename4);
    while(i < MAX_INTEGERS){
    cout << "Calculating Delete Index Number :" << i <<endl;
       /*find index where value of input[i] is equal to search list or run through entire list*/
       for(j=0; input[i]!=search[j] && j < MAX_INTEGERS;j++){
       }
       //check if the index is true
       if(input[i] == search[j]){
         deleteList[k]=input[i];
	 fout2 << deleteList[k] << endl;
         k++;
         }
     i++;
    }
     //close file and append name
     fout2.close();
     if(fileChar3 == '9'){
     	fileChar3 = '0';
     	tempChar = filename4[indexFilenameStart-1];
     	tempChar++;
     	filename4[indexFilenameStart-1] = tempChar;
     	filename4[indexFilenameStart] = fileChar3;
     }
     else{
	fileChar3++;
	filename4[indexFilenameStart] = fileChar3;
	}
  cout << k << "AND" << i <<endl;//See how many were in both lists

  //Loop through all ADTs
  for(index = 0; index < NUM_ADTS; index++){
    //initialize swaps and comparisons
    swaps=0;
    comparisons=0;
    //INSERTION PHASE
     start = clock();
      //insert all randomly generated numbers into adt
         //adt1
         if(index == 0){
		adt1 = new linkedListSorted;
		fout << "ADT 1: Sorted Linked List" << endl;
		cout << "ADT 1: Sorted Linked List" << endl;
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt1).insert(input[x], swaps, comparisons);
      		}
	 }
         //adt2
         else if(index == 1){
		adt2 = new linkedListUNSorted;
		fout << "---------------------------" << endl;
		fout << "ADT 2: Unsorted Linked List" << endl;
		cout << "---------------------------" << endl;
		cout << "ADT 2: Unsorted Linked List" << endl;
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt2).insert(input[x], swaps, comparisons);
      		}
	 }
         //adt3
         else if(index == 2){
		adt3 = new iTreeType;
		fout << "---------------------------" << endl;
		fout << "ADT 3: Binary Search Tree (iterative)" << endl;
		cout << "---------------------------" << endl;
		cout << "ADT 3: Binary Search Tree (iterative)" << endl;
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt3).PutItem(input[x], swaps, comparisons);
      		}
	 }
         //adt4
         else if(index == 3){
		adt4 = new TreeType;
		fout << "---------------------------" << endl;
		fout << "ADT 4: Binary Search Tree (recursive)" << endl;
		cout << "---------------------------" << endl;
		cout << "ADT 4: Binary Search Tree (recursive)" << endl;
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt4).PutItem(input[x], swaps, comparisons);
      		}
	 }
         else if(index == 4){
		adt5 = new arrayListSorted(MAX_INTEGERS);
		fout << "---------------------------" << endl;
		fout << "ADT 5: Array Based List (sorted)" << endl;
		cout << "---------------------------" << endl;
		cout << "ADT 5: Array Based List (sorted)" << endl;
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt5).insert(input[x], swaps, comparisons);
      		}
	 }
       
           else if(index == 5){
		adt6 = new arrayListUNSorted(MAX_INTEGERS);
		fout << "---------------------------" << endl;
		fout << "ADT 6: Array Based List (unsorted)" << endl;
		cout << "---------------------------" << endl;
		cout << "ADT 6: Array Based List (unsorted)" << endl;
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt6).insert(input[x], swaps, comparisons);
      		}
	 }
 
	  else if(index == 6){
		adt7 = new rbtree;
		fout << "---------------------------" << endl;
		fout << "ADT 7: Red Black Tree (Extra Credit)" << endl;
		cout << "---------------------------" << endl;
		cout << "ADT 7: Red Black Tree (Extra Credit)" << endl;
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt7).rbInsert(input[x], swaps, comparisons);
      		}
 	  }
	  else if(index == 7){
                x=0;
		adt8 = new RBTree( input[x], NULL );
		fout << "---------------------------" << endl;
		fout << "ADT 8: Red Black Tree" << endl;
		cout << "---------------------------" << endl;
		cout << "ADT 8: Red Black Tree" << endl;
		//insert
      		for(x =1; x<MAX_INTEGERS;x++){
      		adt8->insertNode(input[x], NULL, swaps, comparisons );
      		}
 	  }
      //output end time
      end = clock();
      fout << "Clocks =" << (end - start) << endl;
      fout << "Seconds = " << ((end - start)/(double)(CLOCKS_PER_SEC)) << endl;
      //output number of swaps
      cout << "SWAPS for Insertion Phase: "<< swaps << endl;
      fout << "SWAPS for Insertion Phase: "<< swaps << endl;
      //output number of comparisons
      cout << "COMPARISONS for Insertion Phase: "<<comparisons << endl<<endl;
      fout << "COMPARISONS for Insertion Phase: "<<comparisons << endl<<endl;

    //initialize swaps and comparisons
    swaps=0;
    comparisons=0;

    //SEARCH PHASE
    start = clock();
        //adt1
         if(index == 0){
		//search
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt1).find(search[x], swaps, comparisons);
      		}
	 }
         //adt2
         else if(index == 1){
		//search
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt2).find(search[x], swaps, comparisons);
      		}
	 }
         //adt3
         else if(index == 2){
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		tempNum = (*adt3).GetItem(search[x], found, swaps, comparisons);
      		}
	 }
         //adt4
         else if(index == 3){
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		tempNum = (*adt4).GetItem(search[x], found, swaps, comparisons);
      		}
	 }
         else if(index == 4){
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt5).search(search[x], swaps, comparisons);
      		}
	 }
         
          else if(index == 5){
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt6).search(search[x],swaps, comparisons);
      		}
	 }

           else if(index == 6){
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		(*adt7).find(search[x], swaps, comparisons);
      		}
	 }
           else if(index == 7){
		//insert
      		for(x =0; x<MAX_INTEGERS;x++){
      		adt8->queryTree( search[x], comparisons );
  		//delete node;
      		}
	 }
      //output end time
      end = clock();
      fout << "Clocks =" << (end - start) << endl;
      fout << "Seconds = " << ((end - start)/(double)(CLOCKS_PER_SEC)) << endl;

      //output number of swaps
      cout << "SWAPS for Search Phase: "<< swaps << endl;
      fout << "SWAPS for Search Phase: "<< swaps << endl;
      //output number of comparisons
      cout << "COMPARISONS for Search Phase: "<<comparisons << endl<<endl;
      fout << "COMPARISONS for Search Phase: "<<comparisons << endl<<endl;

    //initialize swaps and comparisons
    swaps=0;
    comparisons=0;

    //DELETION PHASE
    start = clock();
        //adt1
         if(index == 0){
 		for(y =0; y<k-1;y++){
		//delete
      		(*adt1).remove(deleteList[x], swaps, comparisons);
		}
         delete adt1;
	 }
        //adt2
         else if(index == 1){
 		for(y =0; y < k-1;y++){
		//search
      		for(x =0; x<k;x++){
      		(*adt2).find(deleteList[x], swaps, comparisons);
      		}
		//delete
      		(*adt2).remove(swaps, comparisons);
		}
	delete adt2;
	 }
         //adt3
         else if(index == 2){
		//delete
      		for(x =0; x<k;x++){
      		(*adt3).iDeleteItem(deleteList[x], swaps, comparisons);
      		}
	 delete adt3;
	 }
         //adt4
         else if(index == 3){
		//delete
      		for(x =0; x<k;x++){
      		(*adt4).DeleteItem(deleteList[x], swaps, comparisons);
      		}
	  delete adt4;
	 }
         else if(index == 4){
		//delete
      		for(x =0; x<k;x++){
      		(*adt5).deleteInt(deleteList[x], swaps, comparisons);
      		}
	 delete adt5;
	 }
         
          else if(index == 5){
		//delete
      		for(x =0; x<k;x++){
      		(*adt6).deleteInt(deleteList[x], swaps, comparisons);
      		}
	 delete adt6;        
	 }

           else if(index == 6){
		//delete
      		for(x =0; x<k;x++){
      		(*adt7).rbDelete(deleteList[x], swaps, comparisons);
      		}  
	 delete adt7;      
	 }
         else if(index == 7){
		//delete
      		for(x =0; x<k;x++){
      		tempNum = (*adt8).deleteNode(deleteList[x], swaps, comparisons);
      		}  
	 delete adt8;      
	 }
      //output end time
      end = clock();
      fout << "Clocks =" << (end - start) << endl;
      fout << "Seconds = " << ((end - start)/(double)(CLOCKS_PER_SEC)) << endl;

      //output number of swaps
      cout << "SWAPS for Deletion Phase: "<< swaps << endl;
      fout << "SWAPS for Deletion Phase: "<< swaps << endl;
      //output number of comparisons
      cout << "COMPARISONS for Deletion Phase: "<<comparisons << endl<<endl;
      fout << "COMPARISONS for Deletion Phase: "<<comparisons << endl<<endl;

  }//end of for loop
     //delete lists
     delete[] input;
     delete[] search;
     delete[] deleteList;
//LOOP END, TEST_CASE DETERMINES HOW MANY TIMES THE PROGRAM TESTS ALL ADTs
  }
  //end 
  return 0;
}

