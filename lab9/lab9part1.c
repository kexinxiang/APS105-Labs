#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* DO NOT EDIT THE LINES BELOW */
#define STRING_MAX 1024

typedef struct node {
	char *name;
	int lines;
	int runtime;
	int memory_usage;

	struct node *next;
} Node;

typedef struct linked_list {
	Node *head;
} LinkedList;

void readInputString(char *, int);
void readInputNumber(int *);
void readInputChar(char *);

LinkedList * newList();
char getCommand();

void handleInsert(LinkedList *);
void handleDelete(LinkedList *);
void handleSearch(LinkedList *);
void handlePrint(LinkedList *);
void handleQuit(LinkedList *);

int main() {
	LinkedList *list = newList();
	char command = '\0';

	printf("Experimental database entry\n");

	while (command != 'Q') {
		command = getCommand();

		switch (command) {
			case 'I':
				handleInsert(list);
				break;
			case 'D':
				handleDelete(list);
				break;
			case 'S':
				handleSearch(list);
				break;
			case 'P':
				handlePrint(list);
				break;
			case 'Q':
				handleQuit(list);
				break;
		}
	}

	free(list);
	return 0;
}
/* DO NOT EDIT THE LINES ABOVE */

void handleInsert(LinkedList *list) {
	// place your code to handle the insert command here
	printf("\nNumber of characters in file name: ");
	int charnum;
	readInputNumber(&charnum);
	
	printf("File name: ");
	char name[charnum+1];
	readInputString(name, charnum+1);
	
	printf("Number of lines in CSV file: ");
	int line; 
	readInputNumber(&line);

	printf("Experiment runtime (ms): ");
	int runtime; 
	readInputNumber(&runtime);

	printf("Experiment memory usage (B): ");
	int memory;
	readInputNumber(&memory);

	Node *newNode = (Node *)malloc(sizeof(Node));

	if(newNode != NULL){
		newNode->name = (char*) malloc((charnum + 1) * sizeof(char));
		strcpy(newNode -> name, name);
		newNode -> lines = line;
		newNode -> runtime = runtime;
		newNode -> memory_usage = memory;
	}

	//empty list
	if(list->head == NULL){
		newNode -> next = NULL;
		list -> head = newNode;
		return;
	}

	//check if exist
	Node *current = list -> head;
	while(current != NULL){
		if(strcmp(current -> name, name) == 0){
			printf("\nAn entry with that file name already exists.\n");
			return;
		}
		current = current -> next;
	}

	//first element
	if(strcmp(newNode -> name, list->head->name)< 0){
		newNode -> next = list -> head;
		list -> head = newNode;
		return;
	}

	//must find place to insert
	current = list -> head;
	while(current -> next != NULL && strcmp(newNode -> name, current -> next -> name) > 0){
		current = current -> next;
	}//exit if name precedes the current's next node's name, remain pointer to the current node 
	newNode -> next = current -> next;
	current -> next = newNode;
	return;
}

void handleDelete(LinkedList *list) {
	// place your code to handle the delete command here
	printf("\nEnter file name to delete: ");
	char name[STRING_MAX];
	readInputString(name, STRING_MAX);

	bool found = false;

	//empty list 
	if(list -> head == NULL){
		printf("An entry for file <%s> does not exist.\n", name);
		return;
	}

	//delete first
	Node *current = list -> head -> next;
	if(strcmp(list->head->name, name)==0){
		printf("Deleting entry for CSV file <%s>\n", list->head->name);
		free(list -> head -> name);
		free(list -> head);
		list -> head = current;
		return;
	}

	//general case
	current = list -> head;
	while(current -> next != NULL && strcmp(current -> next -> name, name) != 0){
		current = current -> next;
	}//exit if current -> next is equal to name or end of the list
	if(current -> next != NULL){
		found = true;
		Node *temp = current -> next;
		current -> next = temp -> next;
		printf("Deleting entry for CSV file <%s>\n", temp -> name);
		free(temp -> name);
		free(temp);
	}

	if(!found){
		printf("An entry for file <%s> does not exist.\n", name);
	}

}

void handleSearch(LinkedList *list) {
	// place your code to handle the search command here
	printf("\nEnter file name to find: ");
	char name[STRING_MAX];
	readInputString(name, STRING_MAX);
	Node *current = list -> head;
	if(current == NULL){
		printf("An entry for file <%s> does not exist.\n", name);
	}
	while(current != NULL && strcmp(current -> name, name) != 0){
		current = current -> next;
	}
	if(current == NULL){
		printf("An entry for file <%s> does not exist.\n", name);
	}else{
		printf("File <%s>\n", current -> name);
		printf("Lines: %d\n", current -> lines);
		printf("Runtime (ms): %d\n", current -> runtime);
		printf("Memory usage (B): %d\n", current -> memory_usage);
		printf("Throughput: %.2lf\n", (1000 * (double)current->lines / current->runtime));
	}
}

void handlePrint(LinkedList *list) {
	// place your code to handle the print command here
	Node *current = list -> head;
	printf("\nData entries:\n");
	if(current == NULL){
		printf("There are no data entries.\n");
	}else{
		while(current != NULL){
			printf("\n");
			printf("File <%s>\n", current -> name);
			printf("Lines: %d\n", current -> lines);
			printf("Runtime (ms): %d\n", current -> runtime);
			printf("Memory usage (B): %d\n", current -> memory_usage);
			printf("Throughput: %.2lf\n", (1000 * (double)current->lines / current->runtime));
			current = current -> next;
		}
	}
}

void handleQuit(LinkedList *list) {
	// place your code to handle the quit command here
	Node *current = list->head;
	Node *temp;
	while(current != NULL){
		temp = current;
		current = current -> next;
		printf("Deleting entry for CSV file <%s>\n", temp -> name);
		free(temp -> name);
		free(temp);
	}
}

/* DO NOT EDIT THE LINES BELOW */
void readInputString(char *str, int length) {
	int i = 0;
	char c;

	while (i < length && (c = getchar()) != '\n') {
		str[i++] = c;
	}

	str[i] = '\0';
}

void readInputNumber(int *number) {
	char buf[STRING_MAX];
	readInputString(buf, STRING_MAX);
	*number = (int)strtol(buf, (char **)NULL, 10);
}

void readInputChar(char *character) {
	char buf[2];
	readInputString(buf, 3);
	*character = buf[0];
}

LinkedList * newList() {
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->head = NULL;
	return list;
}

char getCommand() {
	char command;

	printf("\nSupported commands are:\n");
	printf("  I - Insert\n");
	printf("  D - Delete\n");
	printf("  S - Search\n");
	printf("  P - Print\n");
	printf("  Q - Quit\n");

	printf("\nPlease select a command: ");
	readInputChar(&command);

	while (command != 'I' && command != 'D' && command != 'S' && command != 'P' && command != 'Q') {
		printf("Invalid command <%c>, please select a command: ", command);
		readInputChar(&command);
	}

	return command;
}
/* DO NOT EDIT THE LINES ABOVE */
