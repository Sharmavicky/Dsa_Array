#include <bits/stdc++.h>
using namespace std;

/*
    * Class Name: Solution
    *
    * Description:
    * -------------
    * This class provides a method to generate all unique subsets (the power set)
    * of a given integer array that may contain duplicate elements.
    * It uses a recursive backtracking approach combined with sorting and duplicate
    * skipping logic to ensure that no duplicate subsets are included in the final result.
    *
    * Key Features:
    * --------------
    * - Handles duplicate elements using sorting and conditional skipping.
    * - Uses backtracking to explore all subset combinations.
    * - Includes the empty subset by default.
    *
    * Time Complexity:
    * ----------------
    * O(2^n), where n is the number of elements in the input array.
    * (Each element can either be included or excluded.)
    *
    * Space Complexity:
    * -----------------
    * O(n) for recursion stack and O(2^n) for storing all subsets.
*/

class Solution {
    void getAllSubsets_2(vector<int>& nums, vector<int>& sub_array, vector<vector<int>>& res, int idx) {
        res.push_back(sub_array);

        for (int i=idx; i<nums.size(); i++) {
            if (i > idx && nums[i] == nums[i-1]) continue;

            // include
            sub_array.push_back(nums[i]);
            getAllSubsets_2(nums, sub_array, res, i+1);

            // exclude
            sub_array.pop_back();
        }
    }

public:
    vector<vector<int>> Subsets_2(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub_array;
        sort(nums.begin(), nums.end());
        getAllSubsets_2(nums, sub_array, res, 0);
        return res;
    }    
};

// main function
int main() {
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> res = Solution().Subsets_2(nums);

    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}