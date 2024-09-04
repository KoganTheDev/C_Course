#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 256


typedef struct book {
	char code[11]; // Maximum 10 characters. One extra for '\0'
	char *name; // A pointer that will be used later when allocating dynamically for the book`s name.
}Book;

typedef struct library {
	char name[MAX];
	int num_books; // Represents how many books are in the library.
	Book *arr;
}Library;


int input_book(Book* B,FILE *in);
void input_library(Library *L,FILE *in);
void output_book(Book* B,FILE *out);
void output_library(Library* L,FILE *out);

int main()
{
	FILE *in,*out;
	Library Libr;        
	int i;
	
	if ((in = fopen("input.txt", "r")) == NULL) {
		printf("File input is wrong.");
		exit(1);
	}

	input_library(&Libr,in);
	fclose(in);

	if ((out = fopen("output.txt", "w")) == NULL) {
		printf("File output is wrong.");
		exit(1);
	}

	output_library(&Libr,out);
	fclose(out);
        

	for (i = 0;i < Libr.num_books; i++) {  /* free the memory!!!*/
		free(Libr.arr[i].name); // Free all of the dynamically allocated names.
	}
	free(Libr.arr); // Releases the array entirely.
    return 0;
}

void input_library(Library* L, FILE* in) {
	/*
	* Summary:
	* This function is used to recieve input from a text file into a library structure.
	* 
	* Arguments:
	* L - (Library type structure): A stracture that contains an array of books, how many books the library contains and its name.
	* in - (FILE type pointer): A pointer to a text file. Used to gather input.
	* 
	* Varibles:
	* i - (INT type): Used for iteration.
	*/
	int i;

	if (fscanf(in, "%s", L->name) != 1) {
		printf("An error has occurred when the software tried to recieve the library`s name.");
		exit(1);
	}

	if (fscanf(in, "%d", &L->num_books) != 1) {
		printf("An error has occurred when the software tried to get how many books are in the library.");
		exit(1);
	}

	L->arr = malloc(L->num_books* sizeof(Book)); // Allocates enough space to contain all of the book structures.

	for (i = 0; i < L->num_books; i++) {
		if (input_book(&L->arr[i], in) == 0){
			printf("An Error has occurred when the software tried to recieve more information on a book.");
			for (i = i-1; i >= 0;i--) { // (i-1) currently contains how many books were written. Using that information now it`s possible to release each memory allocated earlier.
				free(L->arr[i].name); // Releases each name that was allocated.
			}
			free(L->arr); // Releases the whole array of books.
			exit(1);
		} 
	}
}

int input_book(Book* B, FILE* in) {
	/*
	* Summary:
	* This function is used to gather information from a text file specifically into a book structure element.
	* 
	* Arguments:
	* B - (Book type structure): A stracture that contains the name of he book and its code.
	* in - (FILE type pointer): Used for gathering input from the file.
	*
	* Variables:
	* len - (INT type): Used to store the string length/
	* temp - (Char type pointer): Used to store the address when dynamically allocating.
	* 
	* Returns:
	* 1 - (TRUE): If gathering input succeeded.
	* 0 - (FALSE): If getting input failed.
	*/
	int len;
	char* temp = NULL;

	if (fscanf(in, "%10s", B->code) != 1) { // Checks if the function recieved an element.
		printf("An error has occurred when the function tried to read the book`s code.");
		return 0;
	}
	B->name = malloc(MAX * sizeof(char)); // contains a starting value of characters in the strin gwhich is max.

	if ((fscanf(in, "%s", B->name)) != 1) {
		printf("An error has occurred when grabbing the name of the book.");
		free(B->name);
		return 0;
	}

	if (B->name == NULL) {
		printf("Memory allocation failed.");
		free(B->name);
		return 0;
	}
	len = strlen(B->name); // Contains how many character the name trully needs, and reallocates.

	if ((temp = (char*)realloc(B->name, (len+1) * sizeof(char))) == NULL) {
		printf("Reallocating the book`s name into another position has failed.");
		free(B->name);
		return 0;
	}
	B->name = temp;
	return 1;
}

void output_book(Book* B, FILE* out) {
	/*
	* Summary:
	* This function is used to print a book`s data into a text file.
	* 
	* Arguments:
	* B - (Book type pointer): A pointer to a book structure that contain the book`s name and code.
	* out - (FILE type pointer): A pointer to the output file.
	* 
	* Prints:
	* The information of the book.
	*/
	fprintf(out, "%s\t\t%s\n", B->code, B->name);

}

void output_library(Library* L, FILE* out) {
	/*
	* Summary:
	* This function prints information of a library into a text file.
	* 
	* Arguments:
	* L - (Library type structure): Contains the information of the library.
	* out - (FILE type pointer): Used to print output into the text file.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	* 
	* Prints:
	* Prints the data of the library into a text file.
	*/
	int i;

	fprintf(out, "%s\n", L->name);
	for (i = 0;i < L->num_books;i++) {
		output_book(&L->arr[i], out);
	}
}
