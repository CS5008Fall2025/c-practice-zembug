/**
 * Student Name: Emily Despres
 * Semester: Fall 2025
 * 
 * C Practice
 * This assignment is to help you practice using C. Is is setup to
 * a set of various functions that tests the ideas you are learning.
 * 
 * In addition to this file, you will need to create a test file, that tests
 * every function!
 * 
 * This is called a 'header' library, meaning it is a collection of functions
 * that can be used in other files. This is the standard way of creating
 * libraries in C. In this case, the functions are implemented in the header file (.h)
 * but sometimes they are separated between header declarations (.h) and source files (.c)
 * which you will explore in other assignments. 
*/

#ifndef C_PRACTICE_H
#define C_PRACTICE_H

#include <stdio.h> // basic input and output
#include <stdlib.h> // standard library

/**
 * Basic struct to hold two coordinates
*/
typedef struct {
    int x;
    int y;
} Point;


/**
 * Basic struct to hold a list of points - this list could be a polygon, 
 * but no checking for complexity is done.
*/
typedef struct {
    Point **points;
    int size;
} Polygon;


/**
 * Swaps the values of a and b. Makes use of pointers to change the values
 * of the variables in the calling function. 
**/
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Prints an array of integers to the screen. Has a space after each value, and new line at the end
 * so an array of [1, 3, 2] would be
 * 1 3 2 
 * (notice there is a hidden space at the end of the 2 before the \n )
*/
void print_array(int *arr, int size)
{
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Creates an array based on the fibonacci sequence.
 * The size is the number of elements in the array.
 *
 * For example, if size is 5, then the array should be [1, 1, 2, 3, 5]
 * if the size is 1, then the array should be [1]
 * if the size is <= 0, then NULL should be returned.
 *
 * As a reminder, the fibonacci sequence is:
 * is the value of the two previous values added together.
 *
 * So the first two values [0], [1] are 1, 1.
 * The third value is 1 + 1 = 2
 * The fourth value is 1 + 2 = 3
 * The fifth value is 2 + 3 = 5
 *
 * This means, you can set the first two values of the array to 1, 1,
 * and then start your loop forward.
 *
 * You can assume the size is less than 95, so you don't have to worry about
 * integer overflow.
 *
 * here is a quick list of numbers: https://www.math.net/list-of-fibonacci-numbers
 **/
int* create_array_of_ints_fib(int size){
    if (size <= 0) { // check for input validation
        return NULL;
    }

    int* arr = (int*)malloc(size * sizeof(int)); // allocate memory for the array
    if (!arr) return NULL; // check for malloc failure

    arr[0] = 1; // first Fibonacci number is 1
    if (size > 1) { // if size is greater than 1, set the second Fibonacci number
        arr[1] = 1; // second Fibonacci number is also 1
        for (int i = 2; i < size; i++) { // start loop from the third element
            arr[i] = arr[i - 1] + arr[i - 2]; // each number is the sum of the two preceding ones
        }
    }
    return arr; // return the pointer to the array
}


/**
 * Reverses an array *in place* (meaning you don't copy into another array)
 * 
 * For example, if the array is [1, 2, 3, 4, 5] then the array should be
 * [5, 4, 3, 2, 1]
 * 
 * To receive full points, you should only loop through *half* of the array. (size/2). 
 * Consider using swap. 
*/
void reverse_array(int *arr, int size){
    for (int i = 0; i < size / 2; i++) { // loop through half the array (to not undo swap)
        swap(&arr[i], &arr[size - i - 1]); // swap the elements
    }
}


 
/**
 * Doubles the size of an array, and copies all previous values into the new array.
 * All other values should be set to 0. Returns a pointer to the new array
 * 
 * You may want to look at calloc to help with this, to confirm all values are set to 0.
 * though you don't have to, if you want to loop through and set them to 0 yourself.
 * 
*/
int* double_array_size(int *arr, int size){
    if (size <= 0 || arr == NULL) {
        return NULL; // handle invalid size
    }

    int* new_arr = (int*)calloc(size * 2, sizeof(int)); // allocate memory for the new array and initialize to 0
    if (!new_arr) return NULL; // check for allocation failure

    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i]; // copy old values to new array
    }
    return new_arr; // return the new array
}

