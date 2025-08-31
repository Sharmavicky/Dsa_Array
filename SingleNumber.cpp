#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    * Problem: Find the single non-duplicate element in an array
    
    * Approach 1 (BruteForce - Using HashMap):
    *  - Count the frequency of each element using an unordered_map.
    *  - Return the element with frequency = 1.
    *  - Time Complexity: O(n)  (one pass to build map + one pass to check frequencies)
    *  - Space Complexity: O(n) (extra space for the hash map)
    
    * Approach 2 (Optimal - Using XOR):
    *  - XOR all elements in the array.
    *  - Since x ^ x = 0 and 0 ^ y = y, all duplicate pairs cancel out.
    *  - The remaining value is the single non-duplicate element.
    *  - Time Complexity: O(n)  (single pass through array)
    *  - Space Complexity: O(1) (no extra space, done in-place)
    
    * Note: XOR approach works only if every element appears exactly twice except one.
*/



class Solutions {
    public:
    int BruteForce(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]; // if length of array is 1, return that element
        unordered_map<int, int> count;

        for (int i=0; i<nums.size(); i++) {
            count[nums[i]]++; // count the frequency of each element in the array
        };

        for (auto it: count) {
            if (it.second == 1) return it.first; // return the element which has frequency 1
        }
    };

    int OptimalApproach(vector<int>& nums) {
        int result = 0;
        for (auto it: nums) {
            result ^= it; // XOR all elements in the array
        }

        return result;
    }
};


// Main Function
int main(){
    vector<int> nums = { 2, 2, 1, 1, 3 };
    int result = Solutions().BruteForce(nums);
    cout << result;
    return 0;
}