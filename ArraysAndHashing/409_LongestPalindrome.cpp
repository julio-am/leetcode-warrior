class Solution {
public:
    int longestPalindrome(string s) {
        int result = 0, leftover = 0;
        vector<int> seen(128,0);

        for (auto c : s) 
            ++seen[c];

        for (auto i : seen) {
            result += i;
            if (i % 2) {
                --result;
                leftover = 1;
            }
        }

        return result + leftover;
    }
};
