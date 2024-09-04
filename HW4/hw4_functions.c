#include "hw4_header.h"

void InitTables(Products_manager Tables[tables]) {
	/*
	* Summary:
	* This function creates a linked list for each table in the store so it can store information about the orders
	* of each table.
	* 
	* Arguments:
	* Tables - (Product_manager type array): An array in which each element contains a manager`s linked list.
	* 
	* Variables:
	* i  - (INT type): Used for iteration.
	*/
	int i;

	for (i = 0;i < tables;i++) {
		Tables[i].Head = NULL; // Initialize each linked list for a table.
		Tables[i].Tail = NULL;
	}
}

void CreateProducts(Products_manager List, FILE* manot) {
	/*
	* Summary:
	* This functions initializes each product in the stock and creates a linked list of the products that`ll be used later.
	* 
	* Arguments:
	* List - (Products manager type): A manager structure that contains both the head and the tail of the linked list, represents the kitchen.
	* manot - (FILE type pointer): Used to gather input, get new products into the linked list.
	* 
	* Variables:
	* temp_name - (char type array): Used to store the name of the product temporarily.
	* node - (Product type pointer): Used to store the information about the product.
	* 
	* Prints:
	* "The kitchen was created" to the cmd once the function ends its runtime.
	*/
	char temp_name[name_max_len];
	Product* node = (Product*)malloc(sizeof(Product));

	if (node == NULL){ // First node in the linked list therefore there`s no need to realease the whole list.
		printf("Memory allocation failed when the function \"CreateProducts\" tried to allocate memory for node for the first time.\n");
		exit(1);
	}
	node->next = NULL;

	while (fscanf(manot, "%s %d %d", temp_name, &node->quantity, &node->price) != EOF) {
		if (node->price <= 0) { // Input check for price which must be a positive integer.
			printf("The price of %s is invalid since it`s not positive value.\nAdvancing to the next product.\n", temp_name);
			continue;
		}
		else if (node->quantity <= 0) { // Input check for quantity which must be a positive value.
			printf("The quantity of %s is invalid since it`s not positive value.\nAdvancing to the next product.\n", temp_name);
			continue;
		}

		node->name = (char*)malloc(sizeof(char) * (strlen(temp_name) + 1)); // Create memory allocation for the name and then insert it into the node.
		if (node->name == NULL) {
			printf("Memory allocation failed when the function \"CreateProducts\" tried to allocate memory for node.name\n");
			FreeLinkedList(&List); // Release all of the allocated memory.
			free(node);
			exit(1);
		}

		strcpy(node->name, temp_name);



		if (IfProductAlreadyExists(&List, temp_name) == 1) {
			printf("The product \"%s\" already exists in the linked list, advancing to the next product\n", temp_name);
			continue; // Skip to the next line in "manot.txt".
		}

		if (List.Tail == NULL) { // When the linked list is empty.
			List.Tail = node;
			List.Head = node;
		}
		else {
			List.Tail->next = node; // Insert the node from the bottom.
			List.Tail = node; // Update the Tail since there`s a new Tail in the linked list.
			List.Tail->next = NULL;
		}

		node = (Product*)malloc(sizeof(Product));
		if (node == NULL) { // Allocation failed, delete the linked list and exit.
			printf("Memory allocation failed when the function \"CreateProducts\" tried to allocate memory for 'node'.\n");
			FreeLinkedList(&List);
			exit(1);
		}
	}
	printf("The kitchen was created\n");
}

