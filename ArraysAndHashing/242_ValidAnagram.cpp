class Solution {
public:
    bool isAnagram(string s, string t) {

        // Early return if sizes not same.
        if (s.size() != t.size()) return false;

        // Keep track of values in array
        int count[26] = {};
        for (auto c : s) ++count[c-'a'];
        for (auto c : t) --count[c-'a'];

        for (auto i : count) {
            if (i != 0) return false;
        }
    
        return true;
    }
};
