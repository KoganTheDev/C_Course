#include<stdio.h>

void BinPrint(unsigned char x);
unsigned char check_ms(unsigned char x);
unsigned char change_bit(unsigned char x, int index);


int main()
{
	unsigned char num1 = 102,num2 = 58;
	int n;

	printf("\nThe first part :");
	printf("\nThe number is %d   ", num1);
	BinPrint(num1);
	num1 = check_ms(num1);
	printf ("\nThe new number is: %d   ", num1);
	BinPrint(num1);

	printf("\n\nThe second part :");
	printf("\nThe number is %d   ", num2);
	BinPrint(num2);
	printf ("\nEnter a number of the bit to change(1-8) ");
	scanf ("%d",&n);
	num2 = change_bit(num2, n);
	printf("\nThe new number is: %d   ", num2);
	BinPrint(num2);
	return 0;
}



void BinPrint(unsigned char x)
{
 /*
 * Summary:
 * This function prints the argument x.
 * 
 * Arguments:
 * x - (Unsigned char type): A number given by the user.
 * 
 * Variables:
 * i - (INT type): Used for iteration.
 * mask - (Unsigned char type): Contains '1' on its leftmost bit. Used for bitwise operations with x.
 */
	
	int i; 
	unsigned char mask = 128; // 1 on the MSB on the 8th bit. EX: 10...0.
	for (i = 0;i < 8;i++) {
		if ((x & mask) == 128) { // The result will be one if both x and the mask will have '1' on their MSB
			printf("1"); 
		}
		else {
			printf("0");
		}
		x = x << 1; // Moving once to the next bit so the function can print it.
	}
}

unsigned char check_ms(unsigned char x) {
	/*
	* Summary:
	* This function checks if the MSB is equal to '1'. If it does it returns that number, Otherwise it will change the MSB 
	* to '1' and then return the number.
	* 
	* Arguments:
	* x - (Unsigned Char type): An ASCII character.
	* 
	* Variables:
	* mask - (unsigned char type): Used to change and check x using bitwise operators.
	* 
	* Returns:
	* x - (Unsigned Char type): If x contains '1' on its MSB the function will return the same value x contains.
	*						If x has '0' on its MSB the function will change the MSB from '0' to '1' and then return it.
	*/
	unsigned char mask = 128; // In binary form 10...0, Used to check if the MSB is equal 1 or not.

	if ((x & mask) == 128) { // Will return that number only if x has 1 on its MSB.
		return x;
	}
	
	x = x | mask; // Now every '1' on x will be passed onwards but the bitwise operator OR will change the MSB from '0' to '1'.
	return x;
}

unsigned char change_bit(unsigned char x, int index) {
	/*
	* Summary:
	* This function checks if the variable x has '1' or '0' on a specific bit then it inverts that bit - from '0' to '1' OR from '1' to '0'
	* 
	* Arguments:
	* x - (Unsigned char type): The character given by the user.
	* index - (INT type): The location of the bit the function has to invert.
	* 
	* Variables:
	* mask - (unsigned char type): At the start contain 1 on its MSB, changes according to the index given as an argument.
	* 
	* Returns:
	* x - (Unsigned char type): The value after the bit in the argument 'index' was inverted.
	*/
	unsigned char mask = 128; // In binary form 10...0, Used to check if the MSB is equal 1 or not.

	mask = mask >> (index - 1); // The value is (index-1) so if the user inputs 1 the mask won`t move since the MSB is the first location, therefore the MSB will be changed.

	if ((x & mask) == 0) { // The result is '0' only if x doesn`t have 1 on its bit in the same index of the mask`s bit. 
		x = x | mask; // Using the mask, in the place where x has '0' but the mask has '1' the new value will be '1'
	}
	else {
		x ^= mask; // Using XOR on the place where both the mask and x have '1' the result will have '0' in that bit instead of '1'.
	}

	return x;
}