#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    * Class Solution provides three different approaches to find the intersection of two arrays:
    *
    * 1. BruteForce:
    *    - Uses nested loops to compare each element of nums1 with nums2.
    *    - Marks matched elements in nums2 to avoid duplicate matches.
    *    - Time Complexity: O(n * m)
    *    - Space Complexity: O(1)
    *
    * 2. OptimalApproach:
    *    - Uses an unordered_map to count the frequency of elements in nums1.
    *    - Iterates over nums2 and collects elements if they still have a remaining count.
    *    - Handles duplicates correctly.
    *    - Time Complexity: O(n + m)
    *    - Space Complexity: O(n)
    *
    * 3. sortedArrayCase:
    *    - Two-pointer approach for the case when both arrays are already sorted.
    *    - Advances pointers based on comparison of elements to find matches efficiently.
    *    - Time Complexity: O(n + m)
    *    - Space Complexity: O(1)
    *
    * Each method ensures duplicates are handled properly, but the choice of method depends
    * on whether the arrays are sorted and the input size.
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    res.push_back(nums2[j]);
                    nums2[j] = -1; // mark visited elements
                    break; // break inner loop to prevent duplication
                }
            }
        }

        return res;
    }

    vector<int> OptimalApproach(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> seen;
        vector<int> res;

        for (int n: nums1) {
            seen[n]++;
        }

        for (int n: nums2) {
            if (seen.find(n) != seen.end() && seen[n] > 0) {
                res.push_back(n);
                seen[n]--;
            }
        }

        return res;
    }

    vector<int> sortedArrayCase(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> res;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};

// main function
int main() {
    vector<int> n1 = { 4, 4, 5, 9 };
    vector<int> n2 = { 4, 4, 4, 8, 9 };

    vector<int> result = Solution().sortedArrayCase(n1, n2);

    for (int n: result) {
        cout << n << " ";
    }

    return 0;
}