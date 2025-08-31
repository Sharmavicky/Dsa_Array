#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    * Problem: Two Sum
    * ----------------
    * Given an array of integers and a target value, return the indices of the 
    * two numbers such that they add up to the target.
    
    * Approach 1 (BruteForce):
    *  - Check all possible pairs using nested loops.
    *  - Return the first pair that sums to target.
    *  - Time Complexity: O(n^2)
    *  - Space Complexity: O(1)
    
    * Approach 2 (Optimal - Hash Map):
    *  - Use a hash map to store numbers and their indices.
    *  - For each number, check if its complement (target - current) is in the map.
    *  - If yes, return the pair of indices.
    *  - Time Complexity: O(n)
    *  - Space Complexity: O(n)
*/


class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums, int target) {
        vector<int> result = {};
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result; // Return immediately after finding the first pair
                }
            }
        }
        return result; // Return empty vector if no pair is found
    }

    vector<int> OptimalApproach(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // map to store the number and it's index

        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];

            // if remaining number is found in map, return the indices
            if (num_map.find(remaining) != num_map.end()) return { num_map[remaining], i }; 

            // else, store the number and it's index in map
            num_map[nums[i]] = i;
        }

        return {}; // return empty vector if no pair is found
    }
}; 

// main function
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = Solution().OptimalApproach(nums, target);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}