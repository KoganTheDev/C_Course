#pragma once
#ifndef hw4_header_h
#define hw4_header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define name_max_len 51 // 50 characters for the name + one extra for '\0'.
#define tables 50

typedef struct Product {

	char* name;
	int price;
	int quantity;
	struct Product *next;

}Product;

typedef struct Manager_struct_product {
	Product* Head;
	Product* Tail;

}Products_manager;

void InitTables(Products_manager Tables[tables]);
int IfProductAlreadyExists(Products_manager* List, char s[]);
void FreeLinkedList(Products_manager* List);
void CreateProducts(Products_manager* List, FILE* manot);
void ReleaseNodeWithQuantityZero(Products_manager List);

void AddItems(char ProductName[], int Quantity, Products_manager List);
void OrderItem(Products_manager Tables[], Products_manager List, int TableNumber, char ProductName[], int Quantity);
void RemoveItem(Products_manager Tables[], int TableNumber, char ProductName[], int Quantity);
void RemoveTable(Products_manager Tables[], int TableNumber);


#endif 
