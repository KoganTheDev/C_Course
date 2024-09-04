#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct student {
	char* name;
	long id;
	float CS_grade;
	char exercises[6]; // Recieves a string of binary charaters. Up to 5 characters and one extra for '\0'.
	char final_grade;
}Student;

typedef struct university {
	Student* arr;
	int size;
}University;


University* option1_input(FILE* in);
int option2_output(FILE* out, University* university);
int option3_calculate_grade(FILE* out, University* university);
int option4_output_statistics(FILE* out, University* university);
int option5_output_students_above_avg(FILE* out, University* university);
void option6_end_running(FILE* out);
int show_menu(FILE* out, University* university);

int main() {
	FILE* in;
	FILE* out;
	University* university;

	if ((in = fopen("input.txt", "r")) == NULL) {
		printf("File pointer failed to connect to the text file.");
		exit(1);
	}

	printf("Initializing Option 1 - Recieving the information of the students from the file \"input.txt\"\n\n");

	university = option1_input(in);
	printf("Option 1 COMPLETED.\n");

	fclose(in); // Recieved the input and there`s no need for the input file to stay open.

	if ((out = fopen("output.txt", "w")) == NULL) {
		printf("File pointer failed to create and connect to the new text file");
		exit(1);
	}


	if (show_menu(out, university) == 6) {
		printf("\n\nYou picked to exit the program and the only output in the file is \"End Of Program\".\n"
			"\n\t\t****Thank you for your cooperation****\n");
	}
	else {
		while (1) {
			if (show_menu(out, university) == 6) {
				printf("\n\nThe program finished running.\n\n\t\t****Thank you for your cooperation****\n");
				break;
			}
		}
	}

	fclose(out);
	
	return 0;
}

int show_menu(FILE* out, University* university) {
	/*
	* Summary:
	* This function is used to control the flow of the program, when needed it calls the function the user`s looking for.
	*
	* Arguments:
	* out - (FILE  pointer type): Used to send the file to the other functions.
	* university - (University type pointer): Used to send the structure 'university' into the relevant functions.
	*
	* Variables:
	* i - (INT type): Used for iteration.
	* option - (Char type): Contains the option picked from the user.
	*
	* Prints:
	* The menu accordingly to the instruction given as well as if any function succeded running or failed.
	*
	* Returns:
	* 0 - For the usual functions and to keep on running.
	* 6 - To flag that its time to end the runtime of the program.
	*/
	int i;
	char option;

	printf("\n._______________________________________________________________.\n"
		"|\t\t   _____ Menu ____                              |\n|\t\t\t\t\t\t\t        |\n"
		"|\tOption 2 - Output information into \"output.txt\".     \t|\n"
		"|\tOption 3 - Calculate the final grade.\t\t     \t|\n"
		"|\tOption 4 - Show statistics for the exam grades.\t\t|\n"
		"|\tOption 5 - Show which students are above the average.\t|\n"
		"|\tOption 6 - Exit.\t\t\t\t\t|\n"
		"|_______________________________________________________________|\n\n"
		"Please enter an integer that represent the option you want to pick from 2-6:\n");


	if (scanf(" %c", &option) != 1) { // Input check.
		printf("\n A failed attempt occurred when the function tried to pick the value from the user. ");

		for (i = 0;i < university->size;i++) { // Release memory allocated in case of failure.
			free(university->arr[i].name);
		}
		free(university->arr); // Release the dynamically allocated array of students.
		exit(1);
	}

	if (option > '6') { // Special case, the user can enter a double digit and it will take the 'ones'. This takes care of it.
		printf("\nPlease enter a valid input.\nAn integer from 2-6\n");
		return 0; // Exit in advance to the user can re-enter new value.
	}

	switch (option)
	{
	case '2':
		printf("\nInitializing Option 2 - Output student`s data.\n");
		if (option2_output(out, university) == 0) {
			printf("\nOption 2 COMPLETED.\n");
		}
		else {
			printf("\nOption 2 FAILED.\n");

			for (i = 0;i < university->size;i++) { // Release memory allocated in case of failure.
				free(university->arr[i].name);
			}
			free(university->arr);
			exit(1);
		}
		break;

	case '3':
		printf("\nInitializing Option 3 - Output student`s data.\n");
		if (option3_calculate_grade(out, university) == 0) {
			printf("\nOption 3 COMPLETED\n");
		}
		else {
			printf("\nOption 3 FAILED\n");

			for (i = 0;i < university->size;i++) { // Release memory allocated in case of failure.
				free(university->arr[i].name);
			}
			free(university->arr);
			exit(1);
		}
		break;

	case '4':
		printf("\nInitializing Option 4 - Output statistical information.\n");
		if (option4_output_statistics(out, university) == 0) {
			printf("\nOption 4 COMPLETED\n");
		}
		else {
			printf("\nOption 4 FAILED\n");

			for (i = 0;i < university->size;i++) { // Release memory allocated in case of failure.
				free(university->arr[i].name);
			}
			free(university->arr); // Release the dynamically allocated array of students.
			exit(1);
		}
		break;

	case '5':
		printf("\nInitializing Option 5 - Output students that their grade is above average.\n");
		if (option5_output_students_above_avg(out, university) == 0) {
			printf("\nOption 5 COMPLETED\n");
		}
		else {
			printf("\nOption 5 FAILED\n");

			for (i = 0;i < university->size;i++) { // Release memory allocated in case of failure.
				free(university->arr[i].name);
			}
			free(university->arr);
			exit(1);
		}
		break;

	case '6':
		printf("\nInitializing Option 6 - Finish running the program.\n");

		option6_end_running(out);

		for (i = 0;i < university->size;i++) { //  Finish running altogether and release all of the dynamically allocated memory.
			free(university->arr[i].name);
		}
		free(university->arr);

		return 6;

	default:
		printf("\nPlease enter a valid input.\nAn integer from 2-6\n");
		break;
	}
	return 0;
}

