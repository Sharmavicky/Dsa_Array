#include <iostream>
#include <vector>
using namespace std;

/*
    Problem:
    * Given a flowerbed (represented as a binary array) and a number n, determine if n new flowers can be planted without violating the rule that no two flowers can be adjacent.

    * Approach:
    - Traverse each plot in the flowerbed.
    - If the current plot is empty (0), check if both left and right plots are also empty (or out of bounds).
    - If yes, plant a flower (mark as 1) and increase the counter.
    - Stop early if we already planted n flowers.

    * Time Complexity: O(n), where n is the size of the flowerbed.
    * Space Complexity: O(1), since we modify the array in place.
*/

class Solution {
    public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                // check if left and right plots are empty or out of bounds
                bool emptyLeft = (i == 0 || flowerbed[i-1] == 0);
                bool emptyRight = (i == size-1 || flowerbed[i+1] == 0);

                // place a flower if both sides are empty
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; // place a flower
                    count++;
                    if (count >= n) return true; // early exit if done
                }
            }
        }

        return count >= n;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;

    bool result = solution.canPlaceFlowers(flowerbed, n);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
