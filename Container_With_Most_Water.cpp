#include <iostream>
#include <vector>
using namespace std;

/*
    * This class provides two approaches to solve the "Container With Most Water" problem.
    * The goal is to find two lines in the given array `nums` that together with the x-axis
    * form a container, such that the container holds the maximum amount of water.
    
    * Approaches:
    * 1. BruteForce:
    *    - Time Complexity: O(n^2)
    *    - Checks every pair of lines and calculates the area.
    *    - Simple but inefficient for large inputs.
    
    * 2. OptimalApproach:
    *    - Time Complexity: O(n)
    *    - Uses a two-pointer technique (left and right).
    *    - Moves the pointer pointing to the shorter line inward.
    *    - Efficient and widely accepted solution.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int max_area = INT32_MIN;
        int n = nums.size();

        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                int width = j - i, ht = min(nums[i], nums[j]);
                int curr_area = width * ht; // calculate area using length*breadth
                max_area = max(max_area, curr_area); // calculate max_area b/w curr_area & max_area
            }
        }

        return max_area;
    }

    int OptimalApproach(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int max_area = 0;

        while (left < right) {
            int w = right - left;
            int ht = min(nums[left], nums[right]);
            int area = w * ht;
            max_area = max(max_area, area);

            nums[left] < nums[right] ? left++ : right--;
        }

        return max_area;
    }
};

// main function
int main() {
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // vector<int> nums = {1, 1};
    int result = Solution().OptimalApproach(nums);
    cout << result;
    return 0;
}