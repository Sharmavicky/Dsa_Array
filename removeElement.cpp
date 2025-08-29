#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * Function: removeElement
    * ------- BruteForce Approach -------------
    * Removes all occurrences of a given value from the vector and returns the new length.
    *
    * Approach:
    *  1. Sort the array so that all occurrences of `val` are contiguous.
    *  2. Find the first occurrence of `val` using a loop.
    *  3. Count how many times `val` appears.
    *  4. Erase the contiguous block of `val` from the vector.
    *
    * Example:
    *   Input: nums = [3, 2, 2, 3], val = 3
    *   Sorted: [2, 2, 3, 3]
    *   Output: 2   (nums = [2, 2])
    *
    * Time Complexity:
    *   - Sorting: O(n log n)
    *   - Finding + Counting: O(n)
    *   - Erase: O(n)
    *   => Overall: O(n log n)
    *
    * Space Complexity:
    *   - O(log n) (due to recursion stack used by std::sort)
    *   - All other steps use O(1) extra space.

    
    * -------- Optmal (Two-pointer) Approach ---------------
    * Approach:
    *  - Use two pointers:
    *      - `i` scans through the array.
    *      - `k` tracks the position to place the next valid (non-val) element.
    *  - Whenever nums[i] != val, copy nums[i] to nums[k] and increment k.
    *  - At the end, elements before index `k` are valid, and the rest can be ignored.
    *
    * Example:
    *   Input: nums = [3, 2, 2, 3], val = 3
    *   Output: 2   (nums = [2, 2])
    *
    * Time Complexity: O(n)   (single pass through the array)
    * Space Complexity: O(1)  (in-place, no extra memory)
*/


class Solution {
    public:
    int BruteForce(vector<int>& nums, int val) {
        // sort the array
        sort(nums.begin(), nums.end());

        int i=0, length = nums.size(), count = 0;
        int firstOccurrence = 0, lastOccurrence = length-1;

        // increment i until we find our target element, which also gives the index of first occurrence
        while (i < length && nums[i] != val) i++;
        if (i == length) return length;
        firstOccurrence = i;

        // loop until nums[i] == target value and count the no. of occurrence
        while (i < length && nums[i] == val) {
            i++;
            count++;
        }
        lastOccurrence = i-1;

        nums.erase(nums.begin()+firstOccurrence, nums.begin() + lastOccurrence+1);

        return length-count;
    }

    int OptimalApproach(vector<int>& nums, int val) {
        int k = 0; // keeps track where to put element that is not equal to val
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        // return k, which is remaining length of the list after removing val
        return k;
    }
};

// main function 
int main() {
    vector<int> num = {3, 3};
    int val = 3;

    int result = Solution().BruteForce(num, val);

    cout << "remaining length is: " << result << endl;

    for(int n: num) {
        if (num.size() == 0) {
            cout << "array is empty\n";
            break;
        }
        cout << n << " ";
    }

    cout << endl;

    return 0;
}