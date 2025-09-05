#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * Provides two methods to rotate an array to the right by `k` steps:
    
    * 1. BruteForce:
    *    - Uses an extra vector to first take the last `k` elements,
    *      then append the remaining elements from the front.
    *    - Copies everything back into the original array.
    *    - Time: O(n), Space: O(n)
    
    * 2. OptimalApproach:
    *    - Uses the reversal algorithm (in-place, O(1) space).
    *    - Steps:
    *        a) Reverse the entire array
    *        b) Reverse the first `k` elements
    *        c) Reverse the remaining `n-k` elements
    *    - Time: O(n), Space: O(1)
    
    * Example:
    *   nums = [1,2,3,4,5,6,7], k = 3
    *   Result = [5,6,7,1,2,3,4]
*/


class Solution {
    public:
    void BruteForce(vector<int>& nums, int k) {
        int length = nums.size();

        if (length == 0 || length == 1 || k == 0) return;

        k = k % length; // handles value if k > length
        vector<int> copy = {};

        for (int i = length-k; i < length; i++) {
            copy.push_back(nums[i]);
        }

        for (int i = 0; i < length-k; i++) {
            copy.push_back(nums[i]);
        }

        // copy values from copyvector to nums
        nums.clear();

        for (int n: copy) {
            nums.push_back(n);
        }
    }

    void OptimalApproach(vector<int>& nums, int k) {
        int length = nums.size();

        // edge case
        if (k == 0 || length == 0 || length == 1) return;

        k = k % length;

        // reverse the entire array
        reverse(nums.begin(), nums.end());

        // reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // reverse remaining elements
        reverse(nums.begin()+k, nums.end());
    }
};

// main function
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution sol;
    sol.BruteForce(nums, k);

    cout << "nums after rotating array: \n";

    for (int i: nums) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}