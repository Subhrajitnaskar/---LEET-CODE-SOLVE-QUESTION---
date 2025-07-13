// 

#include <stdio.h>

int maxAscendingSum(int* nums, int numsSize) {
    int maxSum = nums[0]; 
    int currentSum = nums[0]; 
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            currentSum += nums[i]; 
        } else {
            if (currentSum > maxSum) {
                maxSum = currentSum; 
            }
            currentSum = nums[i]; 
        }
    }
    
    if (currentSum > maxSum) {
        maxSum = currentSum; 
    }
    
    return maxSum;
}

int main() {
    int nums1[] = {10, 20, 30, 5, 10, 50};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Max ascending sum: %d\n", maxAscendingSum(nums1, size1)); // Output: 65

    int nums2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Max ascending sum: %d\n", maxAscendingSum(nums2, size2)); // Output: 150

    int nums3[] = {12, 17, 15, 13, 10, 11, 12};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Max ascending sum: %d\n", maxAscendingSum(nums3, size3)); // Output: 33

    return 0;
}
