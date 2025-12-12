#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    *
    * @brief Implements two approaches to solve the "Count of Smaller Numbers After Self"
    *        problem: a brute-force method and an optimized merge-sort based algorithm.
    *
    * The class contains:
    *
    * 1. BruteForce():
    *        - Directly compares each element with every element to its right.
    *        - Counts how many smaller elements come after each index.
    *        - Time Complexity: O(n²)
    *        - Space Complexity: O(1)
    *
    * 2. MergeSortApproach():
    *        - Uses a modified Merge Sort to count smaller elements on the right.
    *        - Maintains an `indices` array to track original positions.
    *        - During merging, whenever a right-side element is smaller than
    *          a left-side element, it indicates an inversion affecting the
    *          original index of the left element.
    *        - Adds the number of such smaller elements to the result array.
    *        - Time Complexity: O(n log n)
    *        - Space Complexity: O(n)
    *
    * Internal helper functions:
    *    - merge(): Merges two sorted halves while updating the count of
    *               smaller elements for each index.
    *    - mergesort(): Recursively splits the array and re-merges it.
    *
    * Both approaches return a vector<int> where res[i] represents the
    * number of smaller elements to the right of arr[i].
*/

class Solution {
private:
    void merge(vector<int>& arr, vector<int>& indices, vector<int>& res, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int left = low, right = mid + 1, k = 0, count = 0;

        while (left <= mid && right <= high) {
            if (arr[indices[right]] < arr[indices[left]]) {
                count++;
                temp[k++] = indices[right++];
            } else {
                res[indices[left]] += count;
                temp[k++] = indices[left++];
            }
        }

        while (left <= mid) {
            res[indices[left]] += count;
            temp[k++] = indices[left++];
        }

        while (right <= high) {
            temp[k++] = indices[right++];
        }

        for (int i = low; i <= high; i++) {
            indices[i] = temp[i - low];
        }
    }

    void mergesort(vector<int>& arr, vector<int>& indices, vector<int>& res, int low, int high) {
        if (low >= high) return; // base case

        int mid = (low + high) / 2;
        mergesort(arr, indices, res, low, mid); // left half
        mergesort(arr, indices, res, mid + 1, high); // right half

        // merge step
        merge(arr, indices, res, low, mid, high);
    }

public:
    vector<int> BruteForce(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n-1; i++) {
            int count = 0;

            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) count++;
            }

            res[i] = count;
        }

        return res;
    }

    vector<int> MergeSortApproach(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        vector<int> indices(n, 0); // to store original indices

        for (int i = 0; i < n; i++) indices[i] = i;
        mergesort(arr, indices, res, 0, n - 1);
        return res;
    }
};

// main function
int main() {
    vector<int> arr = {5, 2, 6, 1};
    vector<int> res = Solution().MergeSortApproach(arr);

    for (int count: res) {
        cout << count << " ";
    }

    return 0;
}