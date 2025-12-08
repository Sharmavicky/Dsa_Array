#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    * @brief Implements matrix reshaping functionality similar to MATLAB's reshape operation.
    *
    * The class provides:
    *
    * 1. **matrixReshape() – O(m × n)**
    *      - Takes a 2D matrix `mat` and reshapes it into a matrix of dimensions `r × c`.
    *      - First checks if reshaping is possible by comparing total element counts
    *        (`m × n` must equal `r × c`).
    *      - If valid, iterates through the original matrix and places elements
    *        sequentially into the new matrix using row/column tracking.
    *      - If reshaping is not possible, returns the original matrix unchanged.
    *
    * This method ensures all elements retain their original traversal order
    * (row-major order) and provides an efficient solution with O(m × n) time
    * and O(r × c) additional space.
*/

class Solution {
    public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        // check if reshape is possible or not
        if (m * n != r * c) return mat;

        vector<vector<int>> res(r, vector<int>(c));
        int row = 0, col = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[row][col] = mat[i][j];
                col++;

                // if we reach end of row, than start from next col
                if (col == c) {
                    col = 0;

                    row++;
                }
            }
        }

        return res;
    }
};

// main function
int main() {
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };

    int r = 1, c = 4;

    vector<vector<int>> res = Solution().matrixReshape(mat, r, c);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}