#include <bits/stdc++.h>
using namespace std;

/*
    * Class: Solution
    * ----------------
    * This class solves the "Assign Cookies" problem, where each child has a greed
    * factor and each cookie has a size. A child can be satisfied if they receive
    * a cookie whose size is greater than or equal to their greed factor. Each
    * cookie can be assigned to at most one child. The goal is to maximize the
    * number of satisfied children.
    *
    * The class provides two approaches:
    *
    * 1) BruteForce Approach:
    *    - Both the child and cookies arrays are first sorted in ascending order.
    *    - For each child, the method scans all cookies to find the smallest
    *      available cookie that can satisfy that child.
    *    - Once a cookie is used, it is marked (set to -1) so it cannot be reused.
    *    - This approach is straightforward but inefficient because it uses
    *      nested loops after sorting.
    *
    *    Time Complexity:
    *      O(n log n + m log m + n * m), where n is the number of children and
    *      m is the number of cookies.
    *
    *    Space Complexity:
    *      O(1) extra space (in-place sorting and marking cookies).
    *
    * 2) OptimalApproach (Greedy + Two Pointers):
    *    - Both arrays are sorted in ascending order.
    *    - Two pointers are used: one for children and one for cookies.
    *    - If the current cookie can satisfy the current child, both pointers
    *      move forward and the satisfied children count is increased.
    *    - Otherwise, only the cookie pointer moves forward to try a larger cookie.
    *    - This greedy strategy always assigns the smallest sufficient cookie
    *      to the least greedy child, which leads to an optimal result.
    *
    *    Time Complexity:
    *      O(n log n + m log m), dominated by sorting.
    *
    *    Space Complexity:
    *      O(1) extra space (excluding sorting).
    *
    * Overall, the OptimalApproach is the optimal solution, while BruteForce is
    * included for comparison and learning purposes.
*/

class Solution {
    public:
    int BruteForce(vector<int>& child, vector<int>& cookies) {
        // sort both array
        sort(child.begin(), child.end());
        sort(cookies.begin(), cookies.end());

        int cnt = 0;

        for (int i = 0; i < child.size(); i++) {
            for (int j = 0; j < cookies.size(); j++) {
                if (child[i] <= cookies[j] && cookies[j] != -1) {
                    cnt++;
                    cookies[j] = -1; // mark cookie as used
                    break;
                }
            }
        }

        return cnt;
    }

    int OptimalApproach(vector<int>& child, vector<int>& cookies) {
        // sort both array
        sort(child.begin(), child.end());
        sort(cookies.begin(), cookies.end());

        int cnt = 0;
        int i = 0, j = 0;

        while (i < child.size() && j < cookies.size()) {
            if (child[i] <= cookies[j]) {
                cnt++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return cnt;
    }
};

// main function
int main() {
    Solution sol;

    vector<int> child = {1, 2, 3};
    vector<int> cookies = {1, 1};

    cout << sol.BruteForce(child, cookies) << endl;

    return 0;
}