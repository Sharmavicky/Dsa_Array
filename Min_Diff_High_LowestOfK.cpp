#include <bits/stdc++.h>
using namespace std;

/*
    * This class provides two approaches to solve the
    * "Minimum Difference Between Highest and Lowest of K Elements" problem.
    *
    * 1. BruteForce:
    *    Uses recursion and backtracking to generate all possible combinations
    *    of k elements from the array. For each combination, it computes the
    *    difference between the maximum and minimum values and keeps track of
    *    the global minimum difference. This approach is primarily for learning
    *    purposes, as it has exponential time complexity O(2^n).
    *
    * 2. OptimalApproach:
    *    Uses sorting followed by a sliding window technique. After sorting the
    *    array, it checks every consecutive window of size k and computes the
    *    difference between the first and last elements of each window, which
    *    represents the minimum and maximum for that group. The smallest such
    *    difference is returned. This approach runs in O(n log n) time due to sorting.
    *
    * Overall, this class demonstrates both a brute-force recursive solution
    * (to understand combinations and backtracking) and an optimized solution
    * suitable for real-world and interview scenarios.
*/

class Solution {
    void usingRecursion(vector<int>& nums, int k, int idx, int& minDiff, vector<int>& tempArray) {
        // when we have picked k elements
        if (tempArray.size() == k) {
            int currDiff = *max_element(tempArray.begin(), tempArray.end()) - *min_element(tempArray.begin(), tempArray.end());
            minDiff = min(minDiff, currDiff);
            return;
        }

        // base case
        if (idx >= nums.size()) return;

        // pick condition
        tempArray.push_back(nums[idx]);
        usingRecursion(nums, k, idx + 1, minDiff, tempArray);
        tempArray.pop_back(); // backtrack

        // not pick condition
        usingRecursion(nums, k, idx + 1, minDiff, tempArray);
    }
    
public:
    int BruteForce(vector<int>& nums, int k) {
        // base case
        if (k <= 1) return 0;

        int minDiff = INT_MAX, idx = 0;
        vector<int> tempArray;
        usingRecursion(nums, k, idx, minDiff, tempArray);
        return minDiff;
    }

    int OptimalApproach(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        for (int i = 0; i + k - 1 < nums.size(); i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {20980, 13353, 51423, 11920, 41836, 51586, 54445};
    int k = 5;
    int result = sol.BruteForce(nums, k);
    cout << "Minimum difference between highest and lowest of any subarray of size " << k << " is: " << result << endl;
    return 0;
}