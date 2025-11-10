#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    * @brief Implements two approaches to solve the "Next Greater Element I" problem.
    *
    * The class provides:
    * 1. BruteForce() - A straightforward O(n^2) approach that, for each element in nums1,
    *    scans nums2 to find the first greater element to its right.
    * 2. Optimal() - An optimized O(n) approach using a monotonic stack and a hash map
    *    to precompute next greater elements for nums2, then map results to nums1.
    *
    * Example:
    * Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
    * Output: [-1,3,-1]
    *
    * Time Complexity:
    *  - BruteForce: O(n1 * n2)
    *  - Optimal: O(n1 + n2)
    *
    * Space Complexity:
    *  - BruteForce: O(1)
    *  - Optimal: O(n2)
*/


class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            int next_greater = -1;
            bool found = false;

            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) found = true;

                if (found && nums2[j] > nums1[i]) {
                    next_greater = nums2[j];
                    break;
                }
            }

            res.push_back(next_greater);
        }

        return res;
    }

    vector<int> Optimal(vector<int> nums1, vector<int> nums2) {
        stack<int> stk;
        unordered_map<int, int> next_greater_map;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums2[i]) stk.pop();
            next_greater_map[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }

        vector<int> res;
        for (int n: nums1) {
            res.push_back(next_greater_map[n]);
        }

        return res;
    }
};

// main function
int main() {
    vector<int> n1 = {4, 1, 2};
    vector<int> n2 = {1, 3, 4, 2};

    Solution sol;
    vector<int> result = sol.Optimal(n1, n2);

    for (int n: result) cout << n << " ";

    return 0;
}