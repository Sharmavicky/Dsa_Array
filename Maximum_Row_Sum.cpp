#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    * Problem:
    *   Given a 2D matrix of integers, return the maximum sum among all rows.
    *
    * Example:
    *   Input: [[1, 2, 3],
    *           [4, 5, 6],
    *           [7, 8, 9]]
    *   Row sums = [6, 15, 24]
    *   Maximum = 24
    *
    * Approach:
    *   - Iterate through each row of the matrix.
    *   - Compute the sum of all elements in that row.
    *   - Track the maximum row sum encountered so far.
    *   - Return the maximum after all rows are processed.
    *
    * Time Complexity: O(m × n), where m = number of rows, n = number of columns.
    * Space Complexity: O(1), since only counters are used.
*/

class Solution {
    public:
    int maximumRowSum(vector<vector<int>>& matrix) {
        int maxRowSum = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            int currRowSum = 0;

            // calculate sum of the current row
            for (int j = 0; j < cols; j++) {
                currRowSum += matrix[i][j];
            }

            // update maxRowSum if current row sum is greater
            maxRowSum = max(maxRowSum, currRowSum);
        }

        return maxRowSum;
    }
};

// main function
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << sol.maximumRowSum(matrix) << endl;

    return 0;
}