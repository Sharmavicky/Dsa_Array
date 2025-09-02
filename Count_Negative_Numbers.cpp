#include <iostream>
#include <vector>
using namespace std;

/*
    * Problem: Count the number of negative numbers in a 2D grid where each row is sorted in non-increasing order.

    * Approaches:
    1. BruteForce:
       - Check every element in the grid and count negatives.
       - Time Complexity: O(m * n), Space Complexity: O(1).

    2. countNegatives (Optimized):
       - Use Binary Search on each row to find the first negative number. 
         Since rows are sorted, all elements to the right are also negative.
       - Time Complexity: O(m * log n), Space Complexity: O(1).

    * Parameters:
        - grid: 2D vector of integers (sorted rows in non-increasing order)
    
    * Returns:
        - Total count of negative numbers in the grid.
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