#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
    * Problem:
    * Find the total count of elements that occur with the maximum frequency
    * in the given array.
    *
    * Example:
    * Input: [1,2,2,3,1,4]
    * Frequency: {1:2, 2:2, 3:1, 4:1}
    * Maximum frequency = 2
    * Elements with max frequency = {1, 2}
    * Answer = 2+2 = 4
    *
    * Approaches:
    * 1. BruteForce (Sort + Count) -> O(n log n)
    * 2. OptimalApproach (HashMap + One Pass) -> O(n)
*/

class Solution {
    public:
    int SortAndCount(vector<int>& nums) {
        // edge case
        if (nums.size() == 1) return 1;
        if (nums.size() == 0) return -1;

        // sort the array
        sort(nums.begin(), nums.end());

        // find maximum frequency
        int max_freq = 0, cnt = 1;

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                max_freq = max(max_freq, cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }

        // if array have all same elements
        max_freq = max(max_freq, cnt);

        // store all elements with it's frequency in a unordered_map
        unordered_map<int, int> seen;
        for (int n: nums) {
            seen[n]++;
        }

        // find elements with maximum frequency
        int total_freq = 0;
        for (auto it: seen) {
            if (it.second == max_freq) {
                total_freq += max_freq;
            }
        }

        return total_freq;
    }

    int HashMapApproach(vector<int>& nums) {
        unordered_map<int, int> seen;
        int max_freq = 0;

        // store all elements with it's frequency and compare with max_freq
        for (int n: nums) {
            seen[n]++;
            max_freq = max(max_freq, seen[n]);
        }

        // loop through map and find elements having max_freq & add it to total_freq
        int total_freq = 0;
        for (auto it: seen) {
            if (it.second == max_freq) {
                total_freq += it.second;
            }
        }

        // return total_freq
        return total_freq;
    }
};

// main function
int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    int res = Solution().HashMapApproach(nums);
    cout << res;
    return 0;
}