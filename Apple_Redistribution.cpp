#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    *
    * @brief Determines the minimum number of boxes required to store all apples
    *        given the capacities of available boxes.
    *
    * The approach followed is greedy:
    *   - First, compute the total number of apples.
    *   - Sort the box capacities in descending order.
    *   - Select the largest capacity boxes first until all apples are placed.
    *
    * This greedy strategy works because using boxes with maximum capacity
    * minimizes the total number of boxes needed.
    *
    * Method:
    *   - minimumBoxes():
    *        • Calculates the total apples.
    *        • Sorts capacities in decreasing order.
    *        • Iteratively subtracts box capacities until all apples are stored.
    *
    * Time Complexity: O(n + m log m)
    *   - n = number of apple piles
    *   - m = number of boxes
    *
    * Space Complexity: O(1) (excluding sorting overhead)
*/

class Solution {
    public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int n = apples.size();
        int m = capacity.size();

        // total apples
        int totalApples = 0;
        for (int apple: apples) totalApples += apple;

        // sort capacities in descending order to minimize number of boxes used
        sort(capacity.begin(), capacity.end(), greater<int>());

        // count number of boxes to redistribute apples
        int boxCount = 0;
        for (int i = 0; i < m; i++) {
            if (totalApples <= 0) break;

            totalApples -= capacity[i];
            boxCount++;
        }

        return boxCount;
    }
};

// main function
int main() {
    vector<int> apples = {10, 20, 30};
    vector<int> capacity = {15, 25, 10, 20, 30};

    Solution sol;
    int result = sol.minimumBoxes(apples, capacity);

    cout << "Minimum number of boxes required: " << result << endl;

    return 0;
}