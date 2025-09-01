#include <iostream>
#include <vector>
using namespace std;

/*
    * BruteForce Approach:
        - For every 0 at index i, find the next non-zero at index j and swap.
        - Preserves order but can take O(n^2) in the worst case.

        * Time Complexity: O(n^2)
        * Space Complexity: O(1)
    
    * Better Approach:
        - Copy all non-zero elements into a new array.
        - Count zeros and append them at the end.
        - Copy the result back to nums.

       * Time Complexity: O(n)
       * Space Complexity: O(n) → uses an extra array
       * Note: This approach is valid only if copying of array is allowed.
       
    * Optimal Approach 1 (Snowball Technique):
        - Use a "snowball" to count zeros.
        - For each non-zero, swap it with the position offset by the snowball size.
        - This maintains relative order and is done in one pass.

        * Time Complexity: O(n)
        * Space Complexity: O(1)
    
    * Optimal Approach 2 (Two-Pointer Technique):
        - Use one pointer to track the position to insert the next non-zero.
        - First pass: Move all non-zeros to the front.
        - Second pass: Fill the rest of the array with zeros.

        * Time Complexity: O(n)
        * Space Complexity: O(1)
    
*/

class Solution {
    public:
    void BruteForce(vector<int>& nums) {
        int i = 0, j = i+1;

        while (i < nums.size()-1) {
            if (nums[i] == 0) {
                while (j < nums.size() && nums[j] == 0) {
                    j++;
                }

                if (j < nums.size()) {
                    swap(nums[i], nums[j]);
                }
            }
            i++;
            j = i + 1; // Reset j to the next position after i
        }
    }

    void BetterApproach(vector<int>& nums) {
        vector<int> result = {};
        int cntZero = 0;

        for (int n: nums) {
            if (n != 0) result.push_back(n);
            else cntZero++;
        }

        // append zeros at the end
        while (cntZero--) {
            result.push_back(0);
        }

        nums = result; // copy result back to nums.
    }

    void OptimalApproach_1(vector<int>& nums) {
        int snowBallSize = 0;

        for(int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                snowBallSize++;
            } else if (snowBallSize > 0) {
                swap(nums[i], nums[i - snowBallSize]);
            }
        }
    }

    void OptimalApproach_2(vector<int>& nums) {
        int insertIdx = 0;

        // move non-zero elements to the front
        for (int n: nums) {
            if (n != 0) {
                nums[insertIdx++] = n;
            }
        }

        // fill remaining array space with 0's 
        while (insertIdx < nums.size()) {
            nums[insertIdx++] = 0;
        }
    }
};


// main function
int main() {
    vector<int> nums = {0, 1, 3, 12, 0};
    Solution().OptimalApproach_2(nums);
    
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}