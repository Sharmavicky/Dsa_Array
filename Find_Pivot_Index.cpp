#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    * This class provides a method to find the pivot index in an array,
    * where the sum of elements to the left equals the sum of elements to the right.
    *
    * Approach:
    * ---------
    * 1. Compute the total sum of the array.
    * 2. Traverse the array while maintaining a running prefix sum.
    * 3. At each index i, check if:
    *        leftSum == totalSum - leftSum - nums[i]
    *    If true, index i is the pivot index.
    * 4. If no such index exists, return -1.
    *
    * Time Complexity: O(n)   — single pass through the array.
    * Space Complexity: O(1)  — only uses a few variables.
*/

class Solution {
public:
    int PrefixSumApproach(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;

        // calculate total Sum of the array
        for (int n : nums) totalSum += n;

        // find pivot index;
        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (rightSum == leftSum) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};

// main function
int mian() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int res = Solution().PrefixSumApproach(nums);
    cout << res;
    return 0;
}