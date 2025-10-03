#include <iostream>
#include <vector>
using namespace std;

/*
    * Class Solution provides two methods to search for a target in a 2D matrix:
    *
    * 1. LinearSearch:
    *    - Brute force search of all elements.
    *    - Time complexity: O(m * n), Space: O(1)
    *
    * 2. search2DMatrix (Staircase Search):
    *    - Start from top-right corner and move left/down based on comparisons.
    *    - Works for row-wise and column-wise sorted matrices.
    *    - Time complexity: O(m + n), Space: O(1)
    *
    * m = number of rows, n = number of columns.
*/

class Solution {
    public:
    bool LinearSearchApproach(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) return true;
            }
        }

        return false;
    }

    bool StaircaseApproach(vector<vector<int>>& matrix, int target) {
        int rows = 0, cols = matrix[0].size() - 1;

        while (cols >= 0  && rows < matrix.size()) {
            // if current cell is our target than return true
            if (matrix[rows][cols] == target) return true;
            
            // if current cell is less than target, than target lies in the next row
            else if (matrix[rows][cols] < target) rows++;

            // if current cell is greater than target, than target lies in previous col
            else cols--;
        }

        return false;
    }
};

// main function
int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    bool res = sol.StaircaseApproach(mat, 26);
    cout << res;

    return 0;
}