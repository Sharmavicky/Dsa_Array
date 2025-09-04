#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Count Negative Numbers in a Sorted Matrix
    (LeetCode 1351)

    Approach 1: BruteForce (O(m * n))
        - Traverse every element of the matrix.
        - Count how many elements are < 0.

    Approach 2: Optimized using Binary Search (O(m * log n))
        - Each row is sorted in non-increasing order.
        - For every row, apply binary search to find the first negative number.
        - Count all elements to the right of that index as negative.

    Functions:
        - BruteForce(vector<vector<int>>& grid):
            Returns count of negatives by checking each element (O(m*n)).

        - countNegatives(vector<vector<int>>& grid):
            Returns count of negatives using binary search on each row (O(m log n)).

    Complexity:
        Time: O(m * log n) for optimized approach
        Space: O(1)
*/


class Solution {
    public:
    int BruteForce(vector<vector<int>>& grid) {
        int cnt = 0;
    
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] < 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        
        for (int i=0; i<grid.size(); i++) {
            int left = 0, right = grid[i].size()-1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (grid[i][mid] < 0) {
                    // count all negative numbers from mid to right
                    cnt += (right - mid + 1);
                    right = mid - 1; // move left to find more negatives
                } else {
                    left = mid + 1; // move right to find negatives
                }
            }
        }

        return cnt;
    }
};

// main function
int main() {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    int result = Solution().countNegatives(grid);
    cout << result << endl;

    return 0;
}