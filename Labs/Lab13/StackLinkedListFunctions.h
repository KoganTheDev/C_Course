#pragma once

#ifndef StackLinkedListFunctions_h
#define StackLinkedListFunctions_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
	int num;
	struct Item* next;
}Item;

typedef struct Stack {
	Item* head;
	int size; // a current number of items.
}stack, *PStack;


int isFull(stack Stack, int max_size); // Check if a Stack (composed of a linked list) is full.
int Pop(PStack s, int* del_value);
void Push(PStack s, int new_element);
void FreeLinkedList(PStack s);
void PrintStack(stack s);

#endif StackLinkedListFunctions_h