void option6_end_running(FILE* out) {
	/*
	* Summary:
	* This function prints "End Of Program" in the output file.
	*
	* Arguments:
	* out - (FILE pointer type): Used as the location in which the output will be printed.
	*
	* Prints:
	* A specific line "End Of Program" to the output file.
	*/
	fprintf(out, "\nOPTION 6:\n\nEnd Of Program.");
}

University* option1_input(FILE* in) {
	/*
	* Summary:
	* This function recieves input from a file and then enters that data into a University structure that contains information of students.
	*
	* Arguments:
	* in - (FILE type pointer): Used to recieve input from the file "input.txt".
	*
	* Variables:
	* i - (INT type): Used for iteration and at the same time represents how many students are contained in the array of students in 'university'.
	* name_temp - (Char type pointer): Used for memory reallocation.
	* student_temp - (Student type pointer): Used for memory reallocation.
	* university - (University type pointer): Contains the address of the university structure.
	*
	* Returns:
	* university - (University type pointer): Contains the address of the universsity which has the information about the students.
	*/
	int i = 1; // Used for iteration to count how many students are in the university in the same time.
	Student* student_temp = NULL; // Used to reallocate the array when there`s an extra student that the program will have to enter into the array (arr) of universty.
	University* university = (University*)malloc(sizeof(University));
	char* name_temp = (char*)malloc(100 * sizeof(char)); // Used to reallocate the name of the student

	if (university == NULL) {
		printf("\nAllocating memory for the structure 'university' has failed.\n");
		exit(1);
	}

	if (name_temp == NULL) {
		printf("\nAllocating memory to name_temp has failed.\n");
		exit(1);
	}

	university->arr = (Student*)malloc(sizeof(Student)); // Opens one element in the array to contain one student
	if (university->arr == NULL) { // Input check
		printf("\nCreating the array in the university stracture has failed.");
		exit(1);
	}

	while (fscanf(in, "%s %ld %f %s", name_temp, &university->arr[i - 1].id, &university->arr[i - 1].CS_grade, &university->arr[i - 1].exercises) != EOF) {
		university->arr[i - 1].name = (char*)malloc((strlen(name_temp) + 1) * sizeof(char)); // Reallocates the name into an actual place that stores the exact amount of characters.
		if (university->arr[i - 1].name == NULL) {
			printf("\nThe program failed to reallocate the name of the student in the university structure.");
			for (;i - 1 >= 0;i--) { // Free everything.
				free(university->arr[i - 1].name);
			}
			free(university->arr);
			exit(1);
		}

		strcpy(university->arr[i - 1].name, name_temp);


		i++; // Incrementing i by one so the program will be able to open a new location for another Student type element.

		student_temp = (Student*)realloc(university->arr, (i * sizeof(Student)));
		if (student_temp == NULL) { // Memory allocation check.
			printf("\nThe program failed to reallocate the array into the new location.");
			for (;i - 1 >= 0;i--) {
				free(university->arr[i - 1].name);
			}
			free(university->arr);
			exit(1);
		}

		university->arr = student_temp;
		university->size = i - 1; // Inserts the size of the array of students.
	}

	free(name_temp);
	return university;
}

