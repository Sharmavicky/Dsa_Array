#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Spiral Matrix II
    -------------------------
    Generates an n x n matrix filled with numbers from 1 to n^2 in spiral order (clockwise).

    Approach:
    - Maintain four boundaries: top (srow), bottom (erow), left (scol), right (ecol)
    - Fill the matrix layer by layer:
        1. Top row (left → right)
        2. Right column (top → bottom)
        3. Bottom row (right → left)
        4. Left column (bottom → top)
    - After filling a layer, shrink the boundaries inward.
    - Continue until all numbers (1 → n^2) are placed.

    Key Edge Cases:
    - Odd n → center element should only be filled once.
    - Avoid overwriting by checking if top != bottom or left != right before bottom/left loops.

    Time Complexity: O(n^2) — each cell is filled exactly once
    Space Complexity: O(1) extra space (excluding output matrix)
*/

class Solution {
    public:
    vector<vector<int>> generateMatrix(int n) {
        // initiate an empty 2D matrix with all values 0
        vector<vector<int>> res(n, vector<int>(n, 0));

        int srow = 0, erow = n - 1, scol = 0, ecol = n - 1;
        int i = 1;

        while (srow <= erow && scol <= ecol) {
            // top
            for (int j = scol; j <= ecol; j++) res[srow][j] = i++;

            // right
            for (int k = srow + 1; k <= erow; k++) res[k][ecol] = i++;

            // bottom
            if (srow != erow) {
                for (int j = ecol-1; j >= scol; j--) res[erow][j] = i++;
            }

            // left
            if (scol != ecol) {
                for (int k = erow-1; k >= srow+1; k--) res[k][scol] = i++;
            }
        
            srow++; erow--;
            scol++; ecol--;
        }

        return res;
    }
};

// main function
int main() {
    int n = 3;

    Solution sol;
    vector<vector<int>> res = sol.generateMatrix(n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}