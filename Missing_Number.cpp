#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
    This class provides multiple approaches to solve the "Missing Number" problem.
    Given an array of size n containing distinct numbers from the range [0..n],
    exactly one number is missing. Each method demonstrates a different strategy:

    1. BruteForce       -> Check for each number 0..n if it exists in the array. (O(n^2), O(1))
    2. sortingApproach  -> Sort the array, then find the first index where nums[i] != i. (O(n log n), O(1))
    3. hashMapApproach  -> Store elements in a hash map and find which number in 0..n is missing. (O(n), O(n))
    4. sumApproach      -> Use the formula sum(0..n) - sum(array) to find the missing number. (O(n), O(1))
    5. xorApproach      -> XOR all numbers from 0..n with array elements; remaining number is missing. (O(n), O(1))

    This demonstrates different trade-offs in time & space complexity while solving the same problem.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums) {
        int length = nums.size();

        for (int i = 0; i < length+1; i++) {
            // check if 'i' is present in the array or not
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                return i; // if not than return i
            }
        }

        // if every element is present than return element one greater than size of array
        return length + 1;
    }

    int sortingApproach(vector<int>& nums) {
        // sort the array;
        sort(nums.begin(), nums.end());

        // find the first number that doesn't match with 'i' & return it
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }

        return nums.size();
    }

    int hashMapApproach(vector<int>& nums) {
        unordered_map<int, int> track;
        int length = nums.size();

        // store all elements from the array with it's index
        for (int i = 0; i < length; i++) {
            track[nums[i]] = i;
        }

        // loop from 0 -> n & check if it is present in map or not
        for (int i = 0; i < length+1; i++) {
            if (track.find(i) == track.end()) return i; // if yes, than return 'i'
        }

        return length+1;
    }

    int sumApproach(vector<int>& nums) {
        int currSum = 0, totalSum = 0;
        
        // calculate the sum of numbers present in array;
        for (int n: nums) {
            currSum += n;
        }

        // calculate sum from 0 -> n(size of array)
        for (int i = 0; i < nums.size()+1; i++) {
            totalSum += i;
        }

        // difference is our missing number
        return totalSum - currSum;
    }

    int xorApproach(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0, xorNums = 0;

        // XOR of range [0..n]
        for (int i = 0; i <= n; i++) {
            xorAll ^= i;
        }

        // XOR of all numbers in array
        for (int num : nums) {
            xorNums ^= num;
        }

        // missing number is the difference
        return xorAll ^ xorNums;
    }
};

// main function
int main() {
    vector<int> nums = { 3, 0, 1 };
    int result = Solution().xorApproach(nums);
    cout << result;

    return 0;
}