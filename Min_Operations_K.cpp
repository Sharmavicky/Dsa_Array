#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    * @brief Computes the minimum operations needed based on array sum relative to a target value k.
    *
    * The class contains:
    * 
    * - **arraySum()** (private):  
    *      A utility function that returns the total sum of all elements in the given array.
    *
    * - **minOperations()** (public):  
    *      Determines the minimum number of operations required according to the following logic:
    *        • If the array's total sum is greater than or equal to k, return `totalSum % k`.  
    *        • Otherwise, return the total sum itself.
    *
    * This logic is useful in problems where the goal is to adjust or reduce the sum of an array
    * to match certain modular or threshold constraints.
*/


class Solution {
private:
    int arraySum(vector<int>& arr) {
        int sum = 0;
        for (int num: arr) sum += num;

        return sum;
    }

public:
    int minOperations(vector<int>& arr, int k) {
       int totalSum = arraySum(arr);

        if (totalSum >= k) return totalSum % k;
        return totalSum; 
    }
};

// main function
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 7;

    int res = Solution().minOperations(arr, k);
    cout << res;

    return 0;
}