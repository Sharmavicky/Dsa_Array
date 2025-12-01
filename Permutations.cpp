#include <bits/stdc++.h>
using namespace std;

/*
    * Class: Solution
    * ----------------
    * This class provides two approaches to generate all permutations of a given array of integers.
    *
    * Methods:
    *
    * 1. BruteForce(vector<int>& nums) -> vector<vector<int>>
    *    - Uses C++ STL `next_permutation` to generate permutations in lexicographical order.
    *    - Sorts the input array first to ensure correct order.
    *    - Time Complexity: O(n * n!) where n is the size of the array.
    *    - Space Complexity: O(n!) for storing all permutations.
    *
    * 2. Optimal(vector<int>& nums) -> vector<vector<int>>
    *    - Uses a backtracking approach to explore all possible permutations recursively.
    *    - Maintains a `used` array to keep track of elements already included in the current permutation.
    *    - Time Complexity: O(n * n!)
    *    - Space Complexity: O(n) recursion stack + O(n!) for storing permutations.
    *
    * Key Idea:
    * - BruteForce leverages built-in library functions for simplicity.
    * - Optimal method builds permutations recursively, allowing more control and understanding of the generation process.
    *
    * Example:
    * Input: [1, 2, 3]
    * Output:
    * [
    *   [1, 2, 3],
    *   [1, 3, 2],
    *   [2, 1, 3],
    *   [2, 3, 1],
    *   [3, 1, 2],
    *   [3, 2, 1]
    * ]
*/

class Solution {
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, current, result, used);

            used[i] = false;
            current.pop_back();
        }
    }

public:
    vector<vector<int>> BruteForce(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return result;
    }

    vector<vector<int>> Optimal(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, result, used);
        return result;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    // Using BruteForce method
    vector<vector<int>> permutationsBrute = sol.BruteForce(nums);
    cout << "BruteForce Permutations:" << endl;
    for (const auto& perm : permutationsBrute) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Using Optimal method
    vector<vector<int>> permutationsOptimal = sol.Optimal(nums);
    cout << "Optimal Permutations:" << endl;
    for (const auto& perm : permutationsOptimal) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}