#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Plus One

    Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
    The digits are stored such that the most significant digit is at the head of the list.
    Return the resulting array of digits after adding one.

    Solutions:
    - BruteForce: Convert the array to a number, add one, then convert back to an array.
      * Limitation: Only works for numbers that fit in a 64-bit integer (up to 18 digits).
    - OptimalApproach: Traverse the array from the end, handle carry, and insert a new digit at the front if needed.
      * Works for arrays of any length.

    Time Complexity:
        - BruteForce: O(n), where n is the number of digits.
        - OptimalApproach: O(n), where n is the number of digits.

    Space Complexity:
        - BruteForce: O(n), for the result array.
        - OptimalApproach: O(1), modifies the input array in-place except for possible insertion at the front.
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& digits) { // works for only number having digit 18 or less
        long long num = 0;
        vector<int> resultArray;

        // make a number from the digits in the given array
        for (int n: digits) {
            num = (num*10) + n;
        }

        // now, increment the resulting number by 1;
        num++;

        // then, extract each digit from the number and place it in resultArray
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            resultArray.push_back(digit);
        }

        // reverse the resultArray to maintain the order of the array
        int i=0, j = resultArray.size()-1;

        while (i < j) {
            swap(resultArray[i], resultArray[j]);
            i++;
            j--;
        }

        // return the array
        return resultArray;
    }

    vector<int> OptimalApproach(vector<int>& digits) {
        int length = digits.size();

        for (int i=length-1; i>=0; i--) {
            // if digits[i] is less than < 10 after incrementing by 1 than, simple just add 1 and return the array
            if (digits[i] + 1 != 10) {
                digits[i]++;
                return digits;
            } else {
                // if digits[i] == 10 after incrementing by 1 than make digits[i] equal to 0 and at 1st index add 1 into the array and return
                digits[i] = 0;
                if (i == 0) {
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
            }
        }

        return digits;
    }
};

// main function
int main() {
    vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    vector<int> result = Solution().BruteForce(digits);

    for (int num: result) {
        cout << num << " ";
    }

    return 0;
}