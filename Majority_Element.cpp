#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    * BruteForce Approach
        * Use a hash map to count the frequency of each element.
        * Return the element as soon as its count exceeds ⌊n/2⌋.
        * Time Complexity: O(n)  → one pass through the array
        * Space Complexity: O(n) → extra space for hash map
        
    * Better Approach (Sorting)
        * Sort the array, then count consecutive occurrences of elements.
        * If any element count exceeds ⌊n/2⌋, return it.
        * Time Complexity: O(n log n) → due to sorting
        * Space Complexity: O(1) → in-place sorting (ignoring recursion stack of sort)
    
    * Optimal Approach (Moore’s Voting Algorithm)
        * Phase 1: Find a candidate by cancelling out different elements.
        * Phase 2: Verify if the candidate is actually the majority element.
        * Time Complexity: O(n)  → two passes over the array
        * Space Complexity: O(1) → constant extra space

    * Note: The problem guarantees that a majority element always exists in the array.

*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int length = nums.size(), majorityCount = length / 2;
        unordered_map<int, int> count;

        for (int n: nums) {
            count[n]++;
            // return the element as soon as it's count exceeds majorityCount
            if (count[n] > majorityCount) return n;
        }

        // if there is no majority element
        return -1; 
    }

    int BetterApproach(vector<int>& nums) {
        int length = nums.size(), majorityCount = length / 2;

        // sort the array
        sort(nums.begin(), nums.end());

        int count = 1, majorityElement = INT32_MIN;
        for (int n: nums) {
            if (n != majorityElement) {
                if (count > majorityCount) return majorityElement;
                majorityElement = n;
                count = 1;
            } else if (n == majorityElement) {
                count++;
            }
        }

        // if majority element is the last one
        if (count > majorityCount) return majorityElement;
        return -1;
    }

    int OptimalApproach(vector<int>& nums) {
        int length = nums.size(), majorityCount = length / 2;
        int count = 0, candidate = INT32_MIN;

        for (int n: nums) {
            if (count == 0) candidate = n;
            count += (n == candidate) ? 1 : -1;
        }

        // verify if candidate is actually the majority element
        count = 0;
        for (int n: nums) {
            if (n == candidate) count++;
        }

        if (count > majorityCount) return candidate;
        return -1; // if there is no majority element.
    }
};

// main function
int main() {
    vector<int> nums = {3, 2, 3};

    int result = Solution().OptimalApproach(nums);

    cout << result;

    return 0;
}