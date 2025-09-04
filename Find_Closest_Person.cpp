#include <iostream>
using namespace std;

/*
    * Problem:
    * Given three integer positions x, y, and z, determine which person (at x or y) is closer to the target position z.
    
    * Return:
    *   - 1 if person at y is closer to z,
    *   - 2 if person at x is closer to z,
    *   - 0 if both are equally close.
    
    * Approach:
    * Compare the absolute distances |z - x| and |z - y| to decide.
    
    * Time Complexity: O(1)  (only constant number of operations)
    * Space Complexity: O(1) (no extra space used)
*/

class Solution {
    public:
    int findClosestPerson(int x, int y, int z) {
        if (abs(z-x) > abs(z-y)) return 1;
        else if (abs(z-x) < abs(z-y)) return 2;
        else return 0;
    }
};

// main function
int main() {
    int x = 1, y = 7, z = 5;

    int result = Solution().findClosestPerson(x, y, z);
    cout << result;

    return 0;
}