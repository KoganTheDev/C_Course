#include "hw4_header.h"

int main() {
	
	FILE* instructions = fopen("Instructions.txt", "r");
	FILE* manot = fopen("Manot.txt", "r");
	if (manot == NULL || instructions == NULL) {
		printf("Memory allocation failed when \"main.c\" tried to allocate memory to the pointer manot or instructions");
		exit(1);
	}

	int option, quantity, tableNumber, i;
	Products_manager Tables[tables];
	Products_manager kitchen;
	Product* node = NULL; // Used to free all of the memory at the end of the program.
	char ProductName[name_max_len];

	InitTables(&Tables); // Initialize all of the table`s linked list.
	kitchen.Head = NULL;
	kitchen.Tail = NULL;

	while (fscanf(instructions ,"%d", &option) != EOF) {
		switch (option) {
		case (1):
			CreateProducts(&kitchen, manot);
			break;
		case(2):
			if (fscanf(instructions, "%s %d", ProductName, &quantity) != 2) {
				printf("Recieving input failed\n");
				exit(1);
			}
			AddItems(ProductName, quantity, kitchen);
			break;
		case(3):
			if (fscanf(instructions, "%d %s %d", &tableNumber, ProductName, &quantity) != 3) {
				printf("Recieving input failed.\n");
				exit(1);
			}
			OrderItem(Tables, kitchen, tableNumber, ProductName, quantity);
			break;
		case(4):
			if (fscanf(instructions, "%d %s %d", &tableNumber, ProductName, &quantity) != 3) {
				printf("Recieving input failed.\n");
				exit(1);
			}
			RemoveItem(Tables, tableNumber, ProductName, quantity); // Removed an item
			ReleaseNodeWithQuantityZero(kitchen); // Look for a node that has a product with zero quantity.
			ReleaseNodeWithQuantityZero(Tables[tableNumber]); // Do the same but on the specific table of that linked list.
			break;
		case(5):
			if (fscanf(instructions, "%d", &tableNumber) != 1) {
				printf("Recieving input failed.\n");
				exit(1);
			}
			RemoveTable(Tables, tableNumber);
			break;
		}
	}

	node = kitchen.Head;
	while (node != NULL) {
		kitchen.Head = kitchen.Head->next;
		free(node->name);
		free(node);
		node = kitchen.Head;
	}


	fclose(instructions);
	fclose(manot);
	return 0;
}