int option2_output(FILE* out, University* university) {
	/*
	* Summary:
	* This function prints the information from the 'university' structure into the output file.
	*
	* Arguments:
	* out - (FILE type pointer): The file the output will be printed to.
	* university - (University type pointer): Contains the array from which the information will be printed.
	*
	* Variables:
	* i - (INT type): Used for iteration.
	* j - (INT type): Used for iteration.
	* exercise_cntr - (INT type): Used to count how many exercises each students sent.
	*
	* Prints:
	* The information about each student.
	*
	* Returns:
	* 0 - Whenever the function did good and completed its running time.
	*/
	int i, j, exercise_cntr;

	fprintf(out, "OPTION 2:\n\n");

	for (i = 0;i < university->size;i++) {
		exercise_cntr = 0; // Reset the counter on each iteration.
		for (j = 0; j < 5;j++) { // Inner loop used to check if the student commited 3 exercises or more.
			if (university->arr[i].exercises[j] == '1') {
				exercise_cntr++;
			}
		}

		if (exercise_cntr >= 3) {
			university->arr[i].final_grade = '1';
			fprintf(out, "Student %d: %s %ld %.2f 1\n", (i + 1), university->arr[i].name, university->arr[i].id, university->arr[i].CS_grade);
		}
		else {
			university->arr[i].final_grade = '0';
			fprintf(out, "Student %d: %s %ld %.2f 0\n", (i + 1), university->arr[i].name, university->arr[i].id, university->arr[i].CS_grade);
		}
	}

	fprintf(out, "______________________________________________________________________________________________\n");
	return 0; // Function succeeded
}

int option3_calculate_grade(FILE* out, University* university) {
	/*
	* Summary:
	* This function prints the information of the student before and after they got the change in their grade if they sent enough assignments and their grade is above or equal to 55
	* overwise the function prints the same grade for the updated grade the student got.
	*
	* Aarguments:
	* out - (FILE type pointer): The file to which the output will be printed to.
	* university - (University type pointer): Represents a data base of an university, contains information about students.
	*
	*
	* Variables:
	* i - (INT type): Used for iteraion.
	* j - (INT type): Used for iteraion.
	* exercise_cntr - (INT type): Used to count how many assignments each student sent.
	*
	* Prints:
	* The information of each student both before and after their final grade was calculated.
	*
	* Returns:
	* 0 - If the function finished running its tasks successfully.	.
	*/
	int i, j, exercise_cntr;

	fprintf(out, "OPTION 3:\n\n\tBEFORE:\n");

	for (i = 0;i < university->size;i++) { // This loop only prints the values in the same way option 2 does, in case the user calls this one before option 2, it`ll update the final grade for each student.
		exercise_cntr = 0;
		for (j = 0;j < 5;j++) {
			if (university->arr[i].exercises[j] == '1') {
				exercise_cntr++;
			}
		}

		if (exercise_cntr >= 3) {
			university->arr[i].final_grade = '1';
			fprintf(out, "Student %d: %s %ld %.2f 1\n", (i + 1), university->arr[i].name, university->arr[i].id, university->arr[i].CS_grade);
		}
		else {
			university->arr[i].final_grade = '0';
			fprintf(out, "Student %d: %s %ld %.2f 0\n", (i + 1), university->arr[i].name, university->arr[i].id, university->arr[i].CS_grade);
		}
	}

	fprintf(out, "\n\tAFTER:\n");
	for (i = 0;i < university->size;i++) { // This loop prints the information of the student with the updated grade as well as the information of the student.
		if (university->arr[i].final_grade == '1' && university->arr[i].CS_grade >= 55) {
			fprintf(out, "Student %d: %s %ld %.2f 1 final: %.2f\n", (i + 1), university->arr[i].name, university->arr[i].id, university->arr[i].CS_grade, (15.0 + university->arr[i].CS_grade * (85.0 / 100.0)));
		}
		else {
			fprintf(out, "Student %d: %s %ld %.2f 0 final %.2f\n", (i + 1), university->arr[i].name, university->arr[i].id, university->arr[i].CS_grade, university->arr[i].CS_grade);
		}
	}

	fprintf(out, "______________________________________________________________________________________________\n");
	return 0;
}

