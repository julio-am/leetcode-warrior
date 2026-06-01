class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();
        int minLen = min(first.size(), last.size());

        int prefixLen = 0;
        for (prefixLen; prefixLen < minLen; ++prefixLen){
            if (first[prefixLen] != last[prefixLen]){
                break;
            }
        }

        return first.substr(0, prefixLen);
    }
};
