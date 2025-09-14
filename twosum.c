#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int* sum = (int*)malloc(2 * sizeof(int)); // Allocate memory for result (two indices)
    *returnSize = 2; // Always returning exactly 2 indices
    
    // Brute force approach: check every pair
    for (int i = 0; i < numsSize; i++) { // Iterate through each element
        for (int j = i + 1; j < numsSize; j++) { // Check pairs with subsequent elements
            if (nums[i] + nums[j] == target) { // Check if the sum matches the target
                // Store the indices
                sum[0] = i;
                sum[1] = j;
                return sum; // Return the indices if found
            }
        }
    }

    // This should never be reached because the problem guarantees one solution
    return NULL;
}

int main() {
    int nums[] = {3, 7, 10, 11};
    int target = 13;
    int returnSize;
    
    int* result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result); 
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

/**
 * What I learned:
 * To use malloc to allocate memory for the return array.
 * Why we need to pass `returnSize` back by pointer (since C functions
 * cannot return multiple values directly).
 * The brute force approach is simple but not optimal for large inputs.
 * 
 */

