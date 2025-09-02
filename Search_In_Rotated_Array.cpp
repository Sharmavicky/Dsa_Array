#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Problem: Search in Rotated Sorted Array
    * Binary Search Approach
    *
    * This function searches for a target element inside a rotated sorted array.
    * A rotated sorted array is an array that was originally sorted in ascending order, but then rotated at some pivot. For example: 
    * [4, 5, 6, 7, 0, 1, 2] is a rotated version of [0, 1, 2, 4, 5, 6, 7].
    
    * Approach:
    * - Use modified binary search.
    * - At each step, check which half (left or right) of the array is sorted.
    * - Decide whether the target lies in the sorted half or the unsorted half,
    *   and adjust search boundaries accordingly.

    * Time Complexity: O(log n)  (binary search on n elements)
    * Space Complexity: O(1)     (constant extra space)
    
    * ______________________________________________________
    
    * Linear Search
    * Iterates through the array one by one until the target is found.

    * Time Complexity: O(n)   (must check each element in the worst case)
    * Space Complexity: O(1)  (no extra space used)
*/

class Solution {
    public:
    int searchRotatedArray(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }

    int LinearSearch(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};

// main function 
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = Solution().searchRotatedArray(nums, target);
    cout << result << endl;
    return 0;
}