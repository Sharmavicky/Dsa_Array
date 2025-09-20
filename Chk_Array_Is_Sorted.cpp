#include <iostream>
#include <vector>
using namespace std;

/*
    * This class provides a utility function to check if an array is sorted in ascending order.
    * The function iterates through the array and verifies that every element is greater than
    * or equal to the previous one. It returns true if the array is sorted, and false otherwise.
    * Time Complexity: O(n), Space Complexity: O(1).
*/

class Solution {
    public:
    bool isSorted(vector<int>& nums) {
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                return false;
            }
        }

        return true;
    }
};

// main function
int main() {
    vector<int> nums = { 1, 2, 3, 6, 4 };
    bool res = Solution().isSorted(nums);
    cout << res;
    return 0;
}