//INCLUDES~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "header.h"
#include <sys/types.h>
#include <unistd.h>

//PROTOTYPES~~~~~~~~~~~~~~~~~~~~~~~~
/*Recursively runs the parent process and child processes, outputing to terminal*/
int runProcess(pid_t *pid, struct node* procs, int tabs);

//MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc,  char *argv[])
{
	//variables
	char input[BUFFER_SIZE];
	int processesTree = 1;/*bool 1-false 0-true*/
	struct node parent;
	pid_t pid;
	struct node* procs = malloc(sizeof(node));;
	(*procs).count = 0;
	(*procs).spouseName = '\0';

	//initial statement
	outputConst();
	if(argc <= 1){
	//input
	printf("Enter the file name of the family tree:\n");
	fgets(input, BUFFER_SIZE, stdin);
	readFile(input, input);
	}
	else{
	readFile(argv[1], input);
	}
	//printf("%s\n", input);
	//printf("The string length function returned: %d\n", stringLen(input));

	//create process tree
    processesTree = buildProcesses(input, procs);
	if(processesTree == 0){

		//execute process tree recursively and outputs to terminal
		return runProcess(&pid, procs, 0);
	}

	//failure
	return 1;
}

//IMPLEMENTATION~~~~~~~~~~~~~~~~~~~~
/*Recursively runs the parent process and child processes, outputing to terminal*/
int runProcess(pid_t *pid, struct node* procs, int tabs)
{
	//variables
	int i = 0;
	//output tabs
	for(i = 0; i < tabs; i++){
	printf("\t");
	}
	//output process and spouse
	if((*procs).spouseName != '\0'){
		printf("%c - %c\n", (*procs).name, (*procs).spouseName);
	}
	else{
		printf("%c\n", (*procs).name);
	}
	//fork foreach child process
	for(i = 0; i < (*procs).count; i++){
		(*pid) = fork();
		//error occured
    	if((*pid) < 0){
			//fprintf(stderr, "Fork Failed\n");
			return 1;
		}
		//child process
		else if((*pid) == 0){
			if((*procs).children[i]->name != '\0'){
				return runProcess(pid, (*procs).children[i], tabs+1);
			}
			else{
			return 0;
			}
		}
		//parent process
		else{
			waitpid((*pid), NULL, 0);
		}
	}
	return 0;
}
