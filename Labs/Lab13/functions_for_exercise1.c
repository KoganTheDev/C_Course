#include "StackLinkedListFunctions.h"



int isFull(stack Stack, int max_size) {
	/*
	* Summary:
	* This function checks if the stack is full or not.
	*
	* Arguments:
	* Stack - (Stack type structure): A stack composed of a linked list.
	* max_size - (INT type): Contains the maximum size the linked list can be.
	*
	* Variables:
	* cnt - (INT type): Used to check if the the linked list can contain more elements.
	*
	* Returns:
	* 0 - When the stack isn`t full.
	* 1 - If the stack is full.
	* -1 - If the stack is empty.
	*/
	int cnt = 0;

	if (Stack.head == NULL) {
		printf("\n\nThe stack is empty.\n\n");
		return -1;
	}

	while (Stack.head != NULL) {
		cnt++;
		if (cnt == max_size) { // End of the linked list.
			printf("\n\nThe stack is full.\n\n");
			return 1;
		}

		Stack.head = Stack.head->next; // Continue to the next node.
	}
	if (cnt < max_size) { // End of the linked list, but there`s more room for elements in the linked list.
		printf("\n\nThe stack has more room for elements.\n\n");
		return 0;
	}
	return 0; 
}

void Push(PStack s, int new_element) {
	/*
	* Summary:
	* This function inserts a new node into the linked list.
	* The new node becomes the head of the stack.
	*
	* Arguments:
	* s - (Stack type pointer): Will allow us to create changes in the stack.
	* new_element - (INT type): The new element that`ll become the new head of the stack.
	*
	* Variables:
	* node - (Item type pointer): Contains the new node that will be connected as the head of the linked list.
	*/
	Item* node = (Item*)malloc(sizeof(Item));
	if (node == NULL) {
		printf("\n\nAn error has occurred when the function \"Push\" tried to allocte memory for the node.");
		FreeLinkedList(s);
		exit(1);
	}

	node->num = new_element; // Inserts the new element to the node.

	if (s->head == NULL) { // Special case when the stack is empty.
		s->head = node;
		s->head->next = NULL;
	}
	else {
		node->next = s->head; // Put the new node first. 
		s->head = node;
	}
}

int Pop(PStack s, int* del_value) {
	/*
	* Summary:
	* This function pops an element from the stack.
	*
	* Arguments:
	* s - (PStack type): A pointer to the stack that contains a linked list.
	* del_value - (INT type pointer): The value that`s in the node the funciton will delete.
	*
	* Arguments:
	* temp - (Item type pointer):Used to traverse the linked list, connecting nodes and deleting nodes.
	* tail - (Item type pointer): Used to delete the tail of the linked list.
	*
	* Returns:
	* 0 - If the node isn`t found.
	* 1 - If the node was deleted.
	*/
	Item* temp = NULL;
	Item* temp_next = NULL;
	Item* temp_prev = NULL;

	if (s->head == NULL) {
		printf("\nThere's no element to pop since the stack is empty.");
		return 0;
	}

	temp = s->head;
	temp_next = s->head->next;

	if (temp != NULL && temp->num == *del_value) { // Special case: First node.
		free(temp);
		s->head = temp_next;
		return 1;
	}

	while (temp != NULL) {
		if (temp->num == *del_value) {
			if (temp_prev != NULL)
				temp_prev->next = temp_next;
			else
				s->head = temp_next;

			free(temp);
			return 1;
		}

		temp_prev = temp;
		temp = temp_next;
		if (temp_next != NULL)
			temp_next = temp_next->next;
	}

	printf("\nThe function \"Pop\" couldn't find the node that contains the value %d", *del_value);
	return 0;
}


void FreeLinkedList(PStack s) {
	/*
	* Summary:
	* This function is used to release all of the dynamically allocated memory.
	*
	* Arguments:
	* s - (Stack type pointer): A pointer to the stack will allow us to change the actual stack.
	*
	* Variabels:
	* temp - (Item type pointer): Used to contain the released node on each iteration.
	*/
	Item* temp;

	while (s->head != NULL) {
		temp = s->head;
		s->head = s->head->next; // Continue the chain onwards.
		free(temp);
	}
}

void PrintStack(stack s) {
	/*
	* Summary:
	* This function prints the contents of the stack.
	*
	* Arguments:
	* s - (Stack type structure): The stack.
	*
	* Prints:
	* The elements of the stack chained to one another.
	*/
	Item* temp = s.head;

	printf("\nThe stack content: ");
	while (temp != NULL) {
		printf("-%d-->", temp->num);
		temp = temp->next; // Move towards the next node in the linked list.
	}
}