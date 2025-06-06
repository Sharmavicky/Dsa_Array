#include <iostream>
#include <vector>
using namespace std;

/*
    Problem here is that we have given an array of stock prices, and we need to find the maximum profit that can be made by buying and selling the stock once.

    Time Complexity: {
        Brute Force Approach: O(n^2)
        Optimal Approach: O(n)
    }
    
    Space Complexity: {
        Brute Force Approach: O(1)
        Optimal Approach: O(1)
    }
*/

class Solution {
    public:
    int BruteForce_approach(vector<int>& p) {
        int max_profit = 0;
        for (int i=0; i<p.size(); i++) {
            for (int j=i+1; j<p.size(); j++) {
                if (p[j] > p[i] && p[j] - p[i] > max_profit) {
                    max_profit = p[j] - p[i];
                }
            }
        }

        return max_profit;
    }

    int Optimal_approach(vector<int>& p) {
        int minPrice = p[0], maxProfit = 0;
        for (int i=1; i<p.size(); i++) {
            if (p[i] < minPrice) { // if current price < minPrice, update minPrice.
                minPrice = p[i];
            } else { // if current price > minPrice, calculate profit & update maxProfit.
                maxProfit = max(maxProfit, p[i] - minPrice);
            }
        }

        return maxProfit;
    }
};

// Main Function
int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    Solution solution;
    int max_profit = solution.Optimal_approach(prices);
    cout << "Maximum profit: " << max_profit << endl;
    return 0;
}