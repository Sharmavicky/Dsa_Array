#include <iostream>
#include <vector>
using namespace std;

/*
    * Solution class to find the peak index in a mountain array.
    * Provides two approaches:
        * 1. Linear Search (O(n)) - scans the entire array to find the maximum element.
        * 2. Binary Search (O(log n)) - leverages the mountain property to find the peak efficiently.
*/

class Solution {
    public:
    int linearSearch(vector<int>& arr) {
        int m_ht = 0, idx = 0;

        for (int i=0; i < arr.size(); i++) {
            if (arr[i] > m_ht) {
                m_ht = arr[i];
                idx = i;
            }
        }

        return idx;
    }

    int binarySearchApproach(vector<int>& arr) {
        // taken left as 1 and right as length-2 bcz peak element cannot exist on both indices.
        int left = 1, right = arr.size() - 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid; //if arr[mid] > it' previous & next element
            else if (arr[mid-1] < arr[mid]) left = mid + 1; // if arr[mid] > it's previous element
            else right = mid - 1; // if arr[mid] > it's next element
        }
    }
};

// main function
int main() {
    vector<int> nums = { 0, 3, 8, 9, 5, 2 };
    int result = Solution().binarySearchApproach(nums);
    cout << result;

    return 0;
}