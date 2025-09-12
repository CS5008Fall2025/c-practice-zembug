# Homework - C Practice Report

Completely answer the report questions below. Make sure to double check the final version to make sure it is easily readable on your github repository. 




1. What is the difference between a standard numeric type (int, float, double) and a pointer?

   Standard numeric types hold actual data, such as numbers you can directly use in calculations. Pointers hold the location in memory where data lives. They don’t store the value itself, but rather tell you where to find it. This means numeric types represent values, while pointers represent addresses pointing to those values.
   
2. In your test file, we had the following code:
    
    ```c
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    ```
    Later in the code we only `free(arr)` but not expected. Why is this? What is the difference in where they are stored in memory?

    In the code, `arr` is created using `malloc`, which means it lives in the heap. You have to free heap memory manually using `free(arr)`. The expected array is created inside the function without `malloc`, so it lives in the stack. Stack memory is automatically cleaned up when the function ends, so you don’t need to free it.

3. What is the difference between the heap and stack when related to memory allocation and management?

   The stack is used for temporary memory, such as local variables. When the function ends the memory is automatically cleared. The heap is used for dynamic memory. You can allocate this memory with `malloc` and then you have to manually clear the memory with free. 

4. Take the following code:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point pt = {x, y};
     return &pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      return 0;
   }
   ```
   Would the code run correctly? Even if it does compile, what would be some potential runtime issues? After answering your thoughts, put the output of a run below (you may need to run it a few times).
   ```text
   output here
   ```

   Fix the code in the following block:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point pt = {x, y};
     return &pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      return 0;
   }
   ```

5. When you use `malloc`, where are you storing the information?

   The information is allocated to the heap.

6. Speaking about `malloc` and `calloc`, what is the difference between the two (you may need to research it!)?

   The difference lies in how memory is allocated and initialized. `malloc` allocates a single block of memory and does not initialize it, meaning the contents of the memory are undefined. In contrast, `calloc` allocates memory for multiple blocks and initializes all of the memory to zero.

7. What are some common built in libraries used for C, list at least 3 and explain each one in your own words. Name a few (at least 3) functions in those libraries (hint: we used two of the most common ones in this assignment. There are many resources online that tell you functions in each library - you need to include at least 1 reference, but ideally for every library, you should have a reference to it)?
   - Example: stdlib.h - provides functions for general-purpose operations including
              memory management and random numbers [1].
     - void * malloc(size_t) - allocates memory specified in size on the heap and returns a pointer to that location
     - void * calloc(size_t num_elements, size_t element_size) - contiguous allocation for allocating arrays with the default value of 0. Slower than malloc. 
     - int rand(void) - returns a random integer between 0 and RAND_MAX. Seed should be set before hand. 
   
   1. `stdio.h` - provides functions for input and output [2][3].
      - `printf()` - formats and shows messages or values on the screen
      - `scanf()` - gets input from user and stores it in a variable's memory
      - `fopen()` - opens the specific file
   
   2. `string.h` - provides functions to work with test [2][4].
      - `strcomp()` - compares to strings to see if they match
      - `strchr()` - finds a character inside a string
      - `strstr()` - finds word/phrase inside a string
 
   3. `math.h` - provides functions for math operations [2][5].
      - `ceil(x)` - rounds x up to the nearest whole number
      - `floor(x)` - rounds x down to the nearest whole number
      - `pow(x, y)` - raises x to the power of y
 

8. Looking at the struct Point and Polygon, we have a mix of values on the heap, and we make ample use of pointers. Take a moment to draw out how you think that looks after `create_triangle(2,3)` is called (see an example below). The important part of the drawing it to see that not everything is stored together in memory, but in different locations! Store the image file in your github repo and link it here. You can use any program to draw it such as [drawIO](https://app.diagrams.net/), or even draw it by hand and take a picture of it. 


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

## Deeper Thinking
In Java and Python, do you think new objects are stored on the stack or the heap? Feel free to work through your thoughts as to why it would be better to store them on the stack or heap. You should consider pass by reference, and how that is similar to pointer in your answer. Feel free to use resources, but make sure to cite them, and include the citation below using ACM format. You will note LLMs are not valid references, but they can give you directions to valid references. Make sure to use your own words. 

Answer here using a paragraph (not just bullet points). 




## References
Add any references you use here. Use ACM style formatting, adding to the numbers as you add the reference. 

1. cppreference.com Contributors. 2025. Standard library header <stdlib.h>. cppreference.com. Retrieved May 1, 2025 from https://en.cppreference.com/w/c/header/stdlib

2. IBM Documentation. Standard C Library Functions Table, By Name. (July 8, 2025). Retrieved September 11, 2025. (https://www.ibm.com/docs/en/i/7.5.0?topic=extensions-standard-c-library-functions-table-by-namet)

3. IBM Documentation. stdio.h — Standard input and output. (March 26, 2025). Retrieved September 11, 2025. (https://www.ibm.com/docs/en/zos/3.1.0?topic=files-stdioh-standard-input-output)

4. IBM Documentation. string.h — String manipulation functions. (March 26, 2025). Retrieved September 11, 2025. (https://www.ibm.com/docs/en/zos/3.1.0?topic=files-stringh-string-manipulation-functions)

5. IBM Documentation. math.h — Floating-point math functions. (March 26, 2025). Retrieved September 11, 2025. (https://www.ibm.com/docs/en/zos/3.1.0?topic=files-mathh-floating-point-math-functions)

## Resource/Help: Linking to images?
To link an image, you use the following code

```markdown
![alt text](path / link to image)
```
for example
```markdown
![my memory drawing](instructions/rectangle_points.png)
```


Here is a sample using: 
```c
void my_func() {
    Polygon* r = create_rectangle(5,5);
    printf("The area of the rectangle is %d\n", area(r));
}
```

![my memory drawing](instructions/rectangle_points.png)

Note: This is a simplified version. However, it helps illustrate why we need to use `free` on the pointers in the struct. If we do not, we will have memory leaks! (memory that is allocated, but not freed, and thus cannot be used by other programs). In the above example code, `r` is created, and then the variable is destroyed when the function ends. However, the memory allocated for the struct is not freed, and thus we have a memory leak.

When you work on your version for `create_triangle(2, 3)`, you do not have to be exact on the memory structure (the locations on the heap were randomly chosen). The idea is more to show how the memory is stored, and the pointers to different memory addresses. 

