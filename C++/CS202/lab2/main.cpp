#include <iostream>
using namespace std;

template<class type1, int input>
class templateMath{
public:
  templateMath();
  templateMath(type1);
  ~templateMath();
  type1 add (type1, type1);
  void setMember(type1, int);
  type1 getMember(int);
  void printArray();
  int getIndex(type1);
  type1 power(int, int);
private:
  type1* myArray;
};
//add
template<class type1, int input>
type1 templateMath<type1, input>::add(type1 a, type1 b){
   return a+b;
   }
//constructor
template<class type1, int input>
templateMath<type1, input>::templateMath(){
   myArray = new type1[input];
   }
//parameterized constructor
template<class type1, int input>
templateMath<type1, input>::templateMath(type1 a){
   int i;
   myArray = new type1[input];
   	for(i = 0; i < input; i++){
        myArray[i] = a;
        }
   }
//deconstructor
template<class type1, int input>
templateMath<type1, input>::~templateMath(){
   	if(myArray != NULL){
  	delete []myArray;
   	}
   }
//setmember
template<class type1, int input>
void templateMath<type1, input>::setMember(type1 a, int b){
   myArray[b] = a;
   }
//getmember
template<class type1, int input>
type1 templateMath<type1, input>::getMember(int index){
   	if(index >=0 && index < input){
        return myArray[index];
   	}
   }
//getIndex
template<class type1, int input>
int templateMath<type1, input>::getIndex(type1 given){
 	int index;
   	for(index = 0; index < input; index++){
         	if(given == myArray[index]){
 		return index;
		}
   	}
	return -1;
   }
//power
template<class type1, int input>
type1 templateMath<type1, input>::power(int index, int power){
        int i;
	type1 returnValue;
 	if(power == 0)
	return 1;

      	if(index >= 0 && index < input){
	returnValue = myArray[index];
		for(i = 1; i < power; i++){
        	returnValue = returnValue * myArray[index];
		}
   	}
	return returnValue;

   }
//print array
template<class type1, int input>
void templateMath<type1, input>::printArray(){
   int i;
	cout<< "Array:" << endl;
   	for(i= 0; i < input; i++){
        cout<< myArray[i]<<endl;
   	} 
   }
int main(){
   templateMath <int, 5> object1(1);
   int getme, getindex;
   //set member index 2, to 5
   object1.setMember(5,2);
   //print the array
   object1.printArray();
   //get member function
   getme = object1.getMember(2);
   cout << "Member recieved from the getMember function: "<<getme<<endl;
   //find index of the 5
   getindex = object1.getIndex(5);
   cout << "Index of 5 in the array is: "<< getindex<<endl;
   //find index of the 7
   getindex = object1.getIndex(7);
   cout << "Index of 7 in the array is: "<< getindex<<endl;
   //power
   getme = object1.power(2,2);
   cout << "The Squared value of 5 is: "<< getme <<endl;
   return 0;
   }

