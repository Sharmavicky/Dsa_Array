#include <iostream>
#include <vector>
using namespace std;

/*
 * Class Solution provides two approaches to solve the "Maximum Average Subarray I" problem.
 *
 * Problem:
 * Given an integer array nums and an integer k, find the contiguous subarray of length k
 * that has the maximum average value, and return this value.
 *
 * Approaches:
 * 1. BruteForce:
 *    - Compute average of every subarray of size k.
 *    - Time Complexity: O(n * k), Space Complexity: O(1).
 *
 * 2. Optimal (Sliding Window):
 *    - Use a sliding window to maintain the sum of current subarray of size k.
 *    - At each step, add the new element and remove the oldest element.
 *    - Update the maximum average efficiently.
 *    - Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution
{
public:
    double BruteForce(vector<int> &nums, int k)
    {
        double maxAvg = INT32_MIN;
        int start = 0, end = k - 1;

        while (end <= nums.size() - 1)
        {
            double currAvg = 0;
            for (int i = start; i <= end; i++)
            {
                currAvg += nums[i];
            }

            maxAvg = max(maxAvg, currAvg / k);
            start++;
            end++;
        }

        return maxAvg;
    }

    double Optimal(vector<int> &nums, int k)
    {
        double maxAvg = INT32_MIN;
        double currSum = 0;

        // calculate avg of first k elements
        for (int i = 0; i < k; i++)
        {
            currSum += nums[i];
        }

        maxAvg = max(maxAvg, currSum / k);

        // now, add 1 elements in the curravg and remove 1 element from curravg
        for (int i = k; i < nums.size(); i++)
        {
            currSum += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, currSum / k);
        }

        return maxAvg;
    }
};

// main function
int main()
{
    vector<int> nums = {-1};
    int k = 1;

    double res = Solution().Optimal(nums, k);
    cout << res;
    return 0;
}