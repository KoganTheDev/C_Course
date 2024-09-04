#include "StackLinkedListFunctions.h" // Imports the library with hte functions as well as <stdin.h> and <stdlib.h>

#define NUM 5

int main() {
	int num, stack_status;
	stack s;
	char option = '0';
	int* Pnum = NULL; // Will be used to contain the address of the number when using Pop. 

	s.head = NULL; // Initializing the stack.
	s.size = 0;

	printf("Initializing the stack...\n"
		"_________________________\n"
		"The stack can contain up to %d integers.\n\n"
		"\tOptions:\n"
		"1. push (Enter an integer into the stack) <Can`t happen when the stack is full>\n"
		"2. Pop (Delete an element from the stack) <Can`t happen when the stack is empty>\n"
		"3. Exit\n"
		"_________________________\n", NUM);

	while (option != '3') {


		scanf(" %c", &option);

		if (option == '3') { // Print what the stack witholds and end the run time.
			PrintStack(s);
			break;
		}

		stack_status = isFull(s, NUM);

		switch (option) {
		case '1':
			if (stack_status == -1 || stack_status == 0) { // -1 for empty list, 0 when the list has more room for elements.
				printf("\nEnter an element to insert into the stack: ");
				scanf("%d", &num);
				Push(&s, num); // Insert the element into the linked list.
				s.size++; // Update how many nodes are in the stack.
			}
			break;
		case '2':
			if (stack_status == 1 || stack_status == 0) { // 0 when there`re elements in the stack, 1 when the stack`s full.
				printf("Enter an element to pop from the stack: ");
				scanf("%d", &num);
				Pnum = &num;
				Pop(&s, Pnum);
				s.size--;  // Update how many nodes are in the stack.
			}
			break;
		case '3':
			break;
		default:
			printf("Please enter a valid value.\n\n");
		}

		PrintStack(s);

		printf("\n\n\tOptions:\n"
			"1. push (Enter an integer into the stack) <Can`t happen when the stack is full>\n"
			"2. Pop (Delete an element from the stack) <Can`t happen when the stack is empty>\n"
			"3. Exit\n"
			"_________________________\n");
	}

	FreeLinkedList(&s);
	printf("\n\nThank you for your cooperation\n\n\t***Good Bye***\n");
	return 0;
}