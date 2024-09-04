
/* part 1 
#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	int num_square = 2;
	int num_cubed = 3;
	printf("Enter number: ");
	scanf("%d", &x);
	printf("\n");

	int res_square = pow(x, num_square);
	int res_cubed = pow(x, num_cubed);

	printf("number \tsquare \tcubed\n");
	printf("%3d %8d %7d\n", x, res_square, res_cubed);

	x++;
	res_square = pow(x, num_square);
	res_cubed = pow(x, num_cubed);
	printf("%3d %8d %7d\n", x, res_square, res_cubed);

	x++;
	res_square = pow(x, num_square);
	res_cubed = pow(x, num_cubed);
	printf("%3d %8d %7d\n", x, res_square, res_cubed);

	x++;
	res_square = pow(x, num_square);
	res_cubed = pow(x, num_cubed);
	printf("%3d %8d %7d\n", x, res_square, res_cubed);

	x++;
	res_square = pow(x, num_square);
	res_cubed = pow(x, num_cubed);
	printf("%3d %8d %7d\n", x, res_square, res_cubed);
	return 0;
}
*/



/* part 2
#include <stdio.h>
int main()
{
	float len_side;
	float height_triangle;
	printf("Enter a triangle edge and its height respectively, please: ");
	scanf("%f%f", &len_side, &height_triangle);

	float triangle_area;
	triangle_area = (len_side * height_triangle) / 2;
	printf("\nThe triangle area is: %.3f", triangle_area);

	return 0;
}
*/

/* part 3 
#include <stdio.h>

int main()
{
	char letter;
	printf("Enter an English lower case letter, Please: ");
	scanf("%c", &letter);
	printf("The ascii code of '%c' is : %d \n", letter, letter);
	letter = letter - 32;
	printf("The ascii code of '%c' is : %d.\n", letter, letter);
	return 0;
}
*/

/* part 4
#include <stdio.h>
#include <math.h>

int main()
{
	float a;
	float b;
	printf("Given the equattion a^x=b \n");
	printf("Enter a and b, repectively please:  ");
	scanf("%f%f", &a, &b);
	printf("x is: %g", (log(b) / log(a)));
	return 0;
}
*/

/* PART 5
#include <stdio.h>
#include <math.h>

int main()
{
	float equation;
	float x;
	printf("Enter x please: ");
	scanf("%f", &x);
	
	equation = x + pow((1.0 / 3.0) * pow(x, 4) + 2 * pow(x, 0.5), (1.0 / 5.0));
	printf("\nOutput using %%lf format with 2 digits after the dot.\n");
	printf("x + (1 /3*x^4+2*x^(1/2))^(1/5)= %.2lf + (1 /3 *%.2lf^4+2*%.2lf^(1/2))^(1/5)=%.2lf\n", x, x, x, equation);
	printf("Output using %%g format:\n");
	printf("x + (1 /3*x^4+2*x^(1/2))^(1/5)= %g + (1 /3 *%g^4+2*%g^(1/2))^(1/5)=%g\n", x, x, x, equation);

	return 0;

}
*/

