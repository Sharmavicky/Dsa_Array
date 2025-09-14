#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * "Sort Colors" problem (also known as the Dutch National Flag problem).
    * The goal is to sort an array containing only 0s, 1s, and 2s in ascending order.
    *
    * Approaches:
    * 1. BruteForce   → Uses built-in sort (O(n log n)).
    * 2. BetterApproach → Counts occurrences of 0s, 1s, and 2s, then overwrites array (O(n)).
    * 3. OptimalApproach → Dutch National Flag algorithm with three pointers, sorts in one pass (O(n)).
    *
    * This class demonstrates step-by-step optimization from brute force to the most efficient solution.
*/

class Solution {
    public:
    void BruteForce(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }

    void BetterApproach(vector<int>& nums) {
        int cntZeros = 0, cntOnes = 0, cntTwos = 0;

        for (int n: nums) { // loop to count no. of 0s, 1s and 2s
            if (n == 0) cntZeros++;
            else if (n == 1) cntOnes++;
            else cntTwos++;
        }

        int idx = 0;
        
        // replace nums values first with 0s,than 1s and last with 2s
        for(int i=0; i<cntZeros; i++) {
            nums[idx++] = 0;
        }

        for(int i=0; i<cntOnes; i++) {
            nums[idx++] = 1;
        }

        for(int i=0; i<cntTwos; i++) {
            nums[idx++] = 2;
        }
    }

    void OptimalApproach(vector<int>& nums) { // dutch-national flag algorithm
        int low = 0, mid = 0, high = nums.size()-1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

// main function
int main() {
    vector<int> ar = { 2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    Solution().OptimalApproach(ar);

    for (int n: ar) {
        cout << n << " ";
    }

    return 0;
}