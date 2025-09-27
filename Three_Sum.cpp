#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/* 
    * Implements three different approaches to solve the classic "3Sum" problem:
    *   1. BruteForce Approach (O(n^3)):
    *        - Generate all possible triplets and check if they sum to zero.
    *        - Uses a set to avoid duplicate triplets.
    *   2. Better Approach (O(n^2 log k)):
    *        - Fix one element and use hashing to find the other two.
    *        - Still uses a set to store unique triplets.
    *   3. Optimal Approach (O(n^2)):
    *        - Sort the array and use the two-pointer technique to find triplets.
    *        - Skips duplicates efficiently to avoid redundant results.
    *
    * Time Complexities:
    *   - BruteForce: O(n^3 log k) due to set and sorting triplets
    *   - Better: O(n^2 log k) due to set insertions
    *   - Optimal: O(n^2), most efficient solution
    *
    * Space Complexities:
    *   - BruteForce: O(k) for storing unique triplets
    *   - Better: O(n + k) for hash set and triplets
    *   - Optimal: O(1) auxiliary space (ignoring output)
*/


class Solution {
    public:
    vector<vector<int>> BruteForce(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        set<vector<int>> s; // to store all unique triplets

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplets = {nums[i], nums[j], nums[k]};

                        // sort the triplets
                        sort(triplets.begin(), triplets.end());

                        if (s.find(triplets) == s.end()) {
                            s.insert(triplets);
                            res.push_back(triplets);
                        }
                    }
                }
            }
        }

        return res;
    }

    vector<vector<int>> BetterApproach(vector<int>& nums) {
        int n = nums.size();
        
        set<vector<int>> uniqueTriplets; // store all unique triplets
        
        for (int i=0; i<n; i++) {
            int target = -nums[i];
            set<int> s;
            
            for (int j=i+1; j<n; j++) {
                int third = target - nums[j];
                
                if (s.find(third) != s.end()) {
                    vector<int> triplets = {nums[i], nums[j], third};
                    
                    // sort triplets
                    sort(triplets.begin(), triplets.end());
                    uniqueTriplets.insert(triplets);
                }
                s.insert(nums[j]);
            }
        }
        
        vector<vector<int>> res(uniqueTriplets.begin(), uniqueTriplets.end());
        return res;
    }

    vector<vector<int>> OptimalApproach(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        // sort the array
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = n-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    // add triplets to our res
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;

                    // increment left to avoid duplicates if values are same
                    while (left < right && nums[left] == nums[left-1]) left++;
                }
            }
        }

        return res;
    }
};

// main function
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = Solution().OptimalApproach(nums);

    for (int i=0; i<res.size(); i++) {
        for (int n: res[i]) {
            cout << n << " ";
        }
        cout << "\n";
    }

    return 0;
}