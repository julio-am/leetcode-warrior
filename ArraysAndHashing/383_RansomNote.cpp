class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> seen(26, 0);

        for (auto c : magazine) ++seen[c-'a'];

        for (auto c : ransomNote) 
            if (--seen[c-'a'] < 0) return false;

        return true;
    }
};
