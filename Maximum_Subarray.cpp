#include <iostream>
#include <vector>
using namespace std;

/*
    * Class Solution implements two approaches to solve the Maximum Subarray Problem:

    1. BruteForce(): O(n^2) solution that checks all possible subarrays 
        and returns the maximum sum.

    2. OptimalApproach (Kadane's Algorithm) Explanation:
        * The idea is to find the maximum sum of a contiguous subarray in O(n) time.

        * We maintain two variables:
            1. curr_sum -> stores the sum of the current subarray
            2. max_sum  -> stores the maximum sum found so far

        * Steps:
            - Traverse the array element by element
            - Add the current element to curr_sum
            - Update max_sum if curr_sum is greater
            - If curr_sum becomes negative, reset it to 0 (because any subarray 
                starting with a negative sum cannot contribute to the maximum subarray)
            - Continue until the end of the array

        * Example: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        Iteration will track subarray [4, -1, 2, 1] with sum = 6 as the maximum.

        * Time Complexity: O(n)
        * Space Complexity: O(1)


*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT32_MIN;

        if (n == 1) return nums[0];

        for (int i=0; i<n-1; i++) {
            int sum = nums[i];
            max_sum = max(max_sum, sum); // check for first element
            for (int j=i+1; j<n; j++) {
                sum += nums[j];
                max_sum = max(max_sum, sum);
            }
        }

        max_sum = max(max_sum, nums[n-1]); // check for last element

        return max_sum;
    }

    int OptimalApproach(vector<int>& nums) {
        int max_sum = INT32_MIN, curr_sum = 0;

        for (int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);
            if (curr_sum < 0) curr_sum = 0;
        }

        return max_sum;
    }
};

// main function
int main() {
    vector<int> nums = { -1, -2 };
    Solution sol;
    int result = sol.OptimalApproach(nums);
    cout << result;
    return 0;
}