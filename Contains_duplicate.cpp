#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
    TC_nlogn: {
        Time Complexity: O(nlogn) for sorting the array using quick sort algorithm
        Space Complexity: O(n) for sorting the array in place
    }

    TC_n: {
        Time Complexity: O(n) for iterating through the array and checking for duplicates using a hash set
        Space Complexity: O(n) for storing the elements in the hash set
    }

    TC_n2: {
        Time Complexity: O(n^2) for iterating through the array and checking for duplicates using a nested loop
        Space Complexity: O(1) as no extra space is used
    }
*/

class Solution {
    public:
    bool TC_nlogn(vector<int>& nums) {
        // sorting the array using quick sort algorithm
        sort(nums.begin(), nums.end());

        // checking for duplicates in the sorted array
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) return true; // duplicate found
        }

        return false; // no duplicates found
    };

    bool TC_n(vector<int>& nums) {
        unordered_set<int> s;

        for (int i=0; i<nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) return true; // duplicate found
            s.insert(nums[i]); // insert the number into the set if not found
        };
        return false; // no duplicates found

    };

    bool TC_n2(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums.size(); j++) {
                if (i != j && nums[i] == nums[j]) return true; // duplicate found
            }
        };

        return false; // no duplicates found
    }
};

// Main Function
int main() {
    vector<int> nums = {1, 2, 3, 1};
    bool result = Solution().TC_n(nums);
    cout << result;

    return 0;
}