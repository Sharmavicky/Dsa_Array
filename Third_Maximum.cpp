#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for LLONG_MIN
using namespace std;

/*
    * Problem: Find the third distinct maximum number in an array.
    * If the third distinct maximum does not exist, return the maximum number.
    *
    * Approaches implemented:
    *
    * 1. BruteForce:
    *    - Sorts the array in ascending order.
    *    - Traverses from the end to find up to 3 distinct maximum numbers.
    *    - If fewer than 3 distinct numbers exist, returns the maximum.
    *    - Time Complexity: O(n log n) due to sorting
    *    - Space Complexity: O(1)
    *
    * 2. OptimalApproach:
    *    - Uses three variables (first, second, third) to track top 3 distinct maximums.
    *    - Skips duplicates while scanning the array once.
    *    - If fewer than 3 distinct numbers exist, returns the maximum.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(1)
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());

        int count = 0, maxNum = nums[nums.size()-1];

        int i = nums.size()-2;
        while (i >= 0 && count < 2) {
            if (nums[i] < maxNum) {
                maxNum = nums[i];
                count++;
            }
            i--;
        }
        
        return (count < 2) ? nums.back() : maxNum;
    }

    int OptimalApproach(vector<int>& nums) {
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == first || nums[i] == second || nums[i] == third) continue;

            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if (nums[i] > second) {
                third = second;
                second = nums[i];
            } else if (nums[i] > third) {
                third = nums[i];
            }
        }

        return third == LLONG_MIN ? (int)first : (int)third;
    }
};

// main function
int main() {
    vector<int> nums = {1, 2, -2147483648};
    int res = Solution().OptimalApproach(nums);
    cout << res;
    return 0;
}