//Program written by Zachary Carlson
// HEADER FILES
#include <iostream>
#include "adt3.h"
void hanoi(int, stack&, stack&, stack&);
int main(){
	//initialize variables
	int diskN = -1;
	int index;
	//loop until diskN is a valid number
	while(diskN < 0){
	//prompt for number of disks
	cout << "Enter a positive number of disks" <<endl;
	cin >> diskN;
	}
	//initialize stacks
	cout << "Starting Towers of Hanoi" << endl;
	stack A(diskN);
	A.name = 'A';
	stack B(diskN);
	B.name = 'B';
	stack C(diskN);
	C.name = 'C';
	//load A
	for(index = 1; index <= diskN; index++){
	A.push(index);
	}
	//Recursive function
	hanoi(diskN, A, B, C);
return 0;
}
void hanoi(int i, stack& source, stack& mid, stack& destination){
	if(i == 1){
	int temp;
	//move 1 from A to C
	temp = source.pop();
	destination.push(temp);
	cout << "Moved " << i << " from " << source.name << " to " << destination.name << endl;
	}
	else{
	int temp;
	hanoi(i - 1, source, destination, mid);
	temp = source.pop();
	destination.push(temp);
	cout << "Moved " << i << " from " << source.name << " to " << destination.name << endl;
	hanoi(i - 1, mid, source, destination);
	}

}
