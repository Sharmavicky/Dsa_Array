#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Spiral Matrix Traversal
    --------------------------------
    This class provides a method to traverse a given 2D matrix
    in a spiral order (clockwise), returning all elements in that sequence.

    Approach:
    - We maintain four boundaries (top, bottom, left, right).
    - Traverse the matrix layer by layer:
        1. From left → right (top row)
        2. From top → bottom (right column)
        3. From right → left (bottom row)
        4. From bottom → top (left column)
    - After completing one layer, shrink the boundaries inward and repeat
      until all elements are visited.

    Time Complexity: O(m * n)
    Space Complexity: O(1)  (ignoring the output vector)
*/

class Solution {
    public:
    vector<int> sprialMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, erow = m - 1, scol = 0, ecol = n - 1;
        vector<int> res;

        while (srow <= erow && scol <= ecol) {
            // top
            for (int i=scol; i<=ecol; i++) {
                res.push_back(matrix[srow][i]);
            }

            // right
            for (int j=srow+1; j<=erow; j++) {
                res.push_back(matrix[j][ecol]);
            }

            // bottom
            for (int i=ecol-1; i>=scol; i--) {
                if (srow == erow) break;
                res.push_back(matrix[erow][i]);
            }

            // left
            for (int j=erow-1; j>=srow+1; j--) {
                if (scol == ecol) break;
                res.push_back(matrix[j][scol]);
            }

            srow++; erow--;
            scol++; ecol--;
        }

        return res;
    }
};

// main function
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    Solution sol;
    vector<int> res = sol.sprialMatrix(matrix);

    for (int n: res) {
        cout << n << " ";
    }
    
    return 0;
}