// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]

// Output: 4

// Example 3:

// Input: nums = [1]

// Output: 1

 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;

        // Count frequency of each number
        for (int num : nums) {
            m[num]++;
        }

        // Find and return the number with frequency 1
        for (auto pair : m) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return -1; // Just in case input is invalid
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Single number: " << sol.singleNumber(nums1) << endl; // Output: 1

    // Test Case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Single number: " << sol.singleNumber(nums2) << endl; // Output: 4

    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Single number: " << sol.singleNumber(nums3) << endl; // Output: 1

    return 0;
}
