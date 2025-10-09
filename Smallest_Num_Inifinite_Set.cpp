#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <climits>
using namespace std;

/*
    * Class Name: SmallestInfiniteSet
    * Problem: LeetCode #2336 — Smallest Number in Infinite Set
    *
    * Description:
    * This class simulates an infinite set of positive integers {1, 2, 3, ...}
    * and supports two operations:
    *   - popSmallest(): Removes and returns the smallest integer from the set.
    *   - addBack(num):  Adds a number back to the set if it was previously removed.
    *
    * Implementation Details:
    * - The variable `curr` represents the next smallest number that has not yet been removed.
    * - A sorted `set<int>` named `added` stores numbers that were "added back" into the set.
    * - When calling popSmallest():
    *      • If `added` is not empty, the smallest number from `added` is removed and returned.
    *      • Otherwise, the function returns `curr` and increments it.
    * - When calling addBack(num):
    *      • The number is inserted into `added` only if it is smaller than `curr`
    *        (i.e., it was previously popped and can be reintroduced).
    *
    * Time Complexity:
    * - popSmallest(): O(log n) in the worst case, O(1) if no added elements exist.
    * - addBack(): O(log n)
    *
    * Space Complexity: O(n), where n is the number of added-back elements.
*/

class SmallestInfiniteSet {
private:
    set<int> added;
    int curr;

public:
    SmallestInfiniteSet() {
        curr = 1;
    }

    int popSmallest() {
        if (!added.empty()) {
            int smallest = *added.begin(); // find the smallest integer
            added.erase(added.begin()); // remove it from added
            return smallest; // return smallest integer
        }
        return curr++;
    }

    void addBack(int num) {
        // only add number if it is smaller than curr;
        if (num < curr) added.insert(num);
    }
};