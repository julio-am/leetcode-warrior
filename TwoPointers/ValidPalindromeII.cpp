class Solution {
public:
    bool validPalindrome(string s) {
        int front = 0;
        int back = s.size()-1;

        while (front <= back) {
            if (s[front] == s[back]) {
                ++front;
                --back;
            }
            
            else if (s[front] != s[back]) {
                return isPalindrome(front+1, back, s) || isPalindrome(front, back-1, s);
            }
        }

        return true;
    }

    bool isPalindrome(int start, int end, string s) {
        while (start <= end) {
            if (s[start] == s[end]) {
                ++start;
                --end;
                continue;
            }

            return false;
        }
        return true;
    }
};
