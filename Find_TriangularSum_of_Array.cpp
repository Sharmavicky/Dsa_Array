#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n-1; j++) {
                nums[j] = (nums[j] + nums[j+1]) % 10; // sum and take modulo 10
                nums.pop_back(); // remove the last element
            }
        }

        return nums[0];
    }
};

// main function
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    int res = Solution().BruteForce(nums);
    cout << res;

    return 0;
}