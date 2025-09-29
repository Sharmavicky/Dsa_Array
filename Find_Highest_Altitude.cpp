#include <iostream>
#include <vector>
using namespace std;

/*
    * This class provides a method to solve the "Find the Highest Altitude" problem.
    * Given an array `gain` representing the net change in altitude at each step,
    * the task is to determine the maximum altitude reached during the journey.
    *
    * Approach:
    * - Use a running prefix sum to track the current altitude at each step.
    * - Update the maximum altitude whenever a higher value is found.
    *
    * Time Complexity: O(n)  (single pass over the array)
    * Space Complexity: O(1) (constant extra space)
*/


class Solution {
    public:
    int prefixSumApproach(vector<int>& gain) {
        int preSum = 0;
        int highAlt = 0;

        for (int n: gain) {
            preSum += n;
            highAlt = max(highAlt, preSum);
        }

        return highAlt;
    }
};

// main function
int main() {
    vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
    int res = Solution().prefixSumApproach(gain);
    cout << res;

    return 0;
}