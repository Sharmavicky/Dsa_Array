#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

    You are given two sorted integer arrays, nums1 and nums2, with lengths m and n respectively.
    nums1 has enough space (size m + n) to hold additional elements from nums2.
    Merge nums2 into nums1 as one sorted array in non-decreasing order.

    Solutions:
    - BruteForce: Copy all elements from nums2 into nums1, then sort the entire nums1 array.
    - OptimalApproach: Use three pointers starting from the end of nums1 and nums2, and merge in-place from the back to avoid overwriting elements.

    Time Complexity:
        - BruteForce: O((m + n) * log(m + n)) due to sorting after merging.
        - OptimalApproach: O(m + n) since each element is processed once.

    Space Complexity:
        - BruteForce: O(1) (in-place, except for sort's internal stack, which is negligible for std::sort on vectors).
        - OptimalApproach: O(1) (in-place, no extra space used).

*/

class Solution {
    public:
    void BruteForce(vector<int>& n1, int m, vector<int>& n2, int n) {
        int i = m, j = 0;
        
        if (n == 0) return;

        while (i < m+n && j < n) {
            n1[i] = n2[j];
            i++;
            j++;
        }

        sort(n1.begin(), n1.end());
    }

    void OptimalApproach(vector<int>& n1, int m, vector<int>& n2, int n) {
        int i = m-1; 
        int j = n-1;
        int k = m + n - 1; // keeps track where should position n2 elements

        while (j >= 0) {
            if (i >= 0 && n1[i] > n2[j]) n1[k--] = n1[i--];
            else n1[k--] = n2[j--];
        }
    }
};

// main function
int main() {
    vector<int> n1 = {1, 2, 3, 0, 0, 0};
    vector<int> n2 = {2, 5, 6};
    int m = 3;
    int n = 3;

    Solution solution;

    solution.OptimalApproach(n1, m, n2, n);

    // print n1 array after performing function

    for (int num: n1) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}