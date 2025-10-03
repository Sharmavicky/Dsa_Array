#include <iostream>
#include <vector>
using namespace std;

/*
    * Class Solution provides multiple approaches to search for a target element
    * in a 2D sorted matrix (LeetCode 74: Search a 2D Matrix).
    *
    * Approaches:
    * 1. LinearSearch        : Brute force, check all cells. O(m * n).
    * 2. BinarySearchApproach_1 :
    *      - First do binary search on rows to locate the correct row.
    *      - Then binary search within that row.
    *      - Time: O(log m + log n).
    * 3. BinarySearchApproach_2 :
    *      - Treat 2D matrix as a 1D sorted array.
    *      - Perform a single binary search using index mapping.
    *      - Time: O(log(m * n)), Space: O(1).
    *
    * Here m = number of rows, n = number of columns.
*/

class Solution {
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int start = 0, end = matrix[0].size() - 1;

        while (start <= end) {
            int midCol = start + (end - start) / 2;

            if (matrix[row][midCol] == target) return true;
            else if (matrix[row][midCol] < target) start = midCol + 1;
            else end = midCol - 1;
        }

        return false;
    }

public:
    bool LinearSearch(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) return true;
            }
        }

        return false;
    }

    bool BinarySearchApproach_1(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int startRow = 0, endRow = rows - 1;

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if (matrix[midRow][0] <= target && target <= matrix[midRow][cols - 1]) {
                return searchInRow(matrix, target, midRow);
            } else if (matrix[midRow][cols - 1] < target) {
                startRow = midRow + 1;
            } else {
                endRow = midRow - 1;
            }
        }

        return false;
    }

    bool BinarySearchApproach_2(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / cols;
            int c = mid % cols;

            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};

// main function
int main() {
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    // vector<vector<int>> mat = {
    //     {1, 3, 5}
    // };

    bool res = Solution().BinarySearchApproach_2(mat, 10);
    cout << res;
    return 0;
};