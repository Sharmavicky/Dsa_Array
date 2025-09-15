#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    * The longestCommonPrefix method starts with the first string as an initial prefix
    * and iteratively trims it until it matches the beginning of every string
    * in the input vector. If no common prefix exists, it returns an empty string.
    *
    * Time Complexity: O(N * M)
    *   - N = number of strings
    *   - M = length of the shortest string
    *
    * Space Complexity: O(1) (ignoring input storage)
*/

class Solution {
    public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();

        if (length == 0) return "";
        if (length == 1) return strs[0];

        string prefix = strs[0];

        for (int i = 1; i < length; i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

// main function 
int main() {
    vector<string> strs = { "flower", "flight", "flown" };
    string result = Solution().longestCommonPrefix(strs);

    cout << result;
    return 0;
}