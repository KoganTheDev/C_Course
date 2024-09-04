/* 
#include <stdio.h>
#include <string.h>

#define N 8 

int is_in_array(int arr[N], int num);

int main() {
	int arr[N],num, i, flag = 0;
	

	for (i = 0;i < N;i++) {
		printf("Enter arr[%d]: ", i);
		if (scanf("%d", &arr[i]) != 1) {
			return 1; // Exit in case the input is not a digit.
		}
	}

	
	for (i = 0;i < N;i++) { // Checking if the first array entered is already an array full of zeros.
		if (arr[i] == 0) {
			flag++;
		}
	}
	if (flag == N) { // Ending condition.
		printf("\nFINISH\n");
	}

	while (flag != N) {
		printf("Enter an integer, please: ");
		if (scanf("%d", &num) != 1) {
			return 1;
		}

		if (is_in_array(arr, num) == 1) { // All of the digits were in the array in the correct order.
			printf("All of the digits of the number (%d) are in the given array:\n[", num);
			for (i = 0;i < N;i++) {
				if (i == (N - 1)) {
					printf("%d]\n\n", arr[i]);
				}
				else {
					printf("%d, ", arr[i]);
				}
			}
		}
		else {
			printf("Not all of the digits of the number (%d) are in the array or their placement is wrong.\nThe array: [", num);
			for (i = 0;i < N;i++) {
				if (i == (N - 1)) {
					printf("%d]\n\n", arr[i]);
				}
				else {
					printf("%d, ", arr[i]);
				}
			}
		}
		flag = 0; // resetting the counter.

		for (i = 0;i < N;i++) {
			printf("Enter arr[%d]: ", i);
			if (scanf("%d", &arr[i]) != 1) {
				return 1; // Exit in case the input is not a digit.
			}
		}
		for (i = 0;i < N;i++) { // Checking if the first array entered is already an array full of zeros.
			if (arr[i] == 0) {
				flag++;
			}
		}

		if (flag == N) {
			printf("\nFINISH\n"); // Ending condition.
		}
	}
	return 0;
}

int is_in_array(int arr[N], int num) {
	/*
	* Summary:
	* This function accepts an array and a number and checks if all of the digits of the number are in the array in the correct order from left
	* to right.
	*
	* Arguments:
	* arr - (Int type array): An array of numbers entered by the user.
	* num - (Int type): A number that the function will check if its digits are in the array.
	*
	* Variables:
	* i - (INT type): used for iteration
	*
	* Returns:
	* 1 ("TRUE"): If all of the digits of num are in the array.
	* 0 ("False"): If only some of the digits are in array or the order of the digits in the array is misplaced.
	*
	int i = 0;

	if (num == 0){ // Special case, looking for a zero in the array.
		while (i < N) {
			if (num == arr[i]) {
				return 1;// If the function found a zero in the array.
			}
			i++;
		}
		return 0;
	}
	else if (num < 0) { //Changing the number from a negative integer into a positive one.
		num *= (-1);
	}

	for (i = 0; i < N;i++) {
		if (num % 10 == arr[(N - 1) - i]) { // Checks if the digit is assigned to the index, by checking from right to left.
			num /= 10; // Removing the leftmost digit
		}
	}
	if (num == 0) { // The function found all of the digit in num in the correct order.
		return 1;
	}
	return 0; // No digits in num are in the array or their order is wrong.
}
*/

/* Q2

#include <stdio.h>
#include <string.h>

char letterAtIndex(char s[], int m);

int main() {
	char s[51]; // A string with 50 empty spaces + one extra space for '0'
	int i = 0, len_s;
	char res;


	printf("Please enter a string constructed of small letters in english, please:\n");
	fgets(s, 51, stdin); // reciving a string from the user.
	len_s = strlen(s);
	if (s[len_s-1] == '\n') {
		s[len_s-1] = '\0'; // Changing to the string ending character instead of newline.
	}

	printf("\nEnter an integer please, used as the index of the letter in the sorted string\n");
	if (scanf("%d", &i) != 1){
		return 1;
	}
	res = letterAtIndex(s, i);

	if (res >= 'a' && res <= 'z') { // checking if the result is valid.
		printf("\nThe letter in the sorted string is (%c)\n", res);
	}
	return 0;
}

char letterAtIndex(char s[], int m) {
	/*
	* Summary:
	* This function checks which letter could be in a specific index if the string (s) was sorted
	* 
	* Arguments:
	* s - (String type array): represents the string given by the user.
	* m - (INT type): the index of the letter in the sorted string.
	* 
	* Variables:
	* occurs - (INT type array): An array that`s used to check how many times a letter occurs in the string (s)
	* i - (INT type): Used for iterative operations.
	* len_string (INT type): Used as the stopping factor of the for loop that iterates on the string (s).
	* sum (INT type): Used to check when the amount of the occurrences of the letters is bigger than m.
	* 
	* Returns:
	* type (CHAR): The letter in which the index should`ve been if the string was sorted.
	*
	int occurs[26] = { 0 }; // An array full of zeros that`ll be used to count each time a letter occurs in the string.
	int i = 0, len_string = strlen(s), sum = 0;


	if (len_string == 0) { //Special case - Empty string. | contains only '/0'
		printf("\nThere are no small letters in an empty string.\n");
		return 0;
	}
	else if (m >= len_string) { // Special case - Overflow.
		printf("\nThe index is invalid and will cause an overflow error.\n");
		return 0;
	}


	for (i = 0;i < (len_string);i++) { 
		if (s[i] == '\0') {
			return 0; // False, since the string is empty and there are no small letters in the string.
		}
		occurs[s[i] - 'a'] ++; // Using ASCII, increasing the location of the letter in occurs. a = [index] 0 and z = [index] 26
	}
	

	for (i = 0;i < 26;i++) { // Iterating through the array ''occurs'' to check which letter apears on the m index.
		sum += occurs[i];
		if (sum > m) { 
			return (i + 'a');
		}
	}
}
*/

