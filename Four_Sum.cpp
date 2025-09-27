#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
    * Implements solutions for the "4Sum" problem:
    * Find all unique quadruplets in the array that sum up to the given target.
    *
    * Approaches:
    * 1. BruteForce Approach (O(n^4 log k)):
    *      - Generate all possible quadruplets with 4 nested loops.
    *      - Sort each quadruplet and use a set to avoid duplicates.
    *
    * 2. Optimal Approach (O(n^3)):
    *      - Sort the array to simplify duplicate handling.
    *      - Fix the first two numbers using nested loops.
    *      - Use a two-pointer technique to find the remaining two numbers.
    *      - Skip duplicates efficiently for all four positions.
    *
    * Time Complexity:
    *   - BruteForce: O(n^4 log k)
    *   - Optimal: O(n^3)
    *
    * Space Complexity:
    *   - BruteForce: O(k) for storing unique quadruplets
    *   - Optimal: O(1) auxiliary (excluding output storage)
*/

class Solution {
    public:
    vector<vector<int>> BruteForce(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();

        set<vector<int>> s; // store unique quadraplets

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    for (int l=k+1; l<n; l++) {
                        if ((long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[l] == target) {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};

                            // sort the quad array;
                            sort(quad.begin(), quad.end());

                            if (s.find(quad) == s.end()) {
                                s.insert(quad);
                                res.push_back(quad);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }

    vector<vector<int>> OptimalApproach(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        // sort the array;
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++) {
            // increment i if nums[i] == nums[i-1] to avoid first duplicates
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j=i+1; j<n; j++) {
                // increment j if j > i+1 and nums[j] == nums[j-1] to avoid second number duplicates
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1, right = n-1;
                while (left < right) {
                    long long sum = (long long) nums[i] + (long long) nums[j] + (long long) nums[left] + (long long) nums[right];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;

                        // update left if it's same as previous to avoid duplicates;
                        while (left < right && nums[left] == nums[left-1]) left++;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return res;
    }
};

// main function
int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> res = Solution().OptimalApproach(nums, target);

    for (int i=0; i<res.size(); i++) {
        for (int j: res[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}