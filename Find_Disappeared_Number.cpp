#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
    * Problem:
    * Given an array nums of size n containing numbers in the range [1, n],
    * some numbers appear once, some appear twice, and some are missing.
    * Return all the numbers in the range [1, n] that do not appear in nums.
    *
    * Example:
    * Input:  nums = [4,3,2,7,8,2,3,1]
    * Output: [5,6]
    *
    * Approaches:
    *
    * 1. BruteForce (O(n^2), O(1)):
    *    - For each number from 1 to n, check if it exists in nums by scanning the array.
    *    - If not found, add it to the result.
    *
    * 2. Better (O(n), O(n)):
    *    - Use an unordered_set to store all elements in nums.
    *    - For each number from 1 to n, check if it is in the set.
    *    - If not, add it to the result.
    *
    * 3. Optimized (O(n), O(1) extra):
    *    - Use "index marking" (negative marking) technique.
    *    - For each value v in nums, mark index v-1 as visited by flipping its sign to negative.
    *    - After marking, indices with positive values correspond to missing numbers.
    *    - Collect those indices + 1 as the result.
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums) {
        vector<int> res;

        // loop from '1 -> nums.size()'
        for (int i = 1; i <= nums.size(); i++) {
            bool not_found = true;
            for (int n: nums) { //if 'i' found in nums mark as false
                if (i == n) not_found = false;
            }

            if (not_found) res.push_back(i); // if not found is true than add 'i' to res;
        }

        return res;
    }

    vector<int> Better(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        vector<int> res;

        for (int i = 1; i <= nums.size(); i++) {
            if (seen.find(i) == seen.end()) res.push_back(i);
        }

        return res;
    }

    vector<int> Optimized(vector<int>& nums) {
        vector<int> res;

        for (int i=0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }

        return res;
    }
};

// main function
int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    // vector<int> nums = { 1, 1 };
    vector<int> res = Solution().Optimized(nums);

    cout << "nums not present: \n";
    for (int n: res) {
        cout << n << " ";
    }

    return 0;
}