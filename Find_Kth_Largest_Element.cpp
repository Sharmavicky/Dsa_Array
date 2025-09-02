#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * BruteForce:
       - Sort the array in ascending order.
       - The Kth largest element will be at index (n - k), where n = size of array.
       
       Time Complexity: O(n log n)  -> due to sorting
       Space Complexity: O(1)       -> in-place sort (ignoring sort’s internal stack)

*/

class Solution {
    public:
    int BruteForce(vector<int>& nums, int k) {
        // sort the array
        sort(nums.begin(), nums.end());

        // return the kth largest element
        return nums[nums.size() - k];
    }
};

// main function 
int main() {
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << "The " << k << "th largest element is: " << sol.BruteForce(nums, k) << endl;
    return 0;
}