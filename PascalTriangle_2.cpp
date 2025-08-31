#include <iostream>
#include <vector>
using namespace std;

/*
    * Function: PascalTriangle_two
    * ------------------------
    * Generates the `n`th row of Pascal's Triangle.
    
    * Logic:
    *  - Each row starts and ends with 1.
    *  - Any middle element is the sum of the two elements directly above it
    *    from the previous row: triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j].
    
    * Example:
    *   Input: n = 3
    *   Output: [1, 3, 3, 1]
    
    * Time Complexity: O(n^2) 
    *   - We fill all elements in the triangle up to the nth row.
    
    * Space Complexity: O(n^2) 
    *   - Entire triangle is stored in a 2D vector, but we only return one row.
*/

vector<int> PascalTriangle_two(int nums) {
    vector<vector<int>> triangle(nums+1);
    for(int i=0; i<=nums+1; i++) {
        for(int j=0; j<i+1; j++) {
            if (j == 0 || j == i) triangle[i].push_back(1);
            else triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
        }
    }
    return triangle[nums];
}


// Main Function
int main() {
    int nums = 3;
    vector<int> result = PascalTriangle_two(nums);

    for (int it: result) {
        cout << it << " ";
    };

    return 0;
}