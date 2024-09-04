#include "Stack_Header_Array.h"

void InitStack(PStack s, int size) {
	/*
	* Summary:
	* This funciton initializes a stack using an array in the size given as an argument.
	* 
	* Arguments:
	* s - (Stack type pointer): Contains the address of the stack that will be created.
	* size - (INT type): Represents how big the stack is.
	*/
	s->Array = (int*)malloc(sizeof(int) * 5); // Creates the array in the structure.
	if (s->Array == NULL) {
		printf("The function \"InitStack\" failed to allocate memory for the stack.");
		exit(1);
	}

	s->count = 0;
	s->size = size;
	s->top = 0;
}

void Push(PStack s, int   new_elem) { 
	/*
	* Summary:
	* This function inserts a new element to the stack.
	* 
	* Arguments:
	* s - (Stack type pointer): Contains the address of the stack.
	* new_elem - (INT type): The integer that`ll join the stack.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	*/
	int i;

	if (s->count == s->size) {
		printf("\nThe stack full\n");
	}
	else {
		for (i = s->top; i > 0 ;i--) { // Moving each element from right to left.
			s->Array[i] = s->Array[i-1]; // Move the numbers to the right once.
		}
		s->Array[0] = new_elem; // Insert the new element.
		s->count++; // Update how many elements are currently in the stack.
		s->top++; // Update the index of the last element.
	}
}

int Pop(PStack s, int* del_value) { //delete member from the array of the stack and  return the deleted value  using  int * del_value
	/*
	* Summary:
	* This function pops the an element from the stack.
	* 
	* Arguments:
	* s - (Stack type pointer): Contains the address of the stack.
	* del_value - (INT type pointer): Contains the address of the value that`ll be poped.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	* deleted_index - (INT type): Contains the index of the element that`ll be deleted from the stack.
	* 
	* Returns:
	* del_value - (INT type): The element that was deleted from the stack.
	*/
	int i, deleted_index = -1;

	if (s->Array[0] == *del_value) { // Special case: del_value is at the start of the stack.
		for (i = 1; i < s->count -1 ; i++) {
			s->Array[i - 1] = s->Array[i]; // Move each element once to the left.
		}
	}
	else {
		for (i = 1;i < s->count;i++) { // Grab the index of the element we want to delete. Starts from one to save the iteration on the first place.
			if (s->Array[i] == *del_value) {
				deleted_index = i; // Save the index for later use.
				break;
			}
		}

		for (i = deleted_index; i < s->top; i++) {
			s->Array[i] = s->Array[i + 1];
		}
	}

	s->count--; // Update how many elements are in the stack and what`s the index of the last element in it.
	s->top--;

	return *del_value;
}