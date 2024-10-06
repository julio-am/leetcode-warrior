class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    string reverseVowels(string s) {

        int left = 0, right = s.size()-1;
        while (left < right) {
            if (isVowel(s[left])) {
                while (!isVowel(s[right])) {
                    --right;
                }
    
                swap(s[left], s[right]);
                --right;
            }

            ++left;
        }

        return s;
    }
};
