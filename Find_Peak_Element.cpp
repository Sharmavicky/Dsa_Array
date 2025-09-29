#include <iostream>
#include <vector>
using namespace std;

/*
    * Class: Solution
    * ---------------
    * This class provides two methods to solve the "Find Peak Element" problem:
    *
    * 1. BruteForce:
    *    - Scans the array linearly to find the maximum element and its index.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(1)
    *
    * 2. BinarySearchApproach:
    *    - Uses a binary search strategy to efficiently find a peak element.
    *    - At each step, compares nums[mid] with nums[mid+1]:
    *          • If nums[mid] < nums[mid+1], then peak must be on the right side.
    *          • Else, the peak is on the left side (including mid).
    *    - Time Complexity: O(log n)
    *    - Space Complexity: O(1)
    *
    * Note:
    * -----
    * - A "peak element" is defined as an element strictly greater than its neighbors.
    * - The binary search approach guarantees finding one valid peak index,
    *   not necessarily the global maximum.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int peak = INT32_MIN, peakIdx = -1;

        // edge case
        if (nums.size() == 1) return 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > peak) {
                peak = nums[i];
                peakIdx = i;
            }
        }

        return peakIdx;
    }

    int BinarySearchApproach(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid+1]) left =  mid + 1;
            else right = mid;
        }

        return left;
    }
};

// main function
int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int res = Solution().BinarySearchApproach(nums);
    cout << res;
    return 0;
}