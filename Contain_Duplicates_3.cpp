#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    *
    * @brief Solves the "Contains Duplicate III" problem using both brute-force
    *        and optimized bucket-based approaches.
    *
    * The goal is to determine whether there exist two distinct indices i and j
    * such that:
    *    - |i − j| ≤ indexDiff
    *    - |nums[i] − nums[j]| ≤ valueDiff
    *
    * The class provides:
    *
    * 1. BruteForce():
    *        - Compares every pair of elements in the array.
    *        - Checks both index distance and value difference constraints.
    *        - Time Complexity: O(n²)
    *        - Space Complexity: O(1)
    *
    * 2. OptimalApproach():
    *        - Uses a bucket-based hashing technique combined with a sliding window.
    *        - Each bucket stores values within a range of size (valueDiff + 1).
    *        - Elements that fall into the same bucket or adjacent buckets are
    *          checked for the value difference condition.
    *        - Maintains at most `indexDiff` elements in the bucket map by removing
    *          outdated entries.
    *        - Time Complexity: O(n)
    *        - Space Complexity: O(min(n, indexDiff))
    *
    * Helper Function:
    *    - getBucketId(): Safely maps numbers (including negatives) to their
    *      corresponding bucket IDs.
    *
    * This optimized approach efficiently handles large input sizes while
    * respecting both index and value constraints.
*/

class Solution {
private:
    long long getBucketId(long long x, long long width) {
        if (x >= 0) return x / width;
        return (x + 1) / width - 1;
    }

public:
    bool BruteForce(vector<int>& arr, int indexDiff, int valueDiff) {
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(i - j) <= indexDiff && abs(arr[i] - arr[j]) <= valueDiff) return true;
            }
        }

        return false;
    }

    bool OptimalApproach(vector<int> &nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;

        unordered_map<long long, long long> bucket;
        long long width = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {

            long long bucketId = getBucketId(nums[i], width);

            // Same bucket
            if (bucket.count(bucketId)) return true;

            // Neighbor buckets
            if (bucket.count(bucketId - 1) && llabs(nums[i] - bucket[bucketId - 1]) <= valueDiff) return true;

            if (bucket.count(bucketId + 1) && llabs(nums[i] - bucket[bucketId + 1]) <= valueDiff) return true;

            // Insert into bucket
            bucket[bucketId] = nums[i];

            // Remove element outside indexDiff window
            if (i >= indexDiff) {
                long long oldBucketId = getBucketId(nums[i - indexDiff], width);
                bucket.erase(oldBucketId);
            }
        }

        return false;
    }
};

// main function
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 1};
    int indexDiff = 3;
    int valueDiff = 0;

    bool res = sol.BruteForce(arr, indexDiff, valueDiff);
    cout << res << endl;

    return 0;
}