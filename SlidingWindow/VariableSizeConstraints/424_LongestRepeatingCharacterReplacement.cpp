class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int l = 0, maxFreq = 0, result = 0;

        for (int r = 0; r < s.size(); ++r) {
            ++freq[s[r] - 'A'];
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // number wrong chars = length - max frequency
            while (r - l + 1 - maxFreq > k) {
                --freq[s[l] -'A'];
                ++l;
            }
            
            result = max(result, r-l+1);
        }

        return result;
    }
};
