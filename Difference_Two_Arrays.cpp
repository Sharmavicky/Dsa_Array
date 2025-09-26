#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
    * Class Solution provides two approaches to solve the
    * "Find the Difference of Two Arrays" problem (LeetCode 2215).
    *
    * Problem:
    * Given two integer arrays nums1 and nums2, return a 2D vector containing:
    *   - The first vector: all distinct integers in nums1 not in nums2.
    *   - The second vector: all distinct integers in nums2 not in nums1.
    *
    * Approaches:
    * 1. Set Approach:
    *    - Use unordered_sets to store unique elements.
    *    - Iterate over each set and collect elements not in the other set.
    *    - Time Complexity: O(n + m), Space Complexity: O(n + m)
    *
    * 2. Two Pointers Approach:
    *    - Sort both arrays.
    *    - Use two pointers to traverse both arrays simultaneously.
    *    - Skip duplicates and collect elements unique to each array.
    *    - Time Complexity: O(n log n + m log m), Space Complexity: O(1) extra space
*/

class Solution {
    public:
    vector<vector<int>> twoPointerApproach(vector<int>& nums1, vector<int>& nums2) {
        // sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> first, second;

        int i=0, j=0;
        
        while (i < nums1.size() || j < nums2.size()) {
            int val1 = (i < nums1.size()) ? nums1[i] : INT32_MAX;
            int val2 = (j < nums2.size()) ? nums2[j] : INT32_MAX;

            if (val1 == val2) { // if both values are same than increment both i & j until they are not same
                while (i < nums1.size() && nums1[i] == val1) i++;
                while (j < nums2.size() && nums2[j] == val2) j++;
            } else if (val1 < val2) { // if val1 < val2 than, add it to first array & increment until value is different to avoid duplicates
                first.push_back(nums1[i]);
                while (i < nums1.size() && nums1[i] == val1) i++;
            } else {
                second.push_back(nums2[j]);
                while (j < nums2.size() && nums2[j] == val2) j++;
            }
        }

        // return array of first & second as our result
        return {first, second};
    }

    vector<vector<int>> setApproach(vector<int>& n1, vector<int>& n2) {
        vector<vector<int>> res;
        
        /* 
            first store elements of n1 not present in n2
            second store elements of n2 not present in n1
        */
        vector<int> first, second;

        unordered_set<int> n1_seen(n1.begin(), n1.end());
        unordered_set<int> n2_seen(n2.begin(), n2.end());

        // iterate over n1_seen & chk if elements present in n2_seen or not;
        for (auto n: n1_seen) {
            if (n2_seen.find(n) == n2_seen.end()) first.push_back(n);
        }

        // iterate over n2_seen & chk if elements present in n1_seen or not;
        for (auto n: n2_seen) {
            if (n1_seen.find(n) == n1_seen.end()) second.push_back(n);
        }

        // add first & second in our res
        res.push_back(first);
        res.push_back(second);

        // return res
        return res;
    }
};