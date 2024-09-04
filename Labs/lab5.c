/* PART 1
#include <stdio.h>

int avg(float arr[],int length); 


int main() {
	float avg_time, time[10];
	int counter = 0; // declaring variables.
	
	printf("Enter times, please: ");
	for (int i = 0; i<10; i++) { // Gathering input from the user that will be used to calculate the average and the runners who ran faster than the average.
		scanf("%f", &time[i]);
	}
	avg_time = avg(time, 10);

	for (int i = 0; i < 10;i++) { //Calculating which of the runners running time`s below average. 
		if (time[i] < avg_time){
			counter += 1;
		}
	}
	printf("The number of runners, running below average time is %d", counter);
	return 0;
}

int avg(float arr[], int length) {
	/*
	* Summary:
	* This function takes an array of floating point numbers which represent the times of runners and then calculates
	* the average time it takes to complete the 2K run.
	* 
	* Arguments:
	* arr (type - Floating point array): used as the data center for the runner`s running times.
	* kength (type - Int): represents how big variable "arr" is.
	* 
	* Local Variables:
	* average (type - float): used to calculate the average running time of the runners.
	* 
	* Returns:
	* average (type - float): average running time of the runners.
	//? Multyline comment here
	float average = 0; // A variable that`s used to add the numbers and then divide them by the amount of runners which is 10.
	for (int i = 0; i < 10;i++) {
		average += arr[i];
	}
	average /= 10;
	return average;
}
*/

/*Part 2*/

#include <stdio.h>
#include <stdlib.h> 

#define N 7 //Having a constant variable named N that`ll be used to limit the amount of input the user enters to arr1.


int compare_arrays(int arr1[], int arr2[], int array_length);

int main() {
	int i, MaxValue,res, arr1[N], arr2[N]; // Declaring variables.
	srand(time(NULL));

	

	for (i = 0;i < N;i++) {
		printf("Enter arr[%d]: ", i);
		scanf("%d", &arr1[i]);
	}

	printf("Enter max value greater than zero: ");
	scanf("%d", &MaxValue);
	if (MaxValue <= 0) {
		printf("Maximum value must be a positive number <bigger than 0>\n");
	}

	while (MaxValue <= 0) { // Max value must be a positive number therefore as long as the user enters zero/negative numbers he won`t be able to continue.
		printf("Enter max value greater than zero: ");
		scanf("%d", &MaxValue);
		if (MaxValue <= 0) {
			printf("Maximum value must be a positive number <bigger than 0>");
		}
	}
	for (i = 0;i < N;i++) {
		arr2[i] = rand() %MaxValue+1; //Creating random elements and inserting them into arr2
	}
	
	printf("Array 1: ");	// Printing both of the arrays for the user to see.
	for (i = 0;i < N;i++) {
		printf("%d ", arr1[i]);
	}
	printf("\nArray 2: ");
	for (i = 0;i < N;i++) {
		printf("%d ", arr2[i]);
	}

	res = compare_arrays(arr1, arr2, N);
	if (res == -1) {
		printf("\nNO!!!");
	}
	else {
		printf("\nThe index is %d (numbers %d and %d)", res, arr1[res], arr2[res]);
	}

	return 0;
}

int compare_arrays(int arr1[],int arr2[],int array_length) {
	/*
	* Summary:
	* This function compares the values between two different arrays and it`s looking for a value in arr1 that`s bigger than the value
	* in the same index in arr2.
	* 
	* Variables:
	* arr1 - (Int type Array): An array that contains user input.
	* arr2 - (Int type Array): An array that contains randomly generated input.
	* array_length - (Int type): represents the length of both of the arrays.
	*/
	for (int i = 0;i < array_length;i++) {
		if (arr1[i] > arr2[i]) { // compare i element in both arrays.
			return i;
		}
	}
	return -1;
}


/*Part 3

#include <stdio.h>
#include <string.h>

void replaceSubstring(char* str, char* substr);

int main() {
	char str1[101], str2[101]; // Leaving one empty place for '/0'.
	int len;

	printf("Enter text: ");
	fgets(str1, 101, stdin);
	
	len = strlen(str1); // deleting an enter sign and putting '\0' instead.
	if (str1[len - 1] == '\n') {
		str1[len - 1] = '\0';
	}
	if (*str1 == '\0') { 
		printf("Finish");
	}
	else {
		printf("Enter substring: ");
		fgets(str2, 101, stdin);
		len = strlen(str2); // deleting an enter sign and putting '\0' instead.
		if (str2[len - 1] == '\n') {
			str2[len - 1] = '\0';
		}
		if (*str2 == '\0') {
			printf("Finish");
		}
		len = strlen(str1); // resetting len so it`ll be used in a way that allows the function to run o

	}
	while (*str1 != '\0' && *str2 != '\0') {
		
		replaceSubstring(str1, str2);
		
		puts(str1); // prints the main string after the changes.
		printf("\n");

		printf("Enter text: "); // repeats the cycle.
		fgets(str1, 101, stdin);

		len = strlen(str1); // deleting an enter sign and putting '\0' instead.
		if (str1[len - 1] == '\n') {
			str1[len - 1] = '\0';
		}
		if (*str1 == '\0') {
			printf("Finish");
		}
		else {
			printf("Enter substring: ");
			fgets(str2, 101, stdin);
			len = strlen(str2); // deleting an enter sign and putting '\0' instead.
			if (str2[len - 1] == '\n') {
				str2[len - 1] = '\0';
			}
			if (*str2 == '\0') {
				printf("Finish");
			}
		}
	}


	return 0;
}

void replaceSubstring(char* str, char* substring) {
	/*
	* Summary:
	* This function changes all of the occurrences of the substring in the main string from lower case to upper case.
	* 
	* Arguments:
	* str - (char type pointer): pointer to the start of the main string.
	* substring - (char type pointer): pointer to the start of the substring.
	* 
	* Variables: 
	* substring_length - (Int type): used as the stop factor for each time a change occurs
	* current_change -(Char type pointer): represents the current letter that`ll change next.
	
	int substring_length = strlen(substring);
	char* current_change = strstr(str, substring);

	while (current_change != NULL) { // If there are no occurrences of the substring in str1, (strstr) return NULL.
		for (int i = 0;i < substring_length;i++) {
			if (current_change[i] >= 97 && current_change[i] <= 122) { //Checks if the current element in str1 is a lower case letter. 
				current_change[i] -= 32; //Changes to Upper Case.
			}
		}
		current_change = strstr(current_change+1, substring); // Next occurrence of the substring in str1
	}
}
*/