/* PART 1 
#include <stdio.h>
#include <math.h>

int main() {

	int weight, height;
	float bmi, height_in_cm; 

	printf("Please enter weight (in kg) and height (in cm), respectively: ");
	scanf("%d %d", &weight, &height);
	height_in_cm = (float) height / 100;
	bmi = weight / pow(height_in_cm,2);

	if (bmi < 18.5){
		printf("Underweight");
	}
	else if (bmi >= 18.5 && bmi < 25.0){
		printf("Normal weight");
	}
	else if (bmi >= 25.0 && bmi < 30.0){
		printf("Increased weight");
	}
	else if (bmi >= 30.0 && bmi < 40.0){
		printf("Obese");
	}
	else if (bmi >= 40.0){
		printf("Very high obese");
	}
	
	return 0;
}
*/

/*PART 2 
#include <stdio.h>

int num;
int counter = 0;

int main(){
	printf("Enter an integer number, please: ");
	scanf("%d",&num);

	if (num > 0){ //regular case for natural numbers
		for (int i = 1; i<(num-1); i++){
			if (num%i == 0){ // check if the number is diviseable by i.
				printf("%d ",i);
				counter++;
			}
		}
	}
	else { // A case for negative numbers
		for (int i = 1; i <= (num*(-1)); i++){
			if (num%i == 0){
				printf("%d ",i);
				counter++;
			}
		}
	}
	
	if (num == 0){ // Checking for a special case,0, which has infinite amount of divisors
		printf("infinity");
	}
	else { // case for all of the other numbers other than 0.
		printf("\ncount=%d",counter);
	}
	return 0;
}
*/

/* PART 3 
#include <stdio.h>

void f(char, int);
int n;
char ch;

int main() {
    printf("Enter a character and an integer, please: ");
    scanf("%c %d", &ch, &n);
    f(ch, n);
    return 0;
}

void f(char ch, int n) {
	int column = n; //declaring variables

	for (int j = 1; j <= n; j++){
		for (int i = 1; i <= column ; i++) {
			if (i == column) {
				printf("%c\n", ch);
			}
			else {
				printf("%c", ch);
			}
		}
	column--; // This var is used for creating the columns
	}
}
*/

/* PART 4 

#include <stdio.h>
#include <math.h>

int main(){
	char chr = 0;
	int num1, num2;

	printf("\tLegend:\n'A' or 'a'- Average\n'*'- Multiply\n'm'- Minimum\n'M'- Maximum\n'^'- Power\n'Q' or 'q'- Quit\n\nEnter a character please: ");
	scanf("%c", &chr);

	if (chr == 'q' || chr == 'Q'){
		printf("\n\tFINISH\n");
	}

	while (!(chr == 'q' || chr == 'Q')) { 

		switch (chr) {
			case 'a': case 'A':
				printf("Enter two numbers to get their average: ");
			 	scanf("%d %d", &num1, &num2);
			 	printf("The average of %d and %d is %.1f\n", num1,num2, (num1+num2)/2.0);
				break;
			case '*':
				printf("Enter two numbers to get the result of their multiplication: ");
				scanf("%d %d",&num1, &num2);
				printf("The result of %d*%d is %d\n", num1,num2,(num1*num2));
				break;
			case 'm':
				printf("Enter two numbers to check which one is smaller: ");
				scanf("%d %d",&num1,&num2);
				if (num1 > num2){
					printf("%d is smaller than %d\n", num2,num1);
				}
				else if (num2 > num1){
					printf("%d is smaller than %d\n", num1,num2);
				}
				else{
					printf("%d is equal to %d\n", num1,num2);
				}
				break;
			case 'M':
				printf("Enter two numbers to check which one is bigger: ");
				scanf("%d %d",&num1,&num2);
				if (num1 > num2){
					printf("%d is bigger than %d\n", num1,num2);
				}
				else if (num2 > num1){
					printf("%d is bigger than %d\n", num2,num1);
				}
				else{
					printf("%d is equal to %d\n", num1,num2);
				}
				break;
			case '^':
				printf("Enter two numbers to get the result of num1^num2 respectivley: ");
				scanf("%d %d", &num1, &num2);
				if (num2 >= 0){
					printf("The result of %d^%d is %.0lf\n", num1,num2, pow(num1, num2));
				} 
				else if (num2 < 0){
					printf("The result of %d^%d is %.4lf\n", num1, num2, (1 / pow(num1, abs(num2))));
				}
				break;	
			default: 
				printf("\tError\n");
		}

		printf("\n\tLegend:\n'A' or 'a'- Average\n'*'- Multiply\n'm'- Minimum\n'M'- Maximum\n'^'- Power\n'Q' or 'q'- Quit\n\nEnter a character please: ");
		rewind(stdin);
		scanf("%c", &chr);

		if (chr == 'q' || chr == 'Q') {
			printf("\n\tFINISH\n");
		}
	}
	return 0;
}

*/


 
