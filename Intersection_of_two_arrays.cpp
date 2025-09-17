#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
    * Class Solution provides two approaches to find the intersection of two integer arrays:
    *
    * 1. BruteForce:
    *    - Uses nested loops to compare each element of nums1 with every element of nums2.
    *    - Stores common elements in an unordered_set to avoid duplicates.
    *    - Time Complexity: O(n * m), Space Complexity: O(min(n, m)).
    *
    * 2. OptimalApproach:
    *    - Uses an unordered_set to store elements of the first array.
    *    - Iterates through the second array and checks for common elements using constant-time lookups.
    *    - Stores results in another unordered_set to avoid duplicates.
    *    - Time Complexity: O(n + m) on average, Space Complexity: O(n).
    *
    * Both methods return the intersection as a vector<int>.
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> resSet;
        
        // loop throught every element check if it is present in set or not
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) resSet.insert(nums1[i]); // if not than add it into set
            }
        }

        // return the vector<int> form of resSet
        return vector<int>(resSet.begin(), resSet.end());
    }

    vector<int> OptimalApproach(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> track(nums1.begin(), nums1.end()); // stores all elements of nums1
        unordered_set<int> resSet = {};

        //  loop through second array & check if each element in present in resSet or not.
        for (int n: nums2) {
            if (track.find(n) != track.end()) { // if not than add it to resSet
                resSet.insert(n);
            }
        }

        // return the resSet as vector<int>
        return vector<int>(resSet.begin(), resSet.end());
    }
};

// main function
int main() {
    vector<int> n1 = { 4, 9, 5 };
    vector<int> n2 = { 9, 4, 9, 8, 4 };

    vector<int> result = Solution().BruteForce(n1, n2);

    cout << "intersections elements are: \n";
    for (int n: result) {
        cout << n << " ";
    }

    return 0;
};