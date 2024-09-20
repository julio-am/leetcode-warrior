//You are given a string s consisting of lowercase english letters.
//We want to split the string into as many substrings as possible, while ensuring that each letter appears in at most one substring.
//Return a list of integers representing the size of these substrings in the order they appear in the string.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastPos;
        vector<int> result;

        for (int i = 0; i<s.size(); ++i) {
            lastPos[s[i]] = i; 
        }

        int l = 0;
        int r = 0;
        for (int i = 0; i < s.size(); ++i) {
            r = max(r, lastPos[s[i]]);

            if (i == r) {
                result.push_back(r-l+1);
                l = i+1;
            }
        }
        return result;

    }
};
