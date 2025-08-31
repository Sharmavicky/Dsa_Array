#include <iostream>
#include <vector>
using namespace std;

/*
    * Function: PascalTriangle
    * ------------------------
    * Generates the first `n` rows of Pascal's Triangle.
    
    * Logic:
    *  - Each row starts and ends with 1.
    *  - Any middle element is the sum of the two elements directly above it
    *    from the previous row: triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j].
    
    * Example:
    *   Input: n = 5
    *   Output:
    *       1
    *      1 1
    *     1 2 1
    *    1 3 3 1
    *   1 4 6 4 1
    
    * Time Complexity: O(n^2) 
    *   - We fill all elements in the triangle row by row.
    
    * Space Complexity: O(n^2) 
    *   - Entire triangle is stored in a 2D vector.
*/


vector<vector<int>> PascalTriangle(int nums) {
    vector<vector<int>> triangle(nums);
    for(int i=0; i<nums; i++) {
        for(int j=0; j<i+1; j++) {
            if (j == 0 || j == i) triangle[i].push_back(1);
            else triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
        }
    }
    return triangle;
}


// Main Function
int main() {
    int nums = 5;
    vector<vector<int>> result = PascalTriangle(nums);
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}