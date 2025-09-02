#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Product of Array Except Self
    -------------------------------------
    * Given an integer array nums, return an array result such that: result[i] = product of all elements in nums except nums[i].

    * Approaches Implemented in this class:
    -------------------------------------
    1. BruteForce:
       - Multiply all elements except the current one using nested loops.
       - Time Complexity: O(n^2)
       - Space Complexity: O(n)

    2. BetterApproach (Using Division):
       - Compute the product of all elements, handle zeros separately, and divide.
       - Time Complexity: O(n)
       - Space Complexity: O(n)
       - ⚠️ Uses division (may not be allowed in some problems).

    3. Optimal (Without Division):
       - Use prefix and suffix products to avoid division.
       - Time Complexity: O(n)
       - Space Complexity: O(1) extra (ignoring result vector).
*/


class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums) {
        vector<int> result = {};
        for(int i=0; i < nums.size(); i++) {
            int prod =  1;
            for(int j=0; j < nums.size(); j++) {
                if (i != j) prod  *= nums[j];
            }
            result.push_back(prod);
        };
        return result;
    };

    vector<int> BetterApproach(vector<int>& nums) {
        vector<int> result = {};
        int prod = 1, zeroCount = 0;

        // calculate the product of all elements
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
                continue;
            }
            prod *= nums[i];
        }

        if (zeroCount > 1) {
            // if there are more than one zero, all products will be zero
            return vector<int>(nums.size(), 0);
        } else if (zeroCount == 1) {
            // if there is one zero, only one product will be non-zero
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] == 0) result.push_back(prod);
                else result.push_back(0);
            }
        } else {
            // if there are no zeros, calculate product for each element
            for (int i=0; i<nums.size(); i++) {
                result.push_back(prod / nums[i]);
            }
        }

        return result;
    }

    vector<int> OptimalApproach(vector<int>& nums) {
        int length = nums.size();
        vector<int> resultArr(length, 1); // initialize result array with 1s

        // calculate prefix products
        int prefix = 1;
        for (int i=0; i<length; i++) {
            resultArr[i] = prefix;
            prefix *= nums[i];
        }

        // calculate suffix products and multiply with prefix products
        int suffix = 1;
        for (int i = length -1; i >= 0; i--) {
            resultArr[i] *= suffix;
            suffix *= nums[i];
        }

        return resultArr;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    vector<int> result =  Solution().BetterApproach(nums);
    for(int i: result) {
        cout << i << " ";
    }
    return 0;
}
