class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; //and sometimes, y
        int vowelCount = 0;

        for (int i = 0; i < k; ++i)
            vowelCount += vowels.contains(s[i]) ? 1 : 0;

        int result = vowelCount;

        for (int i = k; i < s.size(); ++i) {
            vowelCount += vowels.contains(s[i-k]) ? -1 : 0;
            vowelCount += vowels.contains(s[i]) ? 1 : 0;

            result = max(result, vowelCount);
        }
        
        return result;
    }
};
