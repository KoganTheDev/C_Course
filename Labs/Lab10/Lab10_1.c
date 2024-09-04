#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Error_Msg(char* str);

int main()
{
	FILE* in, * out;
	char name[7], department[5], grade_1[4], grade_2[4]; // Variables that will be used to store information on each iteration. Extra space for '/0'
	int num1, num2; // Used to grab the grades after using atoi.


	if ((in = fopen("Students.txt", "r")) == NULL)
		Error_Msg("The input file is wrong");
	if ((out = fopen("StudentsNew.txt", "w")) == NULL)
		Error_Msg("The output file is wrong");

	while (fgets(name, 7, in) != NULL) {
		fgets(department, 5, in);
		fgets(grade_1, 4, in);
		fgets(grade_2, 4, in);

		if (strcmp(department, "Comp") == 0) { // Didn`t get to the end of the file and recieved a name from the computer science department.
			num1 = atoi(grade_1); // Using atoi to convert the grades from string into integers.
			num2 = atoi(grade_2);
			fprintf(out, "%s %.1f\n", name, (num1 + num2) / 2.0);
		}
	}
	fclose(in);
    fclose(out);
    return 0;
}


void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}




