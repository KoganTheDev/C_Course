/* 
#include<stdio.h>
#include<stdlib.h>


void set_2d(float** a, int m, int n);
void print_2d(float** a, int m, int n);

int main()
{
	int m, n, i;
	float** a;
	printf("\nEnter m and n, for m*n array: \n");
	scanf("%d %d", &m, &n);

	a =(float**) malloc(m * sizeof(float*)); // An array full of addresses.
	if (a == NULL) {
		printf("The software couldn`t find enough memory to allocate for the matrix.");
		free(a);
		exit(1);
	}
	for (i = 0;i < m;i++) { // creats the matrix.
		a[i] = (float*)malloc(n * sizeof(float));
		if (a[i] == NULL) {
			printf("The software couldn`t find enough memory to allocate for the matrix.");
			for (i = 0;i < n;i++) {
				free(a[i]);
			}
			exit(1);
		}
	}
		set_2d(a, m, n);
		print_2d(a, m, n);
	
	return 0;
}

void set_2d(float** a, int m, int n) {
	/*
	* Summary:
	* This function allocates data to each part of the array.
	* 
	* Arguments:
	* a - (Float type X2 pointer): Contains the address of the matrix.
	* m - (INT type): Used to represent the rows of the matrix.
	* n - (INT type): Used to represent the columns of the matrix.
	* 
	* Variables:
	* i - (INT type): Used for iteration
	* j - (INT type): Used for iteration
	* k - (INT type): Represents the value that the function will enter into the matrix.
	*
	int i, j, k = 1;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a[i][j] = k++;
}

void print_2d(float** a, int m, int n) {
	/*
	* Summary:
	* The function recieves a matrix and prints each element in seperate.
	* 
	* Arguments:
	* a - (Float type X2 pointer): Contains the address of the matrix.
	* m - (INT type): Used to represent the rows of the matrix.
	* n - (INT type): Used to represent the columns of the matrix.
	* 
	* Variables:
	* i - (INT type): Used for iteration
	* j - (INT type): Used for iteration
	* 
	* Prints:
	* The matrix as it`s stored in the memory of the computer.
	*
	int i, j; 
	for (i = 0;i < m;i++) { // Iterating through the matrix to print each elemnt.
		for (j = 0;j < n;j++) {
			if (j == n - 1) {
				printf("%.1f\n", a[i][j]); // Prints the last element of the row.
			}
			else if (j == 0) { // Special case for printing.
				printf("\t%.1f\t", a[i][j]);

			}
			
			else {
				printf("%.1f\t", a[i][j]);
			}
		}
	}
}
*/


/* Q2 

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define NUMELEMS 7

char* findMin(char** arrP, int arrSize);


int main()
{
	char* a[] = { "Alona","Nir","Amina","Yosef","alice","Amos","bob" };
	int i;

	for (i = 0; i < NUMELEMS; i++)
		printf("%s\n", a[i]);
	printf("\n%s", findMin(a, NUMELEMS));

	return 0;
}

char* findMin(char** arrP, int arrSize) {
	/*
	* Summary: 
	* This function checks for the word which has the lowest lexicographic value.
	* 
	* Arguments:
	* arrP - (Char type array of pointers): Contains the addresses of the values in the main array.
	* arrSize - (INT type): Represents the length of the array.
	* 
	* Variables:
	* temp - (Char type pointer): Stores the address of the smallest word lexicographically wise.
	* i - (INT type): Used for iteration.
	* 
	* Returns:
	* temp - (Char type pointer): The word with the smallest value lexicographically wise.
	*
	char* temp = arrP[0];
	int i;

	for (i = 1;i < arrSize;i++) {
		if (strcmp(arrP[i], temp) < 0) {
			temp = arrP[i];
		}
	}
	return temp;
}
*/

