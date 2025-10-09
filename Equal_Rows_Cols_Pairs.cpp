#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    * Class Name: Solution
    * Method: BruteForce
    * Problem: Equal Row and Column Pairs (LeetCode #2352)
    *
    * Description:
    * This class provides a brute-force style but efficient approach to count
    * how many pairs of rows and columns in a square matrix are identical.
    *
    * The solution leverages hashing by converting each row and column into a
    * unique string representation. Rows are stored in an unordered_map, and
    * each column is checked against it to count matches.
    *
    * Time Complexity:  O(n^2)
    * Space Complexity: O(n^2)
    *
    * The approach efficiently compares rows and columns without manually
    * comparing each element pair by pair.
*/

class Solution {
    public:
    int BruteForce(vector<vector<int>>& mat) {
        unordered_map<string, int> seen;
        int n = mat.size();

        // convert every row into string and store in map
        for (int i=0; i<n; i++) {
            string key = "";

            for (int j=0; j<n; j++) {
                key += to_string(mat[i][j]) + ", ";
            }

            seen[key]++;
        }

        // check if column matches row or not
        int pairs = 0;

        for (int j=0; j<n; j++) {
            string key = "";

            for (int i=0; i<n; i++) {
                key += to_string(mat[i][j]) + ", ";
            }

            if (seen.find(key) != seen.end()) {
                pairs += seen[key];
            }
        }

        return pairs;
    }
};

// main function
int main() {
    vector<vector<int>> matrix = {
        {3, 2, 1},
        {1, 7, 6},
        {2, 7, 7}
    };
    Solution sol;

    int res = sol.BruteForce(matrix);
    cout << res;
    return 0;
}