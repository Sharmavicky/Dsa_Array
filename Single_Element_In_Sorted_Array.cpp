#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    * This class provides two approaches to solve the "Single Element in a Sorted Array" problem:
    *
    * 1. BruteForce():
    *    - Uses a hash map to count frequencies of each element.
    *    - Returns the element with frequency 1.
    *    - Time Complexity: O(n), Space Complexity: O(n).
    *
    * 2. OptimalApproach():
    *    - Uses binary search with index parity logic to efficiently locate the unique element.
    *    - Leverages the fact that pairs of equal elements normally occupy even-odd positions.
    *    - Time Complexity: O(log n), Space Complexity: O(1).
    *
    * Example:
    * Input:  [1,1,2,3,3,4,4,8,8]
    * Output: 2
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        unordered_map<int, int> count = {};

        for(int n: nums) { // count frequency of every element
            count[n]++;
        }

        for (auto it: count) {
            if (it.second == 1) return it.first;
        }
    }

    int OptimalApproach(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) return nums[0];

        int left = 0, right = length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid == 0 && nums[mid] != nums[mid+1]) return nums[mid];
            if (mid == length-1 && nums[mid] != nums[mid-1]) return nums[mid];

            if (nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            } else if (mid % 2 != 0) { // both left & right halves are odd
                if (nums[mid] == nums[mid-1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // both left & right halves are even
                if (nums[mid] == nums[mid-1]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};

// main function
int main() {
    vector<int> ar = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    int result = Solution().OptimalApproach(ar);
    cout << result;

    return 0;
}