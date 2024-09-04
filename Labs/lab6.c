/*
#include <stdio.h>
#define M 4
#define N 5

double average(int Matrix[][M], int Rows, int Cols, int r, int c);
int is_valid(int Rows, int Cols, int Index_A, int Index_B);

int main() {
	int matrix[N][M] = {{11,12,13,14},
						{0,-7,18,7},
						{1,2,-1,-2},
						{6,-9,-19,9},
						{300,149,267,10}};

	printf("The value of the average of the neighboring numbers near (%d) is (%.3lf).\n", matrix[3][3],average(matrix,N,M,3,3));
	printf("The value of the average of the neighboring numbers near (%d) is (%.3lf).\n", matrix[0][2],average(matrix, N, M, 0, 2));
	printf("The value of the average of the neighboring numbers near (%d) is (%.3lf).\n", matrix[4][1],average(matrix, N, M, 4, 1));
	printf("The value of the average of the neighboring numbers near (%d) is (%.3lf).\n", matrix[3][2],average(matrix, N, M, 3, 2));

	return 0;
}

double average(int Matrix[][M], int Rows, int Cols, int r, int c) {
	/*
	* Summary:
	* This function calculates the average of the existing numbers neighbring the number the function aimed to using index.
	*
	* Arguments:
	* Matrix - (INT type array): Matrix initialized in the main program.
	* Rows - (INT type): Represents how many rows are in the matrix.
	* Cols - (INT type): Represents how many columns are in the matrix.
	* r - (INT type): User given input, represent the row of the number the user chose.
	* c - (INT type): User given input, represent the column of the number the user chose.
	*
	* Variables:
	* i - (INT type): Used for iteration.
	* j - (INT type): Used for iteration.
	* exist_count - (INT type): Used to count how many numbers exist near the number that the user chose.
	* res - (Float type): Used to calculate the sum of the numbers that exist near the number that the player chose.
	*
	int i, j, exist_count = 0;
	double res = 0;

	for (i = -1;i < 2;i++) {
		for (j = -1; j < 2; j++) {
			if ((i != 0 || j != 0) && is_valid(N, M, (r + i), (c + j))) { // Skipping the number in the middle that the user enters as input.
				exist_count ++;
				res += Matrix[r + i][c + j];
			}
		}
	}
	return (res/exist_count); // Returns the average.
}

int is_valid(int Rows, int Cols, int Index_A, int Index_B) {
	/*
	* Summary:
	* This function checks if a part of the matrix truly exist.
	*
	* Arguments:
	* Rows - (INT type): represents the rows of the matrix.
	* Cols - (INT type): represents the columns of the matrix.
	* Index_A - (INT type): represents the index of the row that the function will use to check if that index exists.
	* Index_B - (INT type): represents the index of the column that the function will use to check if that index exists.
	*
	* Returns:
	* 1 - (TRUE): If the there`s trully a member of the matrix in index[Index_A,Index_B]
	* 0 - (False): If that part of the matrix doesn`t exist.
	*

	if (Index_A > (Rows-1) || Index_A < 0 || Index_B > (Cols-1) || Index_B < 0) { // Checking if one of the index is illegal and can cause a problem when trying to find its index.
		return 0;
	}
	return 1;
}
*/

#include <stdio.h>
#include <stdlib.h>

double* inputArithmetic(double* a1, double* d, int* n);
double setArithmetic(double a1, double d, double* arr, int n);

int main() {
	double a1, d,res, *arr;
	int n,i;

	arr = (inputArithmetic(&a1, &d, &n));

	while (arr != (NULL)) {
		res = setArithmetic(a1, d, arr, n);
		for (i = 0;i < n;i++) { // Iterates and prints all of the numbers in the array.
			if (i % 5 == 0 && i != 0) {
				printf("\n");
			}
			printf("%lf ", arr[i]);
		}
		printf("\nThe sum of the sequence elements is: %.6lf\n\n", res);
		arr = inputArithmetic(&a1, &d, &n);
	}
	free(arr);
	return 0;
}

double* inputArithmetic(double* a1, double* d, int* n){
	/*
	* Summary:
	* This function gathers input from the user and then allocates memory for an address that will contain an array of numbers.
	* 
	* Arguments:
	* a1 - (Double type pointer): Resembles the first element in the sequence.
	* d - (Double type pointer): Resembles the difference between each element in the array.
	* n - (Int type pointer): Resembles how many elements are in the array.
	* 
	* Variables:
	* arr - (Double type array): Represents the array that the element will get into.
	* 
	* Returns:
	* arr - the array of the numbers.
	*/
	double *arr;

	printf("Enter a1, d, and n respectively, please: ");
	if (scanf("%lf %lf %d", a1,d,n) != 3) {
		return 1;
	}

	if (*n <= 0) { // The amount of numbers in the sequence must be a positive numebr.
		printf("\nThank you for exploring arithmetic sequences and dynamic allocations of arrays.");
		return (NULL);
	}

	arr = (double*)malloc(*n *sizeof(double)); // Creates a new array that countains n indices that each contain enough bytes to contain a double type element

	if (arr == (NULL)) { // malloc return NULL if the allocation failed.
		printf("\nThe software couldn`t find a space to fit the entire sequence.\n");
		exit(1);
	}
	
	return (arr); // The function allocated a space for the array.
}

double setArithmetic(double a1, double d, double* arr, int n) {
	/*
	*Summary:
	*This function gets the first element of an array, the difference an array and the amount of elements in the array and returns the sum of
	*the elements in the sequence.
	* 
	* Arguments:
	* a1 - (Double type): Represents the first element of the array.
	* d - (Double type): Represents the difference between two elements in the array.
	* arr - (Double type pointer): Represents the array of the elements.
	* n - (INT type): Represents the amount of elements in the array.
	* 
	* Variables:
	* i - (INT type): Used for iterations.
	* res - (Double type): Used to sum the result.
	* 
	* Returns:
	* res - The summary of the arguments in the array.
	*/
	int i;
	double res = 0;
	
	for (i = 0;i < n;i++) {
		if (i == 0) { // Special case, first part of the array has no number to its left to calculate its amount.
			arr[0] = a1;
		}
		else {
			arr[i] = arr[i - 1] + d; // Calculates the last element + the difference between each of the elements in the array.
		}
	}

	for (i = 0;i < n;i++) { // Iterate through the array and calculate the sum of the numbers
		res += arr[i];
	}
	return res;
}