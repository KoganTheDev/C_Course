#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char code[11];
	char* name;
	char Dep[4];
	int marks[3];
	float avg;
	struct node* next;
}std;

void Error_Msg(char* str);
std* FromFileToList(FILE* in);
std* Delete_Stud(std* toDel, std* head);
std* DeleteList(std* head);
void PrintList(std* head);
std* FindMax(std* head);

int main()
{
	int i;
	FILE* f;
	std* Head = NULL, * temp;

	if ((f = fopen("List1.txt", "rt")) == NULL)
		Error_Msg("input error");
	Head = FromFileToList(f);
	if (Head == NULL)
		Error_Msg("The input file is empty");

	fclose(f);
	printf("\nThe list is:\n");
	PrintList(Head);

	temp = FindMax(Head);
	printf("\n\nthe student with max average:\n");
	printf("%s %s %s ", temp->code, temp->name, temp->Dep);
	for (i = 0;i < 3;i++)
		printf(" %d ", temp->marks[i]);

	printf("\n\nThe list after change:\n");
	Head = Delete_Stud(FindMax(Head), Head);
	PrintList(Head);
	Head = DeleteList(Head);        /*Head = NULL */
	return 0;
}

void Error_Msg(char* str)
{
	/*
	* Summary:
	* Prints a string to the stdout.
	* 
	* Prints:
	* A string entered in the main function.
	*/
	printf("\n%s", str);
	exit(1);
}



std* Delete_Stud(std* toDel, std* head)
{
	/*
	* Summary:
	* This function looks for a specific node and then deletes it from the linked list.
	* 
	* Arguments:
	* toDel - (std type pointer): The node that`ll be deleted.
	* head - (std type pointer): The linked list.
	* 
	* Variables:
	* temp - (std type pointer): Used during the deletion of 'toDel'.
	* 
	* Returns:
	* head - (std type pointer): The linked list without the node that was deleted.
	*/
	std* temp;


	if (head == NULL)
		return NULL;

	
	if (toDel == head) // Relates to the part in which the part to delete is the start of the linked list.
	{
		temp = head->next;
		free(head->name);
		free(head);
		head = temp;
	}
	else
	{
		temp = head;
		while (temp->next != toDel) {
			temp = temp->next;
		}
		
		temp->next = toDel->next;
		free(toDel->name);
		free(toDel);
	}

	return head;
}

std* FromFileToList(FILE* in) {
	/*
	* Summary:
	* This function takes input from a file and creates a linked list based on the information it got from the file.
	* 
	* Arguments:
	* in - (FILE type pointer): Used for recieving input from a file.
	* 
	* Variables:
	* temp - (std type pointer): A pointer to a structure that contains the information for each student. Also used to create the linked list.
	* Head - (std type pointer): A pointer to a structure that contains the information for each student. The head of the linked list.
	*temp_name - (char type): Used to dynamically allocate the name of the studnt.
	* 
	* Returns:
	* Head - (std type pointer): The start of the linked list.
	*/
		std* Head = NULL;
		std* temp;
		char temp_name[256];

		while (1) {
			if ((temp = (std*)malloc(sizeof(std))) == NULL) {
				printf("An error occurred when allocating memory for the linked list.\n");
				while (Head != NULL) { // Free allocated memory.
					temp = Head;
					Head = Head->next;
					free(temp->name);
					free(temp);
				}
				exit(1);
			}

			if (fscanf(in, "%s %s %s %d %d %d", temp->code, temp_name, temp->Dep, &temp->marks[0], &temp->marks[1], &temp->marks[2]) != 6)
				break;

			temp->avg = (temp->marks[0] + temp->marks[1] + temp->marks[2]) / 3.0;

			temp->name = malloc(strlen(temp_name) + 1);
			if (temp->name == NULL) {
				printf("An error occurred when allocating memory for the name.\n");
				exit(1);
			}
			strcpy(temp->name, temp_name);

			temp->next = Head;
			Head = temp;
		}

		return Head;
	}


void PrintList(std* head) {
	/*
	* Summary:
	* This function prints the information of each student in the linked list.
	* 
	* Arguments:
	* head - (std type pointer): The head of the linked list.
	* 
	* Prints:
	* The information that each node in the linked list contains.
	*/
	while (head != NULL) {
		printf("%s %s %s %d %d %d\n", head->code, head->name, head->Dep, head->marks[0], head->marks[1], head->marks[2]);
		head = head->next; // Continue onwards.
	}
}

std* FindMax(std* head) {
	/*
	* Summary:
	* This function looks for the student who has the best average among the students in the linked list.
	* 
	* Arguments:
	* head - (std type pointer): A pointer to the start of the linked list.
	* 
	* Variables:
	* max - (Float type): Contains the currently best grade.
	* max_node - (std type pointer): Contains the node of the student who`s the best average among the other students.
	* 
	* Returns:
	* max_node - (std type pointer): The student who`s average is the highest.
	*/
	float max = 0;
	std* max_node = NULL;

	while (head != NULL) {
		if (head->avg > max) {
			max = head->avg; // Now the maximum the value is the value of the student who got the highest average currently.
			max_node = head; // Now max_node contains the address of the part in the linked list that contains the student with the highest average. 
		}
		head = head->next; // Continue down the line.
	}
	return max_node;
}

std* DeleteList(std* head) {
	/*
	* Summary:
	* This function deletes the whole linked list.
	* 
	* Arguments:
	* head - (std type poitner): Contains the address of the start of the linked list.
	* 
	* Variables:
	* temp - (std type pointer): Used for the deletion of the linked list.
	* 
	* Returns:
	* head - (std type pointer): Contains NULL after the deletion of the linked list.
	*/
	std* temp = NULL;

	while (head != NULL) {
		temp = head->next;
		free(head->name);
		free(head);
		head = temp;
	}
	return head;
}
