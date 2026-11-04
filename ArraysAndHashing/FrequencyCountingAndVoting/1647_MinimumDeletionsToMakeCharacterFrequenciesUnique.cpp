class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequencies(26,0);
        
        for (auto c : s) { frequencies[c-'a']++; }
        
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        int maxFreqAllowed = s.size();
        int result = 0;
        
        for (int i = 0; i<frequencies.size() && frequencies[i]>0; ++i) {
            if (frequencies[i] > maxFreqAllowed) {
                result += frequencies[i]-maxFreqAllowed;
                frequencies[i] = maxFreqAllowed;
            }
            maxFreqAllowed = max(0, frequencies[i]-1);
        }
        
        return result;
    }
};
