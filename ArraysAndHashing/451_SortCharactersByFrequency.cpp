// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        vector<vector<int>> frequencies(s.size()+1);
        string result;
      
        for (auto c : s)
            ++count[c];

        for (auto pair : count)
            frequencies[pair.second].push_back(pair.first);

        for (int i = frequencies.size()-1; i>=0; --i) {
            for (auto c : frequencies[i]) {
                result += string(i, c);
            }
        }

        return result;
    }
};
