class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string result;

        while (i < word1.size() || i < word2.size()) {
            if (i < word1.size()) result.push_back(word1[i]);
            if (i < word2.size()) result.push_back(word2[i]);

            ++i;
        }

        return result;
    }
};
