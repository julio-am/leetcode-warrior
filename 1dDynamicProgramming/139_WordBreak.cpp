class Solution {

private:
    bool startsWith(const std::string &str, const std::string &prefix) {
        return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1);
        dp[s.length()] = true;
        
        for (int i = s.length()-1; i >= 0; --i) {
            for (auto word : wordDict) {
                if (startsWith(s.substr(i), word)) {
                    dp[i] = dp[i + word.length()];
                }
                if (dp[i]) break;
            }
        }
        return dp[0];
    }
};