int IfProductAlreadyExists(Products_manager* List, char s[]) {
	/*
	* Summary:
	* This function searches in the linked list if a product with a specific name is already in the linked list.
	*
	* Arguments:
	* List - (Products manager type pointer): Contains the head and tail of the linked list.
	* s - (Char type array): Contains the name of the product which the function`ll check if that product already exists.
	* 
	* Variables:
	* temp - (Product type pointer): Contains the nodes of the linked list so the function can check through each name.
	* 
	* Returns:
	* 1 - If there`s a product with the same name.
	* 0 - The product isn`t in the linked list.
	*/

	Product* temp = NULL;

	temp = List->Head;

	while (temp != NULL) { // Look if there`s already a product that has the same name, if so, skip.
		if (strcmp(temp->name, s) == 0) { // If the strings are equal.
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void FreeLinkedList(Products_manager* List) {
	/*
	* Summary:
	* This function deletes a linked list from the memory of the machine.
	* 
	* Arguments:
	* List - (Product manager type pointer): A pointer to a manager struct.
	* 
	* Variables:
	* temp - (Product type pointer): Used to free the memory.
	*/
	Product* temp = NULL;

	while (List->Head != NULL) {
		temp = List->Head; 
		List->Head = List->Head->next; // store the next node as the new head.
		free(temp);
	}
}

void AddItems(char ProductName[], int Quantity, Products_manager List) { 
	/*
	* Summary:
	* This function looks for a product with the same name as the one given as an argument and if it finds it, the function updates how many of this product are there.
	* 
	* Arguments:
	* ProductName - (char type array): A string that contains the name of the product the function`s looking for.
	* Quantity - (INT type): Represents how many products of the same kind the function will add.
	* List - (Products manage type): Contains the head and tail of the linked list.
	* 
	* Varibles:
	* temp - (Product type pointer): Used for iteration until the function will get to the specific node of the same name as ProductName.
	* 
	* Prints:
	* In a case where there`s no product with the same name as 'ProductName', the function will print that there`s no product with this name in the linked list.
	*/

	Product* temp = List.Head;

	if (Quantity <= 0) {
		printf("The quantity of items to add must be a positive value.\n");
	}

	else if (IfProductAlreadyExists(&List, ProductName) == 1) {
		while (temp != NULL) { // Getting to the node with the same name to update the quantity.
			if (strcmp(temp->name,ProductName) == 0){
				temp->quantity += Quantity; // Update how many products of this name are in the linked list.
				printf("%d %s were added to the kitchen.\n", Quantity, ProductName);
				break;
			}
			temp = temp->next; // Iterate to the next node.
		}
	}
	else {
		printf("There`s no product named \"%s\" in the linked list\n", ProductName);
	}
}

void OrderItem(Products_manager Tables[], Products_manager* List, int TableNumber, char ProductName[], int Quantity) {
	/*
	* Summary:
	* This function adds an item to a linked list of a specific table and at the same time lowers the quantity of that product from
	* the linked list that contains the items.
	*
	* Arguments:
	* Tables - (Product_manager type): Contains manager structures for each table.
	* List - (Product_manger type pointer): Contains the head and tail of the linked list that has the products of the kitchen in it.
	* TableNumber - (INT type): Represents to which table to insert the order.
	* Product name - (Char type array): Contains the name of the product the table ordered.
	* Quantity - (INT type): Represents how many items of that type the table ordered.
	*
	* Variables:
	* product_node - (Product type pointer): Contains the actual node in the table that has that product in it.
	* product_in_kitchen - (Product type pointer): Used to store the information of the product named 'ProductName'.
	*/
	Product* product_node = Tables[TableNumber].Head;
	Product* product_in_kitchen = List->Head;


	if (TableNumber >= tables || TableNumber < 0) { // Special case: The number of the table entered is larger than the actual amount of tables in the restaurant.
		printf("Table no.%d doesn`t exist in the restautant.\n", TableNumber);
	}
	else if (IfProductAlreadyExists(List, ProductName) == 0) { // Special case: Product doesn`t exist.
		printf("We don`t have %s, sorry!\n", ProductName);
	}
	else if (Quantity <= 0) { // Special case: Quantity must be of a positive value.
		printf("The quantity ordered must be a positive value.\n");
	}
	else {
		if (IfProductAlreadyExists(List, ProductName) == 0) {
			printf("The product named %s doesn`t exist in the kitchen.\n", ProductName);
		}
		else {
			while (product_in_kitchen != NULL) {
				if (strcmp(product_in_kitchen->name, ProductName) == 0) { // That`s the node that contains data about that product.
					break;
				}
				product_in_kitchen = product_in_kitchen->next;
			}

			if (product_in_kitchen->quantity >= Quantity) {
				product_in_kitchen->quantity -= Quantity; // Lower the quantity of the product in the kitchen.

				if (product_node == NULL) { // The linked list is empty.
					product_node = (Product*)malloc(sizeof(Product));
					if (product_node == NULL) { // Allocation check.
						free(List);
						printf("Memory allocation failed when the function \"OrderItem\" tried to allocate memory for 'product_node'\n");
						exit(1);
					}
					
					product_node->name = (char*)malloc(sizeof(char) * (strlen(ProductName) + 1));
					if (product_node->name == NULL) { //Allocation check.
						free(product_node);
						free(List);
						printf("Memory allocation failed when the function \"OrderItem\" tried to allocate memory for 'product_node->name'\n");
						exit(1);
					}

					strcpy(product_node->name, ProductName); // Insert information into the new node.
					product_node->price = product_in_kitchen->price;
					product_node->quantity = Quantity;
					product_node->next = NULL;

					Tables[TableNumber].Head = product_node;
					Tables[TableNumber].Tail = product_node;
				}
				else if(IfProductAlreadyExists(&Tables[TableNumber], ProductName) == 1) // The product already exist.
					while (product_node != NULL) {
						if (strcmp(product_node->name, ProductName) == 0) { // we got to the right node.
							product_node->quantity += Quantity;
							break;
						}
						product_node = product_node->next;
					}
				else { // The product is new.
					product_node = (Product*)malloc(sizeof(Product));
					if (product_node == NULL) { // Allocation check
						free(List);
						printf("Memory allocation failed when the function \"OrderItem\" tried to allocate memory for 'product_node'\n");
						exit(1);
					}

					product_node->name = (char*)malloc(sizeof(char) * (strlen(ProductName) + 1));
					if (product_node->name == NULL) { // Allocation check.
						free(product_node);
						free(List);
						printf("Memory allocation failed when the function \"OrderItem\" tried to allocate memory for 'product_node->name'\n");
						exit(1);
					}

					strcpy(product_node->name, ProductName); // Insert data to the new node.
					product_node->price = product_in_kitchen->price;
					product_node->quantity = Quantity;
					product_node->next = Tables[TableNumber].Head;

					Tables[TableNumber].Head = product_node;
				}
				printf("%d %s were added to table number %d\n", Quantity, ProductName, TableNumber);
			}
			else {
				printf("There isn`t enough \"%s\" for table no.%d to order %d of them\n", ProductName, TableNumber, Quantity);
			}
		}
	}
}


void RemoveItem(Products_manager Tables[], int TableNumber, char ProductName[], int Quantity) {
	/*
	* Summary:
	* This function removes an item from the linked list of a table.
	* 
	* Arguments:
	* Tables - (Product_manager type array) - An array that contains the information for each table.
	* TableNumber - (INT type) - The number of the table that wants to remove an item.
	* ProductName - (Char type areay): Represents the name of the product the table we want to remove items from.
	* Quantity - (INT type): Represents how many of that product the table will remove.
	* 
	* Variables:
	* product_node - (Product type pointer): Used to store the actual node in that table that we want to act on.
	* product_doesnt_exist_Fl - (INT type): A flag, Used in a case when the product isn`t on the order of that table.
	*/
	
	Product* product_node = Tables[TableNumber].Head; // Allocate the head as a temporary variable.
	int product_doesnt_exist_Fl = 0; // Switched OFF

	if (TableNumber >= tables ||TableNumber < 0) {
		printf("Table no.%d doesn`t exist in the restaurant\n", TableNumber);
	}
	else if (product_node == NULL) { // No orders atm.
		printf("Table number %d hasn`t been ordered yet.\n", TableNumber);
	}
	else if (Quantity <= 0) {
		printf("The quantity of product to remove must be a positive value, %d was given\n", Quantity);
	}
	else {
		while (product_node != NULL) {
			if (strcmp(product_node->name, ProductName) == 0) {
				if (product_node->quantity < Quantity) { // Special case: The table wanted to remove more than it bought.
					printf("Table no.%d asked to remove %d items, yet the table ordered %d items of that type\n", TableNumber, Quantity, product_node->quantity);
				}
				else {
					product_node->quantity -= Quantity; // Update how many items are currently in the table`s order after the function removed the items.
					printf("%d %s was returned to the kitchen from table number %d\n", Quantity, ProductName, TableNumber);
				}
				break;
			}

			product_node = product_node->next; // Continue onwards.

			if (product_node == NULL) { // Got to the end of the linked list yet the item wasn`t found.
				product_doesnt_exist_Fl = 1; // Switch to - ON.
			}
		}
		if (product_doesnt_exist_Fl == 1) {
			printf("\The product named \"%s\" doesn`t exist in the table`s orders\n", ProductName);
		}
	}
}

void RemoveTable(Products_manager Tables[tables], int TableNumber) {
	/*
	* Summary:
	* This function sums the price for a table and closes its order.
	* 
	* Arguments:
	* Tables - (Product_manger type): An array that contains the order of each table.
	* TableNumber - (INT tyoe): Represents the index of the table the functoin will close its order.
	* 
	* Variables:
	* current_node - (Product type pointer): Used to get information for each product from the table`s orders.
	* temp - (Product type pointer): Used to clean the table and free memory.
	*/

	Product* current_node = Tables[TableNumber].Head;
	Product* temp = Tables[TableNumber].Head;

	if (TableNumber >= tables || TableNumber < 0 ) { // Special case: When the table doesn`t exist.
		printf("Table no.%d doesn`t exist\n", TableNumber);
	}
	else if (Tables[TableNumber].Head == NULL) { // Special case: the table didn`t order anything yet.
		printf("There are no orders for table no.%d currently\n", TableNumber);
	}
	else {
		printf("\n\nSummary:\n");
		while (current_node != NULL) {
			if (current_node == Tables[TableNumber].Head) { // On first iteration
				printf("\n%d %s, . %.2f nis + %.2f nis for tips,please!", current_node->quantity, current_node->name, (float)(current_node->price*current_node->quantity), (float)(current_node->price*current_node->quantity *10)/ 100);
			}
			else {
				printf("\n%d %s, . %.2f nis + %.2f nis for tips,please!", current_node->quantity, current_node->name, (float)(current_node->price*current_node->quantity), (float)(current_node->price * 10) / 100);
			}
			current_node = current_node->next; // Advance forth.
			
			free(temp->name);
			free(temp);
			temp = current_node;
		}
		Tables[TableNumber].Head = NULL; // Reset the table for next use.
		Tables[TableNumber].Tail = NULL; 
	}
}

void ReleaseNodeWithQuantityZero(Products_manager List) {
	/*
	* Summary:
	* This function`s used to delete a node that has a product with 0 quantity.
	* 
	* Arguments:
	* List - (Products_manager type pointer): A manager`s structure that contains the head of the linked list.
	* 
	* Varibles:
	* curr - (Product type pointer): Contains the current node the function passes on.
	* prev - (Product type pointer): Contains the node before curr (The current node).
	*/
	Product* curr = List.Head;
	Product* prev = NULL;
	
	if (curr != NULL && curr->quantity == 0) { // Special case: First item has no quantity.
		List.Head = curr->next; // Assign the second node as the head of the linked list.
		free(curr);
	}
	
	if (curr != NULL) {
		prev = curr;
		curr = curr->next;
	}
	

	while (curr != NULL) {
		if (curr->next == NULL && curr->quantity == 0) { // Special case: Tail has quantity that`s equal to zero.
			prev->next = NULL; // Update the node beforehand so the link to that tail will be cut.
			free(curr);
			curr = NULL;
		}
		else if (curr->quantity == 0) {
			prev->next = curr->next; // Skip on the node that has quantity that`s equal to zero.
			free(curr);
			break; // The function`s used whenever there`s a change in the linked list, so a change will happen once, therefore there isn`t a need to continute iterating.
		}

		if (curr != NULL) {
			prev = curr; // Update both the following and passing nodes.
			curr = curr->next;
		}
	}
}
