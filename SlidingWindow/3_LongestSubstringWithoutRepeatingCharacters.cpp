class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = 0;  
        unordered_map<char, int> prevs;
 
        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            // if this letter has been found before
            // and the previous instance is in our window,
            // jump the window to after the instance.
            l = prevs.contains(c) ? max(l, prevs[c]+1) : l;

            prevs[c] = r;
            res = max(res, r-l+1);
        }

        return res;
    }
};
