class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.length()-1;
        
        while (front < back) {
            if (!isalnum(s[back])) {
                back-=1;
                continue;
            }
            if (!isalnum(s[front])) {
                front+=1;
                continue;
            }
            
            if (tolower(s[front]) != tolower(s[back])) return false;
            front+=1;
            back-=1;
        }
        return true;
    }
};
