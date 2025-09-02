#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Problem: Contains Duplicate II
    -----------------------------------------
    * Given an integer array nums and an integer k, return true if there exist two distinct indices i and j in the array such that:
        nums[i] == nums[j] and |i - j| <= k

    * Approaches Implemented in this class:
    --------------------------------------
    1. BruteForce:
       - Compare every pair (i, j) with nested loops.
       - If nums[i] == nums[j] and |i - j| <= k → return true.
       - Time Complexity: O(n^2)
       - Space Complexity: O(1)

    2. OptimalApproach (Hash Map):
       - Use a hash map to store the last index of each element.
       - If the same element appears again, check the index difference.
       - If |i - lastIndex| <= k → return true.
       - Update the element’s index in the map.
       - Time Complexity: O(n)
       - Space Complexity: O(n)
*/

class Solution {
    public:
    bool BruteForce(vector<int>& nums, int k) {
        int length = nums.size();

        for (int i=0; i < length; i++) {
            for (int j = i+1; j < length; j++) {
                if (nums[i] == nums[j] && abs(i-j) <= k) return true;
            }
        }

        return false;
    }

    bool OptimalApproach(vector<int>& nums, int k) {
        int length = nums.size();
        unordered_map<int, int> map;

        for (int i=0; i < length; i++) {
            if (map.find(nums[i]) != map.end() && abs(map[nums[i]] - i) <= k) {
                return true;
            }
            map[nums[i]] = i; // Update the index of the current element, if already present
        }

        return false;
    }
};

// main function
int main() {
    vector<int> nums = { 1, 2, 3, 1, 2, 3 };
    int k = 2;

    Solution sol;

    bool result = sol.OptimalApproach(nums, k);

    cout << result;
    return 0;
}