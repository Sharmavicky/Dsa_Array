#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
    * Problem: Check if an array contains any duplicates.

    * Approaches Implemented:
    1. Brute Force Approach
       - Compare each element with every other element.
       - Time Complexity: O(n^2)
       - Space Complexity: O(1)

    2. Better Approach (Sorting + Adjacent Comparison)
       - Sort the array, then check if any adjacent elements are equal.
       - Time Complexity: O(n log n)
       - Space Complexity: O(1) (assuming in-place sort)

    3. Optimal Approach (Hash Set)
       - Use a hash set to track seen elements.
       - If an element is already in the set, a duplicate exists.
       - Time Complexity: O(n) on average
       - Space Complexity: O(n)
*/

class Solution {
    public:
    bool BruteForce(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums.size(); j++) {
                if (i != j && nums[i] == nums[j]) return true; // duplicate found
            }
        };

        return false; // no duplicates found
    }

    bool BetterApproach(vector<int>& nums) {
        // sorting the array using quick sort algorithm
        sort(nums.begin(), nums.end());

        // checking for duplicates in the sorted array
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) return true; // duplicate found
        }

        return false; // no duplicates found
    };

    bool OptimalApproach(vector<int>& nums) {
        unordered_set<int> s;

        for (int i=0; i<nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) return true; // duplicate found
            s.insert(nums[i]); // insert the number into the set if not found
        };
        return false; // no duplicates found

    };
};

// Main Function
int main() {
    vector<int> nums = {1, 2, 3, 1};
    bool result = Solution().OptimalApproach(nums);
    cout << result;

    return 0;
}