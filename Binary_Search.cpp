#include <iostream>
#include <vector>
using namespace std;

/*
    * Function: binarySearch
    * Purpose: Iterative implementation of Binary Search algorithm.
    * Given a sorted array (nums) and a target value, 
    * returns the index of target if found, otherwise -1.

    * Time Complexity: O(log n), because the search space is halved in each iteration.
    * Space Complexity: O(1), since no extra space is used apart from variables.

    * Parameters:
        - nums: sorted array of integers
        - target: integer value to be searched
    * Returns:
        - index of target in nums if found, else -1

----------------------------------------------------------------------------------------------

    * Function: recursiveBinarySearch
    * Purpose: Recursive implementation of Binary Search algorithm.
    * Given a sorted array (arr) and a target value, 
    * returns the index of target if found, otherwise -1.

    * Time Complexity: O(log n), because the search space is halved with each recursion.
    * Space Complexity: O(log n), due to recursive call stack.

    * Parameters:
        - arr: sorted array of integers
        - target: integer value to be searched
        - left: left index of current search space
        - right: right index of current search space
    * Returns:
        - index of target in arr if found, else -1
*/

class Solution {
    public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = (left + right) / 2;

            // If target is found, return the index
            if (nums[mid] == target) return mid;

            //Search in right half, if target is greater than mid element
            else if (nums[mid] < target) left = mid + 1;

            // Search in left half, if target is less than mid element
            else right = mid - 1;
        }
    }

    int recursiveBinarySearch(vector<int>& arr, int target, int left, int right) {
        // Base case
        if (left > right) return -1;

        // if arr contains only one element
        if (left == right) {
            if (arr[left] == target) return left;
            else return -1;
        } else { // if arr contains more than one element
            int mid = (left + right) / 2;

            // if target is found, return the index
            if (arr[mid] == target) return mid;

            // search in right half, if target is greater than mid element
            else if (arr[mid] < target) { return recursiveBinarySearch(arr, target, mid + 1, right); }

            // search in left half, if target is less than mid element
            else { return recursiveBinarySearch(arr, target, left, mid - 1); }
        }
    }
};

// Main function
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;

    Solution solution;
    int index = solution.binarySearch(arr, target);
    cout << "Index of " << target << " using binary search: " << index << endl;

    index = solution.recursiveBinarySearch(arr, target, 0, arr.size() - 1);
    cout << "Index of " << target << " using recursive binary search: " << index << endl;

    return 0;
}