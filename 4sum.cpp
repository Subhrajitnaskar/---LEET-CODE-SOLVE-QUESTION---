// 18. 4Sum
// Medium
// Topics
// premium lock icon
// Companies
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();

    if (n < 4) return result;

    sort(nums.begin(), nums.end()); // Sort the array first

    for (int i = 0; i < n - 3; i++) {
        // Skip duplicates for first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {
            // Skip duplicates for second number
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            long long remaining = (long long)target - nums[i] - nums[j];
            int left = j + 1, right = n - 1;

            while (left < right) {
                long long sum = nums[left] + nums[right];
                if (sum == remaining) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for third and fourth numbers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < remaining) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << ":\n";
    for (auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
