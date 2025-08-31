#include <iostream>
#include <vector>
using namespace std;

/*
    * Function: BruteForce
    * ---------------------
    * Finds the median of two sorted arrays by merging them.
    
    * Steps:
    *  - Merge both sorted arrays into a temporary vector.
    *  - If total size is odd, return the middle element.
    *  - If total size is even, return the average of the two middle elements.
    
    * Time Complexity: O(n + m) 
    *   - Merging both arrays requires traversing all elements.
    
    * Space Complexity: O(n + m) 
    *   - Extra vector used to store merged result.
*/

class Solution {
    public:
    double BruteForce(vector<int>& n1, vector<int>& n2) {
        vector<int> temp = {};
        int i=0, j=0;

        while (i < n1.size() && j < n2.size()) {
            if (n1[i] < n2[j]) {
                temp.push_back(n1[i]);
                i++;
            } else {
                temp.push_back(n2[j]);
                j++;
            }
        }

        while (i < n1.size()) { // if n2 is exhausted, then add remaining elements of n1
            temp.push_back(n1[i]);
            i++;
        }

        while (j < n2.size()) { // if n1 is exhausted, then add remaining elements of n2
            temp.push_back(n2[j]);
            j++;
        }

        if (temp.size() % 2 == 0) { // if size is even, then return avg of two middle elements
            return (temp[temp.size()/2 - 1] + temp[temp.size()/2]) / 2.0;
        } else { // if size is odd, then return middle element
            return temp[temp.size()/2];
        }
    }
};


// Main Function
int main() {
    vector<int> n1 = { 1, 3 };
    vector<int> n2 = { 2, 4 };

    double result = Solution().BruteForce(n1, n2);
    cout << result << endl;
    return 0;
}