#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    * This Solution class provides two methods to count the number of subarrays
    * whose sum equals a given target:
    *
    * 1. BruteForce (O(n^2) time, O(1) space):
    *    - Iterates over all possible subarrays and computes their sums.
    *    - Simple and intuitive but inefficient for large inputs.
    *
    * 2. PrefixSumApproach (O(n) time, O(n) space):
    *    - Uses a running prefix sum and a hash map to store frequencies of prefix sums.
    *    - At each step, checks if (prefixSum - target) exists in the map.
    *    - Efficiently counts subarrays by leveraging previous prefix sums.
    *    - Initializes freqMap[0] = 1 to handle subarrays starting at index 0.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums, int target) {
        int subArrayCnt = 0;

        for (int i=0; i<nums.size(); i++) {
            int sum = 0;

            for (int j=i; j<nums.size(); j++) {
                sum += nums[j];

                if (sum == target) subArrayCnt++;
            }
        }

        return subArrayCnt;
    }

    int PrefixSumApproach(vector<int>& nums, int target) {
        unordered_map<int, int> freqMap; // to store frequency of prefix sums
        int prefixSum = 0, subArrayCnt = 0;

        freqMap[0] = 1; // to handle the case when prefixSum itself is equal to target

        for (int n: nums) {
            // calculate prefix sum
            prefixSum += n;

            // check if there is a prefix sum that when subtracted from current prefix sum gives target
            int comp = prefixSum - target;
            if (freqMap.find(comp) != freqMap.end()) subArrayCnt += freqMap[comp];

            // update the frequency of the current prefix sum
            freqMap[prefixSum]++;
        }

        // return the count of subarrays with sum equal to target
        return subArrayCnt;
    }
};

// main function
int main() {
    vector<int> nums = {1, 1, 1};
    int target = 2;

    int res = Solution().PrefixSumApproach(nums, target);
    cout << res;

    return 0;
}