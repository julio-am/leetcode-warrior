//You are given a 0-indexed string s consisting of only lowercase English letters. In one operation, you can change any character of s to any other character.
//Return true if you can make s a palindrome after performing exactly one or two operations, or return false otherwise.

class Solution {
public:
    bool makePalindrome(string s) {
        int l = 0, r = s.size()-1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return palindromeHelper(l+1, r-1, 2, s);
            }

            ++l;
            --r;
        }
        return true;
    }

private:
    bool palindromeHelper(int l, int r, int count, string& s) {
        if (count <= 0) return false;

        while (l <= r) {
            if (s[l] != s[r]) {
                return palindromeHelper(l+1, r-1, count-1, s);
            }

            ++l;
            --r;
        }

        return true;
    }
};
