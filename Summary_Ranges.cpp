#include <bits/stdc++.h>
using namespace std;

/*
    * The Solution class provides an efficient implementation to summarize
    * consecutive ranges from a sorted array of unique integers.
    *
    * The summaryRanges method scans the array in a single pass and groups
    * consecutive numbers into ranges. Each range is represented either as
    * a single number (when start == end) or in the format "start->end".
    *
    * This approach ensures:
    * - Each number is covered exactly once
    * - No extra numbers are included in any range
    * - Time complexity of O(n) with constant extra space
    *
    * This solution is optimal for handling large input sizes.
*/

class Solution {
    public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int start = nums[i];

            while (i + 1 < n && nums[i + 1] == nums[i] + 1) i++;

            int end = nums[i];

            if (start == end) res.push_back(to_string(start));
            else res.push_back(to_string(start) + "->" + to_string(end));
        }

        return res;
    }
};

// main function
int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> res = Solution().summaryRanges(nums);

    for (const string& range : res) {
        cout << range << " ";
    }
    cout << endl;

    return 0;
}