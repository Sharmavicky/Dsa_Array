#include <bits/stdc++.h>
using namespace std;

/*
    * This class provides two approaches to solve the problem of finding
    * the smallest positive missing integer in an unsorted integer array.
    *
    * Methods:
    * 1. BruteForce(vector<int>& nums) -> int
    *    - Checks each integer from 0 to n sequentially.
    *    - Time Complexity: O(n^2)
    *    - Space Complexity: O(1)
    *    - Simple but inefficient for large arrays.
    *
    * 2. Optimal(vector<int>& nums) -> int
    *    - Uses an in-place "cyclic sort" technique to place each number x
    *      at index x-1 if possible.
    *    - Then scans the array to find the first index i where nums[i] != i+1.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(1)
    *    - Efficient and handles negative numbers and duplicates.
    *
    * Example:
    * Input: [3, 4, -1, 1]
    * Output: 2
    *
    * Key Idea:
    * - Only numbers in the range [1, n] are relevant.
    * - Rearranging numbers in-place allows detection of the missing integer without extra space.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if (!found) return i;
        }

        return n + 1;
    }

    int Optimal(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    cout << "First Missing Positive (Brute Force): " << sol.BruteForce(nums) << endl;

    nums = {3, 4, -1, 1}; // Resetting the array for optimal method
    cout << "First Missing Positive (Optimal): " << sol.Optimal(nums) << endl;

    return 0;
}