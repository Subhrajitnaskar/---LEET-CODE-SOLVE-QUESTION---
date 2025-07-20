// 75. Sort Colors
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.


#include <iostream>
#include <vector>
using namespace std;

// Function to sort the colors using Dutch National Flag Algorithm
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// Utility function to print the vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Test input
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    printVector(nums);

    sortColors(nums);

    cout << "After sorting: ";
    printVector(nums);

    return 0;
}
