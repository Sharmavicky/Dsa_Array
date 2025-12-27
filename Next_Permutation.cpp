#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    *
    * @brief Generates the next lexicographically greater permutation
    *        of a given integer array in-place.
    *
    * The algorithm follows a well-known permutation generation strategy:
    *
    * Steps:
    *   1. Traverse from the end to find the first index `i` such that
    *      nums[i] < nums[i + 1]. This identifies the pivot where the
    *      next permutation can be formed.
    *   2. If such an index exists, find the smallest element greater than
    *      nums[i] on the right side and swap them.
    *   3. Reverse the subarray after index `i` to obtain the smallest
    *      lexicographical order for the remaining elements.
    *
    * If no such index exists (the array is in descending order),
    * reversing the entire array produces the smallest permutation.
    *
    * Time Complexity: O(n)
    * Space Complexity: O(1)
    *
    * This approach is optimal and commonly used in interview and
    * competitive programming problems involving permutations.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) 
            i--;

        if (i >= 0) {
            int j = n - 1;
            // Find the element just larger than nums[i]
            while (nums[j] <= nums[i]) 
                j--;

            // Swap the found elements
            swap(nums[i], nums[j]);
        }

        // Reverse the elements after index i
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    sol.nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}