#include <iostream>
#include <vector>
using namespace std;

/*
    * Class Solution provides a method to find the maximum number of
    * consecutive 1s in a given binary array. The algorithm scans
    * through the array, keeps track of the current streak of 1s,
    * and updates the maximum streak found so far.
    *
    * Time Complexity: O(n)  - single traversal of the array
    * Space Complexity: O(1) - uses constant extra space
*/

class Solution {
    public:
    int maxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int currOnes = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 1) {
                currOnes++;
            } else if (nums[i] == 0) {
                maxOnes = max(maxOnes, currOnes);
                currOnes = 0;
            }
        }

        // compare in case array ends with 1
        maxOnes = max(maxOnes, currOnes);

        return maxOnes;
    }
};

// main fucntion
int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = Solution().maxConsecutiveOnes(nums);
    cout << result;
    return 0;
}