int option4_output_statistics(FILE* out, University* university) {
	/*
	* Summary:
	* This function calculates statistical information and then prints it to the output file.
	*
	* Arguments:
	* out - (FILE type pointer): The file the output will be printed to.
	* university - (University type structure): Contains an array that has the information of the students.
	*
	*
	* Variables:
	* i - (INT type): Used for iteration.
	* SD - (Double type): Represetns the standart deviation of the grades.
	* min_gradeCS - (Float type): Contains the lowest grade among the grades of the students.
	* max_gradeCS - (Float type): Contains the highest grade among the grades of the students.
	* average - (Float type): Represents the average of the grades.
	*
	* Prints:
	* The average, standard deviation, how many students are in the university and the range of grades.
	*
	* Returns:
	* 0 - When the function finishes running.
	*/
	int i;
	double SD = 0; // Standard Deviation
	float min_gradeCS = 100, max_gradeCS = 0, average = 0;

	fprintf(out, "OPTION 4:\n\n");

	for (i = 0; i < university->size;i++) {
		average += university->arr[i].CS_grade; // Sums the grades
	}
	average /= university->size; // now the varible average truly contains the average of the grades.

	for (i = 0;i < university->size;i++) { // Used to calculate the standard deviation.
		SD += pow(((double)university->arr[i].CS_grade - (double)average), 2);
	}
	SD = sqrt(SD / university->size);

	for (i = 0;i < university->size;i++) { // Grabs the lowest and highest grades.
		if (university->arr[i].CS_grade < min_gradeCS) {
			min_gradeCS = university->arr[i].CS_grade;
		}
		if (university->arr[i].CS_grade > max_gradeCS) {
			max_gradeCS = university->arr[i].CS_grade;
		}
	}

	fprintf(out, "The average of the grade of the students in CS is - (%.2f).\n"
		"--------------------------------------------------------\n"
		"The standard deviation is %.3lf.\n"
		"--------------------------------------------------------\n"
		"There are %d students in the university.\n"
		"--------------------------------------------------------\n"
		"The range of the grades is [%.2f - %.2f]\n\n", average, SD, university->size, min_gradeCS, max_gradeCS);

	fprintf(out, "______________________________________________________________________________________________\n");
	return 0;
}

int option5_output_students_above_avg(FILE* out, University* university) {
	/*
	* Summary:
	* This function prints the name and ID of each student who`s grade is higher than the average grade.
	*
	* Arguments:
	* out - (FILE type pointer): Where the output will be printed.
	* university - (University type pointer): Contains all of the information of the students.
	*
	* Variables:
	* i - (INT type): Used for iteration.
	* average (Float type): Contains the average grade of all of the students.
	*
	* Prints:
	* The name and the ID of each student who`s a higher grade than the average one.
	*
	* Returns:
	* 0 - When the function completed its runtime.
	*/

	int i;
	float average = 0;

	fprintf(out, "OPTION 5:\n\n");

	for (i = 0;i < university->size;i++) { // Sums the grades.
		average += university->arr[i].CS_grade;
	}

	average /= university->size;

	for (i = 0; i < university->size;i++) {
		if (university->arr[i].CS_grade > average) {
			fprintf(out, "%s %ld\n", university->arr[i].name, university->arr[i].id);
		}
	}
	fprintf(out, "______________________________________________________________________________________________\n");

	return 0; // The function succeded.
}
