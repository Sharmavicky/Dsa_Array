#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
    * Problem:
    * Given an array nums of size n where elements are in the range [1..n],
    * return all elements that appear exactly twice in the array.
    *
    * Example:
    * Input:  nums = [4,3,2,7,8,2,3,1]
    * Output: [2,3]
    *
    * Approaches:
    *
    * 1. BruteForce (O(n log n), O(n)):
    *    - Sort the array.
    *    - Iterate through and compare each element with the next one.
    *    - If two consecutive elements are equal, add it to the result.
    *
    * 2. HashMapApproach (O(n), O(n)):
    *    - Use an unordered_map to track frequency of each element.
    *    - Whenever a number's count reaches 2, add it to the result.
    *
    * 3. Optimized / Index Marking (O(n), O(1) extra):
    *    - For each number v in nums, map it to index v-1.
    *    - Flip nums[v-1] negative to mark it visited.
    *    - If nums[v-1] is already negative, v is a duplicate → add to result.
    *
    * Notes:
    * - Optimized approach achieves linear time and constant extra space.
    * - Input array is modified; use absolute values if original array must be preserved.
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums) {
        // sort the array;
        sort(nums.begin(), nums.end());

        vector<int> res;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }

    vector<int> HashMapApproach(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> seen;

        for (int n: nums) {
            seen[n]++;

            if (seen[n] == 2) res.push_back(n);
        }

        return res;
    }

    vector<int> IndexMarking(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1; // map value to index

            if (nums[idx] < 0) { // already negative → duplicate
                res.push_back(abs(nums[i]));
            } else{
                nums[idx] = -nums[idx]; // mark as visited
            }
        }

        return res;
    }
};

// main function
int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = Solution().HashMapApproach(nums);
    
    for (int n: res) {
        cout << n << " ";
    }
    return 0;
}