/* Q3 */
#include <stdio.h>
#include <string.h>

int isJumble(char s[]);

int main() {
	char s[256], temp[256];
	int main_len, second_len;
	char End[] = { 'E','n','d','\0' };


	printf("Please enter a string\n'End' to exit\n\n");
	fgets(temp, 256, stdin); // receiving input.

	main_len = strlen(temp); // Removes '\n' and puts '\0' instead.
	if (temp[main_len - 1] == '\n') {
		temp[main_len - 1] = '\0';
	}
	main_len = 0;

	if (strstr(temp,End) != (NULL)) { // This line checks if the string END occured. 
		printf("\nThere`s no string that`s jumbled.\n");
		return 1;
	}

	if (strlen(temp) >= main_len && isJumble(temp)) { // Copy the biggest and jumbled string into the string s.
		strcpy(s, temp);
		main_len = strlen(temp);
	}


	while (1) { // Run as long as the user doesn`t input 'End'

		printf("\nEnter a string, please:\n\n");
		fgets(temp, 256, stdin); // receiving input.

		second_len = strlen(temp);
		if (temp[second_len - 1] == '\n') {
			temp[second_len - 1] = '\0';
		}
		second_len -= 1; // '\n' counts as a character so now the is the same size minus 1.

		if (strstr(temp, End) != (NULL)) { // This line checks if the string END occured.
			if (s[0] == '\0') { // Special case - empty string 
				printf("\nThere`s no string that`s jumbled.\n");
			}
			else if (s[0] >= 'a' && s[0] <= 'z'){
				printf("\nThe biggest jumbled string is - ");
				puts(s);
				printf("Its size is %d\n", main_len);
			}
			else { //Undifined behavior 
				printf("\nThere`s no string that`s jumbled.\n");
			}
			break;
		}

		if ((second_len >= main_len) && isJumble(temp)) {
				strcpy(s, temp);
				main_len = second_len;
		}
	}
	return 0;
}

int isJumble(char s[]) {
	/*
	* Summary:
	* This function checks if a letter does`nt occur more than once and it checks if the letters beforhand and afterwards aren`t tailing letters
	* of the letter in index i.
	* 
	* EX:
	* for the letter a, (b or c) are not allowed to apear before or following the letter a.
	* 
	* Arguments:
	* s - (Char type array (string)): The string the software got from the user.
	* 
	* Varibales:
	* i - (INT type): used for iteration.
	* len_string - (INT type): represents the length of the string used to stop the running of the for loop of the function.
	* cnt_list (INT type array): Used to count of many time each letter appers in the string.
	* 
	* Returns:
	* 1 (True) - If the string is jumbled.
	* 0 (False) - If the function isn`t jumbled or a letter apears more than once.
	*/
	int i = 0, len_string = strlen(s), cnt_list[26] = { 0 };

	for (i = 0;i < len_string;i++) {
		cnt_list[s[i] - 'a'] ++; // Increment by one the index in which the software counts a small case letter.

		if (cnt_list[s[i]- 'a'] > 1) { // Stopping factor (if a letter appears more than once).
			printf("The letter (%c) occurs more than once, therefore the string is not jumbled.\n", s[i]);
			return 0;
		}

		if (i == 0) { // The start of the string.
			if ((s[i + 1] == (s[i] + 1)) || (s[i + 1] == (s[i] - 1))) { // Checking if the letter after the first one isn`t a tailing letter.
				return 0;
			}
		}
		else if (i == (len_string - 1)) { // Last character in the string
			if ((s[i - 1] == (s[i] + 1)) || (s[i - 1] == (s[i] - 1))) { // Checking if the letter after the first one isn`t a tailing letter.
				return 0;
			}
		}
		else {
			if ((s[i + 1] == (s[i] + 1)) || (s[i + 1] == (s[i] - 1)) || (s[i - 1] == (s[i] + 1)) || (s[i - 1] == (s[i] - 1))) { // Checking if the letter after the first one isn`t a tailing letter and checking the same for the letter before the checked letter.
				return 0;
			}
		}
	}

	return 1; // Everything is alright and the string is jumbled.
}
