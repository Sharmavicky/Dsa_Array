#include <bits/stdc++.h>
using namespace std;

/*
    This class provides a greedy solution to determine the minimum number of
    operations required to make an array non-decreasing.

    In each operation, the algorithm:
    1. Identifies the adjacent pair with the minimum sum.
    2. Merges the pair by replacing it with their sum.
    3. Repeats the process until the array becomes sorted.

    The approach is based on the observation that merging the smallest adjacent
    pair minimizes disruption to the array order while progressing toward a
    sorted state.

    Time Complexity:
        O(n^2) in the worst case due to repeated scans and vector erase operations.

    Space Complexity:
        O(1) extra space (in-place modifications).

    This implementation prioritizes clarity and correctness and follows
    a greedy strategy consistent with the problem constraints.
*/

class Solution {
    // find the position of the minimum adjacent pair sum
    int minPair(vector<int>& nums) {
        int pos = -1;

        int minVal = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i+1] < minVal) {
                minVal = nums[i] + nums[i+1];
                pos = i;
            }
        }

        return pos;
    }

    // check if the array is sorted
    bool isSorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) return false;
        }

        return true;
    }

    // merge the pair at the given position
    void mergePair(vector<int>& nums, int pos) {
        nums[pos] += nums[pos+1];
        nums.erase(nums.begin() + pos + 1);
    }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isSorted(nums)) { 
            int pos = minPair(nums);
            mergePair(nums, pos);
            ops++;
        }

        return ops;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {5, 3, 2, 4, 1};

    int result = sol.minimumPairRemoval(nums);
    cout << "Minimum pairs to remove: " << result << endl;

    return 0;
}