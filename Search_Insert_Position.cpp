#include <iostream>
#include <vector>
using namespace std;

/*
    * Problem: Search Insert Position
    * -------------------------------
    * Given a sorted array and a target value, return the index if the target 
    * is found. If not, return the index where it would be inserted in order.
    
    * Approach 1 (BruteForce):
    *  - Linearly scan the array.
    *  - Return the first index where nums[i] >= val.
    *  - If not found, return length (insert at end).
    *  - Time Complexity: O(n)
    *  - Space Complexity: O(1)
    
    * Approach 2 (Optimal - Binary Search):
    *  - Perform binary search.
    *  - If found, return index.
    *  - If not found, return the insertion point.
    *  - Time Complexity: O(log n)
    *  - Space Complexity: O(1)
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums, int val) {
        int length = nums.size();

        for (int i=0; i<length; i++) {
            if (nums[i] >= val) return i;
        }

        // if target is greater than all elements in the array
        return length;
    }

    int Optimal(vector<int>& nums, int val) {
        int length = nums.size();
        int left = 0, right = length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == val) return mid;
            else if (nums[mid] < val) left = mid + 1;
            else right = mid - 1;
        }

        // at the end of the loop, left is the insertion point
        return left;
    }
};

// main function 
int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int result = Solution().BruteForce(nums, target);
    cout << result;

    return 0;
}