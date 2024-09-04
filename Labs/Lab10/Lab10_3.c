#include <stdio.h>

int Bit_Count(unsigned int x);
void Bin_Print(unsigned int x);

int main()
 {
	unsigned int x;

	printf("Enter a number: ");
    scanf("%d",&x);
    printf("There are %d bits equal to one in %d\n", Bit_Count(x),x);
	printf("The binary representation of %d is ",x); 
	Bin_Print(x);

        return 0;
}


int Bit_Count(unsigned int x)
 {
	/*
	* Summary:
	* This function calculates how many bits of a number are equal to one using bitwise operators.
	* 
	* Aruguments:
	* x - (Unsigned INT type): The integer given by the user.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	* bit_cnt - (INT type): Used to count how many 1`s are in an unsigned integer number.
	* one_on_LSB - (INT type): 1 in decimal. used as the mask. even_num & 1 == 0, odd_num & 1 == 1.
	* 
	* Returns:
	* bit_cnt - (INT type): How many 1`s are in the number x.
	*/
	int i, bit_cnt = 0;
	int one_on_LSB = 1;// The mask, 0...01.

	for (i=0;i<32;i++){ // An unsigned bit contains 32 bits.
		if (x & 1 == 1){ //  With no.1 we can check if the LSB is 1|0. if the LSB is 1 we`ll recieve the value 1 and if it`s 0 we`ll recieve 0.
			bit_cnt++;
		}
		x = x >> 1; // Moving once to the right. Equivalent to dividing by two.
	}
	return bit_cnt; // Finished calculating if any of the bits is 1|0.
 }




void Bin_Print(unsigned int x)   
 {
	/*
	* Summary:
	* This function`s used to print the number x in binary format.
	* 
	* Arguments:
	* x - (INT type): Contains the number given by the user.
	* 
	* Variables:
	* i - (INT type): Used for iteration.
	* one_on_MSB - (Unsigned INT type): The mask, contains 1 only on the leftmost bit.
	* 
	* Prints:
	* The number in binary format.
	*/
	int i;
	unsigned int one_on_MSB = 2147483648;

	for (i = 0;i < 32;i++) { // One increment for each bit.
		if ((x & one_on_MSB) == 2147483648) { // MSB is equal to 1.
			printf("1");
		}
		else {
			printf("0");
		}
		x = x << 1; // Moving once to the left.
	}
 }
