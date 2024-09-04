#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct Item {
	int code;
	char name[11]; // With one extra space for the NULL operator.
	struct Item* next;
}Item;



int main()
{
	int i;
	Item *Head=NULL, *temp;
	char temp_name[11];

	for(i=1;i<=N;i++){		
		temp = (Item*)malloc(sizeof(Item));
		if (temp == NULL) { // In case of failure, release allocated memory.
			while (Head != NULL) {
				temp = Head->next;
				free(Head); // Free previously allocated memory.
				Head = temp; // Head moves onwards to the next part of the linked list.
			}
			exit(1);
		}
		printf("Enter a new code and name: ");
		if (scanf("%d %10s", &temp->code, temp_name) != 2) {
			while (Head != NULL) {
				temp = Head->next;
				free(Head);
				Head = temp;
			}
			exit(1);
		}
		strcpy(temp->name, temp_name);
		temp->next = Head; // Put head after the new element in the linked list.
		Head = temp; // now temp is the actual head of the chain.
	}

	
	printf("\n\nThe List is:  ");
	while(Head != NULL)
        {

		printf("%d,%s --> ",Head->code,Head->name);
		Head = Head->next; // Continue down the chained list.
	}

	while(Head != NULL){
		temp = Head->next; // let temp pick the next part of the linked list
		free(Head);
		Head = temp; // Now head is the next part and the part beforehand was set free.
	}
        return 0;
}




