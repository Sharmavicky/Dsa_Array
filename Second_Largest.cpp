#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * This class provides two approaches to find the second largest element in an array:
        1. BruteForce(): Sorts the array and scans from the end to find the second largest unique element.
        2. Better(): Uses a single pass with O(1) space to track the largest and second largest values.
    * Both methods handle duplicates and return -1 if no second largest element exists
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());

        int cnt = 0, i = nums.size()-1, s_max = INT32_MAX;

        while (cnt < 2 && i >= 0) {
            if (nums[i] < s_max) {
                s_max = nums[i];
                cnt++;
            }
            i--;
        }

        return s_max == INT32_MIN ? -1 : s_max;
    }

    int Optimized(vector<int>& nums) {
        int max = INT32_MIN, s_max = INT32_MIN;

        for (int n: nums) {
            if (n > max) {
                s_max = max;
                max = n;
            } else if (n < max && n > s_max) {
                s_max = n;
            }
        }

        // if array has only one element than
        return s_max == INT32_MIN ? -1 : s_max;
    }
};

// main function
int main() {
    vector<int> nums = { 5, 1, 3, 8, 39 };
    int res = Solution().Optimized(nums);
    cout << res;
    return 0;
}
