#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    * Problem:
    * Given an array nums containing n numbers in the range [0..n-1] or [1..n],
    * exactly one number appears twice. Return the duplicate number.
    *
    * Example:
    * Input:  nums = [1,3,4,2,2]
    * Output: 2
    *
    * Approaches:
    *
    * 1. BruteForce (O(n^2), O(1)):
    *    - Compare every pair of elements in the array.
    *    - Return the first duplicate found.
    *
    * 2. Better (O(n), O(n)):
    *    - Use an unordered_map (or hash set) to track frequency of elements.
    *    - Return the first element whose count exceeds 1.
    *
    * 3. Optimal (O(n), O(1)):
    *    - Use the sum formula to calculate the expected sum of numbers from 0..n-1 (or 1..n).
    *    - The difference between the actual array sum and expected sum gives the duplicate number.
    *
    * Notes:
    * - BruteForce is simple but inefficient for large arrays.
    * - Better approach uses extra space but runs in linear time.
    * - Optimal approach assumes exactly one duplicate exists and modifies no extra space.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return -1;
    }

    int Better(vector<int>& nums) {
        unordered_map<int, int> track;

        for (int n: nums) {
            track[n]++;
            if (track[n] >  1) return n;
        }

        return -1;
    }

    int Optimal(vector<int>& nums) {
        int n = nums.size();
        int totalSum = (n - 1) * n / 2, currSum = 0;

        for (int n : nums){
            currSum += n;
        }

        return currSum - totalSum;
    }
};

// main function
int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    int res = Solution().BruteForce(nums);
    cout << res;
    return 0;
}