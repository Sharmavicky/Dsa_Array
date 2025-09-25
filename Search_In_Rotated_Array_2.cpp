#include <iostream>
#include <vector>
using namespace std;

/*
    * This class provides two methods to determine whether a target element
    * exists in a rotated sorted array that may contain duplicates.
    *
    * Methods:
    * 1. LinearSearch:
    *    - Traverses the array sequentially to check for the target.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(1)
    *
    * 2. BinarySearch:
    *    - Uses a modified binary search to handle rotation and duplicates.
    *    - Handles edge case when nums[left] == nums[mid] == nums[right] by shrinking the search space.
    *    - Time Complexity: O(log n) on average, but can degrade to O(n) in the presence of many duplicates.
    *    - Space Complexity: O(1)
 *
*/

class Solution {
    public:
    bool LinearSearch(vector<int>& nums, int target) {
        for (int n: nums) {
            if (n == target) return true;
        }

        return false;
    }

    bool BinarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return true;

            // if duplicates found
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }

            // left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

// main function
int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 3;

    bool res = Solution().BinarySearch(nums, target);
    cout << res;
    return 0;
}