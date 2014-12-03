//INCLUDES~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>
//DEFINITIONS~~~~~~~~~~~~~~~~~~~~~~~
#define MAX_CHILDREN 10
#define BUFFER_SIZE 500
#define PARENT_SIZE 1

//STRUCTS~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct node{
	char name;
	char spouseName;
	int count;
	struct node *children[MAX_CHILDREN];
}node;

//PROTOTYPES~~~~~~~~~~~~~~~~~~~~~~~~
//NODE SPECIFIC
/*Takes an input (string of data) and builds the root process, recursively building it's children*/
int buildProcesses(char *input, struct node* procs);

/*Recursive function used in buildProcess that creates the children*/
int buildChildren(char *input, struct node* children[MAX_CHILDREN], int cIndex);

//OTHER FUNCTIONS
/*Simple string length function*/
int stringLen(char *s);

/*Outputs to terminal current defined limitations*/
void outputConst();

//converts a char to an int 0-9
int charToInt(char c);

//finds the SECOND occurence of the char name in the input string
int findStartIndex(char *input, char c);

//reads a file and returns the data
void readFile(char* filename, char data[BUFFER_SIZE]);

int getChildCount(char* input, int i);

//IMPLEMENTATION~~~~~~~~~~~~~~~~~~~
//START NODE SPECIFIC
int buildProcesses(char *input, struct node* procs)
{
	//variables
	int i = 0;/*input index*/
	int childrenIndex = 0;/*child index*/
	int placeholder = 0;
	int streamLen = stringLen(input);

	//check if stream is a waste of time
	if(streamLen <= 1){
		return 1;
	}

	//build the first process: grab Adam+Eve and Child Count
	if(input[0] != ' '){
		//<a><b><n><c><d><e><f>
		(*procs).name = input[0];
		(*procs).spouseName = input[2];
		(*procs).count = getChildCount(input, 3);
		/*printf("Value: %d\n", (*procs).count);*/
	}
	if((*procs).count > 99){
	placeholder = 7;
	}
	else if((*procs).count > 9){
	placeholder = 6;
	}
	else{
	placeholder = 5;
	}

	//create the children and their children recursively
	if((*procs).count != 0){
		//parse the input
		for(i = placeholder; i < streamLen; i++){
			//check if line ends
			if(input[i] == '\n' || input[i] == '\0'){
				return 0;
			}
			//grab child name
			if(input[i] != ' '){
				//initialize the child
				(*procs).children[childrenIndex] = malloc(sizeof(node));
				(*procs).children[childrenIndex] -> name = input[i];
				(*procs).children[childrenIndex] -> spouseName = '\0';
				(*procs).children[childrenIndex] -> count = 0;
				//build the grandchildren
				buildChildren(input, (*procs).children, childrenIndex);
				//increment child index
				childrenIndex++;
			}
		}
	}
	return 0;
}

int buildChildren(char *input, struct node* children[MAX_CHILDREN], int cIndex)
{
	int childrenIndex = 0;/*index for children*/
	int i = 0;/*index for input*/
	int placeholder;
	int streamLen = stringLen(input);
	int index = findStartIndex(input, children[cIndex] -> name);

	//no children or spouse
	if(index == BUFFER_SIZE+10){
	return 1;
	}

	//get spousename and children count
	children[cIndex] -> spouseName = input[index+2];
	children[cIndex] -> count = getChildCount(input,index+3);
	/*printf("Value: %d\n", children[cIndex] -> count);*/
	if(children[cIndex] -> count > 99){
	placeholder = 7;
	}
	else if(children[cIndex] -> count > 9){
	placeholder = 6;
	}
	else{
	placeholder = 5;
	}

	//recursively grab the children and their children
	if(children[cIndex] ->count != 0){
		//parse the line in the input
		for(i = index+placeholder; i < streamLen; i++){
			//check if line ends
			if(input[i] == '\n' || input[i] == '\0'){
				return 0;
			}
			//grab child name
			if(input[i] != ' '){
				//initialize the child
				children[cIndex] -> children[childrenIndex] = malloc(sizeof(node));
				children[cIndex] -> children[childrenIndex] -> name = input[i];
				children[cIndex] -> children[childrenIndex] -> spouseName = '\0';
				children[cIndex] -> children[childrenIndex] -> count = 0;
				//build the grandchildren
				buildChildren(input, children[cIndex] -> children, childrenIndex);
				//increment child index
				childrenIndex++;
			}
		}
	}
	return 0;
}

//START OTHER FUNCTIONS
int stringLen(char *s)
{
	int i;
	for(i = 0; i < BUFFER_SIZE; i++){
		if(s[i] == '\0'){
			return i;
		}
	}
	return i;
}

void outputConst()
{
	printf("--------------------------------------------------.\n");
	printf("Maximum constants have been defined in the program.\n\n");
	printf("\tMaximum Children per Process: %d\n", MAX_CHILDREN);
	printf("\tMaximum Buffer Size: %d\n", BUFFER_SIZE);
	printf("--------------------------------------------------.\n");
}
int charToInt(char c)
{
	return c - '0';
}

int findStartIndex(char *input, char c)
{
	int streamLen = stringLen(input);
	int i;
	int first_occurence = BUFFER_SIZE+10;
	for(i = 0; i < streamLen; i++){
		if(input[i] == c){
			if(first_occurence == BUFFER_SIZE+10){
				first_occurence = i;
			}
			else{
				return i;
			}
		}
	}
	return BUFFER_SIZE+10;
}
void readFile(char* filename, char data[BUFFER_SIZE])
{
   FILE *f;
   // Open file for reading
   f = fopen(filename, "r");
   if(f != NULL){
      // Read data
      fread(data, BUFFER_SIZE, 1, f);
      fclose(f);
   }
}
int getChildCount(char* input, int i)
{
	int a=10,b=10,c=10;
	int index = 1;
	if(input[i] == ' '){
		if(input[i+1] == '0'){
		return 0;
		}
		while(input[i+index] != ' ' && input[i+index] != '\0'){
			switch (index){
			case 1:
			a = charToInt(input[i+index]);
			break;
			case 2:
			b = charToInt(input[i+index]);
			break;
			case 3:
			c = charToInt(input[i+index]);
			break;
			default:
			break;
			}
			index++;
		} 
		//convert a b and c into a 3 digit number
		if(a == 10 && b == 10 && c == 10){
		return 0;
		}
		else if(b == 10 && c == 10){
		return a;
		}
		else if(c == 10){
		return ((a * 10) + b);
		
		}
		else{
		return ((a*100)+(b*10)+c);
		}
	}
	else{
	return 0;
	}
}
