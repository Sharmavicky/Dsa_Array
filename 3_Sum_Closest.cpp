#include <bits/stdc++.h>
using namespace std;

/*
    * @brief Finds the sum of three integers in the array that is closest to a given target.
    *
    * The algorithm uses the two-pointer technique after sorting the array:
    *   - First, sort the array to enable efficient traversal.
    *   - Fix one element and use two pointers (left and right) to find the best
    *     possible sum with the remaining elements.
    *   - Update the closest sum whenever a smaller absolute difference from
    *     the target is found.
    *   - If an exact match is found, return immediately.
    *
    * This approach significantly reduces the time complexity compared to
    * checking all possible triplets.
    *
    * Time Complexity: O(n²)
    *   - Sorting takes O(n log n)
    *   - Two-pointer traversal runs in O(n²)
    *
    * Space Complexity: O(1)
    *   - Only constant extra space is used (excluding sorting overhead).
    *
    * This solution is optimal for the 3Sum Closest problem and is commonly
    * used in interview and competitive programming scenarios.
*/

class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first three elements

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                if (abs(currSum - target) < abs(closestSum - target)) closestSum = currSum;

                if (currSum < target) left++;
                else if (currSum > target) right--;
                else return currSum; // Exact match found
            }
        }

        return closestSum;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = sol.threeSumClosest(nums, target);
    cout << "The sum that is closest to the target " << target << " is: " << result << endl;

    return 0;
}