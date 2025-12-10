#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    *
    * @brief Provides two methods (BruteForce and Optimal) to remove extra
    *        duplicates from a sorted array such that each element appears
    *        at most twice.
    *
    * The class contains:
    *
    * 1. BruteForce():
    *        - Uses extra space.
    *        - Builds a new vector by checking the element two positions back.
    *        - Time Complexity: O(n)
    *        - Space Complexity: O(n)
    *
    * 2. Optimal():
    *        - In-place algorithm without using extra space.
    *        - Maintains a write pointer (index) to place valid elements.
    *        - Ensures each number appears at most twice.
    *        - Time Complexity: O(n)
    *        - Space Complexity: O(1)
    *
    * Both methods return the modified array after removing extra duplicates.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) { // extra space
        int n = nums.size();
        if (n <= 2) return n;

        vector<int> res;
        res.push_back(nums[0]);
        res.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            if (nums[i] != res[res.size() - 2]) {
                res.push_back(nums[i]);
            }
        }

        return res.size();
    }

    int Optimal(vector<int>& nums) { // in-place
        int n = nums.size();
        if (n <= 2) return n;

        int index = 2; // pointer for next position to insert

        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                index++;
            }
        }

        nums.resize(index); // resize numsay to new length
        return index;
    }
};

// main function
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int newLength = Solution().Optimal(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}