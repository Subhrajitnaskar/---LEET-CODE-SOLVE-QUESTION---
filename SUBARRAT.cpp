// 3487. Maximum Unique Subarray Sum After Deletion
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums.

// You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

// All elements in the subarray are unique.
// The sum of the elements in the subarray is maximized.
// Return the maximum sum of such a subarray.

 

// Example 1:

// Input: nums = [1,2,3,4,5]

// Output: 15

// Explanation:

// Select the entire array without deleting any element to obtain the maximum sum.

// Example 2:

// Input: nums = [1,1,0,1,1]

// Output: 1

// Explanation:

// Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array [1] to obtain the maximum sum.

// Example 3:

// Input: nums = [1,2,-1,-2,1,0,-1]

// Output: 3

// Explanation:

// Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int maxUniqueSubarraySum(vector<int>& nums) {
    unordered_set<int> seen;
    int left = 0, right = 0, currentSum = 0, maxSum = 0;

    while (right < nums.size()) {
        while (seen.count(nums[right])) {
            seen.erase(nums[left]);
            currentSum -= nums[left];
            left++;
        }

        seen.insert(nums[right]);
        currentSum += nums[right];
        maxSum = max(maxSum, currentSum);
        right++;
    }

    return maxSum;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 1, 0, 1, 1};
    vector<int> nums3 = {1, 2, -1, -2, 1, 0, -1};

    cout << "Example 1 Output: " << maxUniqueSubarraySum(nums1) << endl;
    cout << "Example 2 Output: " << maxUniqueSubarraySum(nums2) << endl;
    cout << "Example 3 Output: " << maxUniqueSubarraySum(nums3) << endl;

    return 0;
}
