#include <iostream>
#include <vector>
using namespace std;

/*
    * Problem: Remove duplicates from a sorted array
    
    * Approach 1 (BruteForce):
    *  - Traverse the array and store only unique elements in a temporary vector.
    *  - Copy them back to the original array.
    *  - Time Complexity: O(n) 
    *  - Space Complexity: O(n) (extra vector used)
    
    * Approach 2 (OptimalApproach - Two Pointers):
    *  - Use two pointers to overwrite duplicates in place.
    *  - Left pointer `j` tracks the position of the next unique element.
    *  - Right pointer `i` iterates through the array.
    *  - Whenever a new unique element is found, place it at `arr[j]`.
    *  - Time Complexity: O(n)
    *  - Space Complexity: O(1) (no extra space, done in-place)
    
    * Both functions return the new length of the array after removing duplicates.
*/


class Solution {
    public:
    int BruteForce(vector<int>& arr) {
        vector<int> unique = {};
        int lastVisited = INT32_MIN;

        // Edge case
        if (arr.size() == 0) return 0;

        // traverse the array and store only unique elements
        for (int n: arr) {
            if (n != lastVisited){
                unique.push_back(n);
                lastVisited = n;
            }
        }
        
        // clear original array and copy all unique elements to it
        arr.clear();

        for (int n: unique) {
            arr.push_back(n);
        }

        // return the new length of the array
        return arr.size();
    }

    int OptimalApproach(vector<int>& arr) {
        // Edge case
        if (arr.size() == 0) return 0;

        int j = 1; // pointer for the next unique element position

        for (int i=1; i < arr.size(); i++) {
            if (arr[i] != arr[j-1]) { // if current element is not equal to the last unique element
                arr[j] = arr[i];
                j++;
            }
        }

        return j; // new length of the array
    }
};

// main function
int main() {
    vector<int> ar = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    int result = Solution().OptimalApproach(ar);
    cout << "Array after removing duplicates: \n";
    for (int n: ar) {
        cout << n << " ";
    }

    cout << "\nSize of array after removing duplicates: " << result << "\n";

    return 0;
}