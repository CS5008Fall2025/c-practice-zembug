/**
 * Student Name: Emily Despres
 * Semester: Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib() {
    printf("2. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?
    // everything matched
    return 1;
}

int test_reverse_array() {
    printf("3. test_reverse_array()\n");
    int size = 6; // example size
    int* arr = create_simple_array(size); // creates [0, 1, 2, 3, 4, 5]
    reverse_array(arr, size); // should modify arr to be [5, 4, 3, 2, 1, 0]
    int expected[] = {5, 4, 3, 2, 1, 0}; // expected result
    for (int i = 0; i < size; i++) { // check each element
        if (arr[i] != expected[i]) { // if any element doesn't match
            free(arr); // free allocated memory
            return 0; // test failed
        }
    }
    free(arr); // free allocated memory
    return 1; // all elements matched
}

int test_double_array_size() {
    printf("4. test_double_array_size()\n"); // test label stays the same
    int size = 6; // updated original size
    int* arr = create_simple_array(size); // creates [0, 1, 2, 3, 4, 5]
    int* new_arr = double_array_size(arr, size); // should create [0, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0]
    int expected[] = {0, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0, 0}; // updated expected result
    for (int i = 0; i < size * 2; i++) { // check each element in the new array
        if (new_arr[i] != expected[i]) { // if any element doesn't match
            free(arr); // free original array
            free(new_arr); // free new array
            return 0; // test failed
        }
    }
    free(arr); // free original array
    free(new_arr); // free new array
    return 1; // all elements matched
}

int test_double_array_size_null() {
    printf("5. test_double_array_size_null()\n"); // new test label
    int* new_arr = double_array_size(NULL, 5); // passing NULL should return NULL
    if (new_arr == NULL) { // check if the result is NULL
        return 1; // test passed
    }
    free(new_arr); // free if not NULL to avoid memory leak
    return 0; // test failed
}

int test_double_array_size_negative() {
    printf("6. test_double_array_size_negative()\n"); // new test label
    int* arr = create_simple_array(5); // create a valid array
    int* new_arr = double_array_size(arr, -5); // passing negative size should return NULL
    if (new_arr == NULL) { // check if the result is NULL
        free(arr); // free the original array
        return 1; // test passed
    }
    free(arr); // free the original array
    free(new_arr); // free if not NULL to avoid memory leak
    return 0; // test failed
}

int test_double_array_size_zero() {
    printf("7. test_double_array_size_zero()\n"); // new test label
    int* arr = create_simple_array(5); // create a valid array
    int* new_arr = double_array_size(arr, 0); // passing zero size should return NULL
    if (new_arr == NULL) { // check if the result is NULL
        free(arr); // free the original array
        return 1; // test passed
    }
    free(arr); // free the original array
    free(new_arr); // free if not NULL to avoid memory leak
    return 0; // test failed
}

int test_copy_array_start_end_loop() {
    printf("8. test_copy_array_start_end_loop()\n");
    int size = 10;
    int* arr = create_simple_array(size); // creates [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    int return_size = 0;
    int* new_arr = copy_array_start_end_loop(arr, size, 3, 7, &return_size); // should create [3, 4, 5, 6, 7]
    int expected[] = {3, 4, 5, 6, 7}; // expected result
    if (return_size != 5) { // check if the returned size is correct
        free(arr);
        free(new_arr);
        return 0; // test failed
    }
    for (int i = 0; i < return_size; i++) { // check each element in the new array
        if (new_arr[i] != expected[i]) { // if any element doesn't match
            free(arr); // free original array
            free(new_arr); // free new array
            return 0; // test failed
        }
    }
    free(arr); // free original array
    free(new_arr); // free new array
    return 1; // all elements matched
}

int test_create_point() {
    printf("9. test_create_point()\n");
    int x = 5;
    int y = 10;
    Point* p = create_point(x, y);
    if (p == NULL) {
        return 0; // test failed due to allocation failure
    }
    if (p->x == x && p->y == y) {
        free(p); // free allocated memory
        return 1; // test passed
    }
    free(p); // free allocated memory
    return 0; // test failed
}

int test_create_polygon() {
    printf("10. test_create_polygon()\n");
    int size = 4;
    Polygon* poly = create_polygon(size);
    if (poly == NULL) {
        return 0; // test failed due to allocation failure
    }
    if (poly->size == size && poly->points != NULL) {
        free(poly->points); // free allocated points array
        free(poly); // free allocated polygon
        return 1; // test passed
    }
    free(poly->points); // free allocated points array
    free(poly); // free allocated polygon
    return 0; // test failed
}

int test_free_polygon() {
        printf("11. test_free_polygon()\n");

    Polygon* poly = create_polygon(2);
    if (!poly) return 0;

    // Leave points uninitialized (NULL)
    poly->points[0] = NULL;
    poly->points[1] = NULL;

    // Free the polygon
    free_polygon(poly);

    return 1;
}

int test_create_rectangle() {
    printf("12. test_create_rectangle()\n");
    int width = 5;
    int height = 10;
    Polygon* rect = create_rectangle(width, height);
    if (rect == NULL) {
        return 0; // test failed due to allocation failure
    }
    if (rect->size == 4 &&
        rect->points[0]->x == 0 && rect->points[0]->y == 0 &&
        rect->points[1]->x == width && rect->points[1]->y == 0 &&
        rect->points[2]->x == width && rect->points[2]->y == height &&
        rect->points[3]->x == 0 && rect->points[3]->y == height) {
        free_polygon(rect); // free allocated polygon
        return 1; // test passed
    }
    free_polygon(rect); // free allocated polygon
    return 0; // test failed
}

// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_create_array_of_ints_fib,
        // add more test function names here
        test_reverse_array,
        test_double_array_size,
        test_double_array_size_null,
        test_double_array_size_negative,
        test_double_array_size_zero,
        test_copy_array_start_end_loop,
        test_create_point,
        test_create_polygon,
        test_free_polygon,
        test_create_rectangle
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
