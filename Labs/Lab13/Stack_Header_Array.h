#pragma once

#ifndef Stack_Header_Array_h
#define Stack_Header_Array_h

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int top; // Index of the last member in the array of a stack.
	int* Array; // pointer to array of members of the stack.
	int size; // Size of the array of the stack.
	int count; // current number of members.
}Stack, *PStack;

void InitStack(PStack s, int size);    //initialization of a new stack with capacity of size elements
void Push(PStack s, int   new_elem);  //add a new member to array of the stack 
int Pop(PStack s, int* del_value); //delete member from the array of the stack and  return the deleted value  using  int * del_value


#endif 