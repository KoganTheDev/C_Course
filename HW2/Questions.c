/* q1
#include <stdio.h>
#include <stdlib.h>

typedef struct driver { // Creating a structure that will be used to enter data to an object called Driver.
	int id;
	int birthDay;
	int licenseYear;
} driver;

int main() {
	int driver_cnt = 1;
	int age_occurrences = 0; // Used to count which age occurs the most.
	int exp_occurrences = 0; // Used to count when most of the drivers got their license.
	int frequently_age; //Used to represent which age happens the most. value is in years.
	int frequently_exp; //Used to represent in which year most of the drivers got their license.
	int i = 1; // Used for iteration. Starts from 1 since we grab the first index during the initial run of the program.

	int age[121] = { 0 }; // A counting array used to count how many times each year occurs per driver.
	int exp[121] = { 0 }; // A counting array used to count in which year most of the drivers got their license.

	driver* temp = NULL; // A pointer that will be used when reallocating.

	driver* arr = (driver*)malloc(1 * sizeof(driver)); // Creating a pointer to a driver struct
	if (arr == NULL) { // Creating memory failed.
		printf("Memory alloaction failed.");
		return 1;
	}

	printf("Enter list of integers (0 0 0 to finish)\n"); 

	
	while (1) {
		if (scanf("%d %d %d", &arr[0].id, &arr[0].birthDay, &arr[0].licenseYear) != 3) {
			return 1;
		}
		if (arr[0].id == 0 && arr[0].birthDay == 0 && arr[0].licenseYear == 0) { // Exit condition
			printf("\nNo driver is in the database.\nThank you for your cooperation.\n");
			free(arr);
			exit(1); // Quit the software since the user entered the stopping statement.
		}
		else if (arr[0].id <= 0 || arr[0].birthDay <= 0 || arr[0].licenseYear <= 0) {// Special case: User entered an invalid input.
			printf("\nPlease enter positive values: (0 0 0 to finish)\n");
			continue; // Recheck the values from the start. 
		}
		else if (arr[0].birthDay < 1903 || arr[0].birthDay > 2023 || arr[0].licenseYear < 1903 || arr[0].licenseYear >2023) {
			printf("\nPlease enter a valid year in the range between 1903 up to 2023.\n");
			continue;
		}
		else if (arr[0].birthDay > arr[0].licenseYear) {
			printf("\nBirthday must be an earlier date than the date of recieving the license.\nPlease enter positive values: (0 0 0 to finish)\n"); // Special case: Bday happens after the date of getting the license which makes no sense.
			continue; // Recheck the values from the start.
		}
		else if (arr[0].id > 0 && arr[0].birthDay > 0 && arr[0].licenseYear > 0) { // Input is valid therefore continue onwards.
			break;
		}
	}

	age[2023 - arr[0].birthDay]++; // Incrementing a specific date.
	exp[2023 - arr[0].licenseYear]++; // Incrementing the date of the given license by one.

	if (age[2023 - arr[0].birthDay] >= age_occurrences) { // Changing the value to the biggest or latest and equal input entered.
		age_occurrences = age[2023 - arr[0].birthDay];
		frequently_age = 2023 - arr[0].birthDay; // saving which age is the most occurring one.
	}
	if (exp[2023 - arr[0].licenseYear] >= exp_occurrences) { // Changing the value to the biggest or latest and equal input entered.
		exp_occurrences = exp[2023 - arr[0].licenseYear];
		frequently_exp = 2023 - arr[0].licenseYear; // Saving in which date most drivers got their license.
	}

	driver_cnt++;
	temp = (driver*)realloc(arr, driver_cnt * sizeof(driver)); // Reallocating the array to a place which has more memory to contain more drivers.
	if (temp == NULL){
		printf("Reallocating the memory failed.");
		free(arr,temp);
		return 1; // Reallocating failed.
	}
	arr = temp; // Copy the array to the new loaction.

	while (1) {
		if (scanf("%d %d %d", &arr[i].id, &arr[i].birthDay, &arr[i].licenseYear) != 3) {
			return 1;
		}
		while (1) { // Inner loop for input validity.
			if (arr[i].id == 0 && arr[i].birthDay == 0 && arr[i].licenseYear == 0) { // Exit condition, exiting from the first while loop.
				break;
			}

			if (arr[i].id <= 0 || arr[i].birthDay <= 0 || arr[i].licenseYear <= 0) {// Special case: User entered an invalid input.
				printf("\nPlease enter positive values: (0 0 0 to finish)\n");
			}
			else if (arr[i].birthDay < 1903 || arr[0].birthDay > 2023 || arr[i].licenseYear < 1903 || arr[0].licenseYear >2023) {
				printf("\nPlease enter a valid year in the range between 1903 up to 2023.\n");
			}
			else if (arr[i].birthDay > arr[i].licenseYear) {
				printf("\nBirthday must be an earlier date than the date of recieving the license.\nPlease enter positive values: (0 0 0 to finish)\n"); // Special case: Bday happens after the date of getting the license which makes no sense.
			}
			else if (arr[i].id >= 0 && arr[i].birthDay >= 0 && arr[i].licenseYear >= 0) { // Input is valid or exit condition is entered by the user.
				age[2023 - arr[i].birthDay]++; // Incrementing a specific date.
				exp[2023 - arr[i].licenseYear]++; // Incrementing the date of the given license by one.
				break;
			}
			if (scanf("%d %d %d", &arr[i].id, &arr[i].birthDay, &arr[i].licenseYear) != 3)  {
				return 1;
			}
		}

		
		if (arr[i].id == 0 && arr[i].birthDay == 0 && arr[i].licenseYear == 0) { // Exit condition, exiting fully from the while loop to continue onwards to the next part of the code.
			break;
		}

		if (age[2023 - arr[i].birthDay] >= age_occurrences) { // Changing the value to the biggest or latest and equal input entered.
			age_occurrences = age[2023 - arr[i].birthDay];
			frequently_age = 2023 - arr[i].birthDay; // saving which age is the most occurring one.

		}
		if (exp[2023 - arr[i].licenseYear] >= exp_occurrences) { // Changing the value to the biggest or latest and equal input entered.
			exp_occurrences = exp[2023 - arr[i].licenseYear];
			frequently_exp = 2023 - arr[i].licenseYear; // Saving in which date most drivers got their license.

		}


		driver_cnt++;
		temp = (driver*)realloc(arr, driver_cnt * sizeof(driver));// Reallocating to a larger storage in the memory.

		if (temp == NULL) { // Memory validation.
			printf("Reallocating the memory failed.");
			free(arr,temp);
			return 1;
		}
		arr = temp;
		i++; // Enter new data to the next index in the array.
	}

	printf("\nThe most frequent driver age is %d which appears %d times.", frequently_age , age_occurrences);
	printf("\nThe most frequent driver experience is %d which appears %d times.\n", frequently_exp, exp_occurrences);

	free(arr,temp);
	return 0;
}
*/

