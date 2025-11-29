#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> BruteForce(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;

        // For each element, scan leftwards to find the previous smaller element
        for (int i=0; i<n; i++) {
            int prevSmaller = -1;
            for (int j=i-1; j>=0; j--) {
                if (arr[j] < arr[i]) {
                    prevSmaller = arr[j];
                    break;
                }
            }

            // Append the found previous smaller element or -1 if none exists
            res.push_back(prevSmaller);
        }

        return res;
    }

    vector<int> Optimal(vector<int>& arr) {
        stack<int> stk;
        vector<int> res;

        for (int i=0; i<arr.size(); i++) {
            // Pop elements from the stack until the top is smaller than the current element
            while (!stk.empty() && stk.top() >= arr[i]) stk.pop();

            // If stack is empty, no smaller element to the left
            res.push_back(stk.empty() ? -1 : stk.top());

            // Push the current element onto the stack
            stk.push(arr[i]);
        }

        return res;
    }
};

// main function
int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    
    vector<int> res = Solution().Optimal(arr);

    cout << "Previous Smaller Elements are: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}