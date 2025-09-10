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

// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_create_array_of_ints_fib,
        // add more test function names here
        test_reverse_array,
        test_double_array_size,
        test_double_array_size_null,
        test_double_array_size_negative,
        test_double_array_size_zero
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
