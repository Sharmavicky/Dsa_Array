#include <iostream>
#include <vector>
using namespace std;

/*
    * Problem: Find the minimum element in the sorted rotated array from 1 to n-1;

    * Implements two approaches to find the minimum element 
    * in a rotated sorted array:
    
    * 1. BruteForce:
    *    - Linearly scans the entire array to find the smallest element.
    *    - Time Complexity: O(n), Space Complexity: O(1).
    
    * 2. OptimalApproach:
    *    - Uses a modified binary search to find the minimum efficiently.
    *    - Checks if the subarray is sorted; if yes, takes the leftmost element.
    *    - Otherwise, continues search in the unsorted half.
    *    - Time Complexity: O(log n), Space Complexity: O(1).
    
    * Both methods return the minimum element in the array.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int min = INT32_MAX;
        for (int num: nums) {
            if (num < min) min = num;
        }

        return min;
    }

    int OptimalApproach(vector<int>& nums) {
        int length = nums.size();
        int left = 0, right = length - 1;
        int minimum = INT32_MAX;

        if (length == 1) return nums[0]; // if array contains only 1 element

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[left] <= nums[right]) { // whole array is sorted
                return minimum = min(minimum, nums[left]);
                break;
            }

            if (nums[left] <= nums[mid]) { // left half is sorted
                minimum = min(minimum, nums[left]);
                left = mid + 1;
            } else { // right half is sorted
                minimum = min(minimum, nums[mid]);
                right = mid - 1;
            }
        }

        return minimum;
    }
};

// main function
int main() {
    vector<int> nums = {4, 5, 1, 2, 3};
    int result = Solution().OptimalApproach(nums);
    cout << result;

    return 0;
}