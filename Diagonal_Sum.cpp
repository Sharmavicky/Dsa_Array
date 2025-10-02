#include <iostream>
#include <vector>
using namespace std;

/*
    * Problem:
    *   Given a square matrix, return the sum of the primary diagonal
    *   (top-left to bottom-right) and the secondary diagonal
    *   (top-right to bottom-left). If the matrix has an odd dimension,
    *   the center element is included in both diagonals, so it should
    *   be counted only once.
    *
    * Example:
    *   Input: [[1,2,3],
    *           [4,5,6],
    *           [7,8,9]]
    *   Primary diagonal = 1 + 5 + 9 = 15
    *   Secondary diagonal = 3 + 5 + 7 = 15
    *   Total = 30, but center (5) is double-counted → Final = 25
    *
    * Approach:
    *   - Iterate through each row `i` of the matrix.
    *   - Add element at (i, i) [primary diagonal].
    *   - Add element at (i, n-1-i) [secondary diagonal].
    *   - If matrix size is odd and we’re at the middle row, subtract
    *     the center element once to fix double counting.
    *
    * Time Complexity: O(n), since we traverse each row once.
    * Space Complexity: O(1), only using a sum variable.
*/

class Solution {
    public:
    int BruteForce(vector<vector<int>>& matrix) {
        int totalSum = 0;
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            // primary diagonal
            totalSum += matrix[i][i];

            // secondary diagonal
            totalSum+= matrix[i][n - 1 - i];

            // if n is odd, subtract the middle element once
            if (i == n / 2 && n % 2 == 0) totalSum -= matrix[i][i];
        }

        return totalSum;
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

    cout << sol.BruteForce(matrix) << endl;
    return 0;
}