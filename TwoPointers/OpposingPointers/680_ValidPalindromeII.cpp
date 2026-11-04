//Given a string s, return true if it is a palindrome, otherwise return false.
//A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

class Solution {

private:
    bool palindromeHelper(int l, int r, string& s) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }

        return true;
    }

public:
    bool validPalindrome(string s) {
        bool isDeleted = false;
        int l = 0, r = s.size()-1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return palindromeHelper(l+1, r, s) || palindromeHelper(l, r-1, s);
            }
            ++l;
            --r;
        }
        return true;
    }
};