/* Q3

#include <stdio.h>
#include <math.h>

float func1(int x);
float func2(int x);
double sum_square(int m, int n, float(*f)(int a));

int main() {
	printf("The sum of func2: %.5lf\n", sum_square(2, 13, func2));
	printf("The sum of func1: %.5lf\n ", sum_square(1, 10000,func1));
	return 0;
}

float func1(int x) {
	return (1.0 / x);
}

float func2(int x) {
	return (x / 5.0);
}

double sum_square(int m, int n, float(*f)(int a)) {
	/*
	* Summary:
	* This function recieves a range, and calculates the value accrding to the function given in the 'main'
	* function.
	* 
	* Arguments:
	* m - (INT type): The number the fucntion will start from.
	* n - (INT type): The number the function will end its calculations with.
	* f - (Pointer to a function): A pointer that contains the address to a function.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	* res - (Double type): Contains the result of the calculations.
	* 
	* Returns:
	* res - (Double type): The result of the calculations.
	*
	int i;
	double res = 0;

	for (i = m; i <= n;i++) {
		res += pow(f(i), 2);
	}
	return res;
}
*/


/* Q4
#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef  enum { FALSE, TRUE } BOOL;


BOOL Int_Sum(void*, void*, void*);
BOOL Float_Sum(void*, void*, void*);
BOOL Sum(BOOL(*f)(void*, void*, void*), void** p_num, void* number);

int main()
{
	int num[] = { 3,5,23,5,6 }, i, value;
	float  fnum[] = { 3.5,5.0,2.3,5.8,6.2 }, fvalue;
	void* p_num[N];

	
	for (i = 0;i < N; i++) { // Allocating an address so each elemnt in p_num will be connected to an element form the array num.
		p_num[i] = &num[i];
	}


	printf("\nPlease enter an integer number ");
	scanf("%d", &value);
	if (Sum(Int_Sum,p_num,&value)== TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");






	for (i = 0;i < N; i++) { // Allocating an address so each elemnt in p_num will be connected to an element form the array num.
		p_num[i] = &fnum[i];
	}

	printf("\nPlease enter a float number ");
	scanf("%f", &fvalue);
	if (Sum(Float_Sum,p_num,&fvalue) == TRUE)
		printf("There is such sum\n");
	else
		printf("There is no such sum\n");
	
	return 0;
}



BOOL Int_Sum(void* a, void* b, void* c)
{
	/* Summary:
	* The function calculates the sum of two integers and checks if the result is equal to the third one.
	*
	* Arguments:
	* a - (Void type address): Contains a  integer number.
	* b - (Void type address): Contains a  integer number.
	* c - (Void type address): Contains a  integer number. Represents the sum the function`s looking for.
	*
	* Returns:
	* TRUE - If the sum can be calculated using the two elements from the array.
	* FALSE - If the sum can`t be calculated using the two elements from the array.
	*
	if (*(int*)a + *(int*)b == *(int*)c)
		return TRUE;
	return FALSE;
}

BOOL Float_Sum(void* a, void* b, void* c)
{
	/* Summary:
	* The function calculates the sum of two floating point numbers and checks if the result is equal to the third one.
	* 
	* Arguments:
	* a - (Void type address): Contains a floating point number.
	* b - (Void type address): Contains a floating point number.
	* c - (Void type address): Contains a floating point number. Represents the sum the function`s looking for.
	*
	* Returns:
	* TRUE - If the sum can be calculated using the two elements from the array.
	* FALSE - If the sum can`t be calculated using the two elements from the array.
	*
	if (*(float*)a + *(float*)b == *(float*)c)
		return TRUE;
	return FALSE;
}

BOOL Sum(BOOL(*f)(void*, void*, void*), void** p_num, void* number) {
	/*
	* Summary:
	* This function receives a pointer to an array of numbers and a number and then checks using a specific function
	* if two numbers in the array can create the 'number' (An actually sum).
	* 
	* Arguments:
	* f - (Bool type pointer to a function): A pointer to a specific function.
	* p_num - (Void type X2 pointer to an array): An array that contains integers/ floating numbers.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	* j - (INT type): Used for iteration.
	* 
	* Returns:
	* TRUE - If a sum can be calculated using two elements from the array.
	* FALSE - If the sum can`t be calculated using numbers from the array.
	*
	int i, j;

	for (i = 0;i < N;i++) { // Iterates through each element and tries to combine each element with another one to check if it can gather twon numbers that create the sum the function`s looking for. 
		for (j = i+1;j < N;j++) {
			if (f(p_num[i], p_num[j], number) == TRUE) {
				return TRUE;
			}
		}
	}
	return FALSE;
}

*/

