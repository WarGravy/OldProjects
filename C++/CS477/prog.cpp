////////////////////////////////////////////Analysis of Algorithms/////////////////
//INCLUDES///////////////////////////////Developer: Zachary Carlson////////////////
///////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//GLOBAL VARIABLES/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
const int WEEKS = 4;
///////////////////////////////////////////////////////////////////////////////////
//PROTOTYPES///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int max(int l, int h);
int constructTable(int jobs[2][WEEKS],int choices[WEEKS], int index);
int optRecursion(int jobs[2][WEEKS], int choices[WEEKS], int index);
///////////////////////////////////////////////////////////////////////////////////
//MAIN DRIVER//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main(){
  //initialize variables
  int jobs[2][WEEKS] = { {10,1,10,10},{5,50,5,1} };//row1 = low, row2 = high
  int choices[WEEKS] = {0,0,0,0}; // 0, 1=low, 2=high	
  int input = 1;
  int total = 0;
  
  cout <<"Please enter an index"<<endl;
  cin >> input;

  while(input >= 0){
  	//calculate total
  	//total = optRecursion(jobs, choices, input);
	total = constructTable(jobs, choices, input);
  	//output total
  	cout << total << endl;
	cout << "Choices"<<endl;
	for(int i = 0; i <= input; i++){
		switch(choices[i]){
		case 1:
		cout << "Week "<<i+1<<": " << "Low Stress Job " << jobs[0][i]<<endl;
		break;
		case 2:
		cout << "Week "<<i+1<<": " << "High Stress Job " << jobs[1][i]<<endl;
		break;
		case 0:
		cout << "Week "<<i+1<<": " << "No Job " <<endl;
		break;
		
		}
	}
  	//prompt
  	cout <<"Please enter an index"<<endl;
  	cin >> input;
	
  }
  //end
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//IMPLEMENTATION - read prototype definitions at top of page///////////////////////
///////////////////////////////////////////////////////////////////////////////////
int optRecursion(int jobs[2][WEEKS], int choices[WEEKS], int index)
{
   if(index < 0)
	return 0;

   if(index == 0)
	return max(jobs[0][index], jobs[1][index]);
   //T(i) = max(T(i-1) + Li , T(i-2) + Hi)
   return max(optRecursion(jobs,choices,index-1)+jobs[0][index], optRecursion(jobs,choices,index-2)+jobs[1][index]);
   
}
int max(int l, int h){
	if(l >= h)
		return l;
	else
		return h;
}

int constructTable(int jobs[2][WEEKS], int choices[WEEKS],int index){
	int data[WEEKS];
	data[0] = optRecursion(jobs,choices,0);
		if(data[0] == jobs[0][0]){
			choices[0] = 1; //1 = low job
		}
	data[1] = optRecursion(jobs,choices,1);
		if(data[1] == jobs[1][1]){
			choices[0] = 0;//0 = no job
			choices[1] = 2; //2 = high
		}
	for(int i = 2; i <= index;i++){
	
		if((data[i-1] + jobs[0][i]) > (data[i-2] + jobs[1][i])){
			data[i] = data[i-1] + jobs[0][i];
			choices[i] = 1;
		}
		else{
			data[i] = data[i-2] + jobs[1][i];
			choices[i] = 2;
			choices[i-1] = 0; 
		}
	}
	return data[index];
	
}
