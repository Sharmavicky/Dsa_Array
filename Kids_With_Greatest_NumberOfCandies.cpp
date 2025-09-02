#include <iostream>
#include <vector>
using namespace std;

/*
    * Problem: Given an array 'candies' where candies[i] represents the number of candies each kid has, and an integer 'extraCandies'.
    * Determine if giving all the extra candies to a kid would make them have the greatest number of candies among all kids.

    * Approach (BruteForce):
        1. Find the maximum number of candies any kid currently has.
        2. For each kid, check if their candies + extraCandies >= maxCandies.
        3. Store the result (true/false) in a boolean vector.

    * Time Complexity: O(n) -> one pass to find max, another pass to check each kid.
    * Space Complexity: O(n) -> to store the boolean result.

    * Parameters:
        - candies: vector<int>, number of candies each kid has
        - extraCandies: int, number of extra candies available

    * Returns:
        - vector<bool>, where result[i] is true if kid i can have the greatest 
          number of candies after receiving extraCandies, else false.
*/


class Solution {
    public:
    vector<bool> BruteForce(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandies = 0;
        // Find the maximum number of candies
        for (int candy: candies) {
            if (candy > maxCandies) maxCandies = candy;
        }

        // chk if each kid can have the greatest number of candies
        for (int candy: candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};

// Main Function
int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = Solution().BruteForce(candies, extraCandies);
    for (bool canHave : result) {
        cout << (canHave ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}