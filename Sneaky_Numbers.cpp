#include <bits/stdc++.h>
using namespace std;

/*
    Class Name: Solution

    Description:
    This class provides multiple approaches to solve the LeetCode problem
    "The Two Sneaky Numbers of Digitville" (Problem #3289).

    Given an integer array `nums` containing n + 2 elements where each number
    in the range [0, n] appears exactly once, except for two numbers that appear twice —
    the task is to find and return those two duplicate (sneaky) numbers.

    Implemented Approaches:
    1. BruteForce:
       - Sorts the array and checks consecutive elements for duplicates.
       - Time Complexity: O(n log n)
       - Space Complexity: O(1)

    2. HashMapApproach:
       - Uses a frequency map to count occurrences of each number.
       - Returns numbers with frequency > 1.
       - Time Complexity: O(n)
       - Space Complexity: O(n)

    3. SetApproach:
       - Uses an unordered_set to track seen elements.
       - If an element is already seen, it's recorded as a duplicate.
       - Time Complexity: O(n)
       - Space Complexity: O(n)

    Each method demonstrates a different trade-off between simplicity,
    performance, and memory usage — helping understand multiple ways
    to tackle the same problem efficiently.
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums) {
        vector<int> sneakyNumbers;
        int n = nums.size();

        // sort the array
        sort(nums.begin(), nums.end());

        for (int i=1; i<n; i++) {
            if (nums[i] == nums[i-1]) sneakyNumbers.push_back(nums[i]);
        }

        return sneakyNumbers;
    }

    vector<int> HashMapApproach(vector<int>& nums) {
        vector<int> sneakyNumbers;
        unordered_map<int, int> freqMap;

        // build frequency map
        for (int n: nums) freqMap[n]++;

        // collect sneaky numbers
        for (auto it: freqMap) if (it.second > 1) sneakyNumbers.push_back(it.first);

        return sneakyNumbers;
    }

    vector<int> SetApproach(vector<int>& nums) {
        vector<int> sneakyNumbers;
        unordered_set<int> seen;

        for (int n: nums) {
            // if number is already seen, it's a sneaky number
            if (seen.find(n) != seen.end()) sneakyNumbers.push_back(n);
            
            // otherwise, insert it into the set
            else seen.insert(n);
        }

        return sneakyNumbers;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = sol.BruteForce(nums);
    vector<int> resOpt = sol.HashMapApproach(nums);

    for (int n: res) cout << n << " ";
    cout << endl;
    for (int n: resOpt) cout << n << " ";
    return 0;
}