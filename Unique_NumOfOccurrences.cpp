#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
    * This class provides two methods to check whether the frequencies of 
    * elements in an array are unique.
    *
    * 1. BruteForce:
    *    - Sorts the array to group identical elements.
    *    - Counts frequencies and stores them in a vector.
    *    - Sorts the frequency vector and checks for duplicates.
    *    - Time: O(n log n), Space: O(k), where k = number of distinct elements.
    *
    * 2. OptimalApproach:
    *    - Uses an unordered_map to store element frequencies.
    *    - Uses an unordered_set to verify frequency uniqueness.
    *    - Time: O(n), Space: O(k).
    *
    * Both methods return true if all frequencies are unique, otherwise false.
*/


class Solution {
    public:
    bool BruteForce(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());

        vector<int> cnt;
        int count = 1;

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                cnt.push_back(count);
                count = 1;
            } else {
                count++;
            }
        }

        // add last frequency
        cnt.push_back(count);

        // sort the cnt array
        sort(cnt.begin(), cnt.end());

        for (int i=1; i<cnt.size(); i++) {
            if (cnt[i] == cnt[i-1]) return false;
        }

        return true;
    }

    bool OptimalApproach(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_set<int> seen;

        // map frequency of all elements in freq
        for (int n: nums) {
            freq[n]++;
        }

        for (auto& it: freq) {
            // if frequency is not present in set than add it.
            if (seen.find(it.second) == seen.end()) seen.insert(it.second);

            // if frequency is present than return false.
            else return false;
        }

        // return true, if all frequencies are unique
        return true;
    }
};

// main function
int main() {
    vector<int> nums = {1, 1, 2, 2, 1, 3};
    bool res = Solution().BruteForce(nums);
    cout << res;
    return 0;
}