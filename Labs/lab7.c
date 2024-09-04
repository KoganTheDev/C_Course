/* 
#include <stdio.h>


typedef struct point { // Point on an x,y graph
    float x;
    float y;
} point;

typedef struct circle {
    point center;
    float radius;
} circle;

int is_in_circle(point, circle);

int main() {
    point a; // declaring a stracture type variable.
    circle circle1;

    printf("Enter the coordinates of your point: ");
    if (scanf("%f %f", &a.x, &a.y) != 2) { // Gathers input from the user and puts it in the stracture a1.
        return 1;
    }
    printf("\nEnter the radius and the center of your circle: ");
    if (scanf("%f %f %f", &circle1.radius, &circle1.center.x, &circle1.center.y) != 3) {
        return 1;
    }

    if (is_in_circle(a, circle1) == 1) { // The point is within.
        printf("\nThe point is included in the circle.\n");
    }
    else { // The function returns 0 - aka "False"
        printf("\nThe point in not included in the circle.\n");
    }
    return 0;
}

int is_in_circle(point point1 , circle circle1) {
    /*
    * Summary:
    * This function recieves a point (x,y coordinates) and a circle (circle`s radius and its center coordintates) and it checks if the point is
    * actually within the circle.
    * Arguments:
    * point1 - (Structure type) : Resembles a point on an (x,y) graph that the user enters in the main function.
    * circle1 - (Stracture type) : Resembles a circle. This argument contains the radius of the circle and the coordinates (x,y) of the middle point.
    * 
    * Returns:
    * 1 - (True): If the point is whithin the circle or on its circumference.
    * 0 - (False): If the point is outside the circle.
    *
    if ((double)((point1.x - circle1.center.x )* (point1.x - circle1.center.x)) + (double)((circle1.center.y - point1.y)* (circle1.center.y - point1.y)) < (double) (circle1.radius*circle1.radius)) { // Calculates the distance using the pathegoren theorem.
        return 1;
    }
    return 0; // The substraction of the coordinates is larger than the radius, therefore the point is outside the circle or on its borders.
}
*/


/* Q3 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3

typedef struct complex {
    double re; // Real part of the number
    double im; // Imaginary part of the number.
} complex;

double Cradius(complex);
complex* Cmax(complex*, int);

int main() {
    complex arr[N]; // An array of complex number members.
    int i;
    complex* largest = NULL;

    printf("Enter three complex numbers:\n");

    for (i = 0; i < N; i++) {
        if (scanf("%lf %lf", &arr[i].re, &arr[i].im) != 2) { // Input check.
            return 1;
        }
    }

    largest = Cmax(arr, N); // Returns a pointer to the biggest complex number.

    printf("\nThe max complex number is %.2lf+%.2lfi\n", largest->re, largest->im);
    printf("The radius of the max number is %.2lf\n", Cradius(*largest));

    return 0;
}

double Cradius(complex num) {
    /*
    * Summary:
    * This function receives a complex number and returns the radius of the complex number.
    *
    * Arguments:
    * num - (Struct type): represents a complex number which has a real part and an imaginary one.
    *
    * Returns:
    * A double type: The value of the radius of the complex number.
    */
    return sqrt(pow(num.re, 2) + pow(num.im, 2)); // Calculates the length of the radius using the equation sqrt(x^2+y^2).
}

complex* Cmax(complex* arr, int length) {
    /*
    * Summary:
    * This function receives an array of complex numbers and its length and returns the element with the largest radius.
    *
    * Arguments:
    * arr - (Complex type array): An array which contains complex numbers.
    * length - (INT type): Represents the size of the array.
    *
    * Variables:
    * temp_radius - (Double type): Used to store the largest radius at the moment.
    * p - (Complex type pointer): Used to point to the element with the largest radius.
    * i - (INT type): Used for iteration.
    *
    * Returns:
    * p - (Complex type pointer): A pointer to the element with the largest radius.
    */
    double temp_radius = 0; // Initializing a value to compare with the first element.
    complex* p = NULL; // An empty pointer.
    int i;

    for (i = 0; i < length; i++) {
        double radius = Cradius(arr[i]);
        if (radius > temp_radius) {
            temp_radius = radius;
            p = &arr[i];
        }
    }
    return p;
}

