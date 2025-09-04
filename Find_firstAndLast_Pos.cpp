#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Find First and Last Position of Element in Sorted Array
    (LeetCode 34)

    Approaches Implemented:

    1️⃣ BruteForce (O(n))
        - Scan from left to find the first occurrence.
        - Scan from right to find the last occurrence.

    2️⃣ BetterApproach (O(n) worst-case, O(log n + k) average)
        - Use Binary Search to find one occurrence of the target.
        - Expand left and right to find the complete range.

    3️⃣ OptimalApproach (O(log n))
        - Two Binary Searches:
            * One to find the first occurrence.
            * Another to find the last occurrence.
        - This avoids unnecessary scanning.

    Returns:
        - A vector {first_index, last_index}
        - {-1, -1} if the target is not found.

    Complexity:
        - Time: O(log n) for the optimal solution
        - Space: O(1)
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> resultArr = {-1, -1};

        // loop until you find the first occurrence of the target
        int i=0;
        while (i < length) {
            if (nums[i] == target) {
                resultArr[0] = i;
                break;
            }
            i++;
        }

        // loop until you find the last occurrence of the target
        int j = length - 1;
        while (j >= 0) {
            if (nums[j] == target) {
                resultArr[1] = j;
                break;
            }
            j--;
        }

        // return the range array
        return resultArr;
    }

    vector<int> BetterApproach(vector<int>& nums, int target) {
        int length = nums.size(), left=0, right=length-1;
        vector<int> resultArr = {-1, -1};

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                left = mid - 1;
                right = mid + 1;
                resultArr[0] = mid;
                resultArr[1] = mid;

                // loop towards left from the mid to find first occurrence 
                while (left >= 0 && nums[left] == target) {
                    resultArr[0] = left;
                    left--;
                }

                // loop towards right from the mid to find last occurrence
                while (right <= length-1 && nums[right] == target) {
                    resultArr[1] = right;
                    right++;
                }
                // break the outer loop one you found the range
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // return the range array
        return resultArr;
    }

    vector<int> OptimalApproach(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> resultArr = {-1, -1};

        // find the first occurrence of the target
        int left = 0, right = length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                resultArr[0] = mid;
                right = mid - 1; // continue searching in the left half
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // find the last occurrence of the target
        left = 0, right = length - 1;
        while (left <= right) {
            int mid =(left + right) / 2;

            if (nums[mid] == target) {
                resultArr[1] = mid;
                left = mid + 1; // continue searching in the right half
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return resultArr;
    }
};

// main function 
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = Solution().OptimalApproach(nums, target);

    for (int n: result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}