/**
 * Copies elements of an array from start to end (inclusive) into a new array.
 *
 * Returns the new array. However, if end is less than start, it loops around copying
 * elements from the beginning of the array.. (thus picture your array as a circle).
 *
 * if start or end are invalid (less than 0, or greater than or equal to size), then
 * return NULL.
 *
 * Example: assume an array is [1, 2, 3, 4, 5]
 * if make start = 1, and end = 3, then the new array should be [2, 3, 4]
 * if make start = 3, and end = 1, then the new array should be [4, 5, 1, 2]
 *
 * Notice, new_size is a pointer, so you can set the size of the new array in your function. This
 * is commonly done in C, as a way to have multiple return values. (both the return, and the modified parameter)
 *
 * In the two examples above, new_size would be set to 3, and then 4 respectively.
 *
 * You will want to remember pointer arithmetic here. You can't say something like new_size = steps (where steps
 * is your new calculated size based on start to end), instead you have to say *new_size = steps+1)
 *
 * Make sure to test this function, this is probably the hardest of the batch, and easy
 * to get an OB1 error!
 */
int* copy_array_start_end_loop(int *arr, int size, int start, int end, int *new_size) {
    if (start < 0 || end < 0 || start >= size || end >= size) { // validate indices
        return NULL; // handle invalid indices
    }

    int steps;
    if (end >= start) {
        steps = end - start + 1; // calculate number of elements to copy
    } else {
        steps = (size - start) + (end + 1); // wrap around case
    }

    int* new_arr = (int*)malloc(steps * sizeof(int)); // allocate memory for the new array
    if (!new_arr) return NULL; // check for allocation failure

    for (int i = 0; i < steps; i++) {
        new_arr[i] = arr[(start + i) % size]; // copy elements, wrapping around using modulo
    }

    *new_size = steps; // set the new size
    return new_arr; // return the new array
}

/* 
Practice with struts 
*/

/**
 * Creates a point with the given x and y values. Allocates it on the heap. (malloc)
 * and returns the new point
*/
Point* create_point(int x, int y){
    Point* p = (Point*)malloc(sizeof(Point)); // allocate memory for the point
    if (!p) return NULL; // check for allocation failure
    p->x = x; // set x value
    p->y = y; // set y value
    return p; // return the new point
}

/**
 * Creates a polygon with the given size. Allocates it on the heap. (malloc)
 * and returns the new polygon
 * 
 * For the points, you are creating the array of points, but you do not have to allocate
 * the point values. it is just a polygon of eventual size, and an array of empty points. 
*/
Polygon* create_polygon(int size){
    Polygon* create_polygon(int size); // allocate memory for the polygon
    Polygon* p = (Polygon*)malloc(sizeof(Polygon)); // allocate memory for the polygon
    if (!p) return NULL; // check for allocation failure
    p -> size = size; // set the size
    p -> points = (Point**)malloc(sizeof(Point*) * size); // allocate memory for the array of point pointers
    return p; // return the new polygon
}


/**
 * Frees the memory used by the polygon, make sure to loop through
 * all the points, to free them, free the array, and then free the polygon itself.
*/
void free_polygon(Polygon *p){
    for (int i = 0; i < p->size; i++) {
        free(p->points[i]); // free each point
    }
    free(p->points); // free the array of point pointers
    free(p); // free the polygon itself
}

/**
 * Creates a rectangle of width and height, using the polygon struct and returns it.
 * 
 * You can assume the following order of points
 * 0, 0
 * width, 0
 * width, height
 * 0, height
*/
Polygon* create_rectangle(int width, int height){
    return NULL;
}


/**
 * Creates a (right) triangle of width and height, using the polygon struct and returns it.
 * 
 * You can assume the following order of points
 * 0, 0
 * width, 0
 * width, height
*/
Polygon* create_triangle(int width, int height){
    return NULL;
}

/**
 * Prints the point in the format "(x, y) "
*/
void print_point(Point *p){
    printf("(%d, %d)", p->x, p->y);
}

/**
 * Prints the polygon in the format "(x, y) (x, y) (x, y) \n"
*/
void print_polygon(Polygon *p){
    for(int i = 0; i < p->size; i++){
        print_point(p->points[i]);
        printf(" ");
    }
    printf("\n");
}

/**
 * Calculates the area of the polygon using the shoestring formula.
 * 
 * The shoestring formula will loop through every point, and calculates the area by
 * 
 * area +=  i->x * i+1->y - i+1->x * i->y
 * 
 * however, when i+1 is greater than size, you will need to loop back around to the beginning (so think of
 * setting i+1 to j, where j= (i+1) % p->size before running the calculations)
 * 
 * after area is summed across all points, divide by 2.0 and return the area.
*/
double calculate_polygon_area(Polygon *p){
    return 0.0;
}

#endif // C_PRACTICE_H

