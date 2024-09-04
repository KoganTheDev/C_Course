/* PART 1
#include <stdio.h>

void Set_Mid(double x1, double y1, double x2, double y2, double *p_mx, double *p_my);

int main() {
	double x1, y1, x2, y2, p_mx, p_my; // declaring variables

	printf("Please enter 4 values in this order: x1 y1 x2 y2\n");
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	Set_Mid(x1,y1,x2,y2,&p_mx,&p_my);
	printf("The coordinates of the middle point are (%.3lf,%.3lf)", p_mx, p_my);
	return 0;
}

void Set_Mid(double x1, double y1, double x2, double y2, double *p_mx, double *p_my){
	/*
	summary:
	The function takes the coordinates of two points on a 2D axis and calculates the value
	of the middle point between them.

	Variables:
	x1 - x coordinate of the first point.
	y1 - y coordinate of the first point.
	x2 - x coordinate of the second point.
	y2 - y coordinate of the second point.

	\ *p_mx is the pointer of the variable which stores the x coordinate of the middle point.
	\ *p_my is the pointer of the variable which stores the y coordinate of the middle point.

	Returns:
	The function doesn`t return a value but changes values within the main function.
	

	*p_mx = (x1+x2)/2;
	*p_my = (y1+y2)/2;
}
*/

#include <stdio.h>

int InputThree(int *p1, int *p2, int *p3);
void SortTwo(int *p1, int *p2);
void SortThree(int *p1, int *p2, int *p3);

int main(){
	int p1, p2, p3;

	while ((InputThree(&p1, &p2, &p3) == 1)) {
		SortThree(&p1, &p2, &p3);
		printf("Sorted values: %d, %d, %d\n", p1, p2, p3);
	}

	printf("FINISH");
	return 0;
}

int InputThree(int *p1, int *p2, int *p3){
	/*
	Summary:
	This function asks for 3 integers from the user and than enters them into predetermined
	variables.
	
	Varibales:
	p1,p2,p3 are Pointer Type variables.

	Returns:
	1 if successful, 0 otherwise
	*/
	printf("Input 3 integer values: ");
	if (scanf("%d %d %d",p1,p2,p3) == 3){ 
		return 1;
	}
	else{
		return 0;
	}
}

void SortTwo(int *p1, int *p2){
	/*
	Summary:
	This function checks the variable in two given memory locations using pointers.
	it sorts the variables in a way that causes the result to be like this:
	In variable p1- The smaller value will be inserted.
	In variable p2- The larger value will be inserted.

	variables:
	p1 (type- Pointer int): Used to access the value in the variable p1.
	p2 (type- Pointer int): Used to access the value in the variable p2.
	*/
	int temp; // Variable that`s used for the exchange between the values.

	if (*p1 > *p2){
		temp = *p2;
		*p2 = *p1;
		*p1 = temp;
	}
}

void SortThree(int* p1, int* p2, int* p3) {
	/* 
	* Summary:
	* This function sorts 3 different variables by only using the function SortTwo.
	* The first part of the function is sorting using the first value in the order.
	* The second part of the function is sorting the values using the last value in the order.
	*/

	SortTwo(p1, p2); // sort first two values
	SortTwo(p2, p3);
	SortTwo(p1, p2); // sort again to ensure the first two are in the correct order

	SortTwo(p2, p3); // compare third value with second and third values
	SortTwo(p1, p2);
	SortTwo(p2, p3);
}