/*Q5 */

#include<stdio.h>

#define N 5


 // Function declarations.
void Int_Sum(void* sum, void* num);
void Int_Sub(void* sum, void* num);
void Init(void* p);
int Int_Comp(void* a, void* b);
int Do_It(void* sum, void** array, void (*p_Init)(void*), void(*p_Sum)(void*, void*), void(*p_Sub)(void*, void*), int(*p_Comp)(void*, void*));

// Actual functions.
void Int_Sum(void* sum, void* num)
{
	/*
	* Summary: 
	* This function adds a number into a sum.
	* 
	* Arguments:
	* sum - (Void type pointer): A pointer to a value that contains the current sum.
	* num - (Void type pointer): A poitner to a number that will be added to the sum.
	*/
	*(int*)sum += *(int*)num;
}


void Int_Sub(void* sum, void* num)
{
	/*
	* Summary:
	* This function substracts a number from a sum.
	* 
	* Arguments:
	* sum - (Void type pointer): A pointer to a value that contains the current sum.
	* num - (Void type pointer): A poitner to a number that will be substracted from the sum.
	*/
	*(int*)sum -= *(int*)num;
}


void Init(void* p)
{
	/*
	* Summary:
	* This function initializes a value.
	* 
	* Arguments:
	* p - (Void type pointer): A poitner to a value.
	*/
	*(int*)p = 0;
}


int Int_Comp(void* a, void* b)
{
	/*
	* Summary: This function recieves two integer numbers and checks if they are the same.
	* 
	* Arguments:
	* a - (Void type pointer): A pointer to an integer.
	* b - (Void type pointer): A pointer to an integer.
	*
	* Returns:
	* 1 - (TRUE): If the numebrs 'a' and 'b' are equal.
	* 0 - (FALSE): If the numbers 'a' and 'b' are not equal.
	*/
	if (*(int*)a == *(int*)b)
		return 1;
	return 0;
}


int Do_It(void* sum, void** array, void (*p_Init)(void*), void(*p_Sum)(void*, void*), void(*p_Sub)(void*, void*), int(*p_Comp)(void*, void*))
{
	/*
	* Summary:
	* This function sums the even numbers and substracts the odd ones so it can check if the sum of the numbers
	* can be equal to the number in the next location of the array.
	*
	* Arguments:
	* sum - (Void type pointer) - Contains the address of sum.
	* array - (Void type X2 pointer) - Contains the address to the array that the function will work on.
	* p_Init - (Void type pointer to a function) - A pointer that will allow the software to use the function.
	* p_Sum - (Void type pointer to a function) - A pointer that will allow the software to use the function.
	* p_Sub - (Void type pointer to a function) - A pointer that will allow the software to use the function.
	* p_Comp - (Void type pointer to a function) - A pointer that will allow the software to use the function.
	*
	* Variables:
	* i - (INT type): Used for iteration.
	*
	* Returns:
	* 1 - (TRUE): If the number on a specific location can be calculated by using the numbers that come before it.
	* 0 - (FALSE): If the number can`t be calculated by using the numbers that come before it.
	*/

	int i;

	Init(sum); // Initializes the sum.

	for (i = 0; i < (N - 1);i++) { //Runs up until the last element.
		if (i % 2 == 0) { // Specific function for even numbers.
			p_Sum(sum, array[i]);
		}
		else { // Specific funtoin for odd numbers. If it isn`t an even number than it`s an odd one. 
			p_Sub(sum, array[i]);
		}

		if (p_Comp(array[i + 1], sum) == 1) { // When the sum can be calculated using the numbers beforehand.
			return 1;
		}
	}
	return 0; // Finished running on the array and couln`t find a number that can be calculated using the numbers before it.
}

int main()
{
	int num[] = { 5,8,23,20,23 }, i, answer;
	void* p_num[N];


	for (i = 0;i < N;i++) { // Allocating address for each element in the poitner array so it`ll be connected to the main array that contains the numbers.
		p_num[i] = &num[i];
	}




	answer = Do_It(&answer, p_num, Init, Int_Sum, Int_Sub, Int_Comp);
	if (answer == 1)
		printf("The answer is 'Yes'");
	else
		printf("The answer is 'No'");

	return 0;
}