/*q2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct department {
	char code[11]; // Since the code is a string we need an extra space for '\0'.
	char *name; // Maximum length is 20 characters. Extra space for '\0'.
	int hired_engineers; // Represents the amount of new engineers hired to the department.
	int left_engineers; // Represents the amount of engineers that left the department
} department;

void input(department arr[]);
void connect_array_to_pointer(department* p[],department arr[]);
void change_pointers_hired_engineers(department* p[]);
void change_pointers_left_engineers(department* p[]);
void print_res(department* p[]);

int main() {
	department arr[N]; // Creating a new array that will contain many 'departments'.
	department* p[N];

	input(arr);
	connect_array_to_pointer(p, arr);
	change_pointers_hired_engineers(p);
	change_pointers_left_engineers(p);
	print_res(p);

	for (int i = 0; i < N; i++) { // Release allocated memory before completing the end of the software.
		free(arr[i].name);
	}
	return 0;
}

void input(department arr[]) {
	/*
	* Summary:
	* This function recieves an array of a stracture 'department' and enters the data into its fields.
	* 
	* Arguments:
	* arr - (struct type array): An array that contain a stracture called 'department'.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	* str - (Char type arrray): Used to contain the strings the user enters before putting them in the correlated field.
	*
	int i;
	char str[21];
	for (i = 0; i < N; i++) {
		printf("Please enter the code of the department (Up to 10 characters):\n"); // Input for the departments code.
		if (scanf("%s", str) != 1) { // Input check. Grabs up to 10 characters.
			exit(1);
		}
		if (strlen(str) > 10) {
			printf("The code must have up to 10 characters.\nTry again please.\n");
			exit(1);
		}
		strcpy(arr[i].code, str);

		printf("Please enter the name of the department (Up to 20 characters):\n"); // Input for the departments name.
		if (scanf("%s", str) != 1) { // Input check. Grabs up to 20 charcters.
			exit(1);
		}
		if (strlen(str) > 20) {
			printf("The code must have up to 20 characters.\nTry again please.\n");
			exit(1);
		}
		arr[i].name = (char*)malloc(strlen(str) + 1); // Allocating the exact space the name of the department needs.
		if (arr[i].name == NULL) {
			printf("\nMemory allocation failed.");
			exit(1);
		}
		strcpy(arr[i].name, str);

		printf("How many engineers joined %s in last April?\n", arr[i].name); // Input for hired engineers.
		if (scanf("%d", &(arr[i].hired_engineers)) != 1) {
			exit(1);
		}
		printf("How many engineers left %s in the past year?\n", arr[i].name); // Input for engineers that left the company.
		if (scanf("%d", &(arr[i].left_engineers)) != 1) {
			exit(1);
		}
		printf("\n");
	}
}

void connect_array_to_pointer(department* p[],department arr[]) { 
	/*
	* Summary:
	* This function recieves an array of pointers and an array that contain 'department' type elements and allocate a pointer for
	* each element in the array that contain the stractures.
	* 
	* Arguments:
	* p - (Department type array of pointers): An array that will contain the address of each element in the array 'arr'
	* arr - (Department type array): An array that contains stractures called 'Department'.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	*
	int i;
	for (i = 0;i < N;i++) {
		p[i] = &arr[i]; // For each element in the list, grab the address and put it in the pointer.
	}
}

void change_pointers_hired_engineers(department* p[]) {
	/*
	* Summary:
	* This function looks for the best department which hired the biggest amount of enginners comparing to the other departments and
	* for the worst department from which most engineers left their job comparing to the other departments.
	* 
	* Arguments:
	* p - (Department type pointer array): An array filled with pointers to another array which contains the stractures.
	* 
	* Variables:
	* temp - (Department type pointer): Used for crossing addresses between different pointers.
	* i - (INT type): Used for iteration.
	*
	department* temp = NULL;
	int i;

	for (i = 0; i < N;i++) { // Looks for the best department and locates it in the last place in the pointers array.
		if (p[i]->hired_engineers > p[N - 1]->hired_engineers) { // checks if the current department hired more than the department in the last index.
			temp = p[N - 1];
			p[N - 1] = p[i];
			p[i] = temp;
		}
	}

	for (i = 0;i < (N - 1);i++) { // Looks for the worst department and allocates it in index (N-2).
		if (p[i]->hired_engineers < p[N - 2]->hired_engineers) {
			temp = p[N - 2];
			p[N - 2] = p[i];
			p[i] = temp;
		}
	}
}

void change_pointers_left_engineers(department* p[]) {
	/*
	* Summary:
	* This function looks for the worst department which lost the most engineers during last april among the departments and puts it in index 1 (second place)
	* and the best one which lost the fewest amount of engineers during last april and puts it in the first place (index 0).
	* 
	* Arguments:
	* p - (Department type pointer array): An array filled with pointers to another array which contains the stractures.
	* 
	* Variables:
	* temp - (Department type pointer): Used for crossing addresses between different pointers.
	* i - (INT type): Used for iteration.
	*
	department* temp = NULL;
	int i;

	for (i = 1; i < N;i++) { // Looks for the best department and locates it in the last place in the pointers array.
		if (p[i]->left_engineers < p[0]->left_engineers) { // checks if the current department hired more than the department in the first index.
			temp = p[0];
			p[0] = p[i];
			p[i] = temp;
		}
	}

	for (i = 2;i < (N - 1);i++) { // Looks for the worst department and allocates it in index (1).
		if (p[i]->left_engineers > p[1]->left_engineers) {
			temp = p[1];
			p[1] = p[i];
			p[i] = temp;
		}
	}
}

void print_res(department* p[]) {
	/*
	* Summary:
	* This function prints the first and second departments names and codes.
	* 
	* Arguments:
	* p - (Department type pointer array): An array full of pointers which contains stractures called 'Department'.
	*
	printf("\nThe best department`s name is %s\nThe department`s code is %s\n", p[0]->name, p[0]->code);
	printf("\nThe worst department`s name is %s\nThe department`s code is %s\n", p[1]->name, p[1]->code);
}
*/




