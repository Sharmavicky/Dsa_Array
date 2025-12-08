#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    * @brief Provides two methods to reshape a given 2D matrix into dimensions r × c.
    *
    * The class implements:
    *
    * 1. **BruteForce() – O(m × n)**
    *      - First checks if the reshape operation is valid by ensuring the total number
    *        of elements remains the same (`m × n == r × c`).
    *      - Iterates over the original matrix in row-major order and manually tracks
    *        row and column indices (`row`, `col`) while filling the new matrix.
    *      - Resets the column index and increments the row index once a row is filled.
    *      - Returns the reshaped matrix or the original matrix if reshape is impossible.
    *
    * 2. **Optimal() – O(m × n)**
    *      - Uses a single loop from `0` to `m × n - 1` and computes positions in both
    *        matrices using mathematical mapping:
    *            - New matrix position: `(i / c, i % c)`
    *            - Old matrix position: `(i / n, i % n)`
    *      - Eliminates explicit nested loops and manual row/column management.
    *      - Produces a cleaner and more optimized reshape operation.
    *
    * Both approaches maintain **row-major traversal order**, ensuring that the relative
    * ordering of elements remains unchanged. The methods demonstrate the transition from
    * a manual index-tracking solution to a mathematically optimized mapping technique.
*/

class Solution {
    public:
    vector<vector<int>> BruteForce(vector<vector<int>>& mat, int r, int c) {
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

    vector<vector<int>> Optimal(vector<vector<int>> &mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();

        // reshape not possible
        if (m * n != r * c)
            return mat;

        vector<vector<int>> res(r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = mat[i / n][i % n];
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

    vector<vector<int>> res = Solution().Optimal(mat, r, c);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}