// 1726. Tuple with Same Product
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

 

// Example 1:

// Input: nums = [2,3,4,6]
// Output: 8
// Explanation: There are 8 valid tuples:
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
// Example 2:

// Input: nums = [1,2,4,5,10]
// Output: 16
// Explanation: There are 16 valid tuples:
// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104
// All elements in nums are distinct.

#include <stdio.h>
#include <stdlib.h>

int tupleSameProduct(int* nums, int numsSize) {
    int count = 0;
    int max_product = 0;

    // First, determine the maximum possible product
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int product = nums[i] * nums[j];
            if (product > max_product) {
                max_product = product;
            }
        }
    }

    // Allocate space to count number of times each product appears
    int* product_counts = (int*)calloc(max_product + 1, sizeof(int));
    if (product_counts == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Count how many times each product appears from all unique pairs
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int product = nums[i] * nums[j];
            product_counts[product]++;
        }
    }

    // For each product, if it appears more than once, calculate how many tuple combinations can be formed
    for (int product = 1; product <= max_product; product++) {
        int num_pairs = product_counts[product];
        if (num_pairs > 1) {
            count += num_pairs * (num_pairs - 1) * 4;
        }
    }

    free(product_counts);
    return count;
}

int main() {
    // Example input
    int nums[] = {2, 3, 4, 6};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = tupleSameProduct(nums, size);
    printf("Number of valid tuples: %d\n", result); // Expected output: 8

    return 0;
}
