#include <iostream>
#include <vector>
using namespace std;

/*
* Problem: Find the smallest letter in a sorted array of characters that is greater than a given target character.

    * Brute force approach to find the smallest letter in the sorted array that is greater than the given target. If no such letter exists, 
    wraps around and returns the first letter.

    * Time Complexity: O(n)  -> may check all elements
    * Space Complexity: O(1) -> no extra space used
 
    * Optimized approach using Binary Search to find the smallest letter greater than the target in the sorted array. If no such letter exists, 
    wraps around and returns the first letter.

    * Time Complexity: O(log n) -> binary search halves the search space each step
    * Space Complexity: O(1)    -> no extra space used

*/

class Solution {
    public:
    char BruteForce(vector<char>& letters, char target) {
        for (char letter : letters) {
            if (letter > target) {
                return letter;
            }
        }
        return letters[0]; // Wrap around to the first letter if no greater letter is found
    }

    char nextGreaterLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size()-1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (letters[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }

        // If left is out of bounds, wrap around to the start of the array
        return letters[left % letters.size()]; 
    }
};

// main function 
int main() {
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'e';

    char result = Solution().nextGreaterLetter(letters, target);
    cout << result << endl;

    return 0;
}