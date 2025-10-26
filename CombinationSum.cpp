#include <iostream>
#include <vector>
using namespace std;

/*
    * Class: combinationSum
    * ----------------------
    * This class implements a recursive backtracking solution to the "Combination Sum" problem.
    * The goal is to find all unique combinations of numbers from a given array `arr`
    * that add up exactly to a specified target value. Each number in `arr` may be used
    * an unlimited number of times in a combination.
    *
    * Approach:
    * - Uses recursion with two choices at each step:
    *     1. Pick the current element (if it does not exceed the target) and continue
    *        with the same index (allowing repetition).
    *     2. Skip the current element and move to the next index.
    * - Backtracking ensures that after exploring a path, the chosen element is removed
    *   to explore new possibilities.
    *
    * Time Complexity: O(2^n * k)
    *     where n = number of elements in `arr`,
    *           k = average length of a valid combination.
    *
    * Space Complexity: O(k) for recursion stack and temporary combination storage.
    *
    * Example:
    *     Input:  arr = [2, 3, 6, 7], target = 7
    *     Output: [[2, 2, 3], [7]]
*/

class combinationSum {
    void recursion_method(int idx, vector<vector<int>>& result, vector<int>& arr, vector<int> temp, int target) {
        if (idx == arr.size()) { // base case
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }

        if (arr[idx] <= target) { // pick condition
            temp.push_back(arr[idx]);
            recursion_method(idx, result, arr, temp, target-arr[idx]); // not moving to next index
            temp.pop_back(); // backtrack
        }

        recursion_method(idx+1, result, arr, temp, target); // not pick condition
    }

public:
    vector<vector<int>> OptimalApproach(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        recursion_method(0, res, arr, temp, target);

        return res;
    }
};


// Main function
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result;
    vector<int> temp;

    result = combinationSum().OptimalApproach(candidates, target);

    cout << "All combinations that sum to " << target << " are:" << endl;
    for (auto combination: result) {
        for (int num: combination) {
            cout << num << " ";
        }
        cout << endl;
    };

    return 0;
}