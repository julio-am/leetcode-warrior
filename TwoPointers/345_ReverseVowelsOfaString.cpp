class Solution {

private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u';
    }
    
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (isVowel(s[left])) {
                while (right > left) {
                    if (isVowel(s[right])) {
                        char temp = s[left];
                        s[left] = s[right];
                        s[right] = temp;
                        right -=1;
                        break;
                    }
                    right -=1;
                }
            }
            left += 1;
        }
        
        return s;
    }
};