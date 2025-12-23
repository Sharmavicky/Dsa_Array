#include <bits/stdc++.h>
using namespace std;

/*
    * The NumArray class implements an efficient solution for handling
    * range sum queries on an integer array using the Prefix Sum technique.
    *
    * During object construction, a prefix array is created where each
    * element stores the cumulative sum of the array up to that index.
    * This preprocessing allows any sumRange(left, right) query to be
    * answered in constant time.
    *
    * The solution ensures optimal performance with O(n) preprocessing
    * time and O(1) time per query, making it suitable for multiple queries.
*/

class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        prefix.resize(n);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

// main function
int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << endl; // Output: 1
    cout << numArray.sumRange(2, 5) << endl; // Output: -1
    cout << numArray.sumRange(0, 5) << endl; // Output: -3

    